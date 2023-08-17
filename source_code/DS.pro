QT += core gui
QT += core gui sql
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_Time.cpp \
    compression.cpp \
    MyString.cpp \
    MyVector.cpp \
    Mythread.cpp \
    kmp.cpp \
    log.cpp \
    mapStack.cpp \
    main.cpp \
    global.cpp \
    widget.cpp \
    widget_clock.cpp \
    widget_desktop.cpp \
    widget_acivity.cpp \
    widget_guide.cpp \
    widget_lesson.cpp \
    widget_lessonadd.cpp \
    widget_lessonchange.cpp \
    widget_lessontask.cpp \
    widget_lessontest.cpp \
    widget_signup.cpp \
    mainwindow.cpp \


HEADERS += \
    basic_Time.h \
    compression.h \
    heap.h \
    huffman.h \
    MyString.h \
    MyVector.h \
    Vector.h \
    Mythread.h \
    kmp.h \
    log.h \
    mapStack.h \
    global.h \
    widget.h \
    widget_clock.h \
    widget_desktop.h \
    widget_acivity.h \
    widget_guide.h \
    widget_lesson.h \
    widget_lessonadd.h \
    widget_lessonchange.h \
    widget_lessontask.h \
    widget_lessontest.h \
    widget_signup.h \
    mainwindow.h



FORMS += \
    widget.ui \
    widget_clock.ui \
    widget_desktop.ui \
    widget_acivity.ui \
    widget_guide.ui \
    widget_lesson.ui \
    widget_lessonadd.ui \
    widget_lessonchange.ui \
    widget_lessontask.ui \
    widget_lessontest.ui \
    widget_signup.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
