#include <iostream>

using namespace std;

int main(){
    int size;
    cout << "Input the number of elements: ";
    cin >> size;
    
    char str[size + 1] = {'\0'};
    
    cout << "Input the str: ";
    cin.getline(str, size);
    
    cout << "Old string: " << str << endl;

    char my_str[size+1] = {'\0'};
    int count_of_zero = 0;
    int index = 0;
    //Вводные данные    

    for (int i = 0; i < size && str[i] != '\0'; i++){
        if (str[i] == '0'){
            count_of_zero++;
        }
        else{
            my_str[index++] = str[i];
        }
    }
    if (count_of_zero == 0){
        cout << "There are zero 0 in str"<< endl;
        return -1;
    }
    
    for (int i = 0; i < count_of_zero; i++)
        my_str[index++] = '0';


    my_str[index] = '\0';


    cout << "New str: "<< my_str << endl;
    return 0;
}
//Output example
// input: Hell0oW0or00ld
// output: Helloworld0000