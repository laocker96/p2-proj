######################################################################
# Automatically generated by qmake (3.1) Tue Jun 16 21:15:12 2020
######################################################################

TEMPLATE = app
TARGET = p2-proj
QT += widgets gui printsupport
CONFIG += c++-11
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += controller.h \
           model/container.h \
           model/model.h \
           view/carrelloAdapter.h \
           view/carrelloAdapter_copy1.h \
           view/carrelloFilter.h \
           view/carrelloView.h \
           view/filterExample.h \
           view/imageControlBox.h \
           view/imageView.h \
           view/inputexception.h \
           view/insertExample.h \
           view/insertView.h \
           view/magazzinoAdapter.h \
           view/magazzinoFilter.h \
           view/magazzinoView.h \
           view/menu.h \
           view/toolboxrow.h \
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
           model/hierarchy/violino.h
SOURCES += controller.cpp \
           main.cpp \
           model/model.cpp \
           view/carrelloAdapter.cpp \
           view/carrelloFilter.cpp \
           view/carrelloView.cpp \
           view/imageControlBox.cpp \
           view/imageView.cpp \
           view/inputexception.cpp \
           view/insertView.cpp \
           view/magazzinoAdapter.cpp \
           view/magazzinoFilter.cpp \
           view/magazzinoView.cpp \
           view/menu.cpp \
           view/toolboxrow.cpp \
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
           model/hierarchy/violino.cpp
