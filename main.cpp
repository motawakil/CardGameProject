#include "carte.h"
# include"dialog.h"
#include <QApplication>
#include"image.h"
#include<cstdlib>
#include<iostream>
#include<QMessageBox>
#include"joueurs.h"
#include<iostream>
using namespace std ;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MaClasse w;
    w.show();
    return a.exec();
}
