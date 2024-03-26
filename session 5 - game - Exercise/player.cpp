#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QApplication>



Player::Player() : QGraphicsPixmapItem() {
    QPixmap pixmap1(":/new/prefix1/ship.png");
    setPixmap(pixmap1);
    Score = 0;
    healthCount = 3;

    QAudioOutput* SoundOutput = new QAudioOutput();
    SoundOutput->setVolume(100);
    bulletsound = new QMediaPlayer();
    bulletsound->setAudioOutput(SoundOutput);
    bulletsound->setSource(QUrl("qrc:/new/prefix1/bulletsound2.mp3"));



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


        Bullet* bullet = new Bullet();
        bullet->setPos(x() + 30, y());
        scene()->addItem(bullet);

        if(bulletsound->playbackState() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }else{
            bulletsound->play();

        }

        connect(bullet, &Bullet::enemyHit, this, [this](){
            ++Score;
            emit scoreChanged(Score);
        });

    }


}


void Player::decrementHealth() {
    --healthCount;
    if (healthCount == 0) {
        QApplication::exit();
    }
    emit healthChanged(healthCount);
}


 // CreateEnemy function used to create the eneimes
void Player::createEnemy() {
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
    QObject::connect(enemy, &Enemy::enemyBottom, this, &Player::decrementHealth);

}


