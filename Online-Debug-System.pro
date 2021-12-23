QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Module/Login/Data/src/LoginData.cpp \
    Module/Login/View/src/LoginView.cpp \
    Module/Login/Control/src/LoginCtrl.cpp \
    Module/Main/Data/src/MainData.cpp \
    Module/Main/View/src/MainView.cpp \
    Module/Main/Control/src/MainCtrl.cpp \
    main.cpp

HEADERS += \
    Module/Login/Data/inc/LoginData.h \
    Module/Login/View/inc/LoginView.h \
    Module/Login/Control/inc/LoginCtrl.h \
    Module/Main/Data/inc/MainData.h \
    Module/Main/View/inc/MainView.h \
    Module/Main/Control/inc/MainCtrl.h \

FORMS += \
    Adorn/UI/Login/LoginView.ui \
    Adorn/UI/Main/MainView.ui \

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Language/EN/Online-Debug-System_en_AS.ts

RESOURCES += \
    Resource/Style.qrc
