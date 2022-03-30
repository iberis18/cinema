#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "genredelegate.h"
#include "linedelegate.h"
#include "editmoviedialog.h"
#include "dialogdelegate.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);

    GenreDelegate* fdel = new GenreDelegate();
    lineDelegate* ldel = new lineDelegate();
    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,fdel);
    tableView->setItemDelegateForColumn(3,ldel);
    tableView->setItemDelegateForColumn(4,ldel);
    tableView->setItemDelegateForColumn(5,ldel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);

      //tableView->setItemDelegate(ddel);

    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Add row");
    QPushButton* pb2 = new QPushButton("Delete row");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);

    //tableView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditMovieDialog* addDialog = new EditMovieDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Movie* std = new Movie(addDialog->id(),addDialog->name(),addDialog->genre(), addDialog->releaseYear(), addDialog->producer(), addDialog->age(), this);
        myModel->AddMovie(std);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteMovie(selList.row());
}

