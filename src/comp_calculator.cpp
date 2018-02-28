#include <iostream>
#include <stdio.h>

const double exerciseShoePrice = 225.00;
const int weeklyHours = 40;
const double hourlyWage = 7.0;
const double salariedCommissionRate = 0.10;
const double pureCommissionRate = 0.20;
const double unitBonus = 20.00;

double CaluclateSalariedCommissionComp(double weeklySales) {
    double hourlyPay = weeklyHours * hourlyWage;
    double commission = (weeklySales * exerciseShoePrice) * salariedCommissionRate;
    return hourlyPay + commission;
}

double CaluclateCommissionOnlyComp(double weeklySales) {
    double commission = (weeklySales * exerciseShoePrice) * pureCommissionRate;
    double totalUnitBonus = weeklySales * unitBonus;
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
