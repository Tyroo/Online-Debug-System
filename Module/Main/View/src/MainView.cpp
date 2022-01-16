#include "./Module/Main/View/inc/MainView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：MainView()、~MainView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    data = new MainData;                       // 新建主数据对象
    ui = new Ui::MainView;                     // 新建主视图对象

    this->fAddStyleAndUi(MAIN_QSS_FILEPATH);   // 添加样式文件和UI文件

    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Sam");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;
//![1]

//![2]
    QBarSeries *barseries = new QBarSeries();
    barseries->append(set0);
    barseries->append(set1);
    barseries->append(set2);
    barseries->append(set3);
    barseries->append(set4);
//![2]

//![8]
    QLineSeries *lineseries = new QLineSeries();
    lineseries->setName("trend");
    lineseries->append(QPoint(0, 4));
    lineseries->append(QPoint(1, 15));
    lineseries->append(QPoint(2, 20));
    lineseries->append(QPoint(3, 4));
    lineseries->append(QPoint(4, 12));
    lineseries->append(QPoint(5, 17));
//![8]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(barseries);
    chart->addSeries(lineseries);
    chart->setTitle("Line and barchart example");
//![3]

//![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    lineseries->attachAxis(axisX);
    barseries->attachAxis(axisX);
    axisX->setRange(QString("Jan"), QString("Jun"));

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    lineseries->attachAxis(axisY);
    barseries->attachAxis(axisY);
    axisY->setRange(0, 20);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView* chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);

//![7]
    QHBoxLayout* hb = new QHBoxLayout(this->ui->widget_2);
    hb->addWidget(chartView);


    QBarSet *set5 = new QBarSet("Jane");
    QBarSet *set6 = new QBarSet("John");
    QBarSet *set7 = new QBarSet("Axel");
    QBarSet *set8 = new QBarSet("Mary");
    QBarSet *set9 = new QBarSet("Samantha");

    *set5 << 1 << 2 << 3 << 4 << 5 << 6;
    *set6 << 5 << 0 << 0 << 4 << 0 << 7;
    *set7 << 3 << 5 << 8 << 13 << 8 << 5;
    *set8 << 5 << 6 << 7 << 3 << 4 << 5;
    *set9 << 9 << 7 << 5 << 3 << 1 << 2;
//![1]

//![2]
    QHorizontalPercentBarSeries *series = new QHorizontalPercentBarSeries();
    series->append(set5);
    series->append(set6);
    series->append(set7);
    series->append(set8);
    series->append(set9);

//![2]

//![3]
    QChart *chart_1 = new QChart();
    chart_1->addSeries(series);
    chart_1->setTitle("Simple horizontal percent barchart example");
    chart_1->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories_1;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axisY_1 = new QBarCategoryAxis();
    axisY_1->append(categories_1);
    chart_1->addAxis(axisY_1, Qt::AlignLeft);
    series->attachAxis(axisY_1);
    QValueAxis *axisX_1 = new QValueAxis();
    chart_1->addAxis(axisX_1, Qt::AlignBottom);
    series->attachAxis(axisX_1);
//![4]

//![5]
    chart_1->legend()->setVisible(true);
    chart_1->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView_1 = new QChartView(chart_1);
    chartView_1->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout* hb_1 = new QHBoxLayout(this->ui->widget);
    hb_1->addWidget(chartView_1);

}

// 主视图类析构方法，销毁主视图对象
MainView::~MainView()
{
    delete (this->ui);
    delete (this->data);
    delete (this->login_ui);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void MainView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    this->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}
