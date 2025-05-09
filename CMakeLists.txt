cmake_minimum_required(VERSION 3.16)

project(MineSweeper2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        head.h head.cpp head.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MineSweeper2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mainwindow.ui
        gamegrid.h gamegrid.cpp
        cell.h cell.cpp cell.ui
        cellupdater.h cellupdater.cpp
        styles.qss
        player.h player.cpp
        entity.h entity.cpp
        resources.qrc

    )

else()
    if(ANDROID)
        add_library(MineSweeper2 SHARED
            ${PROJECT_SOURCES}
        )

    else()
        add_executable(MineSweeper2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MineSweeper2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MineSweeper2)
endif()
set_target_properties(MineSweeper2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MineSweeper2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MineSweeper2)
endif()
