TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += \
    main.cpp \
    trafficwalk.cpp \
    walksign.cpp \
    trafficlightbutton.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=

HEADERS += \
    outputmessage.h \
    trafficwalk.h \
    walksign.h \
    trafficlightbutton.h
