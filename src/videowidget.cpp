#include "videowidget.h"
#include "../build/ui_videowidget.h"
#include <QMediaPlayer>
#include <QVideoWidget>
static const QString VideoStr = QString("http://video.webmfiles.org/elephants-dream.webm");
VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::VideoWidget),
     mPartner(0)
{
    ui->setupUi(this);
    container = new QWidget(this);



    player = new QMediaPlayer();
    video = new QVideoWidget(container);

//player->setMedia(QMediaContent(QUrl(VideoStr)));
player->setVideoOutput(video);
//player->play();
connectSignals(true);

}
void VideoWidget::showHome(){

   // player->setMuted(true);

    mPartner->show();


    this->hide();
}
void VideoWidget::shootScreen(){
      originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
      saveScreenshot();
}
void VideoWidget::saveScreenshot(){
    //Viewer* v;
    QString format = "png";

       QString initialPath = QDir::currentPath() + tr("/untitled.") + format;

//QString fileName = QFileDialog::getSaveFileName(this, tr ("Save As"),
             //                                   "/home/",
               //                                 tr ("(*.png)"));

QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                           initialPath,
                           tr("%1 Files (*.%2);;All Files (*)")
                           .arg(QString(format.toUpper()))
                           .arg(QString(format)));

       if (!fileName.isEmpty())
           originalPixmap.save(fileName, format.toLatin1());


}
void VideoWidget::setPartner(QWidget *partner){

    mPartner=partner;



}
VideoWidget::~VideoWidget()
{
    delete ui;
}

void VideoWidget::resizeEvent(QResizeEvent *)
{
    container->setGeometry(0, 0, width(), height() - 50);
    video->setGeometry(0, 0, container->width(), container->height());
}
void VideoWidget::play(){

if(ui->url->toPlainText()=="")std::cout<<"lala"<<std::endl;

else{
    player->setMedia(QMediaContent(QUrl(QString(ui->url->toPlainText()))));
player->play();
}
}

void VideoWidget::mute(){
if(!player->isMuted())
    player->setMuted(true);
else{
    player->setMuted(false);
player->setVolume(ui->volume->value());
}}
void VideoWidget::volume(int value){
player->setVolume(value);
}
void  VideoWidget::showFullScreen(){
    if(this->isFullScreen()) {
        //viewer_->setFullScreen(false);
        this->setWindowState(Qt::WindowMaximized);
    }
    else{
        this->setWindowState(Qt::WindowFullScreen);
        //viewer_->setFullScreen 	( 	true	);
    }

}
void VideoWidget::connectSignals(bool establish)
{
    if (establish)
    {
        connect(ui->play, SIGNAL(clicked()), this, SLOT(play()), Qt::UniqueConnection);
           connect(ui->home, SIGNAL(clicked()), this, SLOT(showHome()));
            connect(ui->screenshot, SIGNAL(clicked()), this, SLOT(shootScreen()));
            connect(ui->fullscreen, SIGNAL(clicked()), this, SLOT(showFullScreen()));
            connect(ui->mute, SIGNAL(clicked()),this, SLOT(mute()));
                    connect(ui->volume, SIGNAL(valueChanged(int)), this ,SLOT(volume(int)));
    }
    else
    {
        disconnect(ui->play, SIGNAL(clicked()), this, SLOT(play()));
        disconnect(ui->home, SIGNAL(clicked()), this, SLOT(showHome()));
         disconnect(ui->screenshot, SIGNAL(clicked()), this, SLOT(shootScreen()));
         disconnect(ui->fullscreen, SIGNAL(clicked()), this, SLOT(showFullScreen()));
           disconnect(ui->mute, SIGNAL(clicked()),this, SLOT(mute()));
                   disconnect(ui->volume, SIGNAL(valueChanged(int)), this ,SLOT(volume(int)));

        }
}
