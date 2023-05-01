QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
QT += widgets
LIBS+= -lOpengl32

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../aic.cpp \
    ../analizador.cpp \
    ../archivo.cpp \
    ../editor.cpp \
    ../expositor.cpp \
    ../filtro.cpp \
    ../gestordearchivos.cpp \
    ../imagen.cpp \
    ../interfaz.cpp \
    ../lut.cpp \
    ../mediana.cpp \
    ../pasabajos.cpp \
    ../pixel.cpp \
    ../pnm.cpp

HEADERS += \
    ../aic.h \
    ../analizador.h \
    ../archivo.h \
    ../editor.h \
    ../expositor.h \
    ../filtro.h \
    ../gestordearchivos.h \
    ../imagen.h \
    ../interfaz.h \
    ../lut.h \
    ../mediana.h \
    ../pasabajos.h \
    ../pixel.h \
    ../pnm.h

