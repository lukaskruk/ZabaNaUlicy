#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include "Zaba.h"
#include "Gra.h"
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>

Gra * gra;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gra = new Gra();
    gra->show();
    return a.exec();
}
