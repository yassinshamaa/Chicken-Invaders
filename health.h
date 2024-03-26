#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <enemy.h>

class Health : public QGraphicsPixmapItem, public QObject{
public:


    Health(QGraphicsItem* parent = nullptr) : QGraphicsPixmapItem(parent) {
    QPixmap pixmap4(":/new/prefix1/heart_icon.png");
    QPixmap scaledPixmap = pixmap4.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(scaledPixmap);
    }

};







#endif // HEALTH_H
