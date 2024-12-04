#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double h, m, s;
    std::cout<<"Введите время через пробел (h m s): ";
    std::cin>> h >> m >> s;
    
    double h1, m1, s1;
    s1 = s + h * 3600 + m * 60;
    h1 = round(s1 / 3600);
    m1 = (s1 / 3600 - int(s1 / 3600)) * 60;

    std::cout << h1 << " or " << int(h) << ':' << round(m1) << std::endl;

    return 0;
}