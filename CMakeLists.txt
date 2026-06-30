cmake_minimum_required(VERSION 3.14)
project(CPP_Neural_Scratch)

# Wymagaj nowoczesnego standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dodaj folder include do ścieżek wyszukiwania nagłówków
include_directories(include)

# Stwórz bibliotekę z Twojego kodu (łatwiejsze do testowania)
add_library(nn_core src/Matrix.cpp src/Layer.cpp
        src/Matrix.cpp
        include/Matrix.h
        src/Layer.cpp
        include/Layer.h
        include/Activation.h)

# Plik wykonywalny
add_executable(nn_app src/main.cpp
        include/Activation.h)
target_link_libraries(nn_app nn_core)

# Dołącz folder z testami
enable_testing()
add_subdirectory(tests)
