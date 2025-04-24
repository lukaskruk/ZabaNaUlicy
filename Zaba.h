#ifndef ZABA_H
#define ZABA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Poziom.h"



class Zaba: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    bool isDead;
    bool czekaNaRestart;
public:
    Zaba(Poziom *poziomPointer=nullptr);
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    Poziom *poziom;
public:
    void die();
public:
    void restart();
};

#endif // Zaba_H
