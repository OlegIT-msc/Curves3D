cmake_minimum_required(VERSION 3.5)

project(Curves3D LANGUAGES CXX)

message(">>>>>>> Make Curves3D")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
)

find_path(CURVESOBJECT_3D curvesobject_3d_Base.h ${CMAKE_CURRENT_SOURCE_DIR}/../../Curves3D_lib/src)
include_directories(${CURVESOBJECT_3D})

add_executable(Curves3D ${PROJECT_SOURCES})

add_subdirectory(${CURVESOBJECT_3D} ${CURVESOBJECT_3D})
target_link_libraries(Curves3D PRIVATE Curves3D_lib)


