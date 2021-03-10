cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE all_SRCS
        "*.cpp"
        "*.c")

add_executable(hestia_breakout ${all_SRCS} ../include)

target_link_libraries(hestia_breakout PRIVATE
        breakout_project_options
        breakout_project_warnings)

target_include_directories(hestia_breakout PUBLIC ../include)

add_custom_command(
        TARGET hestia_breakout POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets
        ${CMAKE_BINARY_DIR}/src/assets)