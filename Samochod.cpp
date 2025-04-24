#include "Samochod.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Samochod::Samochod(Zaba *player, int predkosc): QObject(), QGraphicsPixmapItem()
{
    speed = predkosc;
    zaba = player;
    setPixmap(QPixmap("C:/Users/lukas/Downloads/samochod.png"));
    setScale(1.0);
    //Ustawienie timera
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Samochod::move()
{
    QList<QGraphicsItem *> kolidujace = collidingItems();
    for(int i =0, n = kolidujace.size(); i<n; i++){
        if(typeid(* (kolidujace[i]))==typeid(Zaba)){
            zaba->die();
        }
    }
    //Przemieszczenie Samochod w bok
    setPos(x()-speed,y());
    if(pos().x() + (pixmap().width())/2< 0){
        scene()->removeItem(this);
        delete this;
    }
}
