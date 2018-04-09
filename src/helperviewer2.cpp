#include "helperviewer2.h"
#include "../build/ui_helperviewer2.h"

/*
 * Clase estatica para mostrar un dialogo con informacion de configuracion
 * en la pantalla de laboratorio
 * */

HelperViewer2::HelperViewer2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelperViewer2)
{
    ui->setupUi(this);
}

HelperViewer2::~HelperViewer2()
{
    delete ui;
}
