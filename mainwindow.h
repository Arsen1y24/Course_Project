#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "movingcar.h"
#include "sprite.h"
#include "graphme.h"
#include "imagehouse.h"
#include "markerimage.h"
#include "clipsimage.h"
#include "spritegoblin.h"
#include "donemessage.h"
#include "bush.h"
#include "flowerbush.h"
#include "tree.h"
#include "pocket.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //virtual void hideEvent(QHideEvent *event);
    ~MainWindow();

private slots:
    void updScene();
    void on_pushButton_3_clicked();
    void addGoblinOnScene();
    void slotDelClips();
    void slotDelMarker();
    void slotMessageMarker();
    void closeMessage();
    void drawPic();
    void clearPic();
    void getMyPosition(int xPosition, int yPosition);
    void getGobPosition(int xGobPosition, int yGobPosition, int directionGob);

signals:
    void startCarMovingFirst();
    void startCarMovingSecond();
    void signalGoblinNotices(int xDistance);
private:
    int xMyPos = 100;
    int yMyPos = 100;
    int xGobPos = 0;
    int yGobPos = 0;
    int dirGob = 1;
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer* timerRelations;
    QPainter *paint;
    QGraphicsScene* scene;
    QPixmap* pixmapHouse;
    Sprite* spriteGuy;
    SpriteGoblin* goblin;
    MovingCar* myCar;
    GraphMe* gr;
    ImageHouse* iHouse;
    MarkerImage* markerOnScene;
    ClipsImage* clipsOnScene;
    QPixmap* clipsDone;
    DoneMessage* myMessage;
    PicDrawing* picDraw;
    FlowerBush* fBush;
    Bush* bush;
    Tree* tree;
    Pocket* pocketClips;
    Pocket* pocketMarker;
    //HousePic* hPic;
    void drawScene();
    void checkRelations();

    // QWidget interface
// protected:
//     virtual void hideEvent(QHideEvent *event);

//     // QWidget interface
// protected:
//     virtual void resizeEvent(QResizeEvent *event);

    // QObject interface
public:
 //   virtual bool event(QEvent *event);
};
#endif // MAINWINDOW_H
