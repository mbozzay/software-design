#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * Function: MainWindow
 * Purpose: This function initializes the MainWindow class and all of the QTComponents
 * Inputs: None
 * Outputs: None
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //initialize the UI and set the correct layout
    ui->setupUi(this);
    ui->centralwidget->setLayout(new QVBoxLayout);

    //set up the distributions
    numCategories = 20;
    dataPoints = 10000;
    currentDistribution = "nor";
    distributionVals = new QVector<qreal>();
    distributionVals = this->createData(dataPoints, currentDistribution);

    //update the QtChart with the correct data
    this->updateChart(currentDistribution);
}


/*
 * This function (createData) was provided by Dr. Creed Jones from Virginia Tech
 * Function: createData
 * Purpose: This function creates a QVector of a distribution category
 *          distributions could be Gamma, Uniform, or Normal.
 * Inputs:
 *          num (int): the number of points to add to the QVector
 *          theType (QString): the type of distribution to create
 * Output:
 *          return (QVector<qreal>): the output vector containing num points
*/
QVector<qreal>* MainWindow::createData(int num, QString theType){
    QVector<qreal> *dat = new QVector<qreal>;
    std::default_random_engine generator;
    // the distribution type is determined by string input
    if (theType.contains("uni"))
    {
        std::uniform_real_distribution<double> distribution(0, 99.9999);
        // params are arbitrarily chosen
        for (int incr = 0; incr < num; incr++)
            dat->push_front(distribution(generator));
    }
    else if (theType.contains("oth"))
    {
        std::gamma_distribution<double> distribution(5.0, 2.5);
        // params are arbitrarily chosen
        for (int incr = 0; incr < num; incr++)
            dat->push_front(distribution(generator));
    }
    else // default behavior is the normal distribution
    {
        std::normal_distribution<double> distribution(10.0, 2.0);
        // params are arbitrarily chosen
        for (int incr = 0; incr < num; incr++)
            dat->push_front(distribution(generator));
    }
    return dat;
}

/*
 * Function: getMaxMinQVector
 * Purpose: This function retrieves the maximum and minimum values from an input QVector.
 *          It uses the greedy algorithm to accomplish this.
 * Inputs:
 *          inputV (QVector<qreal>): the search vector
 * Output:
 *          max (double): the highest value in the input vector
 *          min (double): the lowest values in the input vector
*/
void MainWindow::getMaxMinQVector(double &max, double &min, QVector<qreal> *inputV){
    //use the greedy algorithm to fetch the highest and lowest values from the list
    auto lowest = inputV->at(0);
    auto highest = inputV->at(0);

    //iterate through one time
    for (int i = 0; i < inputV->size(); ++i) {
        if (inputV->at(i) < lowest)
            lowest = inputV->at(i);

        if (inputV->at(i) > highest)
            highest = inputV->at(i);
    }

    //set the return values
    max = highest;
    min = lowest;
}
/*
 * Function: loadDataIntoChart
 * Purpose: This function generates the chart data
 * Inputs: None
 * Output: None
*/
void MainWindow::loadDataIntoChart(){
    //split the input vector into 20 sections:
    QVector<qreal> categoryList(numCategories,0);
    QVector<qreal> distributionCopy = *distributionVals;

    //set the step values
    double increment = (maxX-minX)/numCategories;
    double threshold = minX+increment/2;

    //wipe the axis so we can redraw it
    axisX->clear();
    categories = QStringList();

    //For each "bin" go ahead and figure out how many values fit within the threshold range
    for (int i = 0; i < numCategories; ++i) {
        QVector<qreal> distributionSwap;
        QString valueAsString = QString::number(increment*(i + 1));
        categories << valueAsString;

        for(int j =0; j < distributionCopy.size(); ++j){
            if(distributionCopy.at(j) < (threshold+increment/2))
                categoryList[i] = categoryList[i] + 1;
            else
                distributionSwap.push_back(distributionCopy.at(j));
        }
        distributionCopy = distributionSwap;
        threshold += increment;
    }

    //redraw the axis values
    axisX->append(categories);
    chart->removeAllSeries();

    barSet = new QBarSet("Data");
    for(int x=0; x < categoryList.size(); ++x)
        *barSet << categoryList.at(x);

    //set the Y ranges
    double lowest, highest;
    getMaxMinQVector(lowest, highest, &categoryList);
    axisY->setRange(lowest,highest);

    series = new QBarSeries();
    series->append(barSet);
    chart->addSeries(series);


}

/*
 * Function: on_radioButton_clicked
 * Purpose: This function runs whenever a radiobutton is pressed.
 *          It updates the input graphs with the selected radio button option
 * Inputs: None
 * Output: None
*/
void MainWindow::on_radioButton_clicked(){
    //get the name of the button that was pressed
    QObject* obj = sender();
    QString objName = obj->objectName();
    QString subString = objName.left(3);
    this->updateChart(subString);
}
/*
 * Function: updateChart
 * Purpose: This function updates the entire QtChart with the appropriate values.
 * Inputs:
 *          distributionType (QString): a 3-character string representing the type of chart to generate
 * Output: None
*/
void MainWindow::updateChart(QString distributionType){
    //Generate a normal distribution
    barSet = new QBarSet("Data");
    series = new QBarSeries();
    chart = new QChart();

    //set the title and add some adorable animation
    chart->setTitle("Sample Data Distribution");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //create new x/y axis
    axisX = new QBarCategoryAxis();
    axisY = new QValueAxis();

    //set the new y axis labels
    distributionVals = this->createData(dataPoints, distributionType);
    this->getMaxMinQVector(maxX, minX, distributionVals);
    this->loadDataIntoChart();

    //set the categories and rotate the axis
    axisX->append(categories);
    axisX->setLabelsAngle(-90);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    //add to the chart and render.
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->distributionChart->setChart(chart);

}

MainWindow::~MainWindow()
{
    delete ui;
}

