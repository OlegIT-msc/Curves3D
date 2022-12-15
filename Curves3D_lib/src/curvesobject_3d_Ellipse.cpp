#include "curvesobject_3d_Ellipse.h"

CurvesObject_3D_Ellipse::CurvesObject_3D_Ellipse()
{
    SetTypeObject_3D(Object_3D_Ellipse);
}

ParamError CurvesObject_3D_Ellipse::CreateCurve3D(float _PosX,float _PosY,float _Rx,float _Ry,float)
{
    PosX = _PosX;
    PosY = _PosY;
    if (_Rx <= 0)
        return ParamError_Rx;
    Rx = _Rx;
    if (_Ry <= 0)
        return ParamError_Ry;
    Ry = _Ry;
    return ParamError_NO;
}

