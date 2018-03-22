#include "QT_STK.h"
#include "ui_QT_STK.h"


QT_STK::QT_STK(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QT_STK)
{
  ui->setupUi(this);
}

QT_STK::~QT_STK()
{
  delete ui;
}

void QT_STK::on_pushButton_clicked()
{
  QSTKEarth *m_stkEarth=&QSTKEarth::getInstance();
  m_stkEarth->NewScenario();
}
