#include "Wheelbase.h"
#include <QTimer>
#include <QDebug>

Wheelbase::Wheelbase() {
    /* set size and initial position */
    setRect(0,0,90,90);
    setPos(0,160);
    /* make wheelbase focusable */
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    /* connect timer with move() */
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void Wheelbase::set_vel(XYTheta velocity){
    vel = velocity;
}

void Wheelbase::move() {
    //WheelSpeed ws = get_wheel_speed(velocity);
    //setPos()
    //change coordinates according to real field
    double x_increment = vel.x*(0.01);
    double y_increment = vel.y*(0.01);
    setPos(x()+x_increment, y()+y_increment);
    qDebug() << x_increment;
}

WheelSpeed Wheelbase::get_wheel_speed(XYTheta velocity) {
    return wheel_speed = {
        .wheels[0].r = static_cast<float>(velocity.x * (-cos45) + velocity.y * (-sin45) - velocity.theta),
        .wheels[1].r = static_cast<float>(velocity.x * (-cos45) + velocity.y * (sin45) - velocity.theta),
        .wheels[2].r = static_cast<float>(velocity.x * (cos45) + velocity.y * (-sin45) - velocity.theta),
        .wheels[3].r = static_cast<float>(velocity.x * (cos45) + velocity.y * (sin45) - velocity.theta)
    };
}
