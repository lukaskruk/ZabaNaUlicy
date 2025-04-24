#include "Poziom.h"
#include <QFont>

Poziom::Poziom(QGraphicsItem * parent): QGraphicsTextItem(parent){
    poziom = 1;
    setPlainText(QString("Poziom: ")+ QString::number(poziom));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}
void Poziom::setPoziom(int newPoziom){
    poziom = newPoziom;
    setDefaultTextColor(Qt::blue);
    setPlainText(QString("Poziom: ") + QString::number(poziom));
}
void Poziom::increase()
{
    poziom++;
    setPlainText(QString("Poziom: ") + QString::number(poziom));
}

void Poziom::setPoziomRestart(){
    setDefaultTextColor(Qt::red);
    setPlainText(QString("Wcisnij przycisk aby rozpocząć od nowa"));
}

int Poziom::getPoziom()
{
    return poziom;
}


