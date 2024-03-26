#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <enemy.h>
#include<QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);

    int Score = 0;
    int healthCount = 3;

    QMediaPlayer* bulletsound;

signals:
    void scoreChanged(int newScore);
    void healthChanged(int newHealth);

public slots:
    void createEnemy();
    void decrementHealth();
};

#endif // PLAYER_H
