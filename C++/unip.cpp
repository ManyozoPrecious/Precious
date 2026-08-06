#include <iostream>
//reading unnown number of inputs from the user
using namespace std;
int main () {
    int sum = 0; 
    int value = 0;
    while(cin>> value) { //istream is used as a condition in this program
        sum += value; //to come out of this loop use ctrl+z or enter an invalid number(not an integer)
    }
    cout<< "sum " <<sum<<endl;
    return 0;
}