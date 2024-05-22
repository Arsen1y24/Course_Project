#ifndef SPRITEGOBLIN_H
#define SPRITEGOBLIN_H

#include <QObject>
#include "MyHeaders.h"

class SpriteGoblin : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit SpriteGoblin(QObject *parent = nullptr);

signals:
    void updateScene();
    void signalSeePic();
    void deletePic();
    void signalShareGoblinPosition(int xGobPosition, int yGobPosition, int directionGob);
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void nextFrame();
    void nextRockFrame();
    void nextBedFrame();
    void clipsSetReady();
    void drawingSetReady();
    void goToEat(int xDistance);
private:
    bool cntCurFrame = true;
    bool startsGoing = true;
    bool didntSleep = true;
    bool clipsAreOnBed = false;
    bool drawingIsDone = false;
    bool up = true;
    bool flies = true;
    int direction = 1; // 1 - right, 0 - stays, -1 - left
    int addToYGoblinSprite = 0;
    int currentFrame;
    int currentPosition;
    int iterator;
    int dix = 0, diy = 0, ix = 0, iy = 0;
    int xPos;
    int yPos;
    int oX = 0;
    int dCurFrame = 0;
    int cntLaughs = 0;
    int numberOfThrows = 0;
    int cntTimesReactedDrawing = 0;
    QPixmap* spriteGoblinImage;
    QTimer* spriteGoblinTimer;
    QTimer* timerRock;
    QTimer* timerBed;
    QTimer* timerClipsReaction;
    QTimer* laughTimer;
    QTimer* timerDrawing;
    QVector<QPoint> vecPlaces;
    QVector<int> vecGoblinWay;
    void funcForWindow();
    void throwRock();
    void execRock();    
    void goToBed();
    void execBed();
    void stopSleeping();
    void lieForTime();
    void execClips();
    void clipsReactionNextFrame();
    void staysIn_4();
    void goblinLaughs();
    void nextLaughFrame();
    void startGoingFrom_4();
    void reactionOnDrawing();
    void execDrawingReaction();
    void nextDrawReactFrame();
};

#endif // SPRITEGOBLIN_H
