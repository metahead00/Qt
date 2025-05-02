#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void logMessage(const QString &message);

private slots:
    void on_buttonStartServer_clicked();

    void on_buttonStopServer_clicked();

    void on_buttonMessage_clicked();

private:
    Ui::MainWindow *ui;
    Server* server;
};
#endif // MAINWINDOW_H
