#include "choice_difficulte.h"
#include "ui_choice_difficulte.h"
#include"dialog.h"
// Initialiser le variable static qui va stocker une valeur dependant d'etat du jeu (facile / difficle )
int choice_difficulte::diff_choice = 0 ;

choice_difficulte::choice_difficulte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choice_difficulte)
{
    ui->setupUi(this);
}

choice_difficulte::~choice_difficulte()
{
    delete ui;
}

void choice_difficulte::on_pushButton_clicked()
{
 choice_difficulte::diff_choice = 1 ;
    // 1 pour le choix moyenne

    this->close();
    Dialog g_suivant ;
    g_suivant.setModal(true);
    g_suivant.exec() ;

}


void choice_difficulte::on_pushButton_2_clicked()
{
    choice_difficulte::diff_choice = 2 ;
    //  2 pour le choix difficile
    this->close();
    Dialog g_suivant ;
    g_suivant.setModal(true);
    g_suivant.exec() ;
}

