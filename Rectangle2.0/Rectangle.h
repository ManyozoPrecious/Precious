#pragma once

using namespace std;

class Rectangle {
    private : 
    float length;
    float width;
    
    public :
    Rectangle();
    Rectangle(int len, int wid);
   // ~Rectangle();
    void getter (float a, float b);
    float getInput ();
    float area();
};