#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    double k;
    cout << "Введите  расстояние (в км): ";
    cin >> k;
    cout << fixed << setprecision(4);
    cout << "\nМили\tКиллометры\n";
    double miles = 0.0;

    while (miles <= k * 0.621371) { 
        double km = miles * 1.609344;
        cout << miles << "\t" << km << endl;
        miles += 0.621371; 
    }

    cout << "\nМили\tКм\n";
    double km = 0.0;

    while (km <= k) {
        double milesb = km * 1.609344; 
        cout << km << "\t" << milesb << "\n";

        km += 1.0; 
    }
}