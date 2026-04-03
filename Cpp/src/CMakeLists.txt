#CMakeLists.txt for source files

set(MAIN_TARGET ${PROJECT_NAME})
add_executable(${MAIN_TARGET}
	main.cpp
)

target_include_directories(${MAIN_TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${MAIN_TARGET} PRIVATE $<$<CONFIG:Debug>:${DEBUG_FLAGS}>)
target_link_options(${MAIN_TARGET} PRIVATE $<$<CONFIG:Debug>:${DEBUG_FLAGS}>)
