#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>
#include <memory>
#include <cmath>

#include "curvesobject_3d_Circle.h"
#include "curvesobject_3d_Ellipse.h"
#include "curvesobject_3d_Helixe.h"

#define Count3D_Object 20
#define Param M_PI/4

using namespace std;

typedef shared_ptr<CurvesObject_3D_Base> ptr_3D_Base;
typedef vector<ptr_3D_Base> V_3D_Base;

int main()
{
    int i;
    float SumR;

    V_3D_Base Object_3D;
    V_3D_Base Object_Circle;


    // Создание массива 3D объектов и заполнение их случайными числами
    srand(time(NULL));
    Object_3D.clear();
    for (i = 0; i < Count3D_Object; i++)
    {
        switch (rand() % 3)
        {
        case 0:
            Object_3D.push_back(ptr_3D_Base
                                (static_cast<CurvesObject_3D_Base*>(new CurvesObject_3D_Circle())));
            if (Object_3D.back()->CreateCurve3D(0,0,rand()%20+1) != ParamError_NO)
                cout << i << "Error";
            break;
        case 1:
            Object_3D.push_back(ptr_3D_Base
                                (static_cast<CurvesObject_3D_Base*>(new CurvesObject_3D_Ellipse())));
            if (Object_3D.back()->CreateCurve3D(0,0,rand()%20+1,rand()%20+1) != ParamError_NO)
                cout << i << "Error";
            break;
        case 2:
            Object_3D.push_back(ptr_3D_Base
                                (static_cast<CurvesObject_3D_Base*>(new CurvesObject_3D_Helixe())));
            if (Object_3D.back()->CreateCurve3D(0,0,rand()%20+1,rand()%20+1,rand()%5+1) != ParamError_NO)
                cout << i << "Error";
            break;
        }
    }

    // Отображение параметров (позиции, радиуса(ов) и шага) 3D объектов
    for (i = 0; i < Count3D_Object; i++)
    {
        switch (Object_3D.at(i)->GetTypeObject_3D())
        {
        case Object_3D_Circle:
            cout << i << " - Circle\tPosX\t" <<
                    Object_3D.at(i)->GetPosX() << "\tPosY\t" << Object_3D.at(i)->GetPosY() <<
                    "\tRx\t" << Object_3D.at(i)->GetRx() << endl;
            break;
        case Object_3D_Ellipse:
            cout << i << " - Ellipse\tPosX\t" <<
                    Object_3D.at(i)->GetPosX() << "\tPosY\t" << Object_3D.at(i)->GetPosY() <<
                    "\tRx\t" << Object_3D.at(i)->GetRx() << "\tRy\t" <<
                    Object_3D.at(i)->GetRy() << endl;
            break;
        case Object_3D_Helixe:
            cout << i << " - Helixe\tPosX\t" <<
                    Object_3D.at(i)->GetPosX() << "\tPosY\t" << Object_3D.at(i)->GetPosY() <<
                    "\tRx\t" << Object_3D.at(i)->GetRx() << "\tRy\t" << Object_3D.at(i)->GetRy() <<
                    "\tStepZ\t" << Object_3D.at(i)->GetStepZ() << endl;
            break;
        }
    }
    cout << endl;
    cout << "-------------------------" << endl;
    // Отображение позиции точки с параметром PI/4
    for (i = 0; i < Count3D_Object; i++)
    {
        Point_3D Point = Object_3D.at(i)->GetPoint3D(Param);
        switch (Object_3D.at(i)->GetTypeObject_3D())
        {
        case Object_3D_Circle:
            cout << i << "\t- Circle   t=PI/4   PointX\t" << Point.X() <<
                    "\tPointY\t" << Point.Y() <<
                    "\t\tDerivative\t" << Object_3D.at(i)->Derivative(Param) << endl;
            break;
        case Object_3D_Ellipse:
            cout << i << "\t- Ellipse  t=PI/4   PointX\t" << Point.X() <<
                    "\tPointY\t" << Point.Y() <<
                    "\tDerivative\t" << Object_3D.at(i)->Derivative(Param) << endl;
            break;
        case Object_3D_Helixe:
            cout << i << "\t- Helixe   t=PI/4   PointX\t" << Point.X() <<
                    "\tPointY\t" << Point.Y() << "\tPointZ\t" << Point.Z() <<
                    "\tDerivative\t" << Object_3D.at(i)->Derivative(Param) << endl;
            break;
        }
    }

    // Заполнение второго массива указателями на окружности из первого массива
    Object_Circle.clear();
    for (i = 0; i < Count3D_Object; i++)
    {
        if (Object_3D.at(i)->GetTypeObject_3D() == Object_3D_Circle)
        {
            Object_Circle.push_back(Object_3D.at(i));
        }
    }

    // Проверка второго контейнера на не клонируемость
    cout << endl;
    if (Object_Circle.size() != 0)
    {
        cout << " - Circle(0)  PosX " << Object_Circle.at(0)->GetPosX() <<
                "  PosY " << Object_Circle.at(0)->GetPosY() << endl;
        Object_Circle.at(0)->SetPosX(15);
        Object_Circle.at(0)->SetPosY(27);
        for (i = 0; i < Count3D_Object; i++)
        {
            if (Object_3D.at(i)->GetTypeObject_3D() == Object_3D_Circle)
            {
                cout << i << " - Circle  PosX " << Object_3D.at(i)->GetPosX() <<
                        "  PosY " << Object_3D.at(i)->GetPosY() << endl;
                break;
            }
        }
    }

    // Подсчёт суммы радиусов окружностей из второго массива
    thread Summ([Object_Circle,&SumR]() {
        SumR = accumulate(Object_Circle.begin(),Object_Circle.end(),0,
                          [](float S,ptr_3D_Base V)
                            {
                                return S+V->GetRx();
                            });
    });

    cout << endl;
    cout << "------------Circle-------------" << endl;
    // Отображение позиции точки с параметром PI/4 для окружностей из второго массива
    for (i = 0; i < Object_Circle.size(); i++)
    {
        Point_3D Point = Object_Circle.at(i)->GetPoint3D(Param);
        cout << i << " - Circle  t=PI/4   PointX\t" << Point.X() <<
                "\tPointY\t" << Point.Y() << "\tR\t" << Object_Circle.at(i)->GetRx() << endl;
    }

    cout << endl;
    cout << "------------Circle  No Sort-------------" << endl;
    // Отображение радиусов окружностей из не отсортированного второго массива
    for (i = 0; i < Object_Circle.size(); i++)
    {
        Point_3D Point = Object_Circle.at(i)->GetPoint3D(Param);
        cout << i << "\tR\t" << Object_Circle.at(i)->GetRx() << endl;
    }

    cout << endl;
    cout << "------------Circle  Sort-------------" << endl;
    // Сортировка второго массива
    sort(Object_Circle.begin(),Object_Circle.end(),[](ptr_3D_Base V1,ptr_3D_Base V2)
    {
        return V1->GetRx() < V2->GetRx();
    });
    // Отображение радиусов окружностей из отсортированного второго массива
    for (i = 0; i < Object_Circle.size(); i++)
    {
        Point_3D Point = Object_Circle.at(i)->GetPoint3D(Param);
        cout << i << "\tR\t" << Object_Circle.at(i)->GetRx() << endl;
    }

    Summ.join();
    // Отображение суммы радиусов окружностей из второго массива
    cout << endl << "Circle  Sum R " << SumR << endl;

    return 0;
}
