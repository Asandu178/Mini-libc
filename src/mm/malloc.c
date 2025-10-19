// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (!mem_list_num_items)
		mem_list_init();
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!p)
		return NULL;
	if (!mem_list_add(p, size)) {
		return p;
	}
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
	if (!mem_list_num_items)
		mem_list_init();
	void *p = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!p)
		return NULL;
	if (!mem_list_add(p, total_size)) {
		return p;
	}
	return NULL;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *l = mem_list_find(ptr);
	munmap(l->start, l->len);
	mem_list_del(ptr);

}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *l = mem_list_find(ptr);
	l->start = mremap(l->start, l->len, size, MREMAP_MAYMOVE);
	l->len = size;
	return l->start;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = size * nmemb;
	struct mem_list *l = mem_list_find(ptr);
	l->start = mremap(l->start, l->len, total_size, MREMAP_MAYMOVE);
	l->len = total_size;
	return l->start;
}
