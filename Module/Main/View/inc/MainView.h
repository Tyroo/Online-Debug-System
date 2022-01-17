#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QFile>
#include <QMainWindow>
#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalPercentBarSeries>
#include <QtCharts/QValueAxis>


#include "ui_MainView.h"
#include "./Module/Main/Data/inc/MainData.h"

#define MAIN_QSS_FILEPATH   ((char*)":/QSS/Main/MainView.qss")   // QSS文件路径


class MainView : public QMainWindow
{
    Q_OBJECT

public:

    MainData* data = nullptr;
    Ui::MainView* ui = nullptr;

    QHBoxLayout hb;

    /*
    * @说明：主视图类构造函数
    * @参数：parent，父Qwidget对象，主视图默认为NULL
    * @返回值：无
    */
    MainView(QWidget *parent = nullptr);

    /*
    * @说明：主视图类析构函数
    * @参数：无
    * @返回值：无
    */
    ~MainView();

private:

    /*
    * @说明：加载控件UI和QSS样式
    * @参数：qssPath，自定义样式表文件的路径（.qss）
    * @返回值：无
    */
    void fAddStyleAndUi(char qssPath[]);

};
#endif // MAINVIEW_H
