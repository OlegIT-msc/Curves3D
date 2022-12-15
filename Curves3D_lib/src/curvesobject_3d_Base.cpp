#include <cmath>
#include "curvesobject_3d_Base.h"

CurvesObject_3D_Base::CurvesObject_3D_Base()
{
    PosX = PosY = 0.0f;
}

ParamError CurvesObject_3D_Base::CreateCurve3D(float _PosX,float _PosY,float _Rx,float _Ry,float _StepZ)
{
    if (_PosX <= 0)
        return ParamError_PosX;
    PosX = _PosX;
    if (_PosY <= 0)
        return ParamError_PosY;
    PosY = _PosY;
    if (_Rx <= 0)
        return ParamError_Rx;
    return ParamError_NO;
}

Point_3D CurvesObject_3D_Base::GetPoint3D(float F)
{
    return Point_3D(PosX+Rx*cos(F),PosY+Ry*sin(F),0.0f);
}

float CurvesObject_3D_Base::Derivative(float F)
{
    return (Ry*cos(F))/(-Rx*sin(F));
}

