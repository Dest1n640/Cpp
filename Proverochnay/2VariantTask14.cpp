#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Input the number of items: ";
    cin >> n;

    double* weight = new double[n];    
    double* price = new double[n];

    cout << "Input the weight of items (e.g., 1.2 3.4 1 3): ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << "Input the price of items (e.g 100 200 300): ";
    for (int i = 0; i < n; i++){
        cin >> price[i];
    }

    double full_weight = 0;
    for (int i = 0; i < n; i++){
        if (full_weight + weight[i] >= 30){
            break;
        } 
        else{
            weight[i] += full_weight;
        }
    }

    double max_price = 0;
    double max_digit = -1;
    for (int i = 0; i < n; i++){
        if (price[i] > max_price){
            max_price = price[i];
            max_digit = i;
        }
    }

    if (max_digit != -1){
        cout << "The maximum price: " << max_price << endl;
    }

    return 0;
}