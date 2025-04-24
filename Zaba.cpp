#include "Zaba.h"
#include <QKeyEvent>
#include "Samochod.h"
#include <QGraphicsScene>
#include <QDebug>

Zaba::Zaba(Poziom* poziomPointer){
    isDead = false;
    czekaNaRestart = false;
    poziom = poziomPointer;
    setPixmap(QPixmap("C:/Users/lukas/Downloads/zaba.png"));
    setScale(0.5);
}


void Zaba::keyPressEvent(QKeyEvent *event)
{
    const int rozmiar= 50;
    if (czekaNaRestart) {
        restart();
        return;
    }

    //Jesli zaba dead to wychodzimy
    if (isDead) return;

    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-rozmiar,y());
        }

    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+rozmiar < 500){
            setPos(x()+rozmiar,y());
        }

    }
    else if(event->key() == Qt::Key_Up){
        if(pos().y() > 0){
            setPos(x(),y()-rozmiar);
        }
        if (pos().y() <= 0 && poziom) {
            poziom->increase();
            // Reset frog to bottom center
            setPos(scene()->width()/2 - pixmap().width()/2, scene()->height() - pixmap().height()/2);
            qDebug()<<"BRAWO kolejny level";
        }

    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y()+rozmiar < 700){
            setPos(x(),y()+rozmiar);
        }
    }


}
void Zaba::spawn(){
    int level = poziom->getPoziom();
    int speed = 5;
    int carsToSpawn = 1;
    int wysokoscLinii = 50;
    int iloscLinii = 14;
    if(level<=14){
        carsToSpawn = 1 + level;
    }else{
        carsToSpawn = 8;
    }

    for (int i = 0; i < carsToSpawn; ++i) {
        speed = 5 + rand() % level;
        Samochod * samochod = new Samochod(this,speed);

        QVector<int> validLanes;
        for (int i = 0; i < iloscLinii; ++i) {
            if (i != 13 && i != 6) {
                validLanes.append(i);
            }
        }

        int lane = validLanes[rand() % validLanes.size()];
        qDebug() << "Spawned car in lane:" << lane;
        //int lane= rand()%(iloscLinii-1);
        int laneY= lane*wysokoscLinii+(wysokoscLinii-samochod->pixmap().height()) / 2;;

        samochod->setPos(500, laneY);
        scene()->addItem(samochod);
    }
}
void Zaba::die() {
    isDead = true;
    czekaNaRestart = true;
    poziom->setPoziomRestart();
    setPixmap(QPixmap("C:/Users/lukas/Downloads/zabaDead.png"));
}
void Zaba::restart(){
    isDead= false;
    czekaNaRestart=false;
    //reset spritea na zyjacy
    setPixmap(QPixmap("C:/Users/lukas/Downloads/zaba.png"));
    //Reset pozycji
    setPos(scene()->width()/2 - pixmap().width()/2,
           scene()->height() - pixmap().height()/2);
    //ustaw jako zfocusowany obiekt
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    //zresetuj Poziom wyswietlany
    poziom->setPoziom(1);

}
