cmake_minimum_required (VERSION 3.24)

project(investigate-stack-issue)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_C_EXTENSIONS Off)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

include(FetchContent)

FetchContent_Declare(
    emil
    GIT_REPOSITORY https://github.com/philips-software/amp-embedded-infra-lib.git
    GIT_TAG        ${EMIL_GIT_HASH}
    # GIT_TAG        58dfa0a8265e15b96ad4696827a6baaa88080b5d #this version is broken
    # GIT_TAG        72f9199cd58a40c24b47983133c28884628e0a07 #this has a fix
    SOURCE_DIR     ${CMAKE_CURRENT_LIST_DIR}/deps/emil
)

set(EMIL_BUILD_EXAMPLES Off CACHE INTERNAL "")

set(EMIL_ENABLE_COVERAGE Off)
set(EMIL_ENABLE_MUTATION_TESTING Off)
set(EMIL_MUTATION_TESTING_RUNNER_ARGUMENTS "")
set(EMIL_INCLUDE_MBEDTLS Off)
set(CMAKE_COMPILE_WARNING_AS_ERROR Off)

FetchContent_MakeAvailable(emil)

add_subdirectory(source)
