QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

QT += widgets
LIBS+= -lOpengl32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        aic.cpp \
        analizador.cpp \
        archivo.cpp \
        editor.cpp \
        expositor.cpp \
        filtro.cpp \
        gestordearchivos.cpp \
        imagen.cpp \
        lut.cpp \
        main.cpp \
        mediana.cpp \
        pasabajos.cpp \
        pixel.cpp \
        pnm.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    aic.h \
    analizador.h \
    archivo.h \
    editor.h \
    expositor.h \
    filtro.h \
    gestordearchivos.h \
    imagen.h \
    lut.h \
    mediana.h \
    pasabajos.h \
    pixel.h \
    pnm.h
