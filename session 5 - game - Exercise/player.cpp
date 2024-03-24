#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"

int Player::Score = 0;
Player::Player() : QGraphicsPixmapItem() {
    QPixmap pixmap1(":/new/prefix1/ship.png");
    setPixmap(pixmap1);
    Player::score = new QGraphicsTextItem;
    Player::score->setFont(QFont("times", 16));
    Player::score->setDefaultTextColor(Qt::white);
    Player::score->setPlainText("Score: " + QString::number(Score));
    Player::score->setPos(700, 10);

}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  scene()->addItem(enemy);

}
void Player::updateScoreDisplay() {
    Player::Score++;
    Player::score->setPlainText("Score: " + QString::number(Player::Score));
}

