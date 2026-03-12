cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set (DEBUG_FLAGS -std=c17 -DDEBUG -ggdb3 -fsanitize=address,alignment -Wall -Wextra
				 -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion
				 -Wempty-body -Wfloat-equal -Wno-format-nonliteral -Wformat-security -Wformat=2 -Winline
				 -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls
				 -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wswitch-default
				 -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing
				 -Wno-varargs -Wno-unused-parameter -fstack-protector
				 -fstrict-overflow -fPIC -fPIE -fno-omit-frame-pointer -fPIE -Werror=vla -Wno-write-strings)
set (RELEASE_FLAGS -std=c17)

find_program(IWYU_PATH NAMES include-what-you-use iwyu)

if(IWYU_PATH)
    message(STATUS "Found include-what-you-use: ${IWYU_PATH}")

    set(IWYU_COMMAND "${IWYU_PATH}"
        "-Xiwyu;--verbose=1;"
        "-Xiwyu;--comment_style=long;"
        "-isysroot;${CMAKE_OSX_SYSROOT};"
        "-Xiwyu;--mapping_file=$ENV{HOME}/iwyu/src/libcxx.imp"
    )

    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE
        "$<$<CONFIG:Debug>:${IWYU_COMMAND}>"
    )
else()
    message(STATUS "include-what-you-use not found, continuing without it")
endif()

file(GLOB SOURCES "src/*.cpp" "src/*.c")
file(GLOB HEADERS "include/*.hpp" "include/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:${DEBUG_FLAGS}>)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:${RELEASE_FLAGS}>)

target_link_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:${DEBUG_FLAGS}>)
target_link_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:${RELEASE_FLAGS}>)
