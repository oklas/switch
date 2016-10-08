//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.09.28

#include <QObject>

class C: public QObject
{
  Q_OBJECT
private Q_SLOTS:
  void test_string();
};
