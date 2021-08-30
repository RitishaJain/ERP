#-------------------------------------------------
#
# Project created by QtCreator 2019-02-19T13:54:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ERP_Final
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        login.cpp \
    attendance.cpp \
    accountmanagement.cpp \
    adduser.cpp \
    employeemanagement.cpp \
    manageemp.cpp \
    welcome.cpp \
    designselect.cpp \
    promanage.cpp \
    dash.cpp \
    planning.cpp \
    cutting.cpp \
    stitching.cpp \
    finishing.cpp \
    changeusername.cpp \
    changepass.cpp \
    changemail.cpp \
    changephone.cpp \
    addemployee.cpp \
    type.cpp \
    typest.cpp \
    typefin.cpp \
    cuttingv.cpp \
    stitchingv.cpp \
    finishingv.cpp


HEADERS += \
        login.h \
    attendance.h \
    accountmanagement.h \
    adduser.h \
    employeemanagement.h \
    manageemp.h \
    welcome.h \
    designselect.h \
    promanage.h \
    dash.h \
    planning.h \
    cutting.h \
    stitching.h \
    finishing.h \
    changeusername.h \
    changepass.h \
    changemail.h \
    changephone.h \
    addemployee.h \
    type.h \
    typest.h \
    typefin.h \
    cuttingv.h \
    stitchingv.h \
    finishingv.h \
    exampleview.h \
    examplemodel.h


FORMS += \
        login.ui \
    attendance.ui \
    accountmanagement.ui \
    adduser.ui \
    employeemanagement.ui \
    manageemp.ui \
    welcome.ui \
    designselect.ui \
    promanage.ui \
    dash.ui \
    planning.ui \
    cutting.ui \
    stitching.ui \
    finishing.ui \
    changeusername.ui \
    changepass.ui \
    changemail.ui \
    changephone.ui \
    addemployee.ui \
    type.ui \
    typest.ui \
    typefin.ui \
    cuttingv.ui \
    stitchingv.ui \
    finishingv.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ERP_Final.pro

RESOURCES += \
    res.qrc

DISTFILES += \
    ERP_Final.pro.user.37ee114
