#-------------------------------------------------
#
# Project created by QtCreator 2010-08-19T21:46:10
#
#-------------------------------------------------

QT       += core gui

TARGET = QTPrj
TEMPLATE = app
LIBS += libqextserialport

SOURCES += main.cpp\
        mainwindow.cpp \
    showArea.cpp \
    progManage.cpp \
    areaProperty.cpp \
    property.cpp \
    progProperty.cpp \
    timerProperty.cpp \
    picProperty.cpp \
    textedit.cpp \
    simpleTextEdit.cpp \
    clockProperty.cpp \
    flashProperty.cpp \
    timeProperty.cpp \
    tempProperty.cpp \
    colorCombo.cpp \
    lunProperty.cpp \
    screenProperty.cpp \
    makeProto.cpp \
    humidityProperty.cpp \
    noiseProperty.cpp \
    QT_SIM.cpp \
    ../STM32/Usr/app/Timer_Show.cpp \
    ../STM32/Usr/app/Time_Show.cpp \
    ../STM32/Usr/app/Temp_Show.cpp \
    ../STM32/Usr/app/Storage.cpp \
    ../STM32/Usr/app/Screen_Status.cpp \
    ../STM32/Usr/app/pub.cpp \
    ../STM32/Usr/app/Pic_Show.cpp \
    ../STM32/Usr/app/OS_Shell.cpp \
    ../STM32/Usr/app/OS_Pub.cpp \
    ../STM32/Usr/app/nongli.cpp \
    ../STM32/Usr/app/Noise_Show.cpp \
    ../STM32/Usr/app/Main_Show.cpp \
    ../STM32/Usr/app/Lun_Show.cpp \
    ../STM32/Usr/app/LED_Show.cpp \
    ../STM32/Usr/app/LED_Para.cpp \
    ../STM32/Usr/app/Humidity_Show.cpp \
    ../STM32/Usr/app/Flash_Show.cpp \
    ../STM32/Usr/app/com.cpp \
    ../STM32/Usr/app/Clock_Show.cpp \
    ../STM32/Usr/app/Border_Show.cpp \
    ../STM32/Usr/app/ZK.cpp \
    Communication.cpp \
    tablePropertyEdit.cpp

HEADERS  += mainwindow.h \
    showArea.h \
    progManage.h \
    areaProperty.h \
    property.h \
    progProperty.h \
    timerProperty.h \
    picProperty.h \
    textedit.h \
    simpleTextEdit.h \
    clockProperty.h \
    flashProperty.h \
    timeProperty.h \
    tempProperty.h \
    colorCombo.h \
    lunProperty.h \
    screenProperty.h \
    makeProto.h \
    humidityProperty.h \
    noiseProperty.h \
    QT_SIM.h \
    ../Timer_Show.h \
    ../Time_Show.h \
    ../Temp_Show.h \
    ../Storage.h \
    ../Shell.h \
    ../Screen_Status.h \
    ../QT_SIM.h \
    ../pub.h \
    ../Pic_Show.h \
    ../OS_Shell.h \
    ../OS_Pub.h \
    ../OS_Includes.h \
    ../OS_Core.h \
    ../OS_Cfg.h \
    ../nongli.h \
    ../Noise_Show.h \
    ../Main_Show.h \
    ../Lun_Show.h \
    ../LED_Show_Proc.h \
    ../LED_Show.h \
    ../LED_Para.h \
    ../LED_Cfg.h \
    ../Includes.h \
    ../Humidity_Show.h \
    ../Flash_Show.h \
    ../com.h \
    ../Clock_Show.h \
    ../Border_Show.h \
    ../ZK.h \
    ../STM32/Usr/app/Timer_Show.h \
    ../STM32/Usr/app/Time_Show.h \
    ../STM32/Usr/app/Temp_Show.h \
    ../STM32/Usr/app/Storage.h \
    ../STM32/Usr/app/Screen_Status.h \
    ../STM32/Usr/app/pub.h \
    ../STM32/Usr/app/Pic_Show.h \
    ../STM32/Usr/app/OS_Time.h \
    ../STM32/Usr/app/OS_Shell.h \
    ../STM32/Usr/app/OS_Sem.h \
    ../STM32/Usr/app/OS_Pub.h \
    ../STM32/Usr/app/OS_Mutex.h \
    ../STM32/Usr/app/OS_Msg_Q.h \
    ../STM32/Usr/app/OS_Msg.h \
    ../STM32/Usr/app/OS_Mem.h \
    ../STM32/Usr/app/OS_Includes.h \
    ../STM32/Usr/app/OS_Ext.h \
    ../STM32/Usr/app/OS_Event.h \
    ../STM32/Usr/app/OS_Core.h \
    ../STM32/Usr/app/OS_Cfg.h \
    ../STM32/Usr/app/nongli.h \
    ../STM32/Usr/app/Noise_Show.h \
    ../STM32/Usr/app/Main_Show.h \
    ../STM32/Usr/app/Lun_Show.h \
    ../STM32/Usr/app/LED_Show_Proc.h \
    ../STM32/Usr/app/LED_Show.h \
    ../STM32/Usr/app/LED_Para.h \
    ../STM32/Usr/app/LED_Cfg.h \
    ../STM32/Usr/app/Includes.h \
    ../STM32/Usr/app/Humidity_Show.h \
    ../STM32/Usr/app/Flash_Show.h \
    ../STM32/Usr/app/com.h \
    ../STM32/Usr/app/Clock_Show.h \
    ../STM32/Usr/app/Border_Show.h \
    ../STM32/Usr/app/ZK.h \
    ../STM32/Usr/app/OS_Port.h \
    Communication.h \
    tablePropertyEdit.h

RESOURCES += \
    textedit.qrc
RC_FILE = app.rc
