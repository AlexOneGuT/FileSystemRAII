cmake_minimum_required(VERSION 3.10)
project(FileSystemRAII)

# ������������� �������� C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ������� ����������
add_library(CringeRAII "src/CringeRAII.cpp" "include/CringeRAII.h")

# ������� ���������������� ���������
add_executable(demo demo/main.cpp)

# ������� ���������� � ���������������� ����������
target_link_libraries(demo CringeRAII)

# ������������� include ���������� ��� ����������
target_include_directories(CringeRAII PUBLIC include)
target_include_directories(demo PRIVATE include)