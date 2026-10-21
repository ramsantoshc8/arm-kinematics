# Dev log

## 2026-10-21 — Project setup
**Time:** ~1.5 hrs

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