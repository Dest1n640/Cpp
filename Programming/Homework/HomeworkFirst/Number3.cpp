
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    float k, p, s, f;
    cout << "Введите стартовый капитал (k): ";
    cin >> k;
    cout << "Введите ежемесячный капитал (p%): ";
    cin >> p;
    cout << "Сумма для покапки магазина (s): ";
    cin >> s;
    f = log(s / k) / 12 /(log(1 + p / 100));
    cout <<int(f) + 1<< " Лет";
    
    return 0;



}