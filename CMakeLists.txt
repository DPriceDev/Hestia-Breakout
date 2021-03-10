cmake_minimum_required(VERSION 3.17)
project(Hestia_Breakout LANGUAGES CXX C VERSION 1.0.0)
include(cmake/StandardProjectSettings.cmake)

set(CMAKE_CXX_STANDARD 20)

add_library(breakout_project_options INTERFACE)
target_compile_features(breakout_project_options INTERFACE cxx_std_20)

add_library(breakout_project_warnings INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
    if (ENABLE_BUILD_WITH_TIME_TRACE)
        add_compile_definitions(breakout_project_options INTERFACE -ftime-trace)
    endif()
endif()

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(breakout_project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(breakout_project_options)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if (ENABLE_PCH)
    target_precompile_headers(
            breakout_project_options
            INTERFACE
            <vector>
            <utility>
            <algorithm>
            <array>)
endif()

add_subdirectory(src)

add_executable(hestia_breakout::hestia_breakout ALIAS hestia_breakout)