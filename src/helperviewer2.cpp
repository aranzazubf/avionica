#include "helperviewer2.h"
#include "ui_helperviewer2.h"

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
