#ifndef CURVESOBJECT_3D_ELLIPSE_H
#define CURVESOBJECT_3D_ELLIPSE_H

#include "curvesobject_3d_Base.h"

class CurvesObject_3D_Ellipse : public CurvesObject_3D_Base
{
public:
    CurvesObject_3D_Ellipse();

    ParamError CreateCurve3D(float,float,float,float=0,float=0);
};

#endif // CURVESOBJECT_3D_ELLIPSE_H
