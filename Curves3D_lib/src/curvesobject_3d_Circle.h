#ifndef CURVESOBJECT_3D_CIRCLE_H
#define CURVESOBJECT_3D_CIRCLE_H

#include "curvesobject_3d_Base.h"

class CurvesObject_3D_Circle : public CurvesObject_3D_Base
{
public:
    CurvesObject_3D_Circle();

    ParamError CreateCurve3D(float,float,float,float=0,float=0);
};

#endif // CURVESOBJECT_3D_CIRCLE_H
