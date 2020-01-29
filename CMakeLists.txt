cmake_minimum_required (VERSION 2.8)
project (ComputationalGeometryAlgorithm)

add_executable(CGA
source/main.cpp
source/convex_hull.cpp
source/edge.cpp
source/face.cpp
source/face_node.cpp
source/math.cpp
source/sweep_line.cpp
source/vector.cpp
source/vertex.cpp
source/tri_flipper.cpp
)

install(TARGETS CGA DESTINATION ${CMAKE_SOURCE_DIR}/exe)
