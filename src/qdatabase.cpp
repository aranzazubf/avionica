#include "qdatabase.h"
#include "../build/ui_qdatabase.h"

/*
 * Base de datos MySQL a la que esta conectada la aplicacion
 * */

/*
 * Inicialmente se añade la base de datos indicando el nombre del servidor, de
 * la base de datos asi como el usario y contraseña
 * Tambien se inicializacn los atributos la tabla de la base de datos y se conectan
 * los elementos del formulario con sus funciones correspondientes
 * */
QDataBase::QDataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDataBase),
    mPartner(0)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("arabar");
    db.setUserName("arabar");
    db.setPassword("arabar");
    initAttributes();
    initTable();
    refreshTable();
    connections();
}

QDataBase::~QDataBase()
{
    delete ui;
}

/*
 * Limpia los campos del formulario
 * */
void QDataBase::clearForm(){

    ui->data->clear();
    ui->comments->clear();
    ui->value->clear();
}
/*
 * Establece desde que pantalla se hace la llamada a esta para volver desde HOME
 * */
void QDataBase::setPartner(QWidget *partner){

    mPartner=partner;
}

/*
 * Vuelta a la pantalla inicial
 * */
void QDataBase::showHome(){
    mPartner->show();
    this->hide();
}


void QDataBase::initAttributes(){

    bool ok;
    int iddato;
    int id;
    QSqlQuery query;
    ok=db.open();
    if(ok){
      query.prepare("SELECT * FROM elementoCalculo");
      query.exec();
      if( query.last()){
        iddato=query.record().indexOf("id");
        id=query.value(iddato).toInt();
        idElemento=id;
        }
    }
   db.close();
}

void QDataBase::initTable(){


    QStringList header;
    header.append("Id");
    header.append("Dato");
    header.append("Valor");
    header.append("Commentarios");
    ui->elements->setHorizontalHeaderLabels(header);


}
/*
 * Actualiza los datos mostrados en la tabla del formulario con los datos
 * de la base de datos.
 * */
void QDataBase::refreshTable(){
   QSqlQuery query;
   QTableWidgetItem *item;
   Qt::ItemFlags flags;
    QString id,dato,valor,comentario;
   int count=0;
   int rows;
   int iddato;
   int idvalor;
   int idcoment;
   int ident;
   bool ok=db.open();
   if(ok){
     query.prepare("SELECT * FROM elementoCalculo");
     query.exec();
     rows=query.size();
     ui->elements->setRowCount(rows);
     if((query.size())>0){
       query.first();
       ident=query.record().indexOf("id");
       iddato=query.record().indexOf("dato");
       idvalor= query.record().indexOf("valor");
       idcoment=query.record().indexOf("comentarios");
       do{
        if(count<rows){
         id= query.value(ident).toString();
         dato = query.value(iddato).toString();
         valor= query.value(idvalor).toString();
         comentario= query.value(idcoment).toString();
         ui->elements->setItem(count, 0, new QTableWidgetItem(id));
         ui->elements->setItem(count, 1, new QTableWidgetItem(dato));
         ui->elements->setItem(count, 2, new QTableWidgetItem(valor));
         ui->elements->setItem(count, 3, new QTableWidgetItem(comentario));
         count++;
        }
       }while(query.next());
     }
    }
    db.close();
    for(int i=0;i<rows;i++){
       item= ui->elements->item(i,0);
       flags = item->flags();
       flags |= Qt::ItemIsSelectable;
       flags &= ~Qt::ItemIsEditable; // reset/clear the flag
       item->setFlags(flags);
    }
}




void QDataBase::connections(){

    connect(ui->add,SIGNAL(clicked()),this, SLOT(addElement()));
    connect(ui->delete_first, SIGNAL(clicked()),this,SLOT(deleteFirst()));
    connect(ui->delete_last, SIGNAL(clicked()),this,SLOT(deleteLast()));
    connect(ui->delete_sel, SIGNAL(clicked()),this,SLOT(deleteSel()));
    connect(ui->elements,SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(update(QTableWidgetItem*)));
    connect(ui->back_2, SIGNAL(clicked()), this, SLOT(showHome()));

}

/*
 * Añade un elemento a la tabla de la base de datos
 * Para ello recoge los datos del formulario y los transforma en el formato adecuado
 * diseñado en la base de datos
 * */
