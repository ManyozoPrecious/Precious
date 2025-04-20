#include <iostream>
#include <string>
using namespace std;
int main () {
    char letter = 'B';
    string wat[8] = {"B123", "C234","A345","C15","B177","G3003", "C235" ,"B179"};
    for (int i = 0; i<9; i++){
        if (wat[i].find(letter) == 0){
            cout << wat[i]<<"\t";
        }
    }
    return 0;
}