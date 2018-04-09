#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include  "common_includes.h"
namespace Ui {
class VideoWidget;
}

class QVideoWidget;
class QMediaPlayer;

class VideoWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::VideoWidget *ui;
    QMediaPlayer *player;
    QVideoWidget *video;
    QWidget *container;
    QWidget * mPartner;
    QPixmap originalPixmap;

public:    
    explicit VideoWidget(QWidget *parent = 0);
    void setPartner(QWidget* partner);

    ~VideoWidget();

private :
    void saveScreenshot();
    void connectSignals(bool establish);
    void resizeEvent(QResizeEvent *);

private slots:
    void showHome();
    void play();
    void mute();
    void volume(int value);
    void shootScreen();
    void showFullScreen();


};

#endif // VIDEOWIDGET_H
