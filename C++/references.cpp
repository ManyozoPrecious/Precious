#include <iostream>
using namespace std;
int main() {
    int ival= 1024; //original value
    int &refval = ival; //reference value
    //int &refval2; since a reference needs to be initilized at the time of definition with a '&'
    cout<<"ival = "<<ival <<endl<<"refval = "<<refval;
    refval= 1000;
    cout<<"new ival = "<<ival <<endl<<"new refval = "<<refval;
    return 0;    
}