#include "zoom_list.hpp"

namespace fractal_images {

ZoomList::ZoomList (Int pWidth, Int pHeight)
    : vWidth (pWidth), vHeight (pHeight)
{

}

Void ZoomList::Add (const tZoom &pZoom)
{
    vZooms.push_back (pZoom);

    vXCenter += (pZoom.uX - vWidth / 2) * vScale;
    vYCenter += -(pZoom.uY - vHeight / 2) * vScale;

    vScale *= pZoom.uScale;
}

pair<Double, Double> ZoomList::DoZoom (Int pX, Int pY)
{
    Double x_fractal = (pX - vWidth / 2) * vScale + vXCenter;
    Double y_fractal = (pY - vHeight / 2) * vScale + vYCenter;

    return pair<Double,Double>(x_fractal, y_fractal);
}

}