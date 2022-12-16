QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    gestordearchivos.cpp \
    main.cpp
HEADERS += \
    gestordearchivos.h
