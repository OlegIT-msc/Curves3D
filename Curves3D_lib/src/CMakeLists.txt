cmake_minimum_required(VERSION 3.14)

project(Curves3D_lib LANGUAGES CXX)

message(">>>>>>> Make Curves3D_lib")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Curves3D_lib STATIC
    curvesobject_3d_Base.cpp
    curvesobject_3d_Base.h
    point_3d.cpp
    point_3d.h
    curvesobject_3d_Circle.cpp
    curvesobject_3d_Circle.h
    curvesobject_3d_Ellipse.cpp
    curvesobject_3d_Ellipse.h
    curvesobject_3d_Helixe.cpp
    curvesobject_3d_Helixe.h
)
