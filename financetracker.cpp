#include "financetracker.h"
#include "ui_financetracker.h"
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QFontDatabase>
#include <QToolButton>
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QTimer>
#include <QLineEdit>
#include <QFormLayout>
#include <QMessageBox>
#include <QSpacerItem>

FinanceTracker::FinanceTracker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FinanceTracker)
{
    ui->setupUi(this);

    QWidget *topContainer = new QWidget(this); //container widget to hold the top bar
    topContainer->setMinimumHeight(120);
    topContainer->setStyleSheet(    //styling
        "background-color: hsl(230, 30%, 15%);"
        "border-top-left-radius: 20px;"
        "border-top-right-radius: 20px;"
    );

    QLabel *headertext = new QLabel(".civ19's Finance Tracker", topContainer); //text label inside the topcontainer
    QPixmap toplogo(":/images/images-removebg-preview.png"); //the logo image
    QLabel *logolabel = new QLabel(topContainer); //the parent is the top container since thats where we wanna add it
    logolabel->setPixmap(toplogo.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QLabel *welctext = new QLabel("Welcome back, User!", topContainer);

    welctext->setAlignment(Qt::AlignLeft);
    welctext->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QFont font3("Segoe UI", 9, QFont::DemiBold);
    QFont Varela("Verela Round",7,QFont::DemiBold);
    QFont Segoe2("Segoe UI",12,QFont::Bold);
    welctext->setFont(Segoe2);
    QLabel *welcsub = new QLabel("Intermediate level     1500XP", topContainer);
    welcsub->setStyleSheet("color: grey;");
    welcsub->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    headertext->setFont(Segoe2);
    headertext->setAlignment(Qt::AlignLeft|Qt::AlignTop);


    QVBoxLayout *introsent = new QVBoxLayout; //layout for the sentences
    introsent->addWidget(welctext);
    introsent->addWidget(welcsub);
    introsent->setContentsMargins(0,0,0,0);
    introsent->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    QHBoxLayout *introlayout = new QHBoxLayout; //layout for the icon and sentences
    introlayout->setAlignment(Qt::AlignLeft);
    introlayout->setSpacing(10);
    logolabel->setFixedSize(40,40);

    QHBoxLayout *ilayoutrow = new QHBoxLayout;
    ilayoutrow->addLayout(introlayout);

    introlayout->addWidget(logolabel,0,Qt::AlignVCenter);
    introlayout->addLayout(introsent);

    QVBoxLayout *toplayout = new QVBoxLayout; //box layout for the top bar widget
    toplayout->addWidget(headertext);
    toplayout->setAlignment(headertext, Qt::AlignTop|Qt::AlignLeft);
    toplayout->addLayout(ilayoutrow); //adding the introlayout to the actual topbar/layout

    toplayout->setContentsMargins(20,20,10,18);
    topContainer->setLayout(toplayout);

//box setup
    QWidget *box1 = new QWidget(this);
    box1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box1->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );
    box1->setMinimumSize(200,250);
    QWidget *box2 = new QWidget(this);
    box2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box2->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );

    QWidget *box3 = new QWidget(this);
    box3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box3->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );
    QWidget *box4 = new QWidget(this);
    box4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box4->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );
    QWidget *box5 = new QWidget(this);
    box5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box5->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );
    QWidget *box6 = new QWidget(this);
    box6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box6->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );

    QWidget *box7 = new QWidget(this);
    box7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    box7->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-radius: 20px;"
    );

