#ifndef ZOOM_LIST_HPP
#define ZOOM_LIST_HPP

#include "common.h"
#include "zoom.hpp"

namespace fractal_images {

class ZoomList {

    private:
        Double vXCenter{0};
        Double vYCenter{0};
        Double vScale{1.0};
        Int vWidth{0};
        Int vHeight{0};
        vector<tZoom> vZooms;

    public:
        ZoomList (Int pWidth, Int pHeight);
        Void Add (const tZoom &pZoom);
        pair<Double, Double> DoZoom (Int pX, Int pY);
};

}


#endif