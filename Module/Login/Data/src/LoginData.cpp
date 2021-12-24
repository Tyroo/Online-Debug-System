#include "./Module/Login/Data/inc/LoginData.h"


/*------------------------------------------------------------
@作用：主数据类默认方法
@包含：LoginData()、~LoginData()
--------------------------------------------------------------*/

// 主数据类构造方法
LoginData::LoginData()
{
    this->username = "zjl";
    this->password = "123";
}

// 主数据类析构方法
LoginData::~LoginData()
{
    // pass
}

/*------------------------------------------------------------
@作用：主数据类自定义方法
@包含：mInitLoginData()
--------------------------------------------------------------*/

// 初始化主数据
void LoginData::mInitLoginData()
{
    // pass
}

// 获取登录用户名
QString& LoginData::mGetUsername()
{
    return (this->username);
}

// 获取登录密码
QString& LoginData::mGetPassword()
{
    return (this->password);
}