// box1 styling

    //pie chart
    QChart *b1pie = new QChart();
    QChartView *chartview = new QChartView(b1pie, box1);
    QPieSeries *series = new QPieSeries();

    QPieSlice *wantsSlice = series->append("Wants", 400);
    QPieSlice *needsSlice = series->append("Needs", 300);
    QPieSlice *expensesSlice = series->append("Expenses", 1300);

    series->setLabelsVisible(true);
    wantsSlice->setLabel("Wants: 400");
    needsSlice->setLabel("Needs: 300");
    expensesSlice->setLabel("Expenses: 1300");
    series->setPieSize(0.7);

    b1pie->addSeries(series);
    b1pie->setBackgroundVisible(false);
    b1pie->setMargins(QMargins(0, 0, 0, 0));

    // Legend styling
    b1pie->legend()->setVisible(true);
    b1pie->legend()->setFont(font3);
    b1pie->legend()->setAlignment(Qt::AlignRight);
    b1pie->legend()->setLabelColor(Qt::white);

    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(200, 200);
    chartview->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Title + subtext
    QLabel *btext1 = new QLabel("Your spending for", box1);
    QLineEdit *month = new QLineEdit();
    month->setPlaceholderText("[Enter Month]");

    QFont font2("Segoe UI", 12, QFont::Bold);
    btext1->setFont(font2);
    month->setFont(font2);
    QFormLayout *b1form = new QFormLayout;
    b1form->addRow(btext1, month);
    QHBoxLayout *form1box = new QHBoxLayout;
    form1box->addStretch();
    form1box->addLayout(b1form);
    form1box->addStretch();

    QVBoxLayout *b1tlay = new QVBoxLayout;
    b1tlay->addLayout(form1box);
    b1tlay->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    b1tlay->setContentsMargins(0, 5, 0, 0);
    b1tlay->setSpacing(2);

    QVBoxLayout *box1main = new QVBoxLayout;
    box1main->setContentsMargins(20, 20, 20, 20);
    box1main->addLayout(b1tlay);
    box1main->addWidget(chartview);
    box1->setLayout(box1main);


