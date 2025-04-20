#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int x = time(0);
    srand(x);
    int randomNumber = 1 + rand() % 11;
    cout<< randomNumber<<endl;
    if (randomNumber>=10) {
        cout << "Your subscription will expire soon. Renew now!"<<endl;
    } else if(randomNumber>=5) {
        cout << "Your subscription will expire in "<< randomNumber<<"Days" <<endl;
        cout<< "Renew and save 10%!"<<endl;
    } else if(randomNumber>=2) {
        cout << "Your subscription expires in a day!\n Renew now and save 20%!"<<endl;
    }else if(randomNumber>=1){
        cout << "Your subscription has expired"<<endl;
    }else {
        cout << "You have an active subscription";
    }
    return 0;
}