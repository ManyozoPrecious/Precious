#include <iostream>
using namespace std;
int main() {
    int count = 1;
    int sum = 0;
    int val;
    cout<<"Enter the number till which the sum has to be calculated";
    cin>>val; //collecting user input
    while(count<=val){
        sum += count;
        count += 1;

    }
    cout<<"sum of 1 to "<<val<<" = "<<sum<<endl; //dislaying the user input
    return 0;
}