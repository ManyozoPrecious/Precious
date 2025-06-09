#include <iostream>
#include "area.h"
#include "square.h"
#include "triangle.h"
#include "circle.h"
#include <cmath>
using namespace shapes;

 namespace shapes{

 float area::calculateSquare(const square& Square){
    float side = Square.getSide(); 
    return side * side;
}
 float area::calculateCircle(const circle& Circle){
    float radi = Circle.getRadius();
    return M_PI * radi *radi;
}
 float area::calculateTriangle(const triangle& Triangle) {
    int area = 0.5f * Triangle.getBase() *Triangle.getHeight();
    return area;
}
 }