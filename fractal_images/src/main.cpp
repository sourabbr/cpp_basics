#include "common.h"
#include "fractal_creator.hpp"
#include "rgb.hpp"
#include "zoom.hpp"

using namespace fractal_images;

int main ()
{
        FractalCreator fractal_creator (800, 600);

    cout << "Generating..." << endl;

    fractal_creator.AddRange (0.0, tRGB (0, 0, 0));
    fractal_creator.AddRange (0.3, tRGB (255, 0, 0));
    fractal_creator.AddRange (0.5, tRGB (255, 255, 0));
    fractal_creator.AddRange (1.0, tRGB (255, 255, 255));

    fractal_creator.AddZoom (tZoom (295, 202, 0.1));
    fractal_creator.AddZoom (tZoom (312, 304, 0.1));

    fractal_creator.Run ("test.bmp");

    cout << "Finished..." << endl;

    return 0;
}