#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle () {
    length = 0;
    width = 0;
}
void Rectangle::getter (float a, float b) {
    length = a;
    width = b;
}
float Rectangle::getInput () {
    return length, width;
}
float Rectangle::area() {
    return length * width;
}
/* Rectangle::~Rectangle (){
    cout << "Nothing"<< endl;
}*/