#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include "common.h"

namespace fractal_images {

class Mandelbrot {

    public:
        static const Int sMaxIterations = 1000;

    public:
        Mandelbrot ();
        virtual ~Mandelbrot ();

        static Int GetIterations (Double pX, Double pY);
};

}

#endif