#ifndef MARKERIMAGE_H
#define MARKERIMAGE_H

#include <QObject>
#include "MyHeaders.h"

class MarkerImage : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MarkerImage(QObject *parent = nullptr);

signals:
    void clickOnMarker();
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   // void canBeTaken();
    void markerInTheBag();
    void slotHideMarker();
    void slotShowMarker();

private:
    QPixmap* markerImage;
    QPixmap pixMark;
    bool visible;
    int xSize;
    int xPos;
    int yPos;
 //   bool canTakeMarker;

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MARKERIMAGE_H
