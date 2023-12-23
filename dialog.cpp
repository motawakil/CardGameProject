#include "dialog.h"
#include "ui_dialog.h"
#include"choice_difficulte.h"
#include"time_choice.h"
#include"joueurs.h"
#include"carte.h"
#include"fin.h"

#include <QTime>
#include <QLabel>
#include <QString>
#include<QTimer>
#include<QPixmap>
#include"image.h"
#include<QMessageBox>
#include <QDialog>
#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QVBoxLayout>


// Initialistion du variable turn correspondant a distinguer les tournes de jeu
int Dialog::turn = 0  ;
// variables de  pos corresponds a savoir les position de l'image targeted dans la bord
//ils prennent des valeurs de 0-7 (existance du 8 images au max dans le bord )
int Dialog::pos = 0 ;
int Dialog::pos_bot = 0 ;
 int Dialog::pos_bord = 0 ;
// var static pour compter le nombre de click sur skip
int Dialog::skip_num  = 0 ;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

     ui->name->setText(MaClasse::name) ;
    // creation a appel du l'objet timer pour realiser un chrono
     timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    connect(ui->stop, SIGNAL(clicked()), this, SLOT(stopTimer()));

    connect(ui->reset, SIGNAL(clicked()), this, SLOT(resetTimer()));
    timer->start(1000); // Update chaque 1000 milliseconds (1 second)




   // Initialiser le chrono avec la valeur choisi par le joueur
    secondsRemaining = time_choice::staticMinutes * 60 + time_choice::staticSeconds ;
updateTimer();
    // button continuer de jouer est initailement masquer  , on l'affiche lors de click sur stop chrono pour continue le temps
    ui->continuer->hide();
// fonction qui affiche les cartes directement apres l'ouverture de cette fenetre
    on_jouer_clicked();


}




Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setText(const QString &text)
{

    //fonction qui affiche le nom choisi par le joueur
    ui->name->setText(text);

}

