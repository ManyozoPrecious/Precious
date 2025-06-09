#include <iostream>
#include "square.h"

using namespace std;
shapes::square::square(){
    sidelength = 0;
}
shapes::square::square(float len){
    sidelength = len;
}
float shapes::square::getSide()const{
     
    return sidelength;
}
