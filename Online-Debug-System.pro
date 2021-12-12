QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Event/Login/src/LoginSlot.cpp \
    Event/Main/src/MainSlot.cpp \
    Frame/Login/src/LoginView.cpp \
    Frame/Main/src/MainView.cpp \
    Model/Login/src/LoginData.cpp \
    Model/Main/src/MainData.cpp \
    main.cpp

HEADERS += \
    Event/Login/inc/LoginSlot.h \
    Event/Main/inc/MainSlot.h \
    Frame/Login/inc/LoginView.h \
    Frame/Main/inc/MainView.h \
    Model/Login/inc/LoginData.h \
    Model/Main/inc/MainData.h

FORMS += \
    Adorn/UI/Login/LoginView.ui \
    Adorn/UI/Main/MainView.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Language/EN/Online-Debug-System_en_AS.ts

RESOURCES += \
    Adorn/QSS/Style.qrc
