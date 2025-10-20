#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    const struct timespec time = {seconds, 0};
    return nanosleep(&time, NULL);
}
