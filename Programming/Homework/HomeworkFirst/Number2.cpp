#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "RU");

    double radians;
    std::cout <<"Ведите количество радиан: ";
    std::cin >> radians;

    double degrees, minutes, seconds;
    degrees = radians * (180.0 / M_PI);
    double y = degrees - int(degrees);
    minutes = y * 60;
    double x = minutes - int(minutes);
    seconds = x * 60;
    

    std::cout << "Количество градусов: "<< degrees <<std::endl;
    std::cout <<"Количество минут: "<< minutes <<std::endl;
    std::cout <<"Количество секунд: "<< seconds << std::endl;
    
    return 0;

}