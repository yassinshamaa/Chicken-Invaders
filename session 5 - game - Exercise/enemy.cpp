#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>

Enemy::Enemy() : QGraphicsPixmapItem() {
        // *******  Setting the size of the enemy ********
    QPixmap pixmap2(":/new/prefix1/ship.png");
    QPixmap scaledPixmap = pixmap2.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(scaledPixmap);

        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

        // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    qDebug() << "inside constructor";

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    setPos(x(),y()+5);
        if(y()+100>800)
    {
        scene()->removeItem(this);
            delete this;
    }
}
