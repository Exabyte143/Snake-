cmake_minimum_required(VERSION 3.10)
if (WIN32)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake") # set this to your vcpkg cmake file    
endif()
project(Snake VERSION 2.0.0)
file(GLOB SRC "src/*.cpp")

find_package(SFML 2.5.1 REQUIRED system window graphics)

IF (WIN32)
    find_package(SFML 2.5.1 REQUIRED main)
    add_executable(Snake WIN32 ${SRC})
    target_link_libraries(Snake PRIVATE sfml-main)
ELSE()
    add_executable(Snake ${SRC})
ENDIF()

target_include_directories(Snake PRIVATE include/)
target_include_directories(Snake PRIVATE include/)
target_link_libraries(Snake PRIVATE sfml-graphics)
target_link_libraries(Snake PRIVATE sfml-window)
target_link_libraries(Snake PRIVATE sfml-system)
    
