#ifndef BITMAP_HPP
#define BITMAP_HPP

#include "common.h"
#include "bitmap_file_header.h"
#include "bitmap_info_header.h"

namespace fractal_images {

class Bitmap {

    private:
        Int                     vWidth{0};
        Int                     vHeight{0};
        unique_ptr<UInt8[]>     vPixels{nullptr};   

    public:
        Bitmap                  (Int pWidth, Int pHeight);
        virtual ~Bitmap         ();

        Bool        Write       (String pFileName);
        Void        SetPixel    (Int pX, Int pY, UInt8 pRed, UInt8 pGreen, UInt8 pBlue);
        
};

}

#endif