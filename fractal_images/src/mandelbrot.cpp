#include "mandelbrot.hpp"

namespace fractal_images {

Mandelbrot::Mandelbrot ()
{

}

Mandelbrot::~Mandelbrot ()
{

}

Int Mandelbrot::GetIterations (Double pX, Double pY)
{
        complex <Double> z = 0;
        complex <Double> c (pX, pY);
        Int iterations = 0;

    while (iterations < sMaxIterations) {

        z = z * z + c;

        // When abs value of the complex number is till 2, then it belongs to mandelbrot's set
        if (abs (z) > 2)
            break;

        iterations++;
    }

    return iterations;
}

}