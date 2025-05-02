#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QCheckBox"
#include "QLineEdit"
#include "QColor"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->verticalLayout->layout());

    QHBoxLayout* horizontal_layout = new QHBoxLayout();

    QCheckBox* new_check = new QCheckBox("CheckBox");
    horizontal_layout->addWidget(new_check);

    QLineEdit* new_line = new QLineEdit();
    horizontal_layout->addWidget(new_line);

    QPushButton* del_button = new QPushButton("x");
    horizontal_layout->addWidget(del_button);

    del_button->setStyleSheet("background-color: red; color: black;");
    new_check->setStyleSheet("QCheckBox::indicator {color: green;}");

    layout->insertLayout(1, horizontal_layout);

    mButtonToLayoutMap.insert(del_button, horizontal_layout);

    QObject::connect(
        del_button, &QPushButton::clicked,
        this, &MainWindow::onRemoveWidget);
}


void MainWindow::onRemoveWidget()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* layout = mButtonToLayoutMap.take(button);

    while (layout->count() != 0) {
        QLayoutItem* item = layout->takeAt(0);
        delete item->widget();
        delete item;
    }
    delete layout;
}

