#include <iostream>
#include <ctime>   //
#include <cstdlib>  //2 БИБЛИОТЕКИ ДЛЯ ИСПОЛЬЗОВАНИЯ РАНДОМА

using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int my_mass[10];
    int* ptr = my_mass;

    for (int i = 0; i < 10; ++i){
        *(ptr + i)= rand() % 101 - 50;
    }
    cout << "Основной массив - " << endl;
    for (int i = 0; i < 10; i++){
        cout << *(ptr + i) <<" ";
    }
    cout << endl;
    
    int* min_ptr = ptr;
    for (int i = 1; i < 1; ++i){
        if (*(ptr + i) < *min_ptr){
            min_ptr = ptr + i;
        }
    }

    cout << "Минимальное значение - " << *min_ptr << endl;
    return 0;
}