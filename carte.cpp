#include "carte.h"
#include "./ui_carte.h"
#include"dialog.h"
#include"time_choice.h"
#include"QMessageBox"
#include<QFile>
#include<QTextStream>
#include"fin.h"
#include <QSharedMemory>
#include <QString>
#include <QTextEdit>
#include<QPixmap>
#include<QPalette>
#include <QApplication>

//Initialiser le la var static qui va contenir le nom du joueur
QString MaClasse::name = "" ;
MaClasse::MaClasse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MaClasse)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // ... Autres configurations et initialisations de la fenêtre ...

    this->show();

    ui->obli_label->hide() ; //message d'erreur initialement massquer

}

MaClasse::~MaClasse()
{
    delete ui;
}


void MaClasse::on_commencer_clicked()
{



    MaClasse::name = ui->lineEdit->text() ;
    // stocker le nom choisi par le joueur dans un variable type static
    if(MaClasse::name == ""){

        ui->obli_label->show() ;//affichage du message d'erreur

    }
    else{
        // fermeture de cette fenetre
        this->close();
        // ouverture de la fenetre suivante
        time_choice t_open ;
        t_open.setModal(true);
        t_open.exec() ;

    }


}




