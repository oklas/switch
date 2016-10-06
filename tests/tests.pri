INCLUDEPATH += $$DEPTH/include

QT = core testlib
QT -= gui

CONFIG -= app_bundle
CONFIG += testcase no_testcase_installs

HEADERS = $$DEPTH/include/switch.h

