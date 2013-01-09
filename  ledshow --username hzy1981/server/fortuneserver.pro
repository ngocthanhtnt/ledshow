HEADERS       = server.h \
    window.h
SOURCES       = server.cpp \
                main.cpp \
    window.cpp
QT           += network

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneserver
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS fortuneserver.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneserver
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000CF71
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    TARGET.CAPABILITY = "NetworkServices ReadUserData"
    TARGET.EPOCHEAPSIZE = 0x20000 0x2000000
}

RESOURCES += \
    systray.qrc
