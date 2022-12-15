#include "point_3d.h"

Point_3D::Point_3D()
{
    CoordX = CoordY = CoordZ = 0.0f;
}

Point_3D::Point_3D(float X,float Y,float Z)
{
    CoordX = X;
    CoordY = Y;
    CoordZ = Z;
}
