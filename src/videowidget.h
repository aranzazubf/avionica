#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include <QPixmap>
#include <iostream>
#include <QFileDialog>
namespace Ui {
class VideoWidget;
}

class QVideoWidget;
class QMediaPlayer;

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = 0);
    void setPartner(QWidget* partner);
    void saveScreenshot();
    ~VideoWidget();
protected:
    void resizeEvent(QResizeEvent *);
     QPixmap originalPixmap;
private slots:

    void play();
    void shootScreen();

    void mute();
    void volume(int value);
    void showHome();
    void showFullScreen();
private :
       void connectSignals(bool establish);
private:
    Ui::VideoWidget *ui;
    QMediaPlayer *player;
    QVideoWidget *video;
    QWidget *container;
 QWidget * mPartner;
};

#endif // VIDEOWIDGET_H
