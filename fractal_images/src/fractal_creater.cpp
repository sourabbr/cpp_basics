#include "fractal_creator.hpp"

namespace fractal_images {

FractalCreator::FractalCreator (Int pWidth, Int pHeight)
    : vWidth (pWidth), vHeight (pHeight), vHistogram ((new Int[Mandelbrot::sMaxIterations]{0})), 
      vFractal (new Int[vWidth * vHeight]{0}), vBitmap  (vWidth, vHeight), 
      vZoomList (vWidth, vHeight)
{
    vZoomList.Add (tZoom (vWidth / 2, vHeight / 2, 4.0 / vWidth));

}

FractalCreator::~FractalCreator ()
{

}

Void FractalCreator::Run (String pName)
{
    CalculateIteration ();
    CalculateTotalIterations ();
    CalculateRangeTotals ();
    DrawFractal ();
    WriteBitmap ("test.bmp");
}


Void FractalCreator::CalculateIteration ()
{
    for (int y = 0; y < vHeight; y++) {

        for (int x = 0; x < vWidth; x++) {

            pair <Double, Double> coords = vZoomList.DoZoom (x, y);

            Int iterations = Mandelbrot::GetIterations (coords.first, coords.second);

            vFractal[y * vWidth + x] = iterations;

            if (iterations != Mandelbrot::sMaxIterations)
                vHistogram[iterations]++;            
        }
    }
}

Void FractalCreator::CalculateTotalIterations ()
{
    for (Int i = 0; i < Mandelbrot::sMaxIterations; i++)
        vTotal += vHistogram[i];
}

Void FractalCreator::DrawFractal ()
{    
    for (int y = 0; y < vHeight; y++) {

        for (int x = 0; x < vWidth; x++) {

            Int iterations = vFractal[y * vWidth + x];

            Int range = GetRange (iterations);
            Int range_total = vRangeTotals[range];
            Int range_start = vRanges[range];

            tRGB &start_color = vColors[range];
            tRGB &end_color = vColors[range + 1];
            tRGB color_diff = end_color - start_color;

            UInt8 red = 0;
            UInt8 green = 0;
            UInt8 blue = 0;            

            if (iterations != Mandelbrot::sMaxIterations) {

                Int total_pixels = 0;

                for (Int i = range_start; i <= iterations; i++)
                    total_pixels += vHistogram[i];

                red = start_color.uR + color_diff.uR * (Double)total_pixels / range_total;
                green = start_color.uG + color_diff.uG * (Double)total_pixels / range_total;
                blue = start_color.uB + color_diff.uB * (Double)total_pixels / range_total;
            }

            vBitmap.SetPixel (x, y, red, green, blue);
        }
    }    
}

Void FractalCreator::AddZoom (const tZoom &pZoom)
{
    vZoomList.Add (pZoom);
}

Void FractalCreator::WriteBitmap (String pName)
{
    vBitmap.Write (pName);
}

Void FractalCreator::AddRange (Double pRangeEnd, const tRGB &pRGB)
{
    vRanges.push_back (pRangeEnd * Mandelbrot::sMaxIterations);
    vColors.push_back (pRGB);

    if (vGotFirstRange)
        vRangeTotals.push_back (0);

    vGotFirstRange = true;    
}

Void FractalCreator::CalculateRangeTotals ()
{
        Int range_index = 0;

    for (Int i = 0; i < Mandelbrot::sMaxIterations; i++) {

        Int pixels = vHistogram[i];

        if (i >= vRanges[range_index + 1])
            range_index++;

        vRangeTotals[range_index] += pixels;
    }
}

Int FractalCreator::GetRange (Int pIterations) const
{
    Int range = 0;

    for (Int i = 0; i < (Int)vRanges.size (); i++) {

        range = i;

        if (vRanges[i] > pIterations)
            break;
    }

    range--;

    assert (range > -1);
    assert (range < (Int)vRanges.size ());

    return range;
}


}