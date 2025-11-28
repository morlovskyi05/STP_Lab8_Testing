cmake_minimum_required(VERSION 3.14)
project(Lab8_Testing)

# Встановлюємо стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаємо підтримку тестування
enable_testing()

# Завантажуємо Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# Для Windows: запобігає перезапису прапорців компілятора батьківського проекту
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включаємо покриття коду (для GCC/Clang)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Додаємо виконуваний файл з тестами
add_executable(
  test_calculator
  test_calculator.cpp
)

# Лінкуємо з Google Test
target_link_libraries(
  test_calculator
  GTest::gtest_main
)

# Включаємо каталог з заголовками
target_include_directories(test_calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Додаємо тести до CTest
include(GoogleTest)
gtest_discover_tests(test_calculator)