#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int a, b;
    cout<<"numbers of elements ";
    cin >> a;
    int nums[a];

    for (int i = 0; i<=a; i++){
        cout<< "Enter number "<<endl;   
        cin >> b;
        cout<<nums[b];
    }
    cout<<nums[b]<<endl;
    return 0;


    
}