#include <iostream>

using namespace std;

int getNod(int, int);
int main(){
    int a = 10, b = 5;
    int c = getNod(a, b);
    cout << c << endl;
    cout << getNod << endl;
}
int getNod(int a, int b){
        return a + b;
}