//
// Created by daniil_stepanenko on 14.11.2021.
//

#include <stdio.h>

#include "../include/time.h"

#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR 60

void normalize(int* h, int* l, int base) {
    int hi = *h;
    int lo = *l;

    if (lo < 0) {
        int n = (-lo-1)/base + 1;
        hi -= n;
        lo += n * base;
    }

    if (lo >= base) {
        int n = lo / base;
        hi += n;
        lo -= n * base;
    }

    *h = hi;
    *l = lo;
}

void div(int* hi, int* lo, int divider, int base) {
    *lo += *hi % divider * base;
    *hi /= divider;
}

void print_time_of_day(time_of_day t) {
    printf("%i:%i:%i\n", t.hours, t.minutes, t.seconds);
}

time_of_day make_time_of_day(int hours, int minutes, int seconds) {
    normalize(&minutes, &seconds, SECONDS_IN_MINUTE);
    normalize(&hours, &minutes, MINUTES_IN_HOUR);

    time_of_day t;
    t.hours = hours;
    t.minutes = minutes;
    t.seconds = seconds;

    return t;
}

time_of_day add_time_of_day(time_of_day a, time_of_day b) {
    return make_time_of_day(
            a.hours + b.hours,
            a.minutes + b.minutes,
            a.seconds + b.seconds
    );
}

time_of_day div_time_of_day(time_of_day t, int divider) {
    div(&t.hours, &t.minutes, divider, MINUTES_IN_HOUR);
    div(&t.minutes, &t.seconds, divider, SECONDS_IN_MINUTE);
    t.seconds /= divider;

    return t;
}
