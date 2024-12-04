#include <iostream>

int main(){
    setlocale (LC_ALL, "RU");
    double k,p,r;
    std::cout<<"The credit: ";
    std::cin>>k;
    std::cout<<"The percent per year: ";
    std::cin>>p;
    std::cout<<"The sellery: ";
    std::cin>>r;
    int count = 0;
    while(r < k){
        r += r;
        k = k + (k * (p/100));
        count += 1;
    }
    if (count>= 60){
        std::cout<<"Кредит не будет погашен"<<std::endl;
        return 0;
    }

    std::cout<<"Погасит кредит за "<<count<<" лет"<<std::endl;

    return 0;
}