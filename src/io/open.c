// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	mode_t mode = 0;
	va_list list;
	long fd;

	if (flags & O_CREAT) {
		va_start(list, flags);
		mode = va_arg(list, mode_t);
		fd = syscall(__NR_open, filename, flags, mode);
		va_end(list);
	} else {
		fd = syscall(__NR_open, filename, flags);
	}
	if (fd < 0) {
		errno = -fd;
		return -1;
	}
	return (int)fd;
}
