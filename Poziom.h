#ifndef POZIOM_H
#define POZIOM_H
#include <QGraphicstextItem>

class Poziom: public QGraphicsTextItem{
public:
    Poziom(QGraphicsItem * parent=0);
    void increase();
    int getPoziom();
    void setPoziom(int poziom);
    void setPoziomRestart();
private:
    int poziom;
};

#endif // POZIOM_H
