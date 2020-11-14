#ifndef FRACTAL_CREATER_HPP
#define FRACTAL_CREATER_HPP

#include "common.h"
#include "bitmap.hpp"
#include "mandelbrot.hpp"
#include "zoom.hpp"
#include "zoom_list.hpp"
#include "rgb.hpp"

namespace fractal_images {

class FractalCreator {

    private:
        Int vWidth;
        Int vHeight;
        unique_ptr <Int[]> vHistogram;
        unique_ptr <Int[]> vFractal;
        Bitmap vBitmap;
        ZoomList vZoomList;
        Int vTotal{0};

        vector <Int> vRanges;
        vector <tRGB> vColors;
        vector <Int> vRangeTotals;

        bool vGotFirstRange{false};

    public:
        FractalCreator (Int pWidth, Int pHeight);
        virtual ~FractalCreator ();

    private:
        Void CalculateIteration ();
        Void CalculateTotalIterations ();
        Void DrawFractal ();
        Void WriteBitmap (String pName);
        Void CalculateRangeTotals ();
        Int GetRange (Int pIterations) const;

    public:
        Void Run (String pName);
        Void AddZoom (const tZoom &pZoom);
        Void AddRange (Double pRangeEnd, const tRGB &pRGB);
};

}

#endif