#include<stdio.h>

double health_premium(double income){
    if (income < 25000) {
        return 0.0;
    }
    else if (income < 50000) {
        return income * 0.05;
    }
    else if (income <= 100000) {
        return income * 0.07;
    } else {
        return (income - 100000) * 0.1 + 7000;
    }
}
int main() {

    printf("Please enter your income:");
    double income;
    scanf("%lf", &income);
    double premium = health_premium(income);
    printf("$%.2f\n", premium);
    return 0;
}
