#pragma once

namespace shapes {
    class circle {
        private:
        float radius;

        public:
        circle();
        circle(float radii);
       // ~circle();
        float getRadius()const;
    };
}