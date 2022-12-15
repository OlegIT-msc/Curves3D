#ifndef CURVESOBJECT_3D_HELIXE_H
#define CURVESOBJECT_3D_HELIXE_H

#include "curvesobject_3d_Base.h"

class CurvesObject_3D_Helixe : public CurvesObject_3D_Base
{
public:
    CurvesObject_3D_Helixe();

    Point_3D GetPoint3D(float);
    float Derivative(float);

    ParamError CreateCurve3D(float,float,float,float=0,float=0);
};

#endif // CURVESOBJECT_3D_HELIXE_H
