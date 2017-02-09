#ifndef HELPERVIEWER2_H
#define HELPERVIEWER2_H

#include <QDialog>

namespace Ui {
class HelperViewer2;
}

class HelperViewer2 : public QDialog
{
    Q_OBJECT

public:
    explicit HelperViewer2(QWidget *parent = 0);
    ~HelperViewer2();

private:
    Ui::HelperViewer2 *ui;
};

#endif // HELPERVIEWER2_H
