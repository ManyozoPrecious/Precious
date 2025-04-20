#include <iostream>
#include <string>
using namespace std;
int main () {
    int* dyna = new int;
    std::string* input = new std::string;
    cout << "Enter an interger"<<endl;
    cin>>*dyna;
    cout <<"Enter a string "<<endl;
    std::getline(std::cin, *input);

    cout << "You have entered the integer: "<< *dyna <<"\nand the string: "<<*input<<endl;
    return 0;
}