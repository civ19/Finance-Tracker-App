#ifndef FINANCETRACKER_H
#define FINANCETRACKER_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QtCharts/QPieSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE
namespace Ui {
class FinanceTracker;
}
QT_END_NAMESPACE

class FinanceTracker : public QMainWindow
{
    Q_OBJECT

public:
    FinanceTracker(QWidget *parent = nullptr);
    ~FinanceTracker();

private:
    Ui::FinanceTracker *ui;
};
#endif // FINANCETRACKER_H
