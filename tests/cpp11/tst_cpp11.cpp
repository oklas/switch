//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.10.04

#define SWITCH_QUICK
#include "switch"

#include "tst_cpp11.h"

QString Cpp11::check( QString top, QString sub, QString val ) {
  static QString res;
  SWITCH_DYNAMIC(top)
    CASE("SAMEFALL") FALL
    CASE("SAME")     res = val; BREAK
    CASE("SUBFALL")  FALL
    CASE("SUB")
      SWITCH(sub)
      CASE("SAMEFALL")    FALL
      CASE("SAME")        res = QString("SUB")+val;     BREAK
      CASE("DOUBLE")      res = QString("SUB")+val+val; BREAK
      CASE("DEFAULTFALL") FALL
      DEFAULT             res = QString("SUB")+"default";
      END
    BREAK
    CASE("DOUBLE")      res = val+val; BREAK
    CASE("DEFAULTFALL") FALL
    DEFAULT             res = "default";
  END
  return res;
}

void Cpp11::test_string() {
  switch_data::SwitchData<int> is_cpp11std; is_cpp11std.cpp11();

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

QString Cpp11::check_static( QString top, QString sub, QString val ) {
  static QString res;
  SWITCH_STATIC(top)
    CASE("SAMEFALL") FALL
    CASE("SAME")     res = val; BREAK
    CASE("SUBFALL")  FALL
    CASE("SUB")
      SWITCH(sub)
      CASE("SAMEFALL")    FALL
      CASE("SAME")        res = QString("SUB")+val;     BREAK
      CASE("DOUBLE")      res = QString("SUB")+val+val; BREAK
      CASE("DEFAULTFALL") FALL
      DEFAULT             res = QString("SUB")+"default";
      END
    BREAK
    CASE("DOUBLE")      res = val+val; BREAK
    CASE("DEFAULTFALL") FALL
    DEFAULT             res = "default";
  END
  return res;
}

void Cpp11::test_static() {
  switch_data::SwitchData<int> is_cpp11std; is_cpp11std.cpp11();

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

QString Cpp11::check( QPair<QString,QString> pair ) {
  QString res;
  SWITCH(pair)
    CASE(( qMakePair<QString,QString>("a","fall") ))  FALL
    CASE(( qMakePair<QString,QString>("a","a") ))     res = "aa"; BREAK
    CASE(( qMakePair<QString,QString>("fall","b") ))  FALL
    CASE(( qMakePair<QString,QString>("b","b") ))     res = "bb"; BREAK
    CASE(( qMakePair<QString,QString>("a","b") ))     res = "ab"; BREAK
    CASE(( qMakePair<QString,QString>("b","a") ))     res = "ba"; BREAK
    CASE(( qMakePair<QString,QString>("df","fall") )) FALL
    DEFAULT                                           res = "default";
  END
  return res;
}

void Cpp11::test_pair() {
  QCOMPARE( QString("aa"),      check( qMakePair<QString,QString>("a","fall") ) );
  QCOMPARE( QString("aa"),      check( qMakePair<QString,QString>("a","a") ) );
  QCOMPARE( QString("bb"),      check( qMakePair<QString,QString>("fall","b") ) );
  QCOMPARE( QString("bb"),      check( qMakePair<QString,QString>("b","b") ) );
  QCOMPARE( QString("ab"),      check( qMakePair<QString,QString>("a","b") ) );
  QCOMPARE( QString("ba"),      check( qMakePair<QString,QString>("b","a") ) );
  QCOMPARE( QString("default"), check( qMakePair<QString,QString>("df","fall") ) );
  QCOMPARE( QString("default"), check( qMakePair<QString,QString>("any","val") ) );
}


QTEST_MAIN(Cpp11)
