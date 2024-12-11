#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    int n;
    cout << "Input the size of mass(n) - ";
    cin >> n;

    int** mass = new int*[n];

    for (int i = 0; i < n; i++){
        mass[i] = new int[n];
    }
    srand(time(nullptr));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mass[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << mass[i][j] << '\t';
    }

       

    
    for (int i = 0; i < n; i++)
        delete[] mass[i];

    delete[] mass;

    return 0;

}