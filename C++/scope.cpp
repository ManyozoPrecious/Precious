#include <iostream>
using namespace std;
int reused = 42; //global variable
int main () {
int unique = 0; //has scope inside block only
cout << reused <<  " "<<" "<<unique<<endl; // uses the first reused
int reused = 0; // overwrites the value of reused inside the block
cout<< reused <<" "<<unique<<endl;
//to access the global variable we use the scope operator(::)
cout<< ::reused <<" "<<unique<<endl;
}