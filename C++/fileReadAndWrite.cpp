#include <iostream>
#include <fstream>
using namespace std;
int main () {
    char data [100];

    //open a text file in write mode
    ofstream outfile;
    outfile.open("afile.txt");

    cout << "Writing to file" << endl;
    cout<< "Enter your name" ;
    cin.getline(data,100);
    //write inputed data into text file
    outfile << data << endl;

    cout << "Enter your age";
    cin>>data;
    cin.ignore();

    //again write inputed data into text file
    outfile << data << endl;

    //close the opened file
    outfile.close();

    //open a text file in read mode
    ifstream infile;
    infile.open("afile.txt");

    cout<< "Reading from a file"<<endl;
    infile>>data;

    //write data on the screen
    cout << data <<endl;

    //again read data from the file and display it
    infile>> data;
    cout<< data << endl;

    //close the opened file
    infile.close();

    return 0;
}