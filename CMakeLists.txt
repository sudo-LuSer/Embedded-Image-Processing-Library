cmake_minimum_required(VERSION 3.10)
project(BITMAP_C)

set(CMAKE_C_STANDARD 11)   

include_directories(include
)

add_executable(bitmap_test
    src/main.c
    src/bitmaplib.c
    src/vectlib.c
)

target_link_libraries(bitmap_test 
)
