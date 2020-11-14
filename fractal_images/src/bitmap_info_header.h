#ifndef BITMAP_INFO_HEADER_H
#define BITMAP_INFO_HEADER_H

#include "common.h"

#pragma pack(2)

namespace fractal_images {

struct tBitmapInfoHeader {

    Int32       uHeaderSize{40};
    Int32       uWidth;
    Int32       uHeight;
    Int16       uPlanes{1};
    Int16       uBitsPerPixel{24};
    Int32       uCompression{0};
    Int32       uDataSize{0};
    Int32       uHorizontalResolution{2400};
    Int32       uVerticalResolution{2400};
    Int32       uColors{0};
    Int32       uImportantColors{0};
};

}

#endif