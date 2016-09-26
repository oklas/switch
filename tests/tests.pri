INCLUDEPATH += $$DEPTH/include

QT = core testlib
QT -= gui

CONFIG -= app_bundle
CONFIG += testcase no_testcase_installs

QMAKE_CXXFLAGS += -std=c++0x
