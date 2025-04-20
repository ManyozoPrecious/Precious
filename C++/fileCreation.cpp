#include <iostream>
#include<fstream>
using namespace std;
int main () {
    //create an output file
    ofstream myFile("Example.txt");
    //close the file
    myFile.close();
    return 0;
}