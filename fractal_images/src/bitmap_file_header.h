#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include "common.h"

#pragma pack (2) // This ensures that compiler doesnt do any optimization for aliging members of structure
// It will store the members as it is

namespace fractal_images {

struct tBitmapFileHeader {

    Char        uHeader[2]{'B', 'M'};
    Int32       uFileSize;
    Int32       uReserved {0};
    Int32       uDataOffset; // From where the data starts in the file
};

}

#endif