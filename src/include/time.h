#ifndef __TIME_H__
#define __TIME_H__ 1


struct timespec {
    long long tv_sec;
    long long tv_nsec;
};

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

#endif
