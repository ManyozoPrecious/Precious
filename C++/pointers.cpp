#include <iostream>
using namespace std;
int main () {
    int ival =50;
    int *p = &ival;
    cout<<"-------------------------------------------"<<endl;
    cout<<"ival = "<<ival<<endl<<"p = "<<p<<endl<<"*p = "<<*p;
    *p = 51;
    cout<<endl<<"--------------------------------------"<<endl;
    cout<<"new ival = "<<ival<<endl<<"new p = "<<p<<endl<<"new *p = "<<*p;
    ival = 52;
    cout<<endl<<"--------------------------------------"<<endl;
    cout<<"new ival = "<<ival<<endl<<"new p = "<<p<<endl<<"new *p = "<<*p;
    cout<<endl<<"---------------------------------------"<<endl;
    return 0;
}