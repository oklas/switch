DEPTH = ../..
include($${DEPTH}/tests/tests.pri)

QMAKE_CXXFLAGS += -std=c++0x

TARGET = tst_cpp11
SOURCES = tst_cpp11.cpp
HEADERS = tst_cpp11.h

