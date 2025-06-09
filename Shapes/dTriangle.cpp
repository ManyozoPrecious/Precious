#include <iostream>
#include "triangle.h"

using namespace std;

shapes::triangle::triangle(){
    height = 0;
}
shapes::triangle::triangle(float bas, float hei){
    base = bas;
    height = hei;
}
float shapes::triangle::getBase()const{
   
    return base;
}
float shapes::triangle::getHeight()const{
    
    return height;
}