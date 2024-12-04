#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int main(){
    setlocale (LC_ALL, "RU");
    float a, b;
    char c;
    cout<<"Enter symbol ";
    cin>>c;
    cout<<"num1 ";
    cin>>a;
    cout<<"num2 ";
    cin>>b;
    
    switch (c)
    {
    case '+':
        a+=b;
        cout<<a<<endl;
        break;
    case '-':
        a-=b;
        cout<<b<<endl;
        break;
    case '*':
        a*=b;
        cout<<a<<endl;
        break;
    case '/':
        a/=b;
        cout<<a<<endl;
        break;
    default:
        cout<<"Wrong symbol"<<endl;
        break;
    }
    return 0;
}