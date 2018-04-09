#ifndef QDATABASE_H
#define QDATABASE_H
#include "common_includes.h"
namespace Ui {
class QDataBase;
}

class QDataBase : public QWidget
{
    Q_OBJECT

public:
    explicit QDataBase(QWidget *parent = 0);
    ~QDataBase();

    void setPartner(QWidget* widget);

private:
   int idmax=0;
   int idElemento=-1;
   Ui::QDataBase *ui;
   QSqlDatabase db;
   QWidget* mPartner;
private:
      void connections();
      void refreshTable();
      void initTable();
      void initAttributes();
      void clearForm();
private slots:
   void addElement();
   void deleteFirst();
   void deleteLast();
   void deleteSel();
   void update(QTableWidgetItem* );
   void showHome();

};

#endif // QDATABASE_H
