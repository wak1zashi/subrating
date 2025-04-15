cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(substats VERSION 1.0.0)

find_package(Curses REQUIRED)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES 
src/main.cc
src/models/subscriber.cc
src/services/convert.cc
src/services/subscriber_manager.cc
src/ui/header_window.cc
src/ui/input_manager.cc
src/ui/layout_manager.cc
src/ui/logo_window.cc
src/ui/sub_form_window.cc
src/ui/ui.cc
src/ui/view_window.cc
src/ui/window.cc
src/ui/window_helpers.cc
src/utils/file_utils.cc
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

