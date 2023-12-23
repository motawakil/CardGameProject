#ifndef IMAGE_CLASS_H
#define IMAGE_CLASS_H
#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QDebug>
#include <QObject>
#include <QList>
;
class image_class : public QObject
{
    Q_OBJECT
public:
    explicit image_class(QObject *parent = nullptr);
     QList<QString> stringList;





signals:

};


#endif // IMAGE_CLASS_H