void Dialog::updateTimer()
{
    // Update le temps choisi par le joueur
    if (secondsRemaining > 0)
    {
        secondsRemaining--;
        int minutes = secondsRemaining / 60;
        int seconds = secondsRemaining % 60;

        // Update le text afficher au  label
        ui->lblTimer->setText(QString("%1:%2").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0')));
    }
    else
    {
        // Si secondsRemaining == 0 , le jeux se termine et on affiche la derniere page
        ui->lblTimer->setText("Time's up!");
    this->close();
        fin f_suivant ;
        f_suivant.setModal(true);
        f_suivant.exec() ;


    }
}



void Dialog::stopTimer(){
    // fonction pour stoper le chrono
    timer->stop();
    ui->jouer->setEnabled(false);
    ui->continuer->show();
    ui->stop->hide() ;
       // le temps arrete ,  le joueur ne  peut pas  jouer maintenant
    ui->image_5->setEnabled(false) ;
    ui->image_6->setEnabled(false) ;
    ui->image_7->setEnabled(false ) ;
    ui->image_8->setEnabled(false) ;

}

// fonction pour reseter le jeu ( reseter le temps et le score )
void Dialog::resetTimer()
{
    secondsRemaining = time_choice::staticMinutes * 60 + time_choice::staticSeconds ; // Reset time to 5 minutes
    updateTimer(); // Update label
    timer->start(); // commenecer le timer dès le debut
    //update du score et affichage de nouveau score
            joueurs::score2  = 0;
    joueurs::score1  = 0;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
            ui->user_score->setText(QString::number(joueurs::score2));

}
//fonction lier au button continuer timer
void Dialog::on_continuer_clicked()
{
    ui->jouer->setEnabled(true);
    timer->start();
    ui->continuer->hide() ;
    ui->stop->show() ;
    // le temps continue ,  le joueur peut jouer maintenant
    ui->image_5->setEnabled(true) ;
    ui->image_6->setEnabled(true) ;
    ui->image_7->setEnabled(true) ;
    ui->image_8->setEnabled(true) ;

}
// fonction pour finir le jeux a condtion qu un score depasse 15

void Dialog::finish_game()
{
    if( joueurs::score1 >= 15||  joueurs::score2 >= 15){

         QMessageBox::about(this , "message"  ,  "GAME OVER !!") ;
        fin f_suivant ;

        f_suivant.setModal(true);
        f_suivant.exec() ;

    }
}

// fonction pour distribuer et afficher les cartes
void Dialog::on_jouer_clicked()
{

    joueurs user1 ; // objet de classe joueur

    image_class ima ; // appel d'un objet du classe image
  // creation de 16 images on utilisant QPixmap et se basant sur le la position aleatoire retenue par object du classe joueur
// 4 images pour le joueur / 8 pour la bord du jeux / 4 identiques pour le bot
    QPixmap pix1(ima.stringList.at(user1.carte_number1) ) ;
    QPixmap pix2(ima.stringList.at(user1.carte_number2) ) ;
     QPixmap pix3(ima.stringList.at(user1.carte_number3) ) ;
      QPixmap pix4(ima.stringList.at(user1.carte_number4) ) ;

     QPixmap pix5(ima.stringList.at(user1.carte_number5) ) ;
     QPixmap pix6(ima.stringList.at(user1.carte_number6) ) ;
     QPixmap pix7(ima.stringList.at(user1.carte_number7) ) ;
     QPixmap pix8(ima.stringList.at(user1.carte_number8) ) ;


     QPixmap pix9(":/images/1000003509.jpg")  ;
     QPixmap pix10(":/images/1000003509.jpg" ) ;
     QPixmap pix11(":/images/1000003509.jpg" ) ;
     QPixmap pix12(":/images/1000003509.jpg" ) ;

     QPixmap pix13(ima.stringList.at(user1.carte_number9))  ;
     QPixmap pix14(ima.stringList.at(user1.carte_number10)) ;
     QPixmap pix15(ima.stringList.at(user1.carte_number11) ) ;
     QPixmap pix16(ima.stringList.at(user1.carte_number12) ) ;

     // images du cartes du Bot initialement sont masquer sous l'image ":/images/1000003509.jpg"
     ui->label_3->setPixmap(pix13);
     ui->label_4->setPixmap(pix14);
     ui->label_5->setPixmap(pix15);
     ui->label_6->setPixmap(pix16);

     ui->label_3->hide();
 ui->label_5->hide();
     ui->label_4->hide();
     ui->label_6->hide();

     //affichage des images de cartes au joueurs + utilisation SetIcon pour les buttons
     //setIconSize pour mis l'image  en size du button

     ui->image_5->setIcon(QIcon(pix5));
     ui->image_5->setIconSize(pix5.size());
     ui->image_6->setIcon(QIcon(pix6));
     ui->image_6->setIconSize(pix6.size());
     ui->image_7->setIcon(QIcon(pix7));
     ui->image_7->setIconSize(pix7.size());
     ui->image_8->setIcon(QIcon(pix8));
     ui->image_8->setIconSize(pix8.size());
     ui->image_9->setIcon(QIcon(pix9));
     ui->image_9->setIconSize(pix9.size());
     ui->image_10->setIcon(QIcon(pix10));
     ui->image_10->setIconSize(pix10.size());
     ui->image_11->setIcon(QIcon(pix11));
     ui->image_11->setIconSize(pix11.size());
     ui->image_12->setIcon(QIcon(pix12));
     ui->image_12->setIconSize(pix12.size());

    ui->image_1->setPixmap(pix1);
      ui->image_2->setPixmap(pix2);
     ui->image_3->setPixmap(pix3);
      ui->image_4->setPixmap(pix4);




// affichage des scores
     ui->bot_score->setText(QString::number(joueurs::score1)) ;

     ui->user_score->setText(QString::number(joueurs::score2));
     //fonction to_show pour afficher toutes les images  de nouveaux a chaque fois qu'on click sur le button distribuer
     to_show() ;


};









//**********************************************************
//********* FONCTIONS DE JOUEUR ***************************


// fonction add_bord pour ajouter une image de joueur dans le bord
// elle prend deux parametres le premier est le button clicker et la deuxieme c'est sa valeur
    void Dialog::add_bord(QPushButton *button , int valeur) {

     // creation d'une copie de button

     QIcon icon = button->icon();
     QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(141, 131)));

