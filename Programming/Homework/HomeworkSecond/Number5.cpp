#include <iostream>
#include <iomanip>

using namespace std;

void printConversionTable(double maxKm) {
    setlocale(LC_ALL, "ru");
    const double mileToKm = 1.609344;
    cout << setw(10) << "Мили" << setw(15) << "Км" << endl;
    for (double km = 1.0; km <= maxKm; km += 1.0) {
        double miles = km / mileToKm;
        cout << setw(10) << fixed << setprecision(4) << miles 
             << setw(15) << fixed << setprecision(4) << km << endl;
    }
}

int main() {
    double maxKm = 10.0;
    printConversionTable(maxKm);
    return 0;
}
