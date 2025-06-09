#pragma once 

namespace shapes {
    class square;
    class triangle;
    class circle;
    class area{
        public:
        static float calculateSquare(const square& Square);
        static float calculateTriangle(const triangle& Triangle);
        static float calculateCircle(const circle& Circle);

    };
}