//
// Created by daniil_stepanenko on 14.11.2021.
//

#ifndef UNIVERSITY_TIME_H
#define UNIVERSITY_TIME_H

struct time_of_day {
    int hours;
    int minutes;
    int seconds;
};

void print_time_of_day(time_of_day t);

time_of_day make_time_of_day(int hours, int minutes, int seconds);

time_of_day add_time_of_day(time_of_day a, time_of_day b);

time_of_day div_time_of_day(time_of_day t, int divider);

#endif //UNIVERSITY_TIME_H
