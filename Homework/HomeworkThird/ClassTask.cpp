#include <iostream>
using namespace std;

int main(){
    int a = 125;
    float b = -1.125;
    float c = 1.125;
    cout << "a(dec) = " << a << "\t a(hex) = " << hex << a << endl;
    cout << "b(dec)= " << b << "\t b(hex) = " << hex << b << endl; // hex не умеет работать с float 
    a = *(int*)&b;
    cout << "dec - "<<dec<< a << "\t(hex) - "<<hex << a << endl;
    int sign = *(int*)&b >> 31;
    int abs_b = a & INT_MIN;
    abs_b = *(float*)&abs_b;
    cout <<"|b - |"<< abs_b << endl;
    cout <<"dec - "<< dec << a <<"\ta(hex) - "<< hex << a <<endl;
    a = a >> 31;
    cout << "dec(a) - "<<dec<<a <<"\thex(a) - "<<hex << a << endl;
    // std::cout<< "a - " << a << "\tadress a = "<< &a << std::endl;
    // std::cout<<"p_a - "<< p_a<< "\t a = " << *p_a <<std::endl;
    // std::cout<<"Hello world"<<std::endl;   //ДОСТАТЬ МИНИМАЛЬНОЕ ЗНАЧЕНИЕ
    return 0;
}