#ifndef {$UPPER_MODULE_NAME}DATA_H
#define {$UPPER_MODULE_NAME}DATA_H


class {$LOWER_MODULE_NAME}Data
{

public:

    /*
    * @说明：主数据类构造函数
    * @参数：无
    * @返回值：无
    */
    {$LOWER_MODULE_NAME}Data();

    /*
    * @说明：主数据类析构函数
    * @参数：无
    * @返回值：无
    */
    ~{$LOWER_MODULE_NAME}Data();

private:

    /*
    * @说明：初始化主数据
    * @参数：无
    * @返回值：无
    */
    void mInit{$LOWER_MODULE_NAME}Data(void);
};

#endif
