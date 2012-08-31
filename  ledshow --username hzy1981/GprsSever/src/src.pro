TEMPLATE = app
TARGET = bpms
DESTDIR = ../bin
CONFIG += release
QT += sql
OBJECTS_DIR = ../tmp
MOC_DIR = ../tmp
#CODECFORTR = GBK
CODECFORSRC = GBK

# Input
HEADERS += mainwindow.h \
	sqlquerymodelgoods.h \
	goodseditdialog.h \
	goodsviewdialog.h \
	goodsinoutdialog.h \
	consumegoodsadddialog.h \
	sqlquerymodelcustomer.h \
	customereditdialog.h \
	sqlquerymodelconsumetop.h \
	sqlquerymodelconsumebottomleft.h \
	sqlquerymodelconsumebottomright.h
FORMS += mainwindow.ui \
	goodseditdialog.ui \
	goodsviewdialog.ui \
	goodsinoutdialog.ui \
	consumegoodsadddialog.ui \
	customereditdialog.ui
SOURCES += main.cpp \
	mainwindow.cpp \
	sqlquerymodelgoods.cpp \
	goodseditdialog.cpp \
	goodsviewdialog.cpp \
	goodsinoutdialog.cpp \
	consumegoodsadddialog.cpp \
	sqlquerymodelcustomer.cpp \
	customereditdialog.cpp \
	sqlquerymodelconsumetop.cpp \
	sqlquerymodelconsumebottomleft.cpp \
	sqlquerymodelconsumebottomright.cpp
