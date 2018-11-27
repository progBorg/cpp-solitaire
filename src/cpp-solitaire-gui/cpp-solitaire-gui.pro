TEMPLATE = app
TARGET = cpp-solitaire

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
	../Card.h \
	../klondike.h \
	../Pile.h \
	../Reserve.h \
	../Stack.h \
	../Stock.h \
	../Waste.h


SOURCES += \
	../Card.cpp \
	../main.cpp \
	../Pile.cpp \
	../Reserve.cpp \
	../Stack.cpp \
	../Stock.cpp \
	../Waste.cpp
