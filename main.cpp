#include "QT_STK.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QT_STK w;
  w.show();

  return a.exec();
}
