#include "bitmap.hpp"

using namespace fractal_images;

namespace fractal_images {

Bitmap::Bitmap (Int pWidth, Int pHeight)
    : vWidth(pWidth), vHeight(pHeight), vPixels(new UInt8[pWidth * pHeight * 3]{})
{

}

Bitmap::~Bitmap ()
{

}

Bool Bitmap::Write (String pFileName)
{
        tBitmapFileHeader file_header;
        tBitmapInfoHeader info_header;

    file_header.uFileSize = sizeof (tBitmapFileHeader) + 
                            sizeof (tBitmapInfoHeader) + 
                            (vWidth * vHeight * 3);
    file_header.uDataOffset = sizeof (tBitmapFileHeader) + 
                            sizeof (tBitmapInfoHeader);

    info_header.uWidth = vWidth;
    info_header.uHeight = vHeight;

        ofstream file;

    file.open (pFileName, ios::out | ios::binary);

    if (!file)
        return false;

    file.write ((StrPtr)&file_header, sizeof (file_header));
    file.write ((StrPtr)&info_header, sizeof (info_header));
    file.write ((StrPtr)vPixels.get (), (vWidth * vHeight * 3));

    file.close ();

    if (!file)
        return false;

    return true;
}

Void Bitmap::SetPixel (Int pX, Int pY, UInt8 pRed, UInt8 pGreen, UInt8 pBlue)
{
    UInt8 * pixel = vPixels.get ();

    pixel += (pY * 3) * vWidth + (pX * 3);

    // We are starting from blue because, bitmap is stored in little endian
    pixel[0] = pBlue;
    pixel[1] = pGreen;
    pixel[2] = pRed;
}

}