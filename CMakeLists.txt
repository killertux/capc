cmake_minimum_required(VERSION 3.1)
project(capc)
find_package(Qt4 COMPONENTS QtCore QtXml QtXmlPatterns QtGui REQUIRED)
find_package(KDE4 REQUIRED)

set (CMAKE_CXX_STANDARD 11)
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(capc_SRCS 
functions.cpp 
Classes/Capc/Capc.cpp 
Classes/Handler/Handler.cpp 
Classes/StartWindowHandler/StartWindowHandler.cpp 
Classes/MainWindowHandler/MainWindowHandler.cpp 
Classes/MainWindowHandler/WidgetSettingsHandler.cpp 
Classes/MainWindowHandler/WidgetCollectHandler.cpp 
Classes/MainWindowHandler/WidgetCollectPointHandler.cpp 
Classes/MainWindowHandler/WidgetVisualizeHandler.cpp
Classes/MainWindowHandler/WidgetListItemsHandler.cpp
Classes/OAI/OAIType.cpp 
Classes/OAI/OAISettingsHandler.cpp 
Classes/OAI/OAI.cpp 
Classes/CollectTypes/CollectTypes.cpp 
Classes/CollectPoints/CollectPointsManager.cpp 
Classes/XML/XML.cpp
Classes/Configuration/Configuration.cpp 
Classes/Message/Message.cpp 
Classes/Article/Article.cpp
Classes/Article/ArticleDAO.cpp
Classes/Article/Field.cpp
Classes/Collect/Collect.cpp
main.cpp)

qt4_automoc(${capc_SRCS})
add_executable(capc ${capc_SRCS})
target_link_libraries(capc ${QT_LIBRARIES} ${KDE4_KDEUI_LIBS} 
${KDE4_KPARTS_LIBS}  Qt4::QtXmlPatterns -lexpat)

install(TARGETS capc RUNTIME DESTINATION bin)