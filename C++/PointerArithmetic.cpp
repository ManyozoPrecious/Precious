#include <iostream>
using namespace std;
int main (){
    int * pPointer = nullptr;

    int numbersArray[3] = {10, 20, 30};

    //assign address of first element to pointer
    pPointer = numbersArray;

    //output the address of the first element
    cout << "Address at pPointer: "<<pPointer <<endl;
    cout << "Address of numbersArray[0]: "<<&numbersArray <<endl;

    //output the value of the first element usin the pointer and indirection 
    cout << "Value at pPointer: "<<*pPointer <<endl;

    //this outputs the value of the second element
    cout << "Value at ++pPointer: "<< *(++pPointer)<<endl;

    //assign address of first element to pointer 
    pPointer = numbersArray;

    //this outputs the value of th first element
    cout<< "Value at pPointer++ " << *(pPointer++) <<endl;
    return 0;
}