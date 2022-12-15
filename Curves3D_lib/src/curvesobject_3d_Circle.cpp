#include "curvesobject_3d_Circle.h"

CurvesObject_3D_Circle::CurvesObject_3D_Circle()
{
    SetTypeObject_3D(Object_3D_Circle);
}

ParamError CurvesObject_3D_Circle::CreateCurve3D(float _PosX,float _PosY,float _Rx,float,float)
{
    PosX = _PosX;
    PosY = _PosY;
    if (_Rx <= 0)
        return ParamError_Rx;
    Rx = _Rx;
    Ry = _Rx;
    return ParamError_NO;
}
