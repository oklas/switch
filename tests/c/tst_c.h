
#include <QObject>
#include <QPair>
#include <QString>
#include <QtTest/QtTest>


class C: public QObject
{
  Q_OBJECT
private Q_SLOTS:
  void test_string();
};
