#include <iostream>

using namespace std;
//В условии задачи для 4 значного, но я сделал дял 6-ти значного

int main() {
    cout << "Четырёхзначные числа с уникальными цифрами:\n";
    for (int number = 900000; number <= 999999; ++number) {
        int f = number / 100000;
        int e = (number / 10000) % 10;
        int a = (number / 1000) % 10;            
        int b = (number / 100) % 10;      
        int c = (number / 10) % 10;        
        int d = number % 10;               

        if (a != b && a != c && a != d && a != e && a != f &&b != c && b != d &&
            b != e && b != f &&
            c != d && c != e && c != f &&
            d != e && d != f && e != f) {
            cout << number << " ";
        }
    }
    return 0;
}