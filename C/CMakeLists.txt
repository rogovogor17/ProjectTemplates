cmake_minimum_required(VERSION 3.20)
project(MyProject VERSION 1.0 LANGUAGES C CXX)
enable_testing()

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEBUG_FLAGS -DDEBUG -O0 -ggdb3 -fsanitize=address,alignment -Wall -Wextra -Wmissing-declarations -Wcast-align
    -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wno-format-nonliteral -Wformat-security
    -Wformat=2 -Winline -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion
    -Wstrict-overflow=2 -Wswitch-default -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers
    -Wno-narrowing -Wno-varargs -Wno-unused-parameter -fstack-protector -fstrict-overflow -fPIC -fPIE -fno-omit-frame-pointer
    -fPIE -Werror=vla -Wno-write-strings)

find_program(IWYU_PATH NAMES include-what-you-use iwyu)
set(IWYU_COMMAND "${IWYU_PATH}"
	"-Xiwyu;--verbose=1;"
	"-Xiwyu;--comment_style=long;"
	"-isysroot;${CMAKE_OSX_SYSROOT};"
	"-Xiwyu;--mapping_file=$ENV{IWYU_MAPPING_FILE};"
)
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${IWYU_COMMAND})

add_library(implementation)
add_subdirectory(src)
add_subdirectory(tests)
