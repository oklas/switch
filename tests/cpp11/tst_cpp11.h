
#include <QObject>
#include <QPair>
#include <QString>
#include <QtTest/QtTest>


class Cpp: public QObject
{
  Q_OBJECT
private Q_SLOTS:
  void test_string();
  void test_pair();
private:
  QString check( QString top, QString sub, QString val );
  QString check( QPair<QString,QString> pair );
};
