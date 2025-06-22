QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    my_brush.cpp \
    my_color.cpp \
    my_drawing_widget.cpp \
    my_ellips.cpp \
    my_line.cpp \
    my_pen.cpp \
    my_pixel.cpp \
    my_point.cpp \
    my_polygon.cpp \
    my_polyline.cpp \
    my_rect.cpp \
    my_shape.cpp \
    rowcountdialog.cpp

HEADERS += \
    mainwindow.h \
    my_brush.h \
    my_color.h \
    my_drawing_widget.h \
    my_ellips.h \
    my_line.h \
    my_pen.h \
    my_pixel.h \
    my_point.h \
    my_polygon.h \
    my_polyline.h \
    my_rect.h \
    my_shape.h \
    rowcountdialog.h

FORMS += \
    mainwindow.ui \
    rowcountdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
