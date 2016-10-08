//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.10.04

#include <QObject>
#include <QPair>
#include <QString>
#include <QtTest/QtTest>


class Cpp11: public QObject
{
  Q_OBJECT
private Q_SLOTS:
  void test_string();
  void test_static();
  void test_pair();
private:
  QString check( QString top, QString sub, QString val );
  QString check_static( QString top, QString sub, QString val );
  QString check( QPair<QString,QString> pair );
};
