#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "Wheelbase.h"
#include "Obstacle.h"
#include "Emulator.h"
#include <QImage>
#include <QBrush>
#include <QElapsedTimer>
#include <QDebug>
#include <QTimer>

using namespace std;
QElapsedTimer *TIME = new QElapsedTimer();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();
    QTimer *timer = new QTimer();
    Wheelbase *wheelbase = new Wheelbase();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setScene(scene);
    view->setFixedSize(1000,665); //size of robocon field in cm
    view->setBackgroundBrush(QBrush(QImage(":/images/background.png")));
    view->show();

    TIME->start();

    Emulator *emulator = new Emulator(timer, scene, wheelbase);
    XYTheta target = {0,0,0};
    float acc_limit = 0;

    cout << "Welcome to the Omni Wheelbase Simulator" << endl;
    cout << "Enter Acceleration Limit" << endl;
    cin >> acc_limit; emulator->set_acc_limit(acc_limit);
    cout << "Enter Target(x)" << endl;
    cin >> target.x;
    cout << "Enter Target(y)" << endl;
    cin >> target.y; emulator->set_target(target);

    return a.exec();
}
