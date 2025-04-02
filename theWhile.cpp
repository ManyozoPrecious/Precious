#include <iostream>
using namespace std;
int main () {
    int num = 0;
    do{
        cout<< "Enter an integer between 5 and 10"<<endl;
        cin>>num;
        if (num>=5&&num<=10){
            cout << "Your input value("<<num<<")has been accepted"<<endl;
           break;
        } else if(~(num>=5&&num<=10)) {
            cout << "Sorry, you have entered a wrong number, please try again"<<endl;
        }
    } while (~(num<=10 && num >=5));
    return 0;
}