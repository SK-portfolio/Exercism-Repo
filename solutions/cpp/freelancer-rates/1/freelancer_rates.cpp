// INFO: Headers from the standard library should be inserted at the top via
#include <cmath>

//#####################################################################
// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate*8;
}

//#####################################################################
// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double reduction = before_discount * (discount * 0.01);
    return before_discount - reduction;
}

//#####################################################################
// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double dsc_hourly_rate = apply_discount(hourly_rate, discount);
    int dsc_monthly_rate = ceil(daily_rate(dsc_hourly_rate) * 22);
    return dsc_monthly_rate;
}

//#####################################################################
// days_in_budget calculates the number of workdays given a budget, hourly rate, and discount
// the returned number of days is rounded down (take the floor) to the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double dsc_hourly = apply_discount(hourly_rate, discount);
    double dsc_daily = daily_rate(dsc_hourly);
    int days_completed = floor(budget/dsc_daily);
    return days_completed;
}
