#include <stdio.h>
#include "datetime.h"
#include "time.h"
#include <time.h>
// #include "time.c"

boolean isLeapYear(int Y){
    boolean leap = false;
    if(Y % 400 == 0) leap = true;
    else if(Y % 400 != 0 && Y % 100 == 0) leap = false;
    else if(Y % 400 != 0 && Y % 100 != 0 && Y % 4 == 0) leap = true;
    else if(Y % 400 != 0 && Y % 100 != 0 && Y % 4 != 0) leap = false;
    return leap;
}

int GetMaxDay(int M, int Y){
            // jan feb mar mei jun jul
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    boolean leap = isLeapYear(Y);

    if(leap){
        return days_leap[M-1];
    } else {
        return days[M-1];
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    boolean time = IsTIMEValid(h, m, s);
    if(M >= 1 && M <= 12 && 1900 <= Y && Y <= 2030){
        if(D >= 1 && D <= GetMaxDay(M, Y)){
            return true && time;
        }
        return false;
    }
    return false;
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    TIME t;
    CreateTime(&t, hh, mm, ss);
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = t;
}

void BacaDATETIME(DATETIME *D){
    int DD, MM, YYYY, hh, mm, ss;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    while(!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)){
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    }
    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}

void TulisDATETIME(DATETIME D){
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2){
    if(Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2))){
        return true;
    }
    return false;
}

long long int DATETIMEToDetik(DATETIME D){
    const int seconds_in_minute = 60;
    const int seconds_in_hour = 3600;
    const int seconds_in_day = 86400;
    const int seconds_in_year = 31536000;  // Non-leap year
    const int seconds_in_leap_year = 31622400;  // Leap year
    long long int total_seconds = 0;

    // Calculate seconds for full years
    for (int year = 1970; year < Year(D); year++) {
        if (isLeapYear(year)) {
            total_seconds += seconds_in_leap_year;
        } else {
            total_seconds += seconds_in_year;
        }
    }

    // Calculate seconds for full months
    const int days_in_month[] = {0, 31, 28 + isLeapYear(Year(D)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int month = 1; month < Month(D); month++) {
        total_seconds += days_in_month[month] * seconds_in_day;
    }

    // Calculate seconds for full days, hours, minutes, and seconds
    total_seconds += (Day(D) - 1) * seconds_in_day;
    total_seconds += Hour(Time(D)) * seconds_in_hour;
    total_seconds += Minute(Time(D)) * seconds_in_minute;
    total_seconds += Second(Time(D));

    return total_seconds;
}

DATETIME CharToDATETIME(char s[]){
    DATETIME d;
    TIME t;

    int len = strLen(s);

    int i;
    int temp = 0;
    int pos = 0;
    for(i=0; i<len; i++){
        // printf("%c\n", s[i]);
        if(s[i] == '/'){
            if(pos == 0){
                Day(d) = temp;
                temp = 0;
                pos++;
                continue;
            } else if (pos == 1){
                Month(d) = temp;
                temp = 0;
                pos++;
                continue;
            }
        } else if(s[i] == ' '){
            if(pos == 2){
                Year(d) = temp;
                temp = 0;
                pos++;
            }
            continue;
        } else if(s[i] == ':'){
            if(pos == 3){
                Hour(t) = temp;
                temp = 0;
                pos++;
                continue;
            } else if (pos == 4){
                // printf("called\n");
                Minute(t) = temp;
                temp = 0;
                pos++;
                continue;
            }
        } else {
            temp = temp * 10 + s[i] - '0';
        }
    }
    if(pos == 5){
        Second(t) = temp;
        temp = 0;
        pos++;
    }
    Time(d) = t;
    return d;
}

boolean DNEQ(DATETIME D1, DATETIME D2){
    return !DEQ(D1, D2);
}

// boolean DLT(DATETIME D1, DATETIME D2){
//     return (DATETIMEToDetik(D1) < DATETIMEToDetik(D2));
// }

boolean DGT(DATETIME D1, DATETIME D2){
    return (DATETIMEToDetik(D1) > DATETIMEToDetik(D2));
}



DATETIME DetikToDATETIME(long long int sec){
    DATETIME D;
    CreateDATETIME(&D, 1, 1, 1970, 0, 0, 0);

    const int seconds_in_minute = 60;
    const int seconds_in_hour = 3600;
    const int seconds_in_day = 86400;
    long long int remaining_seconds = sec + (seconds_in_hour * 7);

    // Handle leap years and calculate years, months, days, hours, minutes, and seconds
    while (remaining_seconds >= 0) {
        int seconds_in_year = (isLeapYear(Year(D)) ? 31622400 : 31536000); // Seconds in a year

        if (remaining_seconds >= seconds_in_year) {
            remaining_seconds -= seconds_in_year;
            Year(D)++;
        } else {
            int month_lengths[] = {0, 31, 28 + isLeapYear(Year(D)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            for (Month(D) = 1; Month(D) <= 12; Month(D)++) {
                int seconds_in_month = month_lengths[Month(D)] * seconds_in_day;

                if (remaining_seconds >= seconds_in_month) {
                    remaining_seconds -= seconds_in_month;
                } else {
                    break;
                }
            }

            Day(D) = remaining_seconds / seconds_in_day + 1;
            remaining_seconds %= seconds_in_day;
            Hour(Time(D)) = remaining_seconds / seconds_in_hour;
            remaining_seconds %= seconds_in_hour;
            Minute(Time(D)) = remaining_seconds / seconds_in_minute;
            Second(Time(D)) = remaining_seconds % seconds_in_minute;
            break;
        }
    }

    return D;
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    long long int second = DATETIMEToDetik(D) + N;
    return DetikToDATETIME(second);
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    return DATETIMENextNDetik(D, -N);
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    return (DATETIMEToDetik(DAkh) - DATETIMEToDetik(DAw));
}

long long int getCurrentTime(){
    // output dalam UNIX Timestamp
    time_t current_time = time(NULL);
    if(current_time == ((time_t) - 1)){
        perror("current_time error");
        return 1;
    }
    return (long long int) current_time;
}