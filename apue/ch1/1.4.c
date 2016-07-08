#include <limits.h>
#include <time.h>
#include <stdio.h>

char *get_date_str_utc(time_t ts)
{
    static char buf[80];

    struct tm max_ts;
    max_ts = *gmtime(&ts);
    
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &max_ts);
    return buf;
}

int main() 
{
    printf("Max time for 32bit signed integer timestamp: %s\n", get_date_str_utc(INT_MAX));
    printf("Max time for 32bit unsigned integer timestamp: %s\n", get_date_str_utc(UINT_MAX));
    return 0;
}

