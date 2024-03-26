#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "enemy.h"
#include"health.h"
#include <health.h>
#include <enemy.h>
#include <QMediaPlayer>
#include <QAudioOutput>


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

    Player * player = new Player;
    player -> setPos(view -> width()/2, view -> height() - player -> pixmap().height());
    Scene->addItem(player);

    QGraphicsTextItem *score = new QGraphicsTextItem;
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(Qt::white);
    score->setPlainText("Score: 0"); // Initialize with 0 score
    score->setPos(700, 10);
    Scene->addItem(score);

    QObject::connect(player, &Player::scoreChanged, [score](int newScore) {
       score->setPlainText("Score: " + QString::number(newScore));
    });

    QGraphicsTextItem *healthx = new QGraphicsTextItem;
    healthx->setFont(QFont("times", 16));
    healthx->setDefaultTextColor(Qt::white);
    healthx->setPlainText("Health: 3"); // Initialize with 0 score
    healthx->setPos(700, 40);
    Scene->addItem(healthx);

    QObject::connect(player, &Player::healthChanged, [healthx](int newHealth) {
        healthx->setPlainText("Health: " + QString::number(newHealth));
    });

\



    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);



    // *******  Setting the foucs to the Player ********
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();
    view->setScene(Scene);
    view->show();
    // *******  Adjust the location of the Player (middle of the screen) ********






    return a.exec();
}
