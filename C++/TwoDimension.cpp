#include <iostream>
using namespace std;
int main () {
    int cols, rows;
    cout << "Enter the number of rows less than or equal to 3"<<endl;
    cin >> rows;
    cout << "Enter the number of columns less than or equal to three "<<endl;
    cin >> cols;
    if (rows<=3 && cols <=3){
    double** twodee = new double*[rows];
    for (int i = 0; i<rows; i++){
        twodee[i] = new double[cols];
    }
    
    cout << "Enter the elements: "<<endl;
    for (int i = 0; i<rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> twodee[i][j];
        }
    }

        cout << "The array is "<<endl;
        for (int i = 0; i < rows; i++){
            for(int j = 0; j <cols; j++){
                cout << twodee[i][j] << "\t";
            
            
            }
            
    }
     //deallocating memory
     for (int i = 0; i < rows; i++) {
        delete[] twodee[i];
     }
     delete[] twodee;
    } else {
        cout << "You are off limits mahn :("<<endl;
    }
     return 0;

}