#include <iostream>
#include "circle.h"

using namespace std;

shapes::circle::circle(){
    radius = 0;
}
shapes::circle::circle(float radii){
    radius = radii;
}
float shapes::circle::getRadius()const{
    
    return radius;
}
