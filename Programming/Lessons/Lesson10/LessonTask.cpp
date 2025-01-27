#include <iostream>

using namespace std;

int main(){
    const int n = 2;
    const int m = 3;

    int arr[n][m] = { {1,2,3}, {5,6,7}};    //Первый индекс строки, второй столбцы     НЕ объявленные значение будут = 0
    int i, j;

    for (i = 0; i < n; i++ ){
        for(j = 0; j < m; j++){
            cout << "Enter arr[ " << i << "][" << j << "] =";
            cin >> arr[i][j];
        }
        cout << '\n';
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }

    return 0;
}