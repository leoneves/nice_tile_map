cmake_minimum_required(VERSION 3.5)

project(nice_tile_map LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(UNIX AND NOT APPLE)
  message("Linux Platform")
  set(CMAKE_PREFIX_PATH "/home/leonardoneves/Qt/5.15.1/gcc_64")
elseif(APPLE)
  message("Apple Platform")
  set(CMAKE_PREFIX_PATH "/Users/leonardoneves/Applications/Qt/5.15.1/clang_64")
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  if(MINGW)
    message("MINGW Platform")
    set(CMAKE_PREFIX_PATH "C:\\Users\\leonardoneves\\Applications\\Qt\\5.15.1\\mingw81_64")
  elseif(WIN32)
    message("Windows 32 Platform Visual studio")
  else()
    message("Windows I don't know which")
  endif()
else()
  message("Other Platform")
endif()

# Set path to custom CMAKE scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Include Qt deployment helper function
include(windeployqt)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Qml Quick LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Qml Quick LinguistTools REQUIRED)

add_subdirectory(src)
