#include <iostream>
using namespace std;
int main () {
     int numbersarray[5];
     int* pPointer = nullptr;
    
     //assign the address of the first element to the pointer
     pPointer = numbersarray;
     
     *pPointer = 10;

     //increment the pointer usin pointer arithmetic 
     //to assign the address of the second element to the pointer
     pPointer++;
     *pPointer = 20; //assign a value to the second element

     //asign the address of the third element to the pointer
     pPointer = &numbersarray[2];
    *pPointer = 30; //assign value to the third element

    //use pointer arithmetic to assign the address of fourth element to pointer
    pPointer = numbersarray + 3;
    *pPointer = 40;

    pPointer = numbersarray;

    //assign a value to the fifth element using indirection and pointer arithmetic
    *(pPointer+4) = 50;
    // iterate and output all the elements in the array

    for (int n = 0; n<5; n++) {
        cout << numbersarray[n]<< ", ";
    }
    return 0;
}