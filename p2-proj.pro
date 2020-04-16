######################################################################
# Automatically generated by qmake (3.1) Tue Apr 14 18:07:54 2020
######################################################################

QT += widgets
CONFIG += c++11
TEMPLATE = app
TARGET = p2-proj
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += controller.h \
           model/model.h \
           view/filterExample.h \
           view/insertExample.h \
    view/magazzinoAdapter.h \
           view/menu.h \
           model/hierarchy/arco.h \
           model/hierarchy/basso.h \
           model/hierarchy/chitarra.h \
           model/hierarchy/corda.h \
           model/hierarchy/fiato.h \
           model/hierarchy/kitBatteria.h \
           model/hierarchy/percussione.h \
           model/hierarchy/pianoforte.h \
           model/hierarchy/sax.h \
           model/hierarchy/strumento.h \
           model/hierarchy/tromba.h \
           model/hierarchy/viola.h \
           model/hierarchy/violino.h \
    model/container.h \
    view/carrelloAdapter.h \
    view/carrelloFilter.h \
    view/carrelloView.h \
    view/ordiniAdapter.h \
    view/ordiniFilter.h \
    view/ordiniView.h \
    view/magazzinoFilter.h \
    view/magazzinoView.h \
    view/addView.h




SOURCES += controller.cpp \
           main.cpp \
           model/model.cpp \
           view/insertExample.cpp \
           view/menu.cpp \
           model/hierarchy/arco.cpp \
           model/hierarchy/basso.cpp \
           model/hierarchy/chitarra.cpp \
           model/hierarchy/corda.cpp \
           model/hierarchy/fiato.cpp \
           model/hierarchy/kitBatteria.cpp \
           model/hierarchy/percussione.cpp \
           model/hierarchy/pianoforte.cpp \
           model/hierarchy/sax.cpp \
           model/hierarchy/strumento.cpp \
           model/hierarchy/tromba.cpp \
           model/hierarchy/viola.cpp \
           model/hierarchy/violino.cpp \
    view/magazzinoAdapter.cpp \
    view/magazzinoFilter.cpp \
    view/magazzinoView.cpp \
    view/ordiniAdapter.cpp \
    view/ordiniFilter.cpp \
    view/ordiniView.cpp \
    view/carrelloAdapter.cpp \
    view/carrelloFilter.cpp \
    view/carrelloView.cpp


