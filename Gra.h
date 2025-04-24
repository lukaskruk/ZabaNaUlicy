#ifndef GRA_H
#define GRA_H
#include <QGraphicsView>
#include "Zaba.h"
#include "Poziom.h"

class Gra: public QGraphicsView{

public:
    Gra(QWidget * parent=0);

    QGraphicsScene * scene;
    Zaba * zaba;
    Poziom * poziom;
};

#endif // GRA_H
