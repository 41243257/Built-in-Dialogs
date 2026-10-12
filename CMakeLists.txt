cmake_minimum_required(VERSION 3.19)
project(Built-in-Dialogs LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Built-in-Dialogs
    WIN32 MACOSX_BUNDLE
    main.cpp
    builtindialog.cpp
    builtindialog.h
)

target_link_libraries(Built-in-Dialogs
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Built-in-Dialogs
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Built-in-Dialogs
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
