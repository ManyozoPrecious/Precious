#include <iostream>
using namespace std;
int main () {
    //declare and initialize a pointer to null
    int* pPointer = nullptr;

    int integerVar = 5;

    //assiggn pointer to address of variable
    pPointer = &integerVar;

    // output the value of integerVar
    cout << "integerVar: "<<integerVar<<endl;

    //output the address of integerVal
    cout << "Address of integerVal: "<< &integerVar<<endl;

    //output the address assigned to pointer
    cout << "pPointer: " <<pPointer <<endl;

    //output the address of pPointer
    cout << "Address of pPointer " << &pPointer <<endl;
    return 0;
}