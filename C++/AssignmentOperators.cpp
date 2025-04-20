#include <iostream>
using namespace std;
int main () {
    int a = 21;
    int c;

    c = a;
    cout<<"Line 1 - = operator, Value of c = : "<<c<<endl;
    c -= a;
    cout<<"Line 2 - -= operator, Value of c = : "<<c<<endl;
    c += a;
    cout<<"Line 3 - + = operator, Value of c = : "<<c<<endl;
    c *= a;
    cout<<"Line 4 - * = operator, Value of c = : "<<c<<endl;
    c /= a;
    cout<<"Line 5 - / = operator, Value of c = : "<<c<<endl;
    c = 200;
    c %= a;
    cout<<"Line 6 - % = operator, Value of c = : "<<c<<endl;
    c <<= 2;
    cout<<"Line 7-  << = operator, Value of c = : "<<c<<endl;
    c >>= 2;
    cout<<"Line 8 - >> = operator, Value of c = : "<<c<<endl;
    c &= 2;
    cout<<"Line 9 - & = operator, Value of c = : "<<c<<endl;
    c ^= 2;
    cout<<"Line 10 - ^= operator, Value of c = : "<<c<<endl;
    c |= 2;
    cout<<"Line 11 - |= operator, Value of c = : "<<c<<endl;
    return 0;
}