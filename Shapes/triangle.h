 #pragma once

namespace shapes {
    class triangle {
        private:
        float base ;
        float height;
        
        public:
        triangle();
        triangle(float bas, float hei);
        ~triangle(){}
        float getBase()const;
        float getHeight()const;
    };
}