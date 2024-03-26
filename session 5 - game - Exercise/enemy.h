#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <player.h>
#include<QMediaPlayer>

class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
public:
    Enemy();

signals:
    void enemyBottom();

public slots:
    void move();

};

#endif // ENEMY_H