void QDataBase::addElement(){

    bool ok;
    bool valorok = false;
    const char *dato, *comentarios;
    double valor;
    QSqlQuery query;
    QString str1,str2,str3;
    QByteArray ba,ba3;

    idElemento++;

    str1=QString(ui->data->toPlainText());
    ba= str1.toUtf8();
    dato= ba.data();

    str2=QString(ui->value->toPlainText());
    valor= str2.toDouble(&valorok);

    str3=QString(ui->comments->toPlainText());
    ba3=str3.toUtf8();
    comentarios= ba3.data();

    ok=db.open();
    if(ok){
     query.prepare("INSERT INTO elementoCalculo (id, dato, valor, comentarios) "  "VALUES (?,?,?,?)");
     query.addBindValue(idElemento);
     query.addBindValue(dato);
     query.addBindValue(valor);
     query.addBindValue( comentarios);
     query.exec();
    }
    db.close();
   refreshTable();
   clearForm();

  }


/*
 * Actualiza los datos en la base de datos cuando son actualizados en la table
 * del formulario
 * */
void QDataBase::update(QTableWidgetItem* item){

    int row= item->row();
    int columns=4;
    int id=0;
    const char* dato;
    const char* coment;
    double value;
    bool ok;
    QAbstractItemModel* model;
    QModelIndex idx;
    QByteArray datoaux;
    QByteArray comentaux;
    model= ui->elements->model();
    idx=model->index(row,1);
    for(int i=0;i<columns;i++){
         switch(i){
         case 0:
            idx= model->index(row, i);
            id = model->data(idx).toInt();
            break;
         case 1:
            idx=model->index(row,i);
            datoaux=model->data(idx).toByteArray();
            dato=datoaux.data();
            break;
         case 2:
            idx=model->index(row,i);
            value=model->data(idx).toDouble();
            break;
         case 3:
            idx=model->index(row,i);
            comentaux=model->data(idx).toByteArray();
            coment=comentaux.data();
            break;
         default: break;
         }
     }

     ok=db.open();
     if(ok){
        QSqlQuery query;
        query.prepare("UPDATE elementoCalculo a SET a.dato = :dato, "
                      "a.valor= :valor, "
                      "a.comentarios=:comentarios "
                      "WHERE a.id = :id;");
         query.bindValue ( ":id",id);
         query.bindValue ( ":dato", dato);
         query.bindValue ( ":valor", value);
         query.bindValue ( ":comentarios", coment);
         if (!query.exec())QMessageBox::information(this,"", query.lastError().text());
     }
     db.close();
 }

/*
 * Elimina el primer elemento de la tabla
 * */
void QDataBase:: deleteFirst(){
   bool ok;
   int iddato;
   int id;
   QSqlQuery query;
   ok=db.open();
   if(ok){
     query.prepare("SELECT * FROM elementoCalculo");
     query.exec();
     query.first();
     iddato=query.record().indexOf("id");
     id=query.value(iddato).toInt();
     query.prepare("DELETE FROM elementoCalculo where id ='" + QString::number(id) + "'");
     query.exec();
   }
   db.close();
   refreshTable();
}

/*Elimina el ultimo elemento de la tabla
 *
 * */
void QDataBase::deleteLast(){
    bool ok;
    int iddato;
    int id;
    QSqlQuery query;

    ok=db.open();
       if(ok){
         query.prepare("SELECT * FROM elementoCalculo");
         query.exec();
         query.last();
         iddato=query.record().indexOf("id");
         id=query.value(iddato).toInt();
         query.prepare("DELETE FROM elementoCalculo where id ='" + QString::number(id) + "'");
         query.exec();
        }
    db.close();
    refreshTable();
}

/*Detecta los items seleccionados y los elimina de la base de datos
 *
 * */
void QDataBase::deleteSel(){
   bool ok;
   QSqlQuery query;
   int row,id;
   int columns=4;
   int rows;
   QList<QTableWidgetItem*> itemList = ui->elements->selectedItems();

   if (!itemList.isEmpty())
   {
       rows=itemList.count();
       for(int i=0; i<rows;i++){
        row = itemList.at(i)->row();
        QAbstractItemModel* model = ui->elements->model();
        QModelIndex idx = model->index(row, 0);
        id = model->data(idx).toInt();
        ok=db.open();
        if(ok){
         query.prepare("DELETE FROM elementoCalculo where id ='" + QString::number(id) + "'");
         query.exec();
        }
        i=i+columns;
       }
   }
   db.close();
   refreshTable();
}