// trouver une position vide dans le bord
         int k = 0 ;
     while(joueurs::list1[k] != 0){
        k++ ;
     }

     // k c'est la position vide dans le bord
         switch(k){
        // ajouter l'image et la valeur au position vide
         case 0:   ui->image_1->setPixmap(pixmap.copy());
             ui->image_1->show();
             joueurs::list1[0] = valeur ;
             break ;
         case 1:   ui->image_2->setPixmap(pixmap.copy());
              ui->image_2->show();
              joueurs::list1[1] = valeur ;
             break ;
         case 2:   ui->image_3->setPixmap(pixmap.copy());
              ui->image_3->show();
             joueurs::list1[2] = valeur ;
             break ;
         case 3:   ui->image_4->setPixmap(pixmap.copy());
              ui->image_4->show();
             joueurs::list1[3] = valeur ;
             break ;

         case 4:
             ui->image_13->setPixmap(pixmap.copy());
              ui->image_13->show();
             joueurs::list1[4] = valeur ;
             break ;
         case 5 :   ui->image_14->setPixmap(pixmap.copy());
              ui->image_14->show();
             joueurs::list1[5] = valeur ;
             break ;
         case 6 :   ui->image_15->setPixmap(pixmap.copy());
              ui->image_15->show();
             joueurs::list1[6] = valeur ;
             break ;
         case 7 :   ui->image_16->setPixmap(pixmap.copy());
              ui->image_16->show();
               joueurs::list1[7] = valeur ;
             break ;
         }


     }


// turn_play est une fonction pour distribuer entre joueur et bot
     // a chaque fois qu'on jeut la valeur de la  variable turn s'augmente par 1
     // si turn est pair alors le turn de joueur si il est impair il s'agit de turn de bot
void Dialog::turn_play(){
     if(Dialog::turn %2 == 0){

// les images de bot
        ui->image_12->setEnabled(false);
        ui->image_11->setEnabled(false);
        ui->image_10->setEnabled(false);
        ui->image_9->setEnabled(false);
        // les buttons de joueurs
        ui->image_5->setEnabled(true);
        ui->image_6->setEnabled(true);
        ui->image_7->setEnabled(true);
        ui->image_8->setEnabled(true);
     }
     else{
        ui->image_12->setEnabled(true);
        ui->image_11->setEnabled(true);
        ui->image_10->setEnabled(true);
        ui->image_9->setEnabled(true);
        ui->image_5->setEnabled(false);
        ui->image_6->setEnabled(false);
        ui->image_7->setEnabled(false);
        ui->image_8->setEnabled(false);
     }


}

// une fonction pour afficher toutes les buttons et les labels masquer (utiliser juste apres le click sur le button distribuer ou apres si une table est vide


void Dialog::to_show(){
     ui->image_5->show();
      ui->image_6->show();
      ui->image_7->show();
       ui->image_8->show();
      ui->image_9->show();
      ui->image_10->show();
      ui->image_11->show();
      ui->image_12->show();
      ui->image_1->show();
      ui->image_2->show();
      ui->image_3->show();
      ui->image_4->show();
}

// fonction pour masquer une image du bord en se basant sur sa position

void Dialog::to_hide(int num2){

     switch(num2){
     case 0 :

        ui->image_1->hide() ;

        break ;
     case 1 :
        ui->image_2->hide() ;
        break ;
     case 2 :
        ui->image_3->hide() ;
        break ;
     case 3 :
        ui->image_4->hide() ;
        break ;
     case 4 :
        ui->image_13->hide() ;
        break ;
     case 5 :
        ui->image_14->hide() ;
        break ;
     case 6 :
        ui->image_15->hide() ;
        break ;
     case 7 :
        ui->image_16->hide() ;
        break ;
     }
}


// fonction pour savoir si une table ( table joueur / Bot / bord ) est vide , donc on est besoin de distribuer de nouveaux cartes
 bool Dialog::is_empty() {
     if(ui->image_5->isHidden() && ui->image_6->isHidden() && ui->image_7->isHidden() && ui->image_8->isHidden() ||
        ui->image_1->isHidden() && ui->image_2->isHidden() && ui->image_3->isHidden() && ui->image_4->isHidden() ||
         ui->image_9->isHidden() && ui->image_10->isHidden() && ui->image_11->isHidden() && ui->image_12->isHidden() ){
        return true  ;
}
     else{
        return false ;
     }
}

