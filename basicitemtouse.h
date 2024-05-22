#ifndef BASICITEMTOUSE_H
#define BASICITEMTOUSE_H

#include <QObject>
#include "MyHeaders.h"

class BasicItemToUse : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit BasicItemToUse(QObject *parent = nullptr);

signals:

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BASICITEMTOUSE_H

//  !! !!!  !! ! !! !! * *( ( ) _ _ __ _ __ _ ) ) ) ) )) 000 0 0 0 0 AAAAAAAAAAAAAAAAAKKKK   K K K KK
// мб запихнуть его куда-нибудь как абстрактный
