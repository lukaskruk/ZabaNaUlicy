#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Zaba.h"

class Samochod: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    int speed;
public:
    Samochod(Zaba *player, int predkosc = 5);
public slots:
    void move();
private:
    Zaba *zaba;
    int predkosc;
};

#endif // SAMOCHOD_H
