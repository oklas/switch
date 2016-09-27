#include "tst_c.h"
#include "tst_c_check.h"


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
}


QTEST_MAIN(C)
