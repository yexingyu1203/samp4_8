#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LabFileName =new QLabel("");
    ui->statusbar->addWidget(LabFileName);
    this->setCentralWidget(ui->scrollArea);
    initTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTree()
{
    QString dataStr="";
   ui->treeWidget->clear();
   QTreeWidgetItem *item=new QTreeWidgetItem(MainWindow::itTopItem);
   item->setText(MainWindow::colItem,"图片文件");   //第一列的文字
   item->setText(MainWindow::colItemType,"type=itTopItem");     //第二列
   item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsAutoTristate);
   item->setCheckState(colItem,Qt::Checked);

   item->setData(MainWindow::colItem,Qt::UserRole,QVariant(dataStr));
   ui->treeWidget->addTopLevelItem(item);   //添加顶层节点
}
