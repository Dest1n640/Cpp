#include <iostream>

using namespace std;

int main(){
    const int n = 3;
    const int m = 4;

    int k = 10;

    int** a = new int*[n]; //Выделение памяти с помощью оператора new
    for(int i = 0; i < n; i++){
        a[i] = new int[m];
    } //Создание динамического массива

    for (int i = 0; i < n; i++ ){
        for(int j = 0; j < m; j++){
            cout << "Enter arr[" << i << "][" << j << "] =";
            cin >> a[i][j];
        }
        cout << '\n';
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << '\t';
        }
        cout << '\n';
    }
    // cout << "adr a = " << &a << endl;
    // cout << "ard a[0] = " << &a[0] << endl;
    // cout << "adr b = " << &b << endl;
    // cout << "adr b[0] = " << &b[0] << endl; // Разница между динамическими массивами и статический
    
    
    for (int i = 0; i < n; i++)
        delete[] a[i]; //Чистка памяти, выделенную под массив с помощью оператора new
    delete a;
    a = 0;

    if (a == NULL )
        cout << "Error" << endl;
    return 0;
}