#include "financetracker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FinanceTracker w;
    w.show();
    return a.exec();
}
