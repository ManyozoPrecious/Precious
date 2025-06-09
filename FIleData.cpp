#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream inputfile("ThisIsTheAdvancedProgrammingModule.txt");
    string filedata, line;

    if(inputfile.is_open()){
        while(getline(inputfile, line)){
            filedata += line + " ";
        }
        inputfile.close();
    } else {
        cout<<" Error: Unable to open the text file";
    }  cout << "FileContent " << filedata <<endl;
    return 0;
}