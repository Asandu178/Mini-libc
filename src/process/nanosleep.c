#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp) {
    int rc = syscall(__NR_nanosleep, rqtp, rmtp);
    if (rc < 0) {
        errno = -rc;
        return -1;
    }
    return rc;
}
