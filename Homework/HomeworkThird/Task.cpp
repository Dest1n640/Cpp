#include <iostream>

using namespace std;

int main(){
    float a;
    cout<<"Enter the number whose sign you want to change - ";
    cin >> a;
        
    if (a < 0){
        int sign = *(int*)&a;
        int abs = sign & INT_MAX;
        a = *(float*)&abs;
        cout << "Number = "<< a << endl;
        return -1;
    }
    else if (a > 0){
        int sign = *(int*)&a;
        int abs = sign | INT_MIN;
        a = *(float*)&abs;
        cout <<"Number = "<< a <<endl;
        return -2;
    }
    else{
        cout <<"Number = 0"<< endl;
    }
    return 0;
}