// fonction d'animation et de mouvement de l'image , prend le button a annimé comme parametre et on se basant sur le variable
// pos on peut savoir la destination du button

 void Dialog::to_move_image(QPushButton *button ) {
     QPropertyAnimation *animationForward = new QPropertyAnimation(button, "geometry");
     animationForward->setStartValue(button->geometry());

     switch (Dialog::pos) {
     case 1:   animationForward->setEndValue(ui->image_1->geometry()); break;
     case 2:   animationForward->setEndValue(ui->image_2->geometry()); break;
     case 3:   animationForward->setEndValue(ui->image_3->geometry()); break;
     case 4:   animationForward->setEndValue(ui->image_4->geometry()); break;
     case 5:   animationForward->setEndValue(ui->image_13->geometry()); break;
     case 6:   animationForward->setEndValue(ui->image_14->geometry()); break;
     case 7:   animationForward->setEndValue(ui->image_15->geometry()); break;
     case 8:   animationForward->setEndValue(ui->image_16->geometry()); break;

     }

     animationForward->setDuration(2000);
     animationForward->start();
     QTimer::singleShot(2000, this, [=]() {
         int k ;
         for(k = 0  ; k<8 ; k++){
          if(joueurs::list1[k] == 0){
                to_hide(k)  ;
             }
      }

         // Animation pourque le button  retourne a sa position initial
         QPropertyAnimation *animationBackward = new QPropertyAnimation(button, "geometry");
         animationBackward->setStartValue(button->geometry());
         animationBackward->setEndValue(animationForward->startValue());
         animationBackward->setDuration(2000);
         animationBackward->start();
     });
 }
 // cette fonction ressamble a la derniere fonction sauf que on la utilise dans le cas ou on savent pas la direction final de l'image
 // on creer une boucle pour trouver une position vide dans le bord

 void Dialog::to_move_nonselected_image(QPushButton *button) {
     QPropertyAnimation *animationForward = new QPropertyAnimation(button, "geometry");
     animationForward->setStartValue(button->geometry());

     int k = 0 ;
     while(joueurs::list1[k] != 0){
        k++ ;
     }
     switch (k+1) {
     case 1:   animationForward->setEndValue(ui->image_1->geometry()); break;
     case 2:   animationForward->setEndValue(ui->image_2->geometry()); break;
     case 3:   animationForward->setEndValue(ui->image_3->geometry()); break;
     case 4:   animationForward->setEndValue(ui->image_4->geometry()); break;
     case 5:   animationForward->setEndValue(ui->image_13->geometry()); break;
     case 6:   animationForward->setEndValue(ui->image_14->geometry()); break;
     case 7:   animationForward->setEndValue(ui->image_15->geometry()); break;
     case 8:   animationForward->setEndValue(ui->image_16->geometry()); break;
     }

     animationForward->setDuration(2000);
     animationForward->start();
     QTimer::singleShot(2000, this, [=]() {

         QPropertyAnimation *animationBackward = new QPropertyAnimation(button, "geometry");
         animationBackward->setStartValue(button->geometry());
         animationBackward->setEndValue(animationForward->startValue());
         animationBackward->setDuration(2000);
         animationBackward->start();
     });
 }

 // fonction qui tester si la valeur du button  clicker existe dans le bord

// Rappelez qu'on stocke les valeurs du joueur dans une liste de 4 dim (liste2 ) et les valeurs des cartes du bord dans une autre de 8 dim (liste1)
bool Dialog::test_exist(int num ){
   int count = 0 ;
     int i  ;
     for(i = 0 ; i<8 ; i++){

        if(num == joueurs::list1[i]){

            joueurs::list1[i] = 0  ;
            // si la valeur existe alors on la mange et change sa valeur en 0
            ++count ;
            Dialog::pos = i+1 ; // pos pour specifier la position d'exsitance de la carte au bord
        } }

    if(count != 0 ){
// fonction de type bool si le retoune est 1 alors existe une valeur aux bord qui egale aux valeur choisi par le joueur
        return 1  ;

     }

     else{

        return 0 ;
     }


}
// meme principe du fonction dernier , celui la pour tester l'existance du valeur+1 dans le bord
bool Dialog::test_exist_plus(int num4 ){
     int count = 0 ;
     int i  ;
     for(i = 0 ; i<8 ; i++){

        if(num4 == joueurs::list1[i]){

            joueurs::list1[i] = 0  ;
            ++count ;
            to_hide(i) ;
        }

     }

     if(count != 0 ){

        return 1  ;

     }

     else{

        return 0 ;
     }


}
// fonction associer au button skip a chaque fois que le joueur choisi de ne pas jouer ce rond et  son score diminue par 1
void Dialog::on_skip_clicked()
{
     if(joueurs::score2 > 0 && Dialog::skip_num <= 3   ){
        --joueurs::score2 ;
        ui->bot_score->setText(QString::number(joueurs::score1)) ;
        ++Dialog::skip_num ;
        ;
        ui->user_score->setText(QString::number(joueurs::score2));
     QMessageBox:(this , "on click sur skip"  , "-1") ;
        ++Dialog::turn ;
        turn_play() ;
        bot_turn();

     }
     else{
        QMessageBox::about(this , "erreur"  , "impossible de faire cette itteration ") ;

     }
     if(Dialog::skip_num == 3){
         QMessageBox::about(this , "erreur"  , "vous avez le droit de skiper 3 fois au max") ;
     }

}



