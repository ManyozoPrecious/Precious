#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int val;
    cout<<"enter the number of values to be added";
    cin>>val;
    for(int i = 1; i<=val; i++) {
        sum += i;
    }
    cout<<"The result of adding numbers from 1 to "<<val<<" is "<<sum<<endl;
    return 0;
}