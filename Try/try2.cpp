#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

int main(){
    srand(time(NULL));
    int rand_number = 1 + rand() % 100,a;
    cout<<rand_number<<endl;
    
    while (a!= rand_number){
        cin>> a;
        if (a == rand_number){
            std::cout<<"Вы угадали " <<rand_number<<endl;
            return 0;
            break;
        }
    }
    return 0;
}