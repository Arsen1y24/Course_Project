#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 1600, 900, this);
    ui->graphicsView->resize(1930, 930);
    ui -> graphicsView -> setScene(scene);
    drawScene();
    markerOnScene = new MarkerImage();
    scene->addItem(markerOnScene);
    clipsOnScene = new ClipsImage;
    scene->addItem(clipsOnScene);
    spriteGuy = new Sprite();
    scene->addItem(spriteGuy);
    gr = new GraphMe();
    scene->addItem(gr);

    myCar = new MovingCar();
    myCar->setZValue(10);
    scene -> addItem(myCar);

    connect(myCar, &MovingCar::updateScene, this, &MainWindow::updScene);
    connect(this, &MainWindow::startCarMovingFirst, myCar, &MovingCar::moveFirstSlot);
    connect(myCar, &MovingCar::addGoblin, this, &MainWindow::addGoblinOnScene);

    connect(spriteGuy, &Sprite::updateScene, this, &MainWindow::updScene);
    connect(iHouse, &ImageHouse::goToRoom, spriteGuy, &Sprite::guyGoMakeVec);
    connect(spriteGuy, &Sprite::findWaySignal, gr, &GraphMe::vecFromTo);
    connect(gr, &GraphMe::shareVecToGo, spriteGuy, &Sprite::getVecToGo);
    connect(spriteGuy, &Sprite::signalIsInRoom_3, iHouse, &ImageHouse::isInRoom_3);

    connect(iHouse, &ImageHouse::signalTakeClips, clipsOnScene, &ClipsImage::clipsInTheBag);
    connect(iHouse, &ImageHouse::signalTakeMarker, markerOnScene, &MarkerImage::markerInTheBag);

    connect(spriteGuy, &Sprite::signalIsInRoom_1, iHouse, &ImageHouse::isInRoom_1);
    connect(spriteGuy, &Sprite::signalIsNotInRoom_1, iHouse, &ImageHouse::isNotInRoom_1);
    connect(iHouse, &ImageHouse::hideClips, clipsOnScene, &ClipsImage::slotHideClips);
    connect(iHouse, &ImageHouse::showClips, clipsOnScene, &ClipsImage::slotShowClips);
    connect(iHouse, &ImageHouse::guyUsesClips, spriteGuy, &Sprite::guyUseClipsOnBed);
    connect(clipsOnScene, &ClipsImage::clickOnClips, iHouse, &ImageHouse::clipsAreClicked);
    connect(iHouse, &ImageHouse::deleteClips, this, &MainWindow::slotDelClips);

    connect(spriteGuy, &Sprite::signalIsInRoom_2, iHouse, &ImageHouse::isInRoom_2);
    connect(spriteGuy, &Sprite::signalIsNotInRoom_2, iHouse, &ImageHouse::isNotInRoom_2);
    connect(iHouse, &ImageHouse::hideMarker, markerOnScene, &MarkerImage::slotHideMarker);
    connect(iHouse, &ImageHouse::showMarker, markerOnScene, &MarkerImage::slotShowMarker);
    connect(iHouse, &ImageHouse::guyUsesMarker, spriteGuy, &Sprite::guyUseMarkerOnPicture);
    connect(markerOnScene, &MarkerImage::clickOnMarker, iHouse, &ImageHouse::markerIsClicked);
    connect(spriteGuy, &Sprite::deleteMarker, this, &MainWindow::slotDelMarker);
    connect(spriteGuy, &Sprite::messageMarker, this, &MainWindow::slotMessageMarker);
    connect(spriteGuy, &Sprite::signalShowPic, this, &MainWindow::drawPic);
    connect(spriteGuy, &Sprite::hadDrawn, iHouse, &ImageHouse::slotNowMayClick);
    connect(spriteGuy, &Sprite::signalSharePosition, this, &MainWindow::getMyPosition);
    connect(this, &MainWindow::signalGoblinNotices, spriteGuy, &Sprite::stopMoving);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawScene()
{
    iHouse = new ImageHouse;
    scene->addItem(iHouse);
    scene->update();
    fBush = new FlowerBush();
    bush = new Bush();
    tree = new Tree();
    pocketClips = new Pocket();
    pocketMarker = new Pocket();
    pocketClips->setPos(1360, 50);
    pocketMarker->setPos(1360, 260);
    fBush->setZValue(16);
    bush->setZValue(17);
    tree->setZValue(15);
//    scene->addItem(fBush);
//    scene->addItem(bush);
    scene->addItem(pocketClips);
    scene->addItem(pocketMarker);
    scene->addItem(tree);
    scene->update();
    timerRelations = new QTimer();
    connect(timerRelations, &QTimer::timeout, this, &MainWindow::checkRelations);
    timerRelations->start(10);
}

