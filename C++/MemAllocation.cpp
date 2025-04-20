#include <iostream>
using namespace std;
int main () {
    int numberOfElements = 0;
    int* dynamicArray = nullptr;

     cout <<" How many numbers would you like to type? "<<endl;
     cin>> numberOfElements;

     dynamicArray = new int [numberOfElements];

     if (dynamicArray==nullptr){
        cout << "Error: memory could not be allocated";
     } else {
        for (int i = 0; i < numberOfElements; i++) {
            cout << "Enter Number: ";
            cin >> dynamicArray[i];
        }
        cout << "You have entered: ";
        for (int i =0; i < numberOfElements; i++){
            cout << dynamicArray[i] <<", ";
        }
        delete[] dynamicArray;
     }
    return 0;
}