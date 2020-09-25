#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //distribution vars
    double maxY, minY, maxX, minX;
    int dataPoints, numCategories;
    QString currentDistribution;
    QVector<qreal>* distributionVals;

    //barchart variables
    QBarSet* barSet;
    QBarSeries *series;
    QChart *chart;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis * axisY;
    QChartView *chartView;

    //constructor and destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //main slot to change the bar chart
    void on_radioButton_clicked();

private:
    //functions to update
    Ui::MainWindow *ui;
    void getMaxMinQVector(double &max, double &min, QVector<qreal> *inputV);
    QVector<qreal>* createData(int num, QString theType);
    void loadDataIntoChart();
    void updateChart(QString distributionType);

};
#endif // MAINWINDOW_H
