#ifndef QDATABASE_H
#define QDATABASE_H

#include <QWidget>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <QApplication>
#include <QtSql/QSqlRecord>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QtSql/QSqlError>
namespace Ui {
class QDataBase;
}

class QDataBase : public QWidget
{
    Q_OBJECT

public:
    explicit QDataBase(QWidget *parent = 0);
    ~QDataBase();
    void connections();
    void refreshTable();
    void initTable();
    void initAttributes();
    void clearForm();

private:
    int idmax=0;
   int idElemento=-1;
    Ui::QDataBase *ui;
     QSqlDatabase db;
private slots:
   void addElement();
   void deleteFirst();
   void deleteLast();
   void deleteSel();
   void updateTable();
   void update(QTableWidgetItem* );

};

#endif // QDATABASE_H