//***********************************************************
//**************** joueur buttons *************************

//a chaque fois que le joueur click sur le button les memes attributs se fonctionne mais avec different parametres (depand de chaque button )
void Dialog::on_image_5_clicked()
{
   // notez bien que la valeur du carte button5 est stocker dans liste2[0]

     if(test_exist(joueurs::list2[0]) == 1 ) // si la valeur existe
     {

              to_move_image(ui->image_5) ; // animation du button
        ++joueurs::score2 ; // on ajoute une point au score du joueur
        ui->bot_score->setText(QString::number(joueurs::score1)) ; // affichage de nouveaux scores
        ui->user_score->setText(QString::number(joueurs::score2));
        QTimer::singleShot(4000, this, [=]() {

        ui->image_5->hide() ; // masquer l'image du joueur
            finish_game() ; //appeler la fonction finish_game (si le nouveau score depasse 15 le jeu se termine )
            ++Dialog::turn ; // ajouter 1 au var turn pour qu'il devient impaire
            turn_play() ; // appeler turn_play pour donner au Bot le turn de jouer
            bot_turn(); // fonction du jeu de Bot

        });

// fonction pour tester l'existance d'une valeur +1 du carte
        if(test_exist_plus(joueurs::list2[0] +1) == 1){

            ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
            QMessageBox::about(this , "message " , " DOUBLET ") ; // message doublet pour informer le joueur que il a manger de cartes sucssessif
            ui->user_score->setText(QString::number(joueurs::score2));
        }


     }
     else{ // si la valeur n'existe pas

        to_move_nonselected_image(ui->image_5) ; // animer l'image


         QTimer::singleShot(2000, this, [=]() {

             ui->image_5->hide() ;
              add_bord(ui->image_5 , joueurs::list2[0]);//add au bord dans la premiere position vide
             ++Dialog::turn ;
             turn_play() ;
             bot_turn();
         });


     }
     if(is_empty()){ // fonction de tester si la table  est devient vide apres la derniere itteration

        to_show() ; // afficher toutes les elements
        on_jouer_clicked() ; // distribuer les cartes de nouveaux

     }


}
void Dialog::on_image_6_clicked()
{
    if(test_exist(joueurs::list2[1]) == 1 )
     {

   to_move_image(ui->image_6 ) ;
            ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
            ui->user_score->setText(QString::number(joueurs::score2));
            QTimer::singleShot(4000, this, [=]() {

                ui->image_6->hide() ;
                finish_game() ;
                ++Dialog::turn ;
                turn_play() ;
                bot_turn();
            });

            if(test_exist_plus(joueurs::list2[1] +1) == 1){

            ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
                 QMessageBox::about(this , "message " , " DOUBLET ") ;
            ui->user_score->setText(QString::number(joueurs::score2));
            }
        }


     else{
            to_move_nonselected_image(ui->image_6) ;

            QTimer::singleShot(2000, this, [=]() {

                ui->image_6->hide() ;
                add_bord(ui->image_6 , joueurs::list2[1]);
                ++Dialog::turn ;
                turn_play() ;
                bot_turn();
            });
        }

     if(is_empty()){
         on_jouer_clicked() ;
          to_show() ;
     }}


