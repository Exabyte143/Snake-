# Snake++

Snake++ rewrite, I might make it work on linux in the future.

## Compiliation
To compile you need [CMAKE](https://cmake.org/), and if you're on windows you can need [VCPKG](https://vcpkg.io/en/index.html) installed.


### If you're on Linux
You only need to install CMake, after that install the SFML devel package from your distro's package manager.
### If you're on Windows
To install the dependencies run `vcpkg @vcpkg_rt.txt`
After that set  **CMAKE_TOOLCHAIN_FILE** in CMakeLists.txt to the path you've installed VCPKG to.
