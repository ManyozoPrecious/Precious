#include <iostream>
using namespace std;
int main() {
    int num = 0;
    cout<<"Enter any number "<<endl;
    cin>>num;
    if (num > 20) {
    cout<<"the number is greater than 20";
    }else if (num==10) {
        cout<<"the number is equal than 20";
    }else {
        cout<<"The number is greater than 20";
    }
    return 0;
}