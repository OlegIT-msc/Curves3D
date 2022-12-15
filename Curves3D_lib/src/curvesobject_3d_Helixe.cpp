#include <cmath>
#include "curvesobject_3d_Helixe.h"

#define PI2 (2.0f*M_PI)

CurvesObject_3D_Helixe::CurvesObject_3D_Helixe()
{
    SetTypeObject_3D(Object_3D_Helixe);
}

ParamError CurvesObject_3D_Helixe::CreateCurve3D(float _PosX,float _PosY,float _Rx,float _Ry,float _StepZ)
{
    PosX = _PosX;
    PosY = _PosY;
    if (_Rx <= 0)
        return ParamError_Rx;
    Rx = _Rx;
    if (_Ry <= 0)
        return ParamError_Ry;
    Ry = _Ry;
    StepZ = _StepZ;
    return ParamError_NO;
}

Point_3D CurvesObject_3D_Helixe::GetPoint3D(float F)
{
    return Point_3D(PosX+Rx*cos(F),PosY+Ry*sin(F),StepZ/(PI2/F));
}

float CurvesObject_3D_Helixe::Derivative(float F)
{
    return (Ry*cos(F))/(-Rx*sin(F));  // ?????????????
}

