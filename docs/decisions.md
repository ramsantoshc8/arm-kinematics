# Decisions

## Using CMake for builds
- **Why:** scales to multiple files and libraries (Eigen, OpenCV later);
  industry standard for C++ and ROS 2
- **Alternative:** calling g++ directly — simpler now, messy later

## Writing my own Vec3 instead of using Eigen
- **Why:** to learn classes and operator overloading in C++
- **Alternative:** Eigen — faster and tested, might switch later for
  matrix-heavy work