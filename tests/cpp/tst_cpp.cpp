//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.09.24

#include "switch"

#include "tst_cpp.h"

QString Cpp::check( QString top, QString sub, QString val ) {
  SWITCH(top)
    CASE("SAMEFALL") FALL
    CASE("SAME")     return val;     BREAK
    CASE("SUBFALL")  FALL
    CASE("SUB")
      SWITCH(sub)
      CASE("SAMEFALL")    FALL
      CASE("SAME")        return QString("SUB")+val;       BREAK
      CASE("DOUBLE")      return QString("SUB")+val+val;   BREAK
      CASE("DEFAULTFALL") FALL
      DEFAULT             return QString("SUB")+"default";
      END
    BREAK
    CASE("DOUBLE")      return val+val; BREAK
    CASE("DEFAULTFALL") FALL
    DEFAULT             return "default";
  END
  return "UNREACHEABLE";
}

void Cpp::test_string() {
  switch_data::SwitchData<int> is_cpp97std(1); is_cpp97std.cpp97();

  QCOMPARE( QString("val"),       check("SAMEFALL","","val") );
  QCOMPARE( QString("val"),       check("SAME","","val") );
  QCOMPARE( QString("valval"),    check("DOUBLE" ,"","val") );
  QCOMPARE( QString("default"),   check("DEFAULTFALL","","val") );
  QCOMPARE( QString("default"),   check("DEFAULT","","val") );

  QCOMPARE( QString("SUBval"),     check("SUBFALL","SAME","val") );
  QCOMPARE( QString("SUBval"),     check("SUB","SAMEFALL","val") );
  QCOMPARE( QString("SUBval"),     check("SUB","SAME","val") );
  QCOMPARE( QString("SUBvalval"),  check("SUB","DOUBLE","val") );
  QCOMPARE( QString("SUBdefault"), check("SUB","DEFAULTFALL","val") );
  QCOMPARE( QString("SUBdefault"), check("SUB","DEFAULT","val") );
}

QString Cpp::check( QPair<QString,QString> pair ) {
  SWITCH(pair)
    CASE(( qMakePair<QString,QString>("a","fall") ))  FALL
    CASE(( qMakePair<QString,QString>("a","a") ))     return "aa"; BREAK
    CASE(( qMakePair<QString,QString>("fall","b") ))  FALL
    CASE(( qMakePair<QString,QString>("b","b") ))     return "bb"; BREAK
    CASE(( qMakePair<QString,QString>("a","b") ))     return "ab"; BREAK
    CASE(( qMakePair<QString,QString>("b","a") ))     return "ba"; BREAK
    CASE(( qMakePair<QString,QString>("df","fall") )) FALL
    DEFAULT                                           return "default";
  END
  return "UNREACHEABLE";
}

void Cpp::test_pair() {
  QCOMPARE( QString("aa"),      check( qMakePair<QString,QString>("a","fall") ) );
  QCOMPARE( QString("aa"),      check( qMakePair<QString,QString>("a","a") ) );
  QCOMPARE( QString("bb"),      check( qMakePair<QString,QString>("fall","b") ) );
  QCOMPARE( QString("bb"),      check( qMakePair<QString,QString>("b","b") ) );
  QCOMPARE( QString("ab"),      check( qMakePair<QString,QString>("a","b") ) );
  QCOMPARE( QString("ba"),      check( qMakePair<QString,QString>("b","a") ) );
  QCOMPARE( QString("default"), check( qMakePair<QString,QString>("df","fall") ) );
  QCOMPARE( QString("default"), check( qMakePair<QString,QString>("any","val") ) );
}


QTEST_MAIN(Cpp)