void Dialog::on_image_7_clicked()
{
     if(test_exist(joueurs::list2[2])  )
     {
             to_move_image(ui->image_7 ) ;
            ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
            ui->user_score->setText(QString::number(joueurs::score2));
            QTimer::singleShot(4000, this, [=]() {

                ui->image_7->hide() ;
                finish_game() ;
                ++Dialog::turn ;
                turn_play() ;
                bot_turn();
            });
            if(test_exist_plus(joueurs::list2[2] +1) == 1){
           ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
         QMessageBox::about(this , "message " , " DOUBLET ") ;
            ui->user_score->setText(QString::number(joueurs::score2));
            }
     }
     else{
            to_move_nonselected_image(ui->image_7) ;


            QTimer::singleShot(2000, this, [=]() {

                ui->image_7->hide() ;
                add_bord(ui->image_7 , joueurs::list2[2]);
                ++Dialog::turn ;
                turn_play() ;
                bot_turn();
            });
     }

     if(is_empty()){
         on_jouer_clicked() ;
           to_show() ;
     }
}


void Dialog::on_image_8_clicked()
{
           if(test_exist(joueurs::list2[3]) == 1){
              to_move_image(ui->image_8 ) ;
            ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
            ui->user_score->setText(QString::number(joueurs::score2));
            QTimer::singleShot(4000, this, [=]() {

                ui->image_8->hide() ;
                finish_game() ;
                ++Dialog::turn ;
                turn_play() ;
                bot_turn();
            });
            if(test_exist_plus(joueurs::list2[3] +1) == 1){

            ++joueurs::score2 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;
                 QMessageBox::about(this , "message " , " DOUBLET ") ;
            ui->user_score->setText(QString::number(joueurs::score2));
            }
           }


     else{
            to_move_nonselected_image(ui->image_8) ;


            QTimer::singleShot(2000, this, [=]() {

                ui->image_8->hide() ;
                add_bord(ui->image_8 , joueurs::list2[3]);
                ++Dialog::turn ;
                turn_play() ;
                bot_turn();
            });


     }
   if(is_empty()){

         on_jouer_clicked() ;
         to_show() ;

     }

}



//**************************************************************************
 //*******************  BOT FONCTIONS **************************

// fonction de l'appel de Bot
void Dialog::bot_turn(){

if(Dialog::turn%2 == 1){ // cas impaire

         test_exist_bot() ; // fonction qui tester l'existance d'une carte de bot dans le bord
         finish_game() ; // appeler la fonction finish_game (si le nouveau score depasse 15 le jeu se termine )


         if(is_empty()){// fonction de tester si la table  est devient vide apres la derniere itteration

            on_jouer_clicked() ; // Distribuer des nouveaux cartes
            to_show() ; // afficher les cartes
         }

}

++Dialog::turn ; // turn devient paire
turn_play() ; //donner turn au joueur

}

// fonction pour masquer une image du bord en se basant sur sa position
// la carte joueur est constituer par deux images (image de la carte au dessous  et l'image qui masque la carte  )
void Dialog::to_hide_bot(int num3) {
switch(num3) {
case 0:
         ui->image_12->hide(); // masquer la deuxieme  image
         ui->label_3->show(); // afficher l'image du carte pour une periode de 2 seconds
         QTimer::singleShot(2000, this, [=]() {
              ui->label_3->hide();
         });
         break;

case 1:
         ui->image_11->hide();

        ui->label_4->show();
         QTimer::singleShot(2000, this, [=]() {
             ui->label_4->hide();
         });
         break;

case 2:
         ui->image_10->hide();

       ui->label_5->show();
         QTimer::singleShot(2000, this, [=]() {
             ui->label_5->hide();
         });
         break;

case 3:
         ui->image_9->hide();

         ui->label_6->show();
         QTimer::singleShot(2000, this, [=]() {
               ui->label_6->hide();

         });

         break;
}
}

