#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void updateScoreDisplay();
public:
    void keyPressEvent(QKeyEvent * event);
    static int Score;
    static QGraphicsTextItem* score;
public slots:
    void createEnemy();
};

#endif // PLAYER_H
