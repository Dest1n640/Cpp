#include <iostream>
using namespace std;

int main(){
    int N = 80;
    char* str = new char[N+1];
    cout << "Write the text - ";
    cin.getline(str, N);
    cout << str << endl;

    for (int i = 0; i < N + 1 && str[i] != '\0'; i++){
        if (str[i] == ' ' && str[i+1] == ' '){
        
        }
    }
    cout << str <<endl;
    delete [] str;
    return 0;
}