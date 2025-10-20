#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "./string.h"

int puts(const char *c) {
    int rc = 0;
    rc = write(1, c, strlen(c));
    if (rc < 0)
        return -1;
    rc = write(1, "\n", 1);
    if (rc < 0)
        return -1;
    return 0;
}
