#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QString>
#include "journallist.h"
#include <QHeaderView>
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <QMessageBox>


void MainWindow::yearValue(QString yearValue)
{
    QDate dateToday = QDate::currentDate();
    int year = dateToday.year();
    year -= 10;
    int l = year;
    l += 5;
    if(yearValue.toInt()<year)
    {
        for(int k = 0;k < m_model->columnCount();k++)
        {
              m_model->item(m_model->rowCount()-1,k)->setData(QBrush(Qt::red),Qt::BackgroundRole);
        }
    }
    else if(yearValue.toInt()<l)
    {
        for(int k = 0;k < m_model->columnCount();k++)
        {
              m_model->item(m_model->rowCount()-1,k)->setData(QBrush(Qt::green),Qt::BackgroundRole);
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //No date later than the currrent date can be entered QRegExp rx1("[A-Za-z\\s\\-]+");
    QDate dateToday = QDate::currentDate();
    ui->spinBox_Year->setMaximum(dateToday.year());

    //Checking if the user entered valid input
    QRegExp rx1("30\\-(04|06|09|11)\\-20[0-1][0-9]");
    QValidator *validator1 = new QRegExpValidator(rx1, this);
    ui->lineEdit_Author->setValidator(validator1);
    QRegExp rx2("[A-Za-z\\s]+[\\s]+[\\d]+[\\s]+[A-Za-z\\s]+");
    QValidator *validator2 = new QRegExpValidator(rx2, this);
    ui->lineEdit_Title->setValidator(validator2);
    QRegExp rx3("[A-Za-z\\s]+[\\s]+[\\d]+[\\s]+[A-Za-z\\s]+");
    QValidator *validator3 = new QRegExpValidator(rx3, this);
    ui->lineEdit_Journal->setValidator(validator3);
    QRegExp rx4("[0-9]+[\\-]+[0-9]+");
    QValidator *validator4 = new QRegExpValidator(rx4, this);
    ui->lineEdit_Pages->setValidator(validator4);


    m_model = new QStandardItemModel(this);
    m_model->setHeaderData(0,Qt::Horizontal,QString("Author"),Qt::DisplayRole);
    m_model->setHeaderData(1,Qt::Horizontal,QString("Year"),Qt::DisplayRole);
    m_model->setHeaderData(2,Qt::Horizontal,QString("Title"),Qt::DisplayRole);
    m_model->setHeaderData(3,Qt::Horizontal,QString("Journal"),Qt::DisplayRole);
    m_model->setHeaderData(4,Qt::Horizontal,QString("Volume"),Qt::DisplayRole);
    m_model->setHeaderData(5,Qt::Horizontal,QString("Issue"),Qt::DisplayRole);
    m_model->setHeaderData(6,Qt::Horizontal,QString("Pages"),Qt::DisplayRole);
    QStringList list;
    list.append("Author");
    list.append("Year");
    list.append("Title");
    list.append("Journal");
    list.append("Volume");
    list.append("Issue");
    list.append("Pages");
    m_model->setHorizontalHeaderLabels(list);
    list.pop_back();
    ui->comboBox_Filter->addItems(list);

    //Able to sort the table according to the headers of the table
    ui->tableView->setModel(m_model);
    ui->tableView->setSortingEnabled(true);
    //Load the tables with some preloaded data
    QString preload1,preload2,preload3,preload4,preload5,preload6,preload7;
    preload1 = "RJ Nkomo-Smythe";
    preload2 = "1983";
    preload3 = "Journal of the Ages";
    preload4 = "National Geographic";
    preload5 = "4";
    preload6 = "6";
    preload7 = "12-23";
    items.append(new QStandardItem(preload1));
    items.append(new QStandardItem(preload2));
    items.append(new QStandardItem(preload3));
    items.append(new QStandardItem(preload4));
    items.append(new QStandardItem(preload5));
    items.append(new QStandardItem(preload6));
    items.append(new QStandardItem(preload7));
    m_model->appendRow(items);
    yearValue(preload2);
    items.clear();
    preload1 = "JJ Jacobs";
    preload2 = "2013";
    preload3 = "South African";
    preload4 = "Journal of science";
    preload5 = "48";
    preload6 = "112";
    preload7 = "56-72";
    items.append(new QStandardItem(preload1));
    items.append(new QStandardItem(preload2));
    items.append(new QStandardItem(preload3));
    items.append(new QStandardItem(preload4));
    items.append(new QStandardItem(preload5));
    items.append(new QStandardItem(preload6));
    items.append(new QStandardItem(preload7));
    m_model->appendRow(items);
    yearValue(preload2);
    items.clear();
    preload1 = "JJ Bravo";
    preload2 = "2019";
    preload3 = "South African";
    preload4 = "Fire and Flame";
    preload5 = "23";
    preload6 = "152";
    preload7 = "60-70";
    items.append(new QStandardItem(preload1));
    items.append(new QStandardItem(preload2));
    items.append(new QStandardItem(preload3));
    items.append(new QStandardItem(preload4));
    items.append(new QStandardItem(preload5));
    items.append(new QStandardItem(preload6));
    items.append(new QStandardItem(preload7));
    m_model->appendRow(items);
    yearValue(preload2);




}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_buttonRest_clicked()
{

}



void MainWindow::on_pushButton_Add_clicked()
{
    items.clear();
    QString temp1,temp2,temp3;
    temp1 = QString::number(ui->spinBox_Year->value());
    temp2 = QString::number(ui->spinBox_Volume->value());
    temp3 = QString::number(ui->spinBox_Issue->value());
    items.append(new QStandardItem(ui->lineEdit_Author->text()));
    items.append(new QStandardItem(temp1));
    items.append(new QStandardItem(ui->lineEdit_Title->text()));
    items.append(new QStandardItem(ui->lineEdit_Journal->text()));
    items.append(new QStandardItem(temp2));
    items.append(new QStandardItem(temp3));
    items.append(new QStandardItem(ui->lineEdit_Pages->text()));
    m_model->appendRow(items);
    ui->lineEdit_Author->clear();
    ui->spinBox_Year->clear();
    ui->spinBox_Issue->clear();
    ui->spinBox_Volume->clear();
    ui->lineEdit_Pages->clear();
    ui->lineEdit_Title->clear();
    ui->lineEdit_Journal->clear();
    //Check to see the reference
    QDate dateToday = QDate::currentDate();
    int year = dateToday.year();
    year -= 10;
    int l = year;
    l += 5;

    if(ui->spinBox_Year->value()<year)
    {
        for(int k = 0;k < m_model->columnCount();k++)
        {
              m_model->item(m_model->rowCount()-1,k)->setData(QBrush(Qt::red),Qt::BackgroundRole);
        }
    }
    else if(ui->spinBox_Year->value()<l)
    {
        for(int k = 0;k < m_model->columnCount();k++)
        {
              m_model->item(m_model->rowCount()-1,k)->setData(QBrush(Qt::green),Qt::BackgroundRole);
        }
    }

}

void MainWindow::on_pushButton_Remove_clicked()
{
    QModelIndex index =  ui->tableView->currentIndex();

    m_model->removeRow(index.row());

}

void MainWindow::on_pushButton_Find_clicked()
{
    QString findName = ui->lineEdit_Filter->text().trimmed();
    QAbstractItemModel *modl = m_model;
    QSortFilterProxyModel proxy;
    proxy.setSourceModel(modl);
    int k = ui->comboBox_Filter->currentIndex();
    proxy.setFilterKeyColumn(k);





    proxy.setFilterFixedString(findName);
    // now the proxy only contains rows that match the name
    // let's take the first one and map it to the original model
    QModelIndex matchingIndex = proxy.mapToSource(proxy.index(0,0));
    if(matchingIndex.isValid()){
            ui->tableView->scrollTo(matchingIndex,QAbstractItemView::EnsureVisible);
            //Testing code:


            for(int i = 0; i < items.count(); i++)
            {
                if(matchingIndex.row()!=i)
                    ui->tableView->hideRow(i);
            }


            QString columnAndRow = "Match Found! Row: ";
            int r = matchingIndex.row();
            columnAndRow.append(QString::number(r));
            columnAndRow.append(" || Column: ");
            int c = matchingIndex.column();
            columnAndRow.append(QString::number(c));

            QMessageBox::information(this,"Name Search:",columnAndRow);
        } else {
        QString columnAndRow = "Match not found!Row: ";
        int r = matchingIndex.row();
        columnAndRow.append(QString::number(r));
        columnAndRow.append(" || Column: ");
        int c = matchingIndex.column();
        columnAndRow.append(QString::number(c));
            QMessageBox::information(this,"Name Search:", columnAndRow);
        }

}



void MainWindow::on_pushButton_Reset_clicked()
{
    for(int i = 0; i < m_model->rowCount(); i++)
    {
                ui->tableView->showRow(i);

    }
}
