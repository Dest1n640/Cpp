#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
using namespace std;
int main(){
    ifstream my_file("text.txt");

    if (!my_file.is_open())
    {
        cout<<"Файла не существет"<<endl;
        return -1;
    }
    else{
        cout<<"Файл открыт"<<endl;
    }
    int a,b,c;
    if (my_file.fail()){
        std::cout<< "READ ERROR"<<endl;
        return -2;
    }
    my_file>>a>>b>>c;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c;
    my_file.close();
    ofstream out("text.txt");
    if (!out.is_open()){
        cout<<"Файл не открылся"<<endl;
    }
    else{
        cout<<"Файл открылся"<<endl;
    }   
    out << a << " + "<< b<< " + "<< c << " = "<<a + b + c << endl;
    out.close();
    return 0;   
}