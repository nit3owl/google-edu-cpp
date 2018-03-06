#include <iostream>
#include <stdio.h>

const double kExerciseShoePrice = 225.00;
const int kWeeklyHours = 40;
const double kHourlyWage = 7.0;
const double kSalariedCommissionRate = 0.10;
const double kPureCommissionRate = 0.20;
const double kUnitBonus = 20.00;

double CaluclateSalariedCommissionComp(double weeklySales) {
    double hourlyPay = kWeeklyHours * kHourlyWage;
    double commission = (weeklySales * kExerciseShoePrice) * kSalariedCommissionRate;
    return hourlyPay + commission;
}

double CaluclateCommissionOnlyComp(double weeklySales) {
    double commission = (weeklySales * kExerciseShoePrice) * kPureCommissionRate;
    double totalUnitBonus = weeklySales * kUnitBonus;
    return commission + totalUnitBonus;
}

int GetWeeklySales() {
    int weeklySales;
    if(!(std::cin >> weeklySales)) {
        return -1;
    }

    return weeklySales;
}

int main() {
    printf("Enter weekly sales units: ");
    int weeklySales = GetWeeklySales();
    if(weeklySales == -1) {
        std::cerr << "Invalid input!" << std::endl;
        return 1;
    }

    printf("Weekly salary calculations:\n");
    printf("Straight salary = $%.2f\n", 600.00);
    printf("Salary plus commisssion = $%.2f\n", CaluclateSalariedCommissionComp(weeklySales));
    printf("Pure commission = $%.2f\n", CaluclateCommissionOnlyComp(weeklySales));

    return 0;
}
