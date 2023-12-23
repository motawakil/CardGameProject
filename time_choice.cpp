#include "time_choice.h"
#include "ui_time_choice.h"
#include"dialog.h"
#include<QTimeEdit>
#include<QMessageBox>
#include<QFile>
#include<QTime>
#include<QTimeEdit>
#include"joueurs.h"
#include"carte.h"
#include"choice_difficulte.h"

//Initialiser les variables statics (minutes / seconds )
int time_choice::staticMinutes = 0;
int time_choice::staticSeconds = 0;

time_choice::time_choice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::time_choice)
{
    ui->setupUi(this);

    connect(ui->timeEdit2, &QTimeEdit::timeChanged, this, time_choice::onTimeEditValueChanged);
    ui->obli_label2->hide() ;
}

time_choice::~time_choice()
{
    delete ui;
}


void time_choice::on_suivant_clicked()
{


    if( time_choice::staticMinutes == 0 && time_choice::staticSeconds == 0){
        // le choix du temps de jeu est obligatoire
        ui->obli_label2->show() ; //affichage de message d'erreur

    }
    else{
        //fermer cette fenetre
        this->close();
// ouvrir la prochaine fenetre
        choice_difficulte to_choice ;
        to_choice.setModal(true);
        to_choice.exec() ;

    }

};

void time_choice::onTimeEditValueChanged(const QTime &time)
{
    // Retirer les  minutes et les  seconds de l'object QTime
    staticMinutes = time.minute();
    staticSeconds = time.second();
}
