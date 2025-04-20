#include <iostream>
#include "Rectangle.h"
using namespace std;
int main () {
    Rectangle rectangle;
    float len, wid;
    cout << "Enter the length: "<<"\n";
    cin>>len;
    cout << "Enter the width: "<< "\n";
    cin >> wid;
    rectangle.getter(len, wid);
    rectangle.area();
    cout << "The area of the rectangle is : "<< rectangle.area()<<"\n" << "Arigato ghozaimasuu";
    return 0;
}