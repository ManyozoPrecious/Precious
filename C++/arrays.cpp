#include <iostream>
using namespace std;
int main () {
    int arr[4];
    cout<<"Please enter four integers"<<endl;
    for(int i = 0; i < 4; i++) {
        cin>>arr[i];
    }
    cout<<"The values in the array are now "<<endl;
    for(int i = 0; i < 4; i++) {
        cout<<" "<<arr[i]<<endl;
    }
    return 0;
}