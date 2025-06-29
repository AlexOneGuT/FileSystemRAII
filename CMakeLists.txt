cmake_minimum_required(VERSION 3.10)
project(FileSystemRAII)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Создаем библиотеку
add_library(CringeRAII "src/CringeRAII.cpp" "include/CringeRAII.h")

# Создаем демонстрационную программу
add_executable(demo demo/main.cpp)

# Линкуем библиотеку с демонстрационной программой
target_link_libraries(demo CringeRAII)

# Устанавливаем include директорию для библиотеки
target_include_directories(CringeRAII PUBLIC include)
target_include_directories(demo PRIVATE include)