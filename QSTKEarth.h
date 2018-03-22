#ifndef QSTKEARTH_H
#define QSTKEARTH_H

#include "STK.h"
#include <QWidget>
#include <ActiveQt/QAxWidget>
#include <QDebug>

class QSTKEarth: public QWidget
{
    Q_OBJECT
public:
    static QSTKEarth &getInstance()
    {//使用双重检测
      if(instance==NULL)//第一次检测
        {
          QMutexLocker locker(&mutex);//加互斥锁
          if(NULL==instance)//第二次检测
            instance=new QSTKEarth;
        }
      return *instance;
    }
    bool enableControl;
    ~QSTKEarth();
private:
    static QMutex mutex;//实例互斥锁
    static QAtomicPointer<QSTKEarth> instance;
    QSTKEarth(const QSTKEarth &);//禁止拷贝构造函数
    QSTKEarth(QWidget *parent = 0);//禁止构造函数
    IAgStkObjectRootPtr  m_pRoot;
    IAgSTKXApplicationPtr m_app;

public:
    void PauseSTK();
    void StartSTK();
    void FasterSTK();
    void SlowerSTK();
    void ResetSTK();
    void NewScenario();
    void LoadScenario();
    void UnloadStkScence();
};

#endif // QSTKEARTH_H
