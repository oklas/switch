//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.09.28

#include <QString>
#include <QtTest/QtTest>

#include "tst_c_check.h"
#include "tst_c_extlink.h"

#include "tst_c.h"


void C::test_string() {
  QCOMPARE( QString("val"),     QString( check("SAMEFALL","","val") ) );
  QCOMPARE( QString("val"),     QString( check("SAME","","val") ) );
  QCOMPARE( QString("valval"),  QString( check("DOUBLE" ,"","val") ) );
  QCOMPARE( QString("default"), QString( check("DEFAULTFALL","","val") ) );
  QCOMPARE( QString("default"), QString( check("DEFAULT","","val") ) );

  QCOMPARE( QString("SUBval"),     QString( check("SUB","SAMEFALL","val") ) );
  QCOMPARE( QString("SUBval"),     QString( check("SUB","SAME","val") ) );
  QCOMPARE( QString("SUBvalval"),  QString( check("SUB","DOUBLE","val") ) );
  QCOMPARE( QString("SUBdefault"), QString( check("SUB","DEFAULTFALL","val") ) );
  QCOMPARE( QString("SUBdefault"), QString( check("SUB","DEFAULT","val") ) );

  QCOMPARE( QString("val"),
    QString( check_multiple_external_link("SAMEFALL","","val") ) );
  QCOMPARE( QString("val"),
    QString( check_multiple_external_link("SAME","","val") ) );
}


QTEST_MAIN(C)
