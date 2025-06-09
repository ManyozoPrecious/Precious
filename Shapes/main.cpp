#include <iostream>
#include "area.h"
#include "square.h"
#include "triangle.h"
#include "circle.h"
#include <cmath>
#include <string>
using namespace std;
using namespace shapes;

int main(){
    int input;
    bool running = true;
    do{
        cout << "1. Calculate area of square" << endl;
        cout << "2. Calculate area of circle" << endl;
        cout << "3. Calculate area of triangle" << endl;
        cout << "4. Quit" << endl;
        cin >> input;

        if (cin.fail()) {
            cin.clear();   // Clear error state
            cin.ignore(1000, '\n'); // Remove invalid input from buffer
            cout << "Invalid input! Please enter a number geez" << endl;
            continue;  // Restart loop
        }

        switch(input){
            case 1: { 
                cout << "Enter the length: ";
                float len;
                cin >> len;
                square sArea(len);
                cout << "The area of the square is " << area::calculateSquare(sArea) << endl;
                break;
            }
            case 2:  {
                cout << "Enter the radius: ";
                float radii;
                cin >> radii;
                circle cArea(radii);
                cout << "The area of the circle is " << area::calculateCircle(cArea) << endl;
                break;
            }
            case 3:  {
                cout << "Enter the base: ";
                float bas, hei;
                cin >> bas;
                cout << "Enter the height: ";
                cin >> hei;
                triangle tArea(bas, hei);
                cout << "The area of the triangle is " << area::calculateTriangle(tArea) << endl;
                break;
            }
            case 4:  
                cout << "Exiting program..." << endl;
                running = false;  
                break;

            default:  
                cout << "Please enter a valid option!" << endl;
        }

    } while(running);

    return 0;
}
