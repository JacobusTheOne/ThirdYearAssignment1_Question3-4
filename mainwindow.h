#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void yearValue(QString yearValue);

private slots:

    void on_buttonRest_clicked();


    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_pushButton_Find_clicked();


    void on_pushButton_Reset_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *m_model;
    QList<QStandardItem*> items;
};
#endif // MAINWINDOW_H
