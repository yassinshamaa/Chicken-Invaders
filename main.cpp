



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
    QGraphicsTextItem * score = new QGraphicsTextItem;
    score-> setFont(QFont("times", 16));
    score-> setDefaultTextColor(Qt::white);
    score->setPlainText("Score: " + QString::number(Player::Score));
    score -> setPos(700, 10);
    Scene->addItem(score);




    // *******  Create the Player ********
    Player * player = new Player;
    player -> setPos(view -> width()/2, view -> height() - player -> pixmap().height());
    Scene->addItem(player);

    Health* h1 = new Health[3];
    h1[0].setPos(500, 30);
    h1[1].setPos(600, 30);
    h1[2].setPos(700, 30);
    for(int i = 0 ; i<3; i++){
    Scene->addItem(&h1[i]);
    }



   /* QGraphicsTextItem * healthc = new QGraphicsTextItem;
    healthc-> setFont(QFont("times", 16));
    healthc-> setDefaultTextColor(Qt::white);
    healthc->setPlainText("Health: " + QString::number(player->HealthCount));
    healthc -> setPos(100, 10);
    Scene->addItem(healthc);
*/



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
