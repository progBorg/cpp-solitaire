TEMPLATE = app
TARGET = cpp-solitaire

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
	../Card.h \
	../Foundation.h \
	../solitaire.h \
	../Pile.h \
	../Reserve.h \
	../Stack.h \
	../Stock.h \
	../Waste.h \
    SolitaireGui.h


SOURCES += \
	../Card.cpp \
	../Foundation.cpp \
	../Pile.cpp \
	../Reserve.cpp \
	../Stack.cpp \
	../Stock.cpp \
	../Waste.cpp \
    SolitaireGui.cpp \
    solitaire.cpp
