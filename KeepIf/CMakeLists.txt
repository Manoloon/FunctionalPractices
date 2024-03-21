find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(Cpp-console main.cpp)

# These tests need their own main
add_executable(main.exe main.cpp)