//fonction pour choisir une carte aleatoire (cette valeur est toujours la derniere carte disponible )
// Rappelez-vous que les valeurs des images du bot sont stockées dans la liste3
void Dialog::choix_alea(){

for(i = 0 ; i<4 ; i++){
         if(joueurs::list3[i] != 0 ){ // trouver une carte avec une valeur diff de 0 (c.a.d une carte afficher )
            rand_num = i ;
         }

}

Dialog::pos_bot  = rand_num ; // pos_bot pour savoir la position de la carte  choisi par le bot / a utiliser pendant l'animation
switch(rand_num){
case 0 :

         add_bord_bot(ui->label_3 , joueurs::list3[0]); //fonction pour ajouter la carte au bord
         to_move_image_bot(ui->label_3 ) ; // fonction pour animer la carte choisi

         joueurs::list3[0] = 0 ;  // changer la valeur de cette dans la liste a 0
         to_hide_bot(rand_num) ; //masquer la carte choisi

         break ;
case 1 :
         add_bord_bot(ui->label_4 , joueurs::list3[1]);
         to_move_image_bot(ui->label_4 ) ;

         joueurs::list3[1] = 0 ;
         to_hide_bot(rand_num) ;
         break ;
case 2 :
         add_bord_bot(ui->label_5 , joueurs::list3[2]);
         to_move_image_bot(ui->label_5 ) ;
         //  ui->image_11->hide() ;
         joueurs::list3[2] = 0 ;
         to_hide_bot(rand_num) ;
         break ;
case 3 :
         add_bord_bot(ui->label_6 , joueurs::list3[3]);
         to_move_image_bot(ui->label_6 ) ;

         joueurs::list3[3] = 0 ;
         to_hide_bot(rand_num) ;
         break ;
}


}
//fonction de choix difficile dont la valeur choisit par le bot doit etre different aux toutes les valeurs du joueurs

void Dialog::choix_alea_defficile(){
int j , l , compteur = 0 , value  ;
for(j = 0 ; j<4 ; j++){
         for(l = 0 ; l<4 ; l++){
            if(joueurs::list3[j] != joueurs::list2[l]){
                ++compteur  ;
            }
            if(compteur == 4){
                value = j ;
            }

         }

}
// le variable value contient une valeur qui existe chez le Bot mais il n'existe pas chez le joueur
// le but de cette fonction est de minimaliser probabilites que le joueur peut gagner de points

if(joueurs::list3[value] == 0 ){ // si y a pas de valeur qui realise la condition
         choix_alea() ;
}
else{
         Dialog::pos_bot  = value ;
         switch(value){
         case 0 :

            add_bord_bot(ui->label_3 , joueurs::list3[0]);
            to_move_image_bot(ui->label_3 ) ;
            joueurs::list3[0] = 0 ;
            to_hide_bot(value) ;
         case 1 :
            add_bord_bot(ui->label_4 , joueurs::list3[1]);
            to_move_image_bot(ui->label_4 ) ;            
            joueurs::list3[1] = 0 ;
            to_hide_bot(value) ;
            break ;
         case 2 :
            add_bord_bot(ui->label_5 , joueurs::list3[2]);
            to_move_image_bot(ui->label_5 ) ;
            joueurs::list3[2] = 0 ;
            to_hide_bot(value) ;
            break ;
         case 3 :
            add_bord_bot(ui->label_6 , joueurs::list3[3]);
            to_move_image_bot(ui->label_6 ) ;
            joueurs::list3[3] = 0 ;
            to_hide_bot(value) ;
            break ;
         }

}

}

