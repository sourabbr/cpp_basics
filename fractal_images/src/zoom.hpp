#ifndef ZOOM_HPP
#define ZOOM_HPP

#include "common.h"

namespace fractal_images {

struct tZoom {

    Int uX{0};
    Int uY{0};
    Double uScale{0.0};

    tZoom (Int pX, Int pY, Double pScale)
        : uX (pX), uY (pY), uScale (pScale)
    {

    } 

};

}

#endif