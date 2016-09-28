DEPTH = ../..
include($${DEPTH}/tests/tests.pri)

TARGET = tst_c
SOURCES = tst_c.cpp tst_c_check.c tst_c_extlink.c
HEADERS = tst_c.h tst_c_check.h tst_c_extlink.h
