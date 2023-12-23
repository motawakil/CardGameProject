#include "fin.h"
#include "ui_fin.h"
#include"carte.h"
#include"joueurs.h"

#include"dialog.h"

fin::fin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fin)
{
    ui->setupUi(this);
affiche_winner();
}

fin::~fin()
{
    delete ui;
}

//fonction pour afficher une expression depandant aux resultat final du jeu
void fin::affiche_winner(){

    if(joueurs::score1 < joueurs::score2){
        ui->label_final->setText("Congratuation " +  MaClasse::name + " you Won");
    }
    if(joueurs::score1 > joueurs::score2){
        ui->label_final->setText("Vous avez echouez !! Essayer une autre fois " +  MaClasse::name);
    }
    if(joueurs::score1 == joueurs::score2){
        ui->label_final->setText("Quelle match !! Essayer une autre fois " + MaClasse::name);
    }


}
// fonction pour rejouer
void fin::on_rejouer_clicked()
{
    joueurs::score2 = 0 ;
    joueurs::score1 = 0 ;
    Dialog::turn = 0 ;
    MaClasse* window1 = new MaClasse(this); // ouvrir la premiere fenetre a
    window1->show();
}

// fonction pour quitter le jeu
void fin::on_Quitter_1_clicked()
{
    this->close() ;
}

