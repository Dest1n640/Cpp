#include <iostream>
#include <cmath>
#include<locale.h>

int maint(){
    setlocale(LC_ALL, "RU");

    double a,b,c,x1,x2, x0;
    
    std::cout<<"Введите значение переменной (a): ";
    std::cin>>a;
    std::cout<<"Введите значение переменной (b): ";
    std::cin>>b;
    std::cout<<"Введите значение переменной (с): ";
    std::cin>>c;
    
    double d = b*b-4*a*c;
    if (d > 0){
        x1 = (-b + sqrt(d))/2*a;
        x2 = (-b - sqrt(d))/2*2;
        std::cout<<"Первый корень уравнения: "<< x1<<std::endl;
        std::cout<<"Второй корень уравнения: "<<x2<<std::endl;
    }

    else if (d=0){
        
        x0 = -b/2*a;
        std::cout<<"Корень уравнения: "<<x0<<std::endl;
        
    }

    else{
        std::cout<<"Корней нет"<<std::endl;
    }

    return 0;

}