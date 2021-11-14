//
// Created by daniil_stepanenko on 14.11.2021.
//

#include "../include/time.h"

time_of_day lab4(time_of_day list[], int size) {
    time_of_day result = list[0];

    for (int i = 1; i < size; i++) {
        result = add_time_of_day(result, list[i]);
    }

    return div_time_of_day(result, size);
}
