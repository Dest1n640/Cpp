#include <iostream>

using namespace std;

int main(){
    const int n = 3;
    const int m = 4;

    int arr[n][m] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}};    //Первый индекс строки, второй столбцы     НЕ объявленные значение будут = 0
    int i, j, k;

    // for (i = 0; i < n; i++ ){
    //     for(j = 0; j < m; j++){
    //         cout << "Enter arr[ " << i << "][" << j << "] =";
    //         cin >> arr[i][j];
    //     }
    //     cout << '\n';
    // }
    

    for (k = 0; k < n* m + m; k++){
        i = k / m;     
        j = k % m;
        cout << "arr["<< i << "][" << j <<"] = " << arr[0][k] << '\t';
        if(j == m - 1)
            cout << '\n';
    }   

    return 0;
}