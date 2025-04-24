#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include "Zaba.h"
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include "Gra.h"
#include <QWidget>


Gra::Gra(QWidget * parent)
{
    const int WYS_SCENY = 700;
    const int SZER_SCENY = 500;
    //Towrzenie sceny
    scene = new QGraphicsScene();
    //Stworzenie napisau Poziom
    poziom = new Poziom();

    //Towrzenie obiektu i dodanie go do sceny
    zaba = new Zaba(poziom);
    //zaba->setRect(0,0,50,50);
    //zaba->setBrush(Qt::black);
    QTransform transformTrawa;
    QTransform transformDroga;
    transformTrawa.scale(1.0, 0.7);
    transformDroga.scale(1.0, 1.1);
    QGraphicsPixmapItem * trawa = new QGraphicsPixmapItem(QPixmap("C:/Users/lukas/Downloads/trawa.png"));
     QGraphicsPixmapItem * trawa1 = new QGraphicsPixmapItem(QPixmap("C:/Users/lukas/Downloads/trawa.png"));
    trawa->setTransform(transformTrawa);
    trawa1->setTransform(transformTrawa);
    QGraphicsPixmapItem * droga = new QGraphicsPixmapItem(QPixmap("C:/Users/lukas/Downloads/droga.png"));
    QGraphicsPixmapItem * droga1 = new QGraphicsPixmapItem(QPixmap("C:/Users/lukas/Downloads/droga.png"));
    droga->setTransform(transformDroga);
    scene->addItem(droga);
    droga1->setTransform(transformDroga);
    scene->addItem(droga1);
    scene->addItem(trawa);
    scene->addItem(trawa1);
    scene->addItem(zaba);
    scene->addItem(poziom);
    //ustawienie kolejnosci wyswietlania elementow
    droga->setZValue(0);
    droga1->setZValue(0);
    trawa->setZValue(1);
    trawa1->setZValue(1);
    zaba->setZValue(2);
    //Ustawienie obiektu jako focusowalnego
    zaba->setFlag(QGraphicsItem::ItemIsFocusable);
    zaba->setFocus();


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("background-color: white;");
    setFixedSize(SZER_SCENY,WYS_SCENY);
    scene->setSceneRect(0,0,SZER_SCENY,WYS_SCENY);
    setScene(scene);

    //Ustawienie obiektu po srodku sceny na samym dole
    droga->setPos(0,height()-droga->pixmap().height()-4);
    droga1->setPos(0,height()-droga->pixmap().height()-355);
    zaba->setPos(width()/2,height()-zaba->pixmap().height()/2);
    trawa->setPos((width()-trawa->pixmap().width())/2,height()-trawa->pixmap().height()/2+59);
    trawa1->setPos(0,height()-droga->pixmap().height()-45);

    //Pomoc do ustawienia wszystkiego równo
    /*for (int i = 1; i < 14; ++i) {
        QGraphicsLineItem* line = new QGraphicsLineItem(0, i * 50, 500, i * 50);
        line->setPen(QPen(Qt::gray));
        scene->addItem(line);
    }*/
    //Tworz wrogow
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),zaba,SLOT(spawn()));
    timer->start(2000);
    show();
}
