TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    fraction.cpp \
    friendsoffraction.cpp \
    mixednumber.cpp \
    driverprogram.cpp

HEADERS += \
    fraction.h \
    mixednumber.h

DISTFILES += \
    knownBugs
