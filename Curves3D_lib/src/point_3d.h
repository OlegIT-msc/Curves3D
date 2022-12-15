#ifndef POINT_3D_H
#define POINT_3D_H

class Point_3D
{
public:
    Point_3D();
    Point_3D(float,float,float);

    float X() {return CoordX;}
    float Y() {return CoordY;}
    float Z() {return CoordZ;}

protected:
    float CoordX,CoordY,CoordZ;
};

#endif // POINT_3D_H
