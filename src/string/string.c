// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *c = destination ;
	for (; *source != '\0' ; c++ , source++) {
		*c = *source;
	}
	*c = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *c = destination;
	for (int i = 0 ; i < len ; i++ , c++, source++) {
		*c = *source;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	size_t len = strlen(destination);
	char *c = destination + len;
	for ( ; *source != '\0' ; source++, c++) {
		*c = *source;
	}
	*c = *source;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t length = strlen(destination);
	char *c = destination + length;
	for (size_t i = 0 ; *source != '\0' && i < len; source++, c++, i++) {
		*c = *source;
	}
	*c = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	char val;
	while (*str1 || *str2) {
		val = *str1 - *str2;
		if (val < 0)
			return -1;
		if (val > 0)
			return 1;
		str1++;
		str2++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	char val;
	while ((*str1 || *str2) && len) {
		val = *str1 - *str2;
		if (val < 0)
			return -1;
		if (val > 0)
			return 1;
		str1++;
		str2++;
		len--;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for ( ; *str != '\0' ; str++)
		if (*str == (char)c)
			return str;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *res = NULL;
	for ( ; *str != '\0' ; str++) 
		if (*str == (char)c)
			res = str;
	return res;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	size_t req = strlen(needle);
	for ( ; *haystack != '\0' ; haystack++) {
		if (strncmp(haystack, needle, req) == 0)
			return haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	size_t req = strlen(needle);
	char *str = NULL;
	for ( ; *haystack != '\0' ; haystack++) {
		if (strncmp(haystack, needle, req) == 0)
			str = haystack;
	}
	return str;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = destination;
	char *src = source;
	for (size_t i = 0 ; i < num ; i++) {
		*dest = *src;
		dest++;
		src++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}
