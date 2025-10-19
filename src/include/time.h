#ifndef TIME_H
#define TIME_H


struct timespec {
    long long tv_sec;
    long long tv_nsec;
};

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

#endif