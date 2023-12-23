#include "image.h"
#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QDebug>
image_class::image_class(QObject *parent)
    : QObject{parent}
{
    // stocker les images dans stringList

    stringList <<" :/images/1000003469.jpg"<< ":/images/1000003479.jpg" <<":/images/1000003489.jpg"<<":/images/1000003499.jpg"
               <<":/images/1000003470.jpg"<<":/images/1000003480.jpg"<<":/images/1000003490.jpg"<<":/images/1000003500.jpg"
               <<":/images/1000003471.jpg"<<":/images/1000003481.jpg"<<":/images/1000003491.jpg"<<":/images/1000003501.jpg"
               <<":/images/1000003472.jpg"<<":/images/1000003482.jpg"<<":/images/1000003492.jpg"<<":/images/1000003502.jpg"
               <<":/images/1000003473.jpg"<<":/images/1000003483.jpg"<<":/images/1000003493.jpg"<<":/images/1000003503.jpg"
               <<":/images/1000003474.jpg"<<":/images/1000003484.jpg"<<":/images/1000003494.jpg"<<":/images/1000003504.jpg"
              <<":/images/1000003475.jpg"<<":/images/1000003485.jpg"<<":/images/1000003495.jpg"<<":/images/1000003505.jpg"
               <<":/images/1000003476.jpg"<<":/images/1000003486.jpg"<<":/images/1000003496.jpg"<<":/images/1000003506.jpg"
               <<":/images/1000003477.jpg"<<":/images/1000003487.jpg"<<":/images/1000003497.jpg"<<":/images/1000003507.jpg"
               <<":/images/1000003478.jpg"<<":/images/1000003488.jpg"<<":/images/1000003498.jpg"<<":/images/1000003508.jpg"
         ;

}