//box 2 styling

    QLabel *b2title = new QLabel("Value Updates", box2);
    b2title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QLabel *b2sub = new QLabel("Enter your values here to update the finance tracker!", box2);
    b2sub->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QFont segoe("Segoe UI",12,QFont::Bold);
    QFont rubik("Rubik",8,QFont::Medium);
    b2title->setFont(segoe);
    b2sub->setFont(Varela);
    b2sub->setStyleSheet("color: grey");

    //line edits
    QLineEdit *wantsInput = new QLineEdit();
    wantsInput->setPlaceholderText("Total Wants");
    QLineEdit *needsInput = new QLineEdit();
    needsInput->setPlaceholderText("Total Needs");
    QLineEdit *expensesInput = new QLineEdit();
    expensesInput->setPlaceholderText("Total Expenses");
    QPushButton *updateChartBtn = new QPushButton("Update Chart");
    updateChartBtn->setMinimumHeight(20);
    updateChartBtn->setMinimumWidth(30);
    updateChartBtn->setStyleSheet("QPushButton {"
                        "background-color: hsl(220,50%,40%);"
                        "border-radius: 10px;"
                        "}"
                        "QPushButton::hover {"
                        "background-color: purple; "
                        "color:black; "
                        "border-radius:10px;"
                        "}"
                        );
    updateChartBtn->setFont(Varela);

    // Form layout
    QFormLayout *formLayout = new QFormLayout;

    formLayout->setContentsMargins(0,0,0,0);
    QSpacerItem *spacer1 = new QSpacerItem(0, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);
    formLayout->addItem(spacer1);
    formLayout->addRow("Wants:", wantsInput);
    QSpacerItem *spacer2 = new QSpacerItem(0, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);
    formLayout->addItem(spacer2);
    formLayout->addRow("Needs:", needsInput);
    QSpacerItem *spacer3 = new QSpacerItem(0, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *spacer4 = new QSpacerItem(0, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);
    formLayout->addItem(spacer3);
    formLayout->addRow("Expenses:", expensesInput);
    formLayout->addItem(spacer4);

    QHBoxLayout *formbox = new QHBoxLayout;
    formbox->setContentsMargins(0,0,0,0);
    formbox->addStretch();
    formbox->addLayout(formLayout);
    formbox->addStretch();


    // Final layout for box2
    QVBoxLayout *box2main = new QVBoxLayout;
    box2main->setContentsMargins(30,20,20,30);

    box2main->addWidget(b2title, 0, Qt::AlignHCenter);
    box2main->addWidget(b2sub, 0, Qt::AlignCenter);
    box2main->addLayout(formbox, Qt::AlignCenter);
    box2main->addWidget(updateChartBtn);
    box2main->setAlignment(Qt::AlignTop);
    box2main->addStretch();

    box2->setLayout(box2main);

    QObject::connect(updateChartBtn, &QPushButton::clicked, [=]() {
        bool ok1, ok2, ok3;
        double w = wantsInput->text().toDouble(&ok1); //convert the string(inputted in the line edit) to a number
        double n = needsInput->text().toDouble(&ok2);
        double e = expensesInput->text().toDouble(&ok3);

        if (ok1 && ok2 && ok3) {
            wantsSlice->setValue(w);
            needsSlice->setValue(n);
            expensesSlice->setValue(e);

            wantsSlice->setLabel(QString("Wants: %1").arg(w));
            needsSlice->setLabel(QString("Needs: %1").arg(n));
            expensesSlice->setLabel(QString("Expenses: %1").arg(e));
            welcsub->setText("Master level     2700XP");
        }
        else {
            QMessageBox::warning(box2, "Invalid Input", "Please enter valid numbers for all fields.");
        }
    });

//box 3 styling

    QLabel *b3title = new QLabel("Accounts", box3);
    b3title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    b3title->setFont(segoe);
    QFont Varela3("Verela Round",8,600);
    QPushButton *addbtn = new QPushButton("+ Add Account");
    addbtn->setMinimumHeight(20);
    addbtn->setStyleSheet("QPushButton {"
                        "color: grey;"
                        "}"
                        "QPushButton::hover {"
                        "background-color: white; "
                        "color:black; "
                        "border-radius:10px;"
                        "}"
                        );

    // Accounts list
    QLabel *bcheq = new QLabel("Chequing", box3);
    bcheq->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    bcheq->setFont(Varela3);
    QLabel *bsav = new QLabel("HISA", box3);
    bsav->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    bsav->setFont(Varela3);
    QLabel *bcred = new QLabel("Credit 1", box3);
    bcred->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    bcred->setFont(Varela3);

    bcheq->setMinimumHeight(15);
    bsav->setMinimumHeight(15);
    bcred->setMinimumHeight(15);

    QLineEdit *fcheq = new QLineEdit();
    fcheq->setPlaceholderText("Enter Balance");
    QLineEdit *fsav = new QLineEdit();
    fsav->setPlaceholderText("Enter Balance");
    QLineEdit *fcred = new QLineEdit();
    fcred->setPlaceholderText("Enter Balance");
    QSpacerItem *aspacer1 = new QSpacerItem(0,15,QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *aspacer2 = new QSpacerItem(0,15,QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *aspacer3 = new QSpacerItem(0,15,QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *aspacer4 = new QSpacerItem(0,15,QSizePolicy::Minimum, QSizePolicy::Expanding);

    QFormLayout *accform = new QFormLayout;
    accform->addItem(aspacer1);
    accform->addRow(bcheq, fcheq);
    accform->addItem(aspacer2);
    accform->addRow(bsav, fsav);
    accform->addItem(aspacer3);
    accform->addRow(bcred, fcred);
    accform->addItem(aspacer4);
    QHBoxLayout* formbox2 = new QHBoxLayout;
    formbox2->addStretch();
    formbox2->addLayout(accform);
    formbox2->addStretch();

    QVBoxLayout *box3main = new QVBoxLayout;
    box3main->setContentsMargins(20, 20, 20, 20);

    box3main->addWidget(b3title);
    box3main->setAlignment(b3title, Qt::AlignTop | Qt::AlignCenter);
    box3main->addLayout(formbox2);
    box3main->addWidget(addbtn, Qt::AlignCenter);

    box3->setLayout(box3main);

    QObject::connect(addbtn, &QPushButton::clicked, [=]() {
        QFormLayout *accform2 = new QFormLayout;
        QLineEdit *acc = new QLineEdit();
        acc->setPlaceholderText("Enter Account");
        acc->setFont(Varela3);
        QLineEdit *amt = new QLineEdit(); //the amount of money for the account
        amt->setPlaceholderText("Enter Balance");
        QSpacerItem *aspacer5 = new QSpacerItem(0,15,QSizePolicy::Minimum, QSizePolicy::Expanding);

        accform->addRow(acc,amt);
        accform->addItem(aspacer5);
        formbox2->addLayout(accform2);
    });

//box 4 styling

    QLabel *b4title = new QLabel("Income and Expenditures", box4);
    b4title->setFont(segoe);
    b4title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QLabel *b4sub = new QLabel("Track your income and expenses by week", box4);
    b4sub->setFont(Varela);
    b4sub->setStyleSheet("color:grey");
    b4sub->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    b4title->setAlignment(Qt::AlignHCenter);
    b4sub->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QFormLayout *form_in = new QFormLayout; //form for the income relationships
    form_in->setHorizontalSpacing(20);
    form_in->setAlignment(Qt::AlignLeft);

    QLineEdit *w1 = new QLineEdit();
    w1->setPlaceholderText("Income Total");
    QLineEdit *w2 = new QLineEdit();
    w2->setPlaceholderText("Income Total");
    QLineEdit *w3 = new QLineEdit();
    w3->setPlaceholderText("Income Total");
    QLineEdit *w4 = new QLineEdit();
    w4->setPlaceholderText("Income Total");

    form_in->addRow("Week 1",w1);
    form_in->addRow("Week 2",w2);
    form_in->addRow("Week 3",w3);
    form_in->addRow("Week 4",w4);

    QFormLayout *form_ex = new QFormLayout; //form for the expenditure relationships
    form_ex->setHorizontalSpacing(20);
    form_ex->setAlignment(Qt::AlignRight);

    QLineEdit *ww1 = new QLineEdit();
    ww1->setPlaceholderText("Expenditure Total");
    QLineEdit *ww2 = new QLineEdit();
    ww2->setPlaceholderText("Expenditure Total");
    QLineEdit *ww3 = new QLineEdit();
    ww3->setPlaceholderText("Expenditure Total");
    QLineEdit *ww4 = new QLineEdit();
    ww4->setPlaceholderText("Expenditure Total");

    form_ex->addRow("Week 1",ww1);
    form_ex->addRow("Week 2",ww2);
    form_ex->addRow("Week 3",ww3);
    form_ex->addRow("Week 4",ww4);

    //the body layout under the title
    QHBoxLayout *bodylayout = new QHBoxLayout;
    bodylayout->setContentsMargins(50,0,50,0);
    bodylayout->addLayout(form_in);
    bodylayout->addStretch();
    bodylayout->addLayout(form_ex);

    QVBoxLayout *box4main = new QVBoxLayout;
    box4main->setContentsMargins(20,20,20,20);
    box4main->addWidget(b4title);
    box4main->addWidget(b4sub);
    box4main->setSpacing(20);
    box4main->addLayout(bodylayout);
    box4main->addStretch();

    box4->setLayout(box4main);

//box 5 styling

    QLabel *b5title = new QLabel("Savings Goals", box5);
    b5title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    b5title->setAlignment(Qt::AlignHCenter);
    b5title->setFont(segoe);
    QLabel *b5sub = new QLabel("Future Treasures!", box5);
    b5sub->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    b5sub->setAlignment(Qt::AlignCenter);
    b5sub->setFont(Varela);
    b5sub->setStyleSheet("color: grey");

    QPushButton *addb = new QPushButton("+ Add Goal"); //push button
    addb->setMinimumHeight(20);
    addb->setStyleSheet("QPushButton {"
                        "color: grey;"
                        "}"
                        "QPushButton::hover {"
                        "background-color: white; "
                        "color:black; "
                        "border-radius:10px;"
                        "}"
                        );

    QFormLayout *listform = new QFormLayout;
    QHBoxLayout *listbox = new QHBoxLayout;
    listbox->addStretch();
    listbox->addLayout(listform);
    listbox->addStretch();

    QVBoxLayout *box5main = new QVBoxLayout;
    box5main->setContentsMargins(20,20,20,20);
    box5main->addWidget(b5title);
    box5main->addSpacing(10);
    box5main->addWidget(b5sub);
    box5main->addSpacing(10);
    box5main->addLayout(listbox);
    box5main->addWidget(addb, Qt::AlignHCenter);
    box5main->addStretch();

    box5->setLayout(box5main);

    QObject::connect(addb, &QPushButton::clicked, [=]() {
        QLineEdit *goal = new QLineEdit();
        QLineEdit *gcost = new QLineEdit();
        goal->setPlaceholderText("Enter Savings Goal");
        goal->setFont(Varela3);
        gcost->setPlaceholderText("Enter Price");
        listform->addRow(goal,gcost);
    });



//box 6 styling

    QLabel *b6title = new QLabel("Today's Transactions", box6);
    b6title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    b6title->setFont(segoe);

    QPushButton *add2 = new QPushButton("+ Add Transaction");
    add2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    add2->setMinimumHeight(20);
    add2->setStyleSheet("QPushButton {"
                        "color: grey;"
                        "}"
                        "QPushButton::hover {"
                        "background-color: white; "
                        "color:black; "
                        "border-radius:10px;"
                        "}"
                        );
    QFormLayout *translist = new QFormLayout;
    translist->setVerticalSpacing(2);
    QHBoxLayout *transbox = new QHBoxLayout;
    transbox->addStretch();
    transbox->addLayout(translist);
    transbox->addStretch();

    QVBoxLayout *box6main = new QVBoxLayout;
    box6main->setContentsMargins(20,20,10,20);
    b6title->setAlignment(Qt::AlignHCenter);
    box6main->addWidget(b6title);
    box6main->setSpacing(20);
    box6main->addLayout(transbox);
    box6main->addWidget(add2, Qt::AlignTop | Qt::AlignCenter);
    box6main->addStretch();
    box6->setLayout(box6main);

    QObject::connect(add2, &QPushButton::clicked, [=](){
        QFont Varela("Varela Round", 8, QFont::Medium);
        QLineEdit *trans = new QLineEdit;
        QLineEdit *cost = new QLineEdit;
        trans->setPlaceholderText("Enter Item/s");
        trans->setFont(Varela3);
        cost->setPlaceholderText("Enter Money Spent");
        cost->setFont(Varela);
        translist->setVerticalSpacing(5);
        translist->addRow(trans,cost);

    });



// box 7 styling

    QLabel *b7title = new QLabel("Upcoming Bills");
    QLabel *b7sub = new QLabel("Total Bills due for the next 30 days: ");

    QLineEdit *brent = new QLineEdit("Rent/Mortgage");
    brent->setPlaceholderText("Enter Bill");
    QLineEdit *nrent = new QLineEdit;
    nrent->setPlaceholderText("Enter Amount");
    QLineEdit *bgroceries = new QLineEdit();
    bgroceries->setPlaceholderText("Enter Bill");
    QLineEdit *ngroceries = new QLineEdit();
    ngroceries->setPlaceholderText("Enter Amount");
    QLineEdit *bphone = new QLineEdit();
    bphone->setPlaceholderText("Enter Bill");
    QLineEdit *nphone = new QLineEdit();
    nphone->setPlaceholderText("Enter Amount");
    QLineEdit *btrans = new QLineEdit();
    btrans->setPlaceholderText("Enter Bill");
    QLineEdit *ntrans = new QLineEdit();
    ntrans->setPlaceholderText("Enter Amount");
    QLineEdit *bins = new QLineEdit();
    bins->setPlaceholderText("Enter Bill");
    QLineEdit *nins = new QLineEdit();
    nins->setPlaceholderText("Enter Amount");

    b7title->setFont(segoe);
    b7sub->setStyleSheet("color:grey;");
    b7sub->setFont(Varela);
    b7title->setMaximumHeight(20);
    b7sub->setMaximumHeight(15);

    QVBoxLayout *box7main = new QVBoxLayout; // Main layout for box 7
    box7main->addWidget(b7title, 0, Qt::AlignHCenter);
    box7main->addWidget(b7sub, 0, Qt::AlignTop | Qt::AlignCenter);


    QPushButton *billbtn = new QPushButton("+ Add Bill"); //push button for addinbg more bills
    billbtn->setMinimumHeight(20);

    billbtn->setStyleSheet("QPushButton {"
                           "color: grey;"
                           "}"
                           "QPushButton::hover {"
                           "background-color: white; "
                           "color:black; "
                           "border-radius:10px;"
                           "}"
                           );

    box7main->setContentsMargins(20, 20, 20, 10);
    box7main->setSpacing(10);
    box7main->addStretch();                              // Add stretch to push button down
    box7main->addWidget(billbtn, 0, Qt::AlignBottom);
    int stretchIndex = box7main->count() - 2;            // Save where stretch is

    box7->setLayout(box7main);

    QObject::connect(billbtn, &QPushButton::clicked, [=]() {
        QLineEdit *bill = new QLineEdit();
        QLineEdit *cost = new QLineEdit();
        bill->setPlaceholderText("Enter Bill");
        cost->setPlaceholderText("Enter Cost");

        QHBoxLayout *rowlayout = new QHBoxLayout;
        QPushButton *markpaid = new QPushButton("Mark Paid");

        markpaid->setStyleSheet("QPushButton {"
                                "background-color: hsl(220,50%,40%);"
                                "border-radius: 10px;"
                                "}"
                                "QPushButton::hover {"
                                "background-color: purple; "
                                "color:black; "
                                "border-radius:10px;"
                                "}");
        markpaid->setMinimumHeight(20);
        markpaid->setMinimumWidth(80);
        markpaid->setFont(Varela);

        QObject::connect(markpaid, &QPushButton::clicked, [=]() {
            markpaid->setText(markpaid->text() == "Mark Paid" ? "Unmark Paid" : "Mark Paid");
        });

        rowlayout->addWidget(bill);
        rowlayout->addStretch();
        rowlayout->addWidget(cost);
        rowlayout->addSpacing(15);
        rowlayout->addWidget(markpaid);

        box7main->insertLayout(stretchIndex, rowlayout);
    });



//column layouts
    QVBoxLayout *col1 = new QVBoxLayout;
    col1->setAlignment(Qt::AlignLeft);
    col1->addWidget(box1);
    col1->addSpacing(10);
    col1->addWidget(box2);
    col1->addSpacing(10);

    QVBoxLayout *col2 = new QVBoxLayout;
    col2->setAlignment(Qt::AlignCenter);
    col2->addWidget(box3);
    col2->addSpacing(10);
    col2->addWidget(box4);
    col2->addSpacing(10);
    col2->addWidget(box5);
    col2->addSpacing(10);

    QVBoxLayout *col3 = new QVBoxLayout;
    col3->setAlignment(Qt::AlignRight);
    col3->addWidget(box6);
    col3->addSpacing(10);
    col3->addWidget(box7);

    QHBoxLayout *columns = new QHBoxLayout;
    columns->addSpacing(10);
    columns->addLayout(col1);
    columns->addSpacing(10);
    columns->addLayout(col2);
    columns->addSpacing(10);
    columns->addLayout(col3);

    //bottom menu bar
    QWidget *footer = new QWidget(this);
    footer->setMinimumHeight(50);
    footer->setStyleSheet(
        "background-color: hsl(230, 30%, 15%);"
        "border-bottom-left-radius: 20px;"
        "border-bottom-right-radius: 20px;"
        );

    QVBoxLayout *footbar = new QVBoxLayout(footer);
    QLabel *foottext = new QLabel("Make good financial decisions!", footer);
    foottext->setFont(Segoe2);
    foottext->setAlignment(Qt::AlignHCenter);
    footbar->setAlignment(Qt::AlignBottom);
    footbar->setContentsMargins(10,10,10,10);
    footbar->addWidget(foottext);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(topContainer);
    mainlayout->addSpacing(10);
    mainlayout->addLayout(columns);

    mainlayout->addWidget(footer);   // Footer now stays at the bottom

    QWidget *central = new QWidget(this);
    central->setContentsMargins(0, 0, 0, 0);
    central->setLayout(mainlayout);

    this->setWindowTitle("Finance Tracker");
    this->setMinimumSize(980,800);
    this->setCentralWidget(central);
    this->setStyleSheet("background-color: hsl(230, 30%, 5%)");


}

FinanceTracker::~FinanceTracker()
{
    delete ui;
}
