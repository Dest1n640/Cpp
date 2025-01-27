#include <iostream>
using namespace std;
int main(){
    int N = 80;
    char* str = new char[N+1]; // Выделяем память под динамический массив str 
    cout << "Write the str - ";
    cin.getline(str, N); //Заполняем пассив данными, введенными с конлсоли
    cout << str <<endl;
    N = 60;
    delete [] str; // Очистка памятиъ
    str = new char [N + 1];

    for(int i = 0; i < N; i++)
        str[i] = 'a' + i; //Английский алфавит
    
    str[N] = '\0';
    cout << str << endl;
    return 0;    

    // const int M = 80
    // char my_str[M];
    // char my_str[80];  
}