#include <iostream>
#include <fstream>
using namespace std;
int main () {
    ofstream myFile("Example.txt");
    if (myFile.is_open()){ 
        myFile<< "This is a new line. \n";
        myFile<< "This is another line. \n";
        myFile.close();
    } else{
        cout<< "Unable to open the file";
    }
    return 0;
}