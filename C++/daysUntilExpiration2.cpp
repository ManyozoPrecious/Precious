#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;    

int main() {
    int x = time(0);
    srand(x);
    int randomNumber = 1 + rand() % 11;
    cout <<randomNumber<<endl;
    switch (randomNumber){
    case 1:  cout<< "Your subscrition has expired"<<endl;
    break;
    case 2: cout<< "Your subscription will expire within a day\n Renew now and save 20%"<<endl;
    break;
    case 3:
    case 4:
    case 5: cout << "Your subscription will expire in "<<randomNumber<<" Days\n Renew now and save 10%!"<<endl;
    break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10: cout <<"Your subscription will expire soon. Renew now"<<endl;
    break;
    default: cout<<"You have an active subscription"<<endl;   
    }
    return 0;
}