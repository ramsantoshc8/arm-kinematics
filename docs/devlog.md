# Dev log

## 2026-10-23 — Built the forward Kinematics class 
**Time:** 2.5 hrs

**Built**
- `DHtable.h`: DH table class with setters for theta, a, d, alpha
- `setTMat()` builds each joint's 4×4 transform
- `matMul()` manual 4×4 matrix multiply
- `setFinalMat()` chains all joints → working forward kinematics

**Broke / stuck**
- CMake used MSVC (Visual Studio) instead of g++
- MSVC didn't understand `-Wextra` → error D8021
- Couldn't find the exe: MSVC puts it in `build\Debug\`
- Forgot to add `.gitignore`, so build/ was being tracked
- "vector subscript out of range" crash: DH vector was empty
- Errors in the transform matrix (wrong row index, used alpha instead of a, one sign)
- Final matrix printed all zeros: called `printFinalMat()` without `setFinalMat()`

**Fixed**
- Added `if(MSVC)` check so warnings work on both compilers
- Run with `.\build\Debug\arm.exe`
- Added `.gitignore` with `build/`
- Sized the vector in the constructor with `resize()`
- Corrected the DH matrix against the standard formula
- Call `setFinalMat()` before printing

**Learned**
- Configure (`cmake -S . -B build`) vs build (`cmake --build build`)
- Different compilers use different flags
- `[i]` never creates elements, only `resize()` / `push_back()` do
- `std::array` for fixed size, `std::vector` for runtime size
- `cos`/`sin` take radians, not degrees
- Matrix multiply order matters 

**Next**
- Verify fkine: all-zero DH → identity, then compare UR5e vs MATLAB
- Store intermediate joint transforms (maybe)


## 2026-10-21 — Project setup
**Time:** 1.5 hrs

**Built**
- Folder structure, README, CMakeLists.txt, hello world

**Broke / stuck**
- CMake used MSVC (Visual Studio) instead of g++
- MSVC didn't understand `-Wextra` → error D8021
- Couldn't find the exe: MSVC puts it in `build\Debug\`
- Forgot to add `.gitignore`, so build/ was being tracked

**Fixed**
- Added `if(MSVC)` check so warnings work on both compilers
- Run with `.\build\Debug\arm.exe`
- Added `.gitignore` with `build/`

**Learned**
- Configure (`cmake -S . -B build`) vs build (`cmake --build build`)
- Different compilers use different flags

**Next**
- Write the Vec3 class