#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(tr("Hello world!"));
    connect(ui->action_About, &QAction::triggered, this,
            &QApplication::aboutQt);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::showMsg);
    connect(ui->action_Quit, &QAction::triggered, this, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMsg()
{
    QMessageBox::warning(this, tr("Translate"), tr("Hello world!"));
}

