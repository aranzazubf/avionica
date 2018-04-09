#include "videowidget.h"
#include "../build/ui_videowidget.h"

/*
 *Esta clase se encarga de reproducir el video alojado en un servidor, que supuestamente
 * se correspondera con el video que esta grabando el dron en tiempo real
 * Permite subir, bajar o quitar el volumen, hacer captiras de pantalla y ver a pantalla completa.
 * Desde aqui podremos volver a la pantalla principal median el boton HOME
*/


/* Al Constructor le pasamos como parametros iniciales el formulario de esta clase e
 * inicializamos el objeto Widget mPartner que indicará a donde tiene que volver la
 * aplicacion al pulsar el boton home, (este atributo es modificado desde la clase
 * mainwindow al pulsar el boton de video)
 * Inicializamos los atributos QWidget, QMediaPlayer y VideoWidget para establecer
 * el widget principal de este formulario como contenedor del video y asignarle al flujo
 * del video desde donde sera visualizado(setVideoOutput)
 * En el constructor tambien conectamos las señales de los elementos del formulario con
 * sus slots
 * */
VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget),
    mPartner(0)
{
    ui->setupUi(this);
    container = new QWidget(this);
    player = new QMediaPlayer();
    video = new QVideoWidget(container);

    player->setVideoOutput(video);
    connectSignals(true);

}

/*Cuando un widget cambia su tamaño se llama a este evento que si no se instancia no pasa nada
 * en este caso para que el widget no quedara de un tamaño 1x1 modificamos este evento y cuando
 * se muestra el video se modifica el tamaño del contenedor del videowidget y de este ultimo.
 */
void VideoWidget::resizeEvent(QResizeEvent *){

    container->setGeometry(0, 0, width(), height() - 50);
    video->setGeometry(0, 0, container->width(), container->height());
}

/*Conectamos cada boton con su slot correspondiente, en este caso conectamos solo si se trata de una conexion estable,
 * esto se debe a que si hay algun error no se van a llevar a cabo las conexiones, evitando errores de ejecucion
 * en los otros casos no se ha hecho asi y si hay algun error se interrumpira la aplicación, es simplemente por mejorar
 * el tema de bugs y asi pero vendria siendo lo mismo
 * */
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

/* Este metodo lo usamos para indicar que se ha llamado a esta clase desde otra, en este caso
 * desde la clase principal, y se usa para luego poder volver a ella con el boton showHome
 *
 */
void VideoWidget::setPartner(QWidget *partner){

    mPartner=partner;
}

/*Vuelta a la pantalla principal
 */
void VideoWidget::showHome(){

    mPartner->show();
    this->hide();
}

/* Se comprueba que se haya introducido algo en el campo de url, aqui lo mas
 * normal seria que si la url no es valida o no se introduce nada saltara un dialogo para indicarlo
 * Si la url es valida se añade al contenido de MediaPlayer y se reproduce
 */
void VideoWidget::play(){

    if(ui->url->toPlainText()=="")std::cout<<"Introduce una url valida"<<std::endl;
    else{
        player->setMedia(QMediaContent(QUrl(QString(ui->url->toPlainText()))));
        player->play();
    }
}


/* Se quita el volumen o se reestablece
 */
void VideoWidget::mute(){

    if(!player->isMuted())player->setMuted(true);
    else{
        player->setMuted(false);
        player->setVolume(ui->volume->value());
    }
}

/*
 Se modifica el volumen en funcion de la barra horizontal del formulario
*/
void VideoWidget::volume(int value){

    player->setVolume(value);
}
/*Hace una captura dela pantalla actual indicada por winId y la guarda*/
void VideoWidget::shootScreen(){

    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    saveScreenshot();
}

/* Crea el directorio inicial que aparecerá para guardar la imagen
 * con el nombre determinado, que se puede cambiar
*/
void VideoWidget::saveScreenshot(){

    QString format = "png";
    QString initialPath = QDir::currentPath() + tr("/untitled.") + format;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath,
                           tr("%1 Files (*.%2);;All Files (*)")
                           .arg(QString(format.toUpper()))
                           .arg(QString(format)));
    if (!fileName.isEmpty())originalPixmap.save(fileName, format.toLatin1());


}

/*Cambia de pantalla completa a maximizada*/
void  VideoWidget::showFullScreen(){

    if(this->isFullScreen())this->setWindowState(Qt::WindowMaximized);
    else(this->setWindowState(Qt::WindowFullScreen));

}

VideoWidget::~VideoWidget(){

    delete ui;
}





