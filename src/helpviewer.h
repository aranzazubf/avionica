#ifndef HELPVIEWER_H
#define HELPVIEWER_H
#include "common_includes.h"

namespace Ui {
class HelpViewer;
}

class HelpViewer : public QDialog
{
    Q_OBJECT

public:
    explicit HelpViewer(QWidget *parent = 0);
    ~HelpViewer();

private:
    Ui::HelpViewer *ui;
};

#endif // HELPVIEWER_H
