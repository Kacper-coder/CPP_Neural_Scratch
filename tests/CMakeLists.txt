# Pobierz automatycznie Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# Skompiluj testy
add_executable(nn_tests test_matrix.cpp
        ../include/Activation.h
        test_activations.cpp)

# Połącz testy z GTest oraz Twoją biblioteką nn_core
target_link_libraries(nn_tests gtest_main nn_core)

# Zarejestruj testy w CTest
include(GoogleTest)
gtest_discover_tests(nn_tests)