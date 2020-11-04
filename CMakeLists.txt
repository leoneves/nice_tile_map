cmake_minimum_required(VERSION 3.5)

project(nice_tile_map LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

# sources
file(GLOB_RECURSE UI_FILES src/widgets/*.ui)
file(GLOB_RECURSE WIDGETS_FILES src/widgets/*.cpp)
file(GLOB_RECURSE I18N_FILES src/i18n/*.ts)

list(APPEND UI_SOURCES ${UI_FILES})
list(APPEND WIDGETS_SOURCES ${WIDGETS_FILES})
list(APPEND I18N_FILES_SOURCES ${I18N_FILES})

add_executable(nice_tile_map
    src/main.cpp
    ${WIDGETS_SOURCES}
    ${UI_SOURCES}
    ${I18N_FILES_SOURCES}
)

target_link_libraries(nice_tile_map PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  add_custom_command(TARGET nice_tile_map POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_directory
      "${PROJECT_SOURCE_DIR}/libs/win64"
      $<TARGET_FILE_DIR:nice_tile_map>)
endif()

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

message("QT Version: " ${QT_VERSION_MAJOR})
