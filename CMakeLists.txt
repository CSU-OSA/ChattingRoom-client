cmake_minimum_required(VERSION 3.20)
project(Chatroom_gui_oct)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/DevelopKits/Qt/6.2.1/mingw81_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

find_package(Protobuf CONFIG REQUIRED)

add_executable(Chatroom_gui_oct
        WIN32
        src/main.cpp
        src/MainWindow/mainwindow.cpp
        src/MainWindow/mainwindow.h
        src/MainWindow/mainwindow.ui
        src/MainWindow/HeartBeat.cpp
        src/MainWindow/HeartBeat.h
        src/dependencies/proto/Response.pb.cc
        src/dependencies/proto/Response.pb.h
        src/dependencies/proto/Request.pb.cc
        src/dependencies/proto/Request.pb.h
        src/MainWindow/JoinChaDialog/joinchadialog.cpp
        src/MainWindow/JoinChaDialog/joinchadialog.h
        src/MainWindow/JoinChaDialog/joinchadialog.ui
        src/MainWindow/CreateChaDialog/createchadialog.cpp
        src/MainWindow/CreateChaDialog/createchadialog.h
        src/MainWindow/CreateChaDialog/createchadialog.ui
        src/MainWindow/TcpSocket/SocketThread.cpp
        src/MainWindow/TcpSocket/SocketThread.h
        src/MainWindow/QuitChaDialog/quitchadialog.cpp
        src/MainWindow/QuitChaDialog/quitchadialog.h
        src/MainWindow/QuitChaDialog/quitchadialog.ui)

target_link_libraries(Chatroom_gui_oct
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        protobuf::libprotobuf
        protobuf::libprotobuf-lite
        protobuf::libprotoc
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Network)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
