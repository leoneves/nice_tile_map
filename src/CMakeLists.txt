include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# sources
file(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/app/*.h)
file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp)
file(GLOB_RECURSE I18N_FILES ${CMAKE_CURRENT_SOURCE_DIR}/i18n/*.ts)

qt5_add_resources(QT_RESOURCES qml.qrc)
list(APPEND HEADERS ${HEADERS_FILES})
list(APPEND SOURCES ${SOURCES_FILES})
list(APPEND I18N_FILES_SOURCES ${I18N_FILES})

add_executable(nice_tile_map
    main.cpp
    ${HEADERS}
    ${SOURCES}
    ${QT_RESOURCES}
    ${I18N_FILES_SOURCES}
    )

target_link_libraries(nice_tile_map
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
    )

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

windeployqt(nice_tile_map)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    add_custom_command(TARGET nice_tile_map POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/libs/win64"
        $<TARGET_FILE_DIR:nice_tile_map>)
endif()

message("QT Version: " ${QT_VERSION_MAJOR})
