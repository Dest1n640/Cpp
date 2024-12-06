#include <iostream>
#include <cmath>

using namespace std;

void calculateDebtRepayment(double k, double p, double r) {
    setlocale(LC_ALL, "ru");
    double debt = k, profit = 0;
    int years = 0;
    while (profit < debt) {
        debt += debt * (p / 100);
        profit += r;
        years++;
        if (years > 100) {
            cout << "Невозможно погасить кредит." << endl;
            return;
        }
    }
    cout << "Кредит будет погашен через " << years << " лет." << endl;
}

int main() {
    double k = 100000, p = 10, r = 15000;
    calculateDebtRepayment(k, p, r);
    return 0;
}
