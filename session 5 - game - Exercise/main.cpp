
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView *view =new QGraphicsView();
    view->setFixedSize(800, 600);

    // ******* Create the Scene ********
    QGraphicsScene *Scene = new QGraphicsScene();
    Scene->setSceneRect(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // *******  Create the Player ********
    Player * player = new Player;
    player -> setRect(0, 0, 100, 100);
    player -> setPos(view -> width()/2, view -> height() - player -> rect().height());
    Scene->addItem(player);
    // *******  Setting the foucs to the Player ********
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();
    view->setScene(Scene);
    view->show();
    // *******  Adjust the location of the Player (middle of the screen) ********


   // *******   Assign scene to the view   ***************


    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

    return a.exec();
}