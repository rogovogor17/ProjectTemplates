include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}_tests
	test_main.cpp
)

target_link_libraries(${PROJECT_NAME}_tests
    PRIVATE gtest_main
    PRIVATE gtest
)

target_include_directories(${PROJECT_NAME}_tests
    PRIVATE ${CMAKE_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/src
)

add_test(NAME ${PROJECT_NAME}_tests
         COMMAND ${PROJECT_NAME}_tests)

set_tests_properties(${PROJECT_NAME}_tests
    PROPERTIES
    ENVIRONMENT "GTEST_COLOR=1"
)
