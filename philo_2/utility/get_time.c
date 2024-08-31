#include "../philosopher.h"

long long get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((long long)(time.tv_sec) * 1000) + ((long long)(time.tv_usec) / 1000);
}
