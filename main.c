#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   
    int year, month, day;
    printf("연도를 입력하세요 (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);


    struct tm input_date = {0};
    input_date.tm_year = year - 1900;
    input_date.tm_mon = month - 1;  
    input_date.tm_mday = day;

  
    mktime(&input_date); 
    char* WEEK[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    printf("입력한 날짜 %d-%02d-%02d는 %s입니다.\n", year, month, day, WEEK[input_date.tm_wday]);

    
    time_t current_time = time(NULL); 
    struct tm* today_info = localtime(&current_time);

    struct tm today = *today_info; 
    today.tm_hour = 0; today.tm_min = 0; today.tm_sec = 0;

    
    time_t input_time = mktime(&input_date);
    time_t today_time = mktime(&today);    

    double difference = difftime(input_time, today_time) / (60 * 60 * 24); 
    if (difference > 0) {
        printf("입력한 날짜는 오늘로부터 %.0f일 남았습니다.\n", difference);
    } else if (difference < 0) {
        printf("입력한 날짜는 오늘로부터 %.0f일 전이었습니다.\n", -difference);
    } else {
        printf("입력한 날짜는 오늘입니다.\n");
    }

    return 0;
}
