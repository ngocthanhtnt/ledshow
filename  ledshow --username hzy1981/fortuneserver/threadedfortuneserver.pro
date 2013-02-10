HEADERS       = dialog.h \
                fortuneserver.h \
                fortunethread.h \
    server.h \
    thread.h \
    mainwindow.h
SOURCES       = dialog.cpp \
                fortuneserver.cpp \
                fortunethread.cpp \
                main.cpp \
    server.cpp \
    thread.cpp \
    mainwindow.cpp
QT           += network
QT           += sql

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/threadedfortuneserver
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS threadedfortuneserver.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/network/threadedfortuneserver
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)

FORMS += \
    mainwindow.ui
