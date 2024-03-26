#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <enemy.h>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);

    static int Score;
    int HealthCount;


public slots:
    void createEnemy();
    void decrementHealth(){
        HealthCount--;
    }





};

#endif // PLAYER_H
