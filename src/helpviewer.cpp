#include "helpviewer.h"
#include "../build/ui_helpviewer.h"

/*
 * Clase estatica para mostrar un dialogo con informacion de configuracion
 * en la pantalla de reconstruccion
 * */
HelpViewer::HelpViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpViewer)
{
    ui->setupUi(this);
}

HelpViewer::~HelpViewer()
{
    delete ui;
}
