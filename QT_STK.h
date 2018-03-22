#ifndef QT_STK_H
#define QT_STK_H

#include <QWidget>
#include "QSTKEarth.h"
#include "stk.h"
namespace Ui {
  class QT_STK;
}

class QT_STK : public QWidget
{
  Q_OBJECT

public:
  explicit QT_STK(QWidget *parent = 0);
  ~QT_STK();


private slots:
  void on_pushButton_clicked();

private:
  Ui::QT_STK *ui;
};

#endif // QT_STK_H
