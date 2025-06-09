#include <iostream>

namespace shapes {
    class square {
        private :
        float sidelength;

        public :
        square();
        square(float len);
       // ~square();
        float getSide ()const;

    };
}