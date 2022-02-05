#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*struct tm {
    int tm_sec;    秒 – 取值區間為[0,59]
    int tm_min;    分 - 取值區間為[0,59]
    int tm_hour;   時 - 取值區間為[0,23]
    int tm_mday;   一個月中的日期 - 取值區間為[1,31]
    int tm_mon;    月份（從一月開始，0代表一月） - 取值區間為[0,11]
    int tm_year;   年份，其值等於實際年份減去1900
    int tm_wday;   星期 – 取值區間為[0,6]，其中0代表星期天，1代表星期一，以此類推
    int tm_yday;   從每年的1月1日開始的天數 – 取值區間為[0,365]，其中0代表1月1日，1代表1月2日，以此類推
    int tm_isdst;  夏令時標識符，實行夏令時的時候，tm_isdst為正。不實行夏令時的進候，tm_isdst為0；不了解情況時，tm_isdst為負。
};*/

int main(void){
    time_t now;
    struct tm* tptr;
    time(&now);
    tptr = localtime(&now);
    printf("%02d/%02d/%d\n", tptr->tm_mon + 1, tptr->tm_mday, tptr->tm_year + 1900);
    printf("%02d:%02d:%02d\n", tptr->tm_hour, tptr->tm_min, tptr->tm_sec);
    switch(tptr->tm_wday){
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 0:
            printf("Sunday\n");
            break;
    }
    return 0;
}
