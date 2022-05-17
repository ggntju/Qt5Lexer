QT -= gui

TEMPLATE = lib
DEFINES += QT5LEXER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qt5lexer.cpp

HEADERS += \
    Qt5Lexer_global.h \
    exprtk.h \
    lexertk.h \
    qt5lexer.h

win32:QMAKE_CXXFLAGS += /bigobj

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