void MainWindow::checkRelations()
{
    if(xMyPos > 940 && yMyPos == 648){
        return;
    }
    //qDebug() << xMyPos << " " << xGobPos << " _ _" << yMyPos << " " << yGobPos;
    if(dirGob != 0){
        if(((xMyPos - xGobPos) * dirGob < 300) && (xMyPos - xGobPos) * dirGob > 0 && (abs(yMyPos - yGobPos) < 30)){
            qDebug() << "notices" << xMyPos;
            emit signalGoblinNotices();
        }
    }
}

// bool MainWindow::event(QEvent *event)
// {
//     if (event->type() == QEvent::WindowStateChange) {  // Состояние окна изменилось?
//         if (isMinimized()) {  // Окно было свернуто?
//             auto stateChangeEvent = static_cast<QWindowStateChangeEvent*>(event);
//             setWindowState(stateChangeEvent->oldState());  // Откатываем назад
//         }
//     }
//     return 0;//MainWindow::event(event);
// }

// void MainWindow::hideEvent(QHideEvent *event)
// {
//    //  qDebug() << "HIDES";
//    //  event->ignore();
//    // event->accept();
// }

// void MainWindow::resizeEvent(QResizeEvent *event)
// {
//     qDebug() << "resize";
//     event->ignore();
// }


void MainWindow::updScene()
{
    scene->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    emit startCarMovingFirst();
}

void MainWindow::addGoblinOnScene()
{
    goblin = new SpriteGoblin();
    scene->addItem(goblin);
    connect(goblin, &SpriteGoblin::updateScene, this, &MainWindow::updScene);
    connect(iHouse, &ImageHouse::deleteClips, goblin, &SpriteGoblin::clipsSetReady);
    connect(goblin, &SpriteGoblin::signalSeePic, this, &MainWindow::clearPic);
    connect(spriteGuy, &Sprite::hadDrawn, goblin, &SpriteGoblin::drawingSetReady);
    connect(goblin, &SpriteGoblin::deletePic, this, &MainWindow::clearPic);
    connect(goblin, &SpriteGoblin::signalShareGoblinPosition, this, &MainWindow::getGobPosition);
    connect(this, &MainWindow::signalGoblinNotices, goblin, &SpriteGoblin::goToEat);
}

void MainWindow::slotDelClips()
{
    myMessage = new DoneMessage();
    myMessage->setPos(1190, 310);
    scene->addItem(myMessage);
    QTimer::singleShot(700, this, &MainWindow::closeMessage);
    delete(clipsOnScene);
    clipsOnScene = nullptr;
}

void MainWindow::slotDelMarker()
{
    delete(markerOnScene);
    markerOnScene = nullptr;
}

void MainWindow::slotMessageMarker()
{
    myMessage = new DoneMessage();
    myMessage->setPos(900, 600);
    scene->addItem(myMessage);
    QTimer::singleShot(700, this, &MainWindow::closeMessage);
}

void MainWindow::closeMessage()
{
    delete(myMessage);
    myMessage = nullptr;
}

void MainWindow::drawPic()
{
    picDraw = new PicDrawing();
    picDraw->setPos(830, 605);
    scene->addItem(picDraw);
}

void MainWindow::clearPic()
{
    delete(picDraw);
    picDraw = nullptr;
}

void MainWindow::getMyPosition(int xPosition, int yPosition)
{
    xMyPos = xPosition;
    yMyPos = yPosition;

}

void MainWindow::getGobPosition(int xGobPosition, int yGobPosition, int directionGob)
{
    xGobPos = xGobPosition;
    yGobPos = yGobPosition;
    dirGob = directionGob;
}


