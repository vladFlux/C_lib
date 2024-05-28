#include "datetime_utils.h"

void vladutz_get_current_time(struct tm *timeinfo) {
    time_t rawtime;
    time(&rawtime);
    localtime_r(&rawtime, timeinfo);
}

char* vladutz_format_time(const struct tm *timeinfo, const char *format) {
    static char buffer[80];
    strftime(buffer, sizeof(buffer), format, timeinfo);
    return buffer;
}

int vladutz_days_difference(const struct tm *date1, const struct tm *date2) {
    time_t time1 = mktime(date1);
    time_t time2 = mktime(date2);
    double difference = difftime(time1, time2);
    return difference / (60 * 60 * 24);
}