//fonction pour tester l'existance d'une valeur d'une carte au bord
void Dialog::test_exist_bot(){
int p , q , exist = 0 , existed_num3 , existed_num1 , old_value;
for(p = 0  ; p<4 ; p++){
         for(q = 0 ; q<8 ; q++){
            if(joueurs::list3[p] == joueurs::list1[q] && joueurs::list1[q] != 0 && joueurs::list3[p] !=0){
                ++exist ;
                existed_num3 = p ;
                existed_num1 = q ;
                joueurs::list1[q] = 0  ;
                old_value = joueurs::list3[p] ;
                joueurs::list3[p] = 0  ;
                    Dialog::pos_bot = p ;
                Dialog::pos_bord = q ;

            }

         }

}
if(exist == 0){ // si y a aucune valeur qui existe au bord
  // on choisi une valeur aleatoire mais on se basant sur le choix de difficulte  de joueur
         if(choice_difficulte::diff_choice == 1 ){
          choix_alea();
         }
         else{
         choix_alea_defficile() ;

         }
}
else{
// update la carte du bot
         switch(Dialog::pos_bot){
         case 0 :     ui->label_3->show(); // show image de la carte
            ui->image_12->hide() ; // carte l'image de massquage
            to_move_image_bot(ui->label_3 ) ; // animate l'image de bot
            break  ;
         case 1 :  ui->label_4->show();  to_move_image_bot(ui->label_4 ) ;
            ui->image_11->hide() ;
            break  ;
         case 2 :  ui->label_5->show(); to_move_image_bot(ui->label_5 ) ;
            ui->image_10->hide() ;
            break  ;
         case 3 :  ui->label_6->show(); to_move_image_bot(ui->label_6 ) ;
            ui->image_9->hide() ;
            break  ;
         }

         QTimer::singleShot(2000, this, [=]() {
        to_hide_bot(existed_num3) ; // hide l'image du bord
        int k ;
         for(k = 0  ; k<8 ; k++){
            if(joueurs::list1[k] == 0){
                to_hide(k)  ;
            }
         }

         });
 test_exist_plus_bot(old_value + 1)  ; // tester si il exisste aussi une valeur de plus 1
         ++joueurs::score1 ; // ajouter une point au Bot score
         ui->bot_score->setText(QString::number(joueurs::score1)) ;

         ui->user_score->setText(QString::number(joueurs::score2));

}
}
// fonction pour tester l'existance du numero de carte de bot +1
void  Dialog::test_exist_plus_bot(int valeur4){
int  q ,  existed_num2;

for(q = 0 ; q<8 ; q++){
         if(valeur4 == joueurs::list1[q] && joueurs::list1[q] != 0 ){
            existed_num2 = q ;
            joueurs::list1[q] = 0  ;
            to_hide(existed_num2) ;
            ++joueurs::score1 ;
            ui->bot_score->setText(QString::number(joueurs::score1)) ;

            ui->user_score->setText(QString::number(joueurs::score2));
            QMessageBox::about(this , "message" , "DOUBELT ") ;
         }
}
}
//fonction d'animation bot , mais principe de la fonction de joueur
void Dialog::to_move_image_bot(QLabel *label ) {
QPropertyAnimation *animationForward = new QPropertyAnimation(label, "geometry");
animationForward->setStartValue(label->geometry());



switch (Dialog::pos_bord ) {
case 0:   animationForward->setEndValue(ui->image_1->geometry()); break;
case 1:   animationForward->setEndValue(ui->image_2->geometry()); break;
case 2:   animationForward->setEndValue(ui->image_3->geometry()); break;
case 3:   animationForward->setEndValue(ui->image_4->geometry()); break;
case 4:   animationForward->setEndValue(ui->image_13->geometry()); break;
case 5:   animationForward->setEndValue(ui->image_14->geometry()); break;
case 6:   animationForward->setEndValue(ui->image_15->geometry()); break;
case 7:   animationForward->setEndValue(ui->image_16->geometry()); break;
}

animationForward->setDuration(2000);
animationForward->start();
QTimer::singleShot(2000, this, [=]() {

    QPropertyAnimation *animationBackward = new QPropertyAnimation(label, "geometry");
    animationBackward->setStartValue(label->geometry());
    animationBackward->setEndValue(animationForward->startValue());
    animationBackward->setDuration(2000);
    animationBackward->start();
});
}

//fonction qui ajoute les cartes dans la bord du jeu , meme principe que add_bord du joueur

void Dialog::add_bord_bot(QLabel* label, int valeur2) {
QPixmap pixmap = label->pixmap().copy();
int k = 0;
while (joueurs::list1[k] != 0) {
         k++;
}

Dialog::pos_bord = k ;

switch (k) {
case 0:
         ui->image_1->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

         ui->image_1->show();
         });

         joueurs::list1[0] = valeur2;
         break;
case 1:
         ui->image_2->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_2->show();
         });
         joueurs::list1[1] = valeur2;
         break;
case 2:
         ui->image_3->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_3->show();
         });
         joueurs::list1[2] = valeur2;
         break;
case 3:
         ui->image_4->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_4->show();
         });
         joueurs::list1[3] = valeur2;
         break;
case 4:
         ui->image_13->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_13->show();
         });
         joueurs::list1[4] = valeur2;
         break;
case 5:
         ui->image_14->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_14->show();
         });
         joueurs::list1[5] = valeur2;
         break;
case 6:
         ui->image_15->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_15->show();
         });
         joueurs::list1[6] = valeur2;
         break;
case 7:
         ui->image_16->setPixmap(pixmap);
         QTimer::singleShot(2000, this, [=]() {

             ui->image_16->show();
         });
         joueurs::list1[7] = valeur2;
         break;
}
}




