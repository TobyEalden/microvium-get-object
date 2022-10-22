cmake_minimum_required(VERSION 3.10)

project(exp1 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME}
        ./microvium.c
        ./microvium.h
        ./microvium_port.h
        ./main.cpp
        ./Experiment1_ffi.cpp
        ./Experiment1_ffi.h
        ./concrete.cpp
        ./concrete.h
        )

target_compile_features(${PROJECT_NAME}
        PRIVATE
        cxx_std_17
        )

target_link_libraries(
        ${PROJECT_NAME}
)