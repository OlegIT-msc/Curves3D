#ifndef CURVESOBJECT_3D_BASE_H
#define CURVESOBJECT_3D_BASE_H

#include "point_3d.h"

typedef enum {
    ParamError_NO = 0,
    ParamError_PosX,
    ParamError_PosY,
    ParamError_Rx,
    ParamError_Ry,
    ParamError_StepZ
} ParamError;

typedef enum {
    Object_3D_Circle,
    Object_3D_Ellipse,
    Object_3D_Helixe
} Object_3D_Type;

class CurvesObject_3D_Base
{
public:
    CurvesObject_3D_Base();

    void SetTypeObject_3D(Object_3D_Type Tp) {Type = Tp;}
    Object_3D_Type GetTypeObject_3D(void) {return Type;}

    void SetPosX(float X) {PosX = X;}
    void SetPosY(float Y) {PosY = Y;}
    float GetPosX() {return PosX;}
    float GetPosY() {return PosY;}
    virtual float GetRx() {return Rx;}
    virtual float GetRy() {return Ry;}
    virtual float GetStepZ() {return StepZ;}

    virtual Point_3D GetPoint3D(float);
    virtual float Derivative(float);

    virtual ParamError CreateCurve3D(float,float,float,float=0,float=0);

protected:
    float PosX,PosY;
    float Rx,Ry;
    float StepZ;
    Object_3D_Type Type;
};

#endif // CURVESOBJECT_3D_BASE_H
