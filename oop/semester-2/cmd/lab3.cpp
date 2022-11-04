#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>

#include "../include/daily_capitalize_deposit.h"
#include "../include/monthly_capitalize_deposit.h"
#include "../include/quarterly_capitalize_deposit.h"
#include "../include/deposits_list.h"
#include "../include/time_utils.h"

#define AMOUNT 350000
#define ANNUAL_PERCENTAGE 4.7

int main() {
    try {
        time_t created;
        time(&created);
        auto from = created - 60 * SECONDS_IN_DAY;
        auto to = created + 273 * SECONDS_IN_DAY;


        auto dailyDeposit = DailyCapitalizeDeposit(AMOUNT, ANNUAL_PERCENTAGE, created);
        std::cout << "Доход от вклада с ежедневной капитализацией за указанный период составит "
                  << dailyDeposit.CalculateCompoundPercentage(from, to) << std::endl;

        auto monthlyDeposit = MonthlyCapitalizeDeposit(AMOUNT, ANNUAL_PERCENTAGE, created);
        std::cout << "Доход от вклада с ежемесячной капитализацией за указанный период составит "
                  << monthlyDeposit.CalculateCompoundPercentage(from, to) << std::endl;

        auto quarterlyDeposit = QuarterlyCapitalizeDeposit(AMOUNT, ANNUAL_PERCENTAGE, created);
        std::cout << "Доход от вклада с ежеквартальной капитализацией за указанный период составит "
                  << quarterlyDeposit.CalculateCompoundPercentage(from, to) << std::endl;


        DepositsList list;
        list.Append(&dailyDeposit);
        list.Append(&monthlyDeposit);
        list.Append(&quarterlyDeposit);
        std::cout << "Сумарный доход со всех вкладов за указанный период составит "
                  << list.CalculateCompoundPercentage(from, to) << std::endl;

    } catch (char const *msg) {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
