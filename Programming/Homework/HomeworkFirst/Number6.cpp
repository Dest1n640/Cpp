#include <iostream>
#include <cmath>

int main(){
    setlocale (LC_ALL, "RU");
    float r,a;
    std::cout<<"Введите радиус круга (r): ";
    std::cin>>r;
    std::cout<<"Введите значение стороны для правильного треугольника(a): ";
    std::cin>>a;
    
    float S_triang = sqrt(3) / (4) * (a*a);
    float S_circle = M_PI * (r*r);
    float count = S_triang/ S_circle;

    std::cout<<"Количество кругов которые поместятся в треугольник: "<< int(count)<<std::endl;
    
    return 0;

    
}