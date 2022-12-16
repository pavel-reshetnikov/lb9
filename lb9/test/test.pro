QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

CONFIG (debug, debug|release){
LIBS += -L../objects/debug -lobjects
}
CONFIG (release, debug|release){
LIBS += -L../objects/release -lobjects
}

SOURCES +=  tst_test_lb.cpp
