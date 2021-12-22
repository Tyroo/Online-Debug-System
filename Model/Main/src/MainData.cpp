#include "./Model/Main/inc/MainData.h"
#include <Qt>


/*------------------------------------------------------------
@作用：主数据类默认方法
@包含：MainData()、~MainData()
--------------------------------------------------------------*/

// 主数据类构造方法
MainData::MainData()
{
    this->ui = new Ui::MainView;    // 创建主视图UI对象

    this->login_view = new LoginView;   // 创建登录视图对象
    this->login_view->setWindowFlag(Qt::FramelessWindowHint);
    this->login_view->setAttribute(Qt::WA_TranslucentBackground, true);
}

// 主数据类析构方法
MainData::~MainData()
{
    // pass
}

/*------------------------------------------------------------
@作用：主数据类自定义方法
@包含：mInitMainData()
--------------------------------------------------------------*/

// 初始化主数据
void MainData::mInitMainData()
{
    // pass
}
