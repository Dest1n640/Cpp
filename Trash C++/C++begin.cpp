#include <iostream>
#include <cmath>

int main(){
    double a;
    std::cout<<"Введите значение угла: ";
    std::cin>>a;
    
    double hours;
    hours = a/60;
    double minute;
    minute = a/3600;

    double radians = a + hours + minute;

    radians = (M_PI / 180) * radians;

    std::cout<<radians;

    return 0;


}