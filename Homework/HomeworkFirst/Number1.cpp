#include <iostream>
#include <cmath>

int main(){
	setlocale(LC_ALL, "RU");

    double degrees;
	double minuts;
	double second;
    std::cout<<"Введите значение угла в граусах: ";
    std::cin>> degrees;
	std::cout<<"Введите значение угла в минутах: ";
	std::cin>> minuts;
	std::cout<<"Значение значение угла в секундах: ";
	std::cin >> second;

    degrees = degrees + second/60 + minuts/3600;
	double radians;
    radians = (M_PI / 180) * degrees;

    std::cout<<radians;

    return 0;


}