#include <iostream>
using namespace std;
int main () {
    int input = 0;
    do {
        cout << "Please select the area of the shape to be calculated"<<endl;
        cout<< "1. Square\n 2. Rectangle\n 3. Triangle\n 4. Quit the program"<<endl;
        cin>>input;
        if (input== 1){
            cout << "Enter the length of the side "<<endl;
            int length = 0;
            cin>>length;
            int area = length * length;
            
            cout << "The area is "<<area <<endl;
        }else if (input == 2) {
            cout << "Enter the length and width"<<endl;
            int length, width = 0;
            cin>>length;
            cin>>width;
            int rectangle = length * width;
            cout << "The area is "<<rectangle <<endl;
        }else if(input == 3) {
            cout << "Provide the base and height "<<endl;
            double base, height = 0;
            cin >> base;
            cin >> height;
            double triangle = 0.5 * base * height;
            cout << "The area is "<<triangle<<endl;
        } else if (input==4){
            exit(0);
        }else {
            cout << "Please enter a valid option"<<endl;
        }

    } while(true);
    return 0;
}
/*
int square(a) {
    int area = length * length;
    return area;
}
int rectangle (length, width){
    int area = length * width;

    return area;
}
double triangle (base, height){
    double area = 0.5* base * height;
    return area;
}*/