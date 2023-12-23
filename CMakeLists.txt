cmake_minimum_required(VERSION 3.5)

project(projet_cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        carte.cpp
        carte.h
        carte.ui

         time_choice.cpp
         time_choice.h
         time_choice.ui
image.h
image.cpp
joueurs.h joueurs.cpp
   dialog.h dialog.cpp dialog.ui
     fin.h fin.cpp fin.ui
      names.txt
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projet_cpp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        time_choice.cpp time_choice.h time_choice.ui
        images/1000003469.jpg images/1000003470.jpg images/1000003471.jpg images/1000003472.jpg images/1000003473.jpg images/1000003474.jpg images/1000003475.jpg images/1000003476.jpg images/1000003477.jpg images/1000003478.jpg images/1000003479.jpg images/1000003480.jpg images/1000003481.jpg images/1000003482.jpg images/1000003483.jpg images/1000003484.jpg images/1000003485.jpg images/1000003486.jpg images/1000003487.jpg images/1000003488.jpg images/1000003489.jpg images/1000003490.jpg images/1000003491.jpg images/1000003492.jpg images/1000003493.jpg images/1000003494.jpg images/1000003495.jpg images/1000003496.jpg images/1000003497.jpg images/1000003498.jpg images/1000003499.jpg images/1000003500.jpg images/1000003501.jpg images/1000003502.jpg images/1000003503.jpg images/1000003504.jpg images/1000003505.jpg images/1000003506.jpg images/1000003507.jpg images/1000003508.jpg images/1000003509.jpg

        images.qrc
        image.h image.cpp
        joueurs.h joueurs.cpp
        fin.h fin.cpp fin.ui
        names.txt
        images/1000003469.jpg
        choice_difficulte.h choice_difficulte.cpp choice_difficulte.ui




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET projet_cpp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(projet_cpp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(projet_cpp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(projet_cpp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.projet_cpp)
endif()
set_target_properties(projet_cpp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS projet_cpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projet_cpp)
endif()
