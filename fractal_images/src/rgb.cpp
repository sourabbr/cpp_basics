#include "rgb.hpp"

namespace fractal_images {

tRGB::tRGB (Double pR, Double pG, Double pB)
    : uR (pR), uG (pG), uB (pB)
{

}

tRGB operator-(const tRGB &pFirst, const tRGB &pSecond)
{
    return tRGB (pFirst.uR - pSecond.uR, pFirst.uG - pSecond.uG, pFirst.uB - pSecond.uB);
}

}