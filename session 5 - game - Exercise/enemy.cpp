#include "enemy.h"
#include "player.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <health.h>
#include <QMediaPlayer>
#include <QAudioOutput>


Enemy::Enemy() : QGraphicsPixmapItem() {
        // *******  Setting the size of the enemy ********
    QPixmap pixmap2(":/new/prefix1/chicky.png");
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


void Enemy::move() {
    setPos(x(), y() + 5);

    if (y() + pixmap().height() > 600) {
        scene()->removeItem(this);
        emit enemyBottom();


        delete this;
        return;
    }


}
