#ifndef OS_2_PROJECT_DATETIME_UTILS_H
#define OS_2_PROJECT_DATETIME_UTILS_H

#include <time.h>

void vladutz_get_current_time(struct tm *timeinfo);

char *vladutz_format_time(const struct tm *timeinfo, const char *format);

int vladutz_days_difference(const struct tm *date1, const struct tm *date2);

#endif //OS_2_PROJECT_DATETIME_UTILS_H
