#include "QSTKEarth.h"
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QFileDialog>
//静态成员变量初始化
QMutex QSTKEarth::mutex;
QAtomicPointer<QSTKEarth> QSTKEarth::instance=0;

QSTKEarth::QSTKEarth(QWidget *parent) : QWidget(parent)
{
    ::CoUninitialize();
    HRESULT ha=m_app.CreateInstance(__uuidof(AgSTKXApplication));
    if(FAILED(ha))
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("系统提示"),
                             QString::fromLocal8Bit("创建程序对象失败！"));
    }
    HRESULT hr = m_pRoot.CreateInstance(__uuidof(AgStkObjectRoot));
    if(FAILED(hr))
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("系统提示"),
                             QString::fromLocal8Bit("创建程序对象失败！"));
    }
    enableControl=false;
}
QSTKEarth::~QSTKEarth()
{
    m_pRoot.Release();
    m_app.Release();
    ::CoUninitialize();
}
void QSTKEarth::NewScenario()
{
    Q_ASSERT(m_app!=NULL);
    STKXLib::IAgSTKXApplicationPtr pSTKXapp(m_app);
    pSTKXapp->ExecuteCommand("Unload / *");
    pSTKXapp->ExecuteCommand("New / Scenario ScenOne");
    enableControl=true;
}
void QSTKEarth::LoadScenario()//加载场景
{
    Q_ASSERT(m_pRoot!=NULL);
    m_pRoot->CloseScenario();
    m_pRoot->LoadScenario(_bstr_t("..\\data\\Scenario1.sc"));
    enableControl=true;
}
void QSTKEarth::PauseSTK()
{
    if(enableControl)
    {
        Q_ASSERT(m_app != NULL);
        STKXLib::IAgSTKXApplicationPtr pSTKXapp(m_app);
        pSTKXapp->ExecuteCommand("Animate * Pause");
        //    pSTKXapp->Pause();//也可以直接调用类成员函数
    }
}
void QSTKEarth::FasterSTK()
{
    if(enableControl)
    {
        Q_ASSERT(m_app != NULL);
        STKXLib::IAgSTKXApplicationPtr pSTKXapp(m_app);
        pSTKXapp->ExecuteCommand("Animate * Faster");
    }
}
void QSTKEarth::SlowerSTK()
{
    if(enableControl)
    {
        Q_ASSERT(m_app != NULL);
        STKXLib::IAgSTKXApplicationPtr pSTKXapp(m_app);
        pSTKXapp->ExecuteCommand("Animate * Slower");
    }
}
void QSTKEarth::ResetSTK()
{
    if(enableControl)
    {
        Q_ASSERT(m_pRoot != NULL);
        STKObjects::IAgAnimationPtr pAnimation( m_pRoot );
        pAnimation->Rewind();
    }
}
void QSTKEarth::UnloadStkScence()//卸载场景
{
    Q_ASSERT(m_app!=NULL);
    STKXLib::IAgSTKXApplicationPtr pSTKXapp(m_app);
    pSTKXapp->ExecuteCommand("UnloadMulti / */Satellite/*");
    pSTKXapp->ExecuteCommand("UnloadMulti / */Missile/*");
    pSTKXapp->ExecuteCommand("Unload / *");
    enableControl=false;
}
