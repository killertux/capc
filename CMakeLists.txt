cmake_minimum_required(VERSION 2.6)
project(capc)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(capc_SRCS Classes/Capc/Capc.cpp Classes/Handler/Handler.cpp Classes/StartWindowHandler/StartWindowHandler.cpp Classes/MainWindowHandler/MainWindowHandler.cpp Classes/MainWindowHandler/WidgetSettingsHandler.cpp Classes/OAI/OAI.cpp Classes/OAI/OAISettingsHandler.cpp Classes/CollectTypes/CollectTypes.cpp Classes/Configuration/Configuration.cpp main.cpp)

qt4_automoc(${capc_SRCS})
add_executable(capc ${capc_SRCS})
target_link_libraries(capc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${KDE4_KDEUI_LIBS} ${KDE4_KPARTS_LIBS})

install(TARGETS capc RUNTIME DESTINATION bin)