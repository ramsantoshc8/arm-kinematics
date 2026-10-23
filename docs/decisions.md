# Decisions

## Using CMake for builds
- **Why:** scales to multiple files and libraries (Eigen, OpenCV later);
  industry standard for C++ and ROS 2
- **Alternative:** calling g++ directly — simpler now, messy later

## Staying on MSVC instead of switching to MinGW/g++
- **Why:** already installed and working; `if(MSVC)` branch in CMake
  handles the different warning flags
- **Alternative:** MinGW g++ — closer to Linux/ROS setups, but extra setup

## Skipping Vec3, going straight to matrices/fkine
- **Why:** already comfortable with the maths; wanted to get to the
  kinematics faster
- **Alternative:** writing Vec3 first to practise classes and operator
  overloading

## `std::array` for 4×4 matrices, `std::vector` for the DH table
- **Why:** matrix size is always 4×4 (fixed at compile time); number of
  joints changes per robot (runtime)
- **Alternative:** `std::vector` for everything — works, but loses the
  fixed-size guarantee

## Manual matrix multiply instead of Eigen (for now)
- **Why:** to learn the indexing/loops myself; fkine only needs multiply
- **Alternative:** Eigen — tested and fast; plan to switch for inverse
  kinematics (needs inverses, solvers, Jacobians)