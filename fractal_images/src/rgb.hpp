#ifndef RGB_HPP
#define RGB_HPP

#include "common.h"

namespace fractal_images {

struct tRGB {

        Double uR;
        Double uG;
        Double uB;

        tRGB (Double pR, Double pG, Double pB);
};

tRGB operator-(const tRGB &pFirst, const tRGB &pSecond);

}


#endif