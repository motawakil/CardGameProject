// joueurs.cpp

#include "joueurs.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

 int joueurs::score1 = 0; // Initialiser les variables statics du scores
int joueurs::score2 = 0;
// Creation de 3 listes  correspondants aux valeurs de catres de joueur , Bot et les valeurs en bord
 int joueurs::list1[8] = {0, 0, 0, 0 , 0 , 0 , 0 , 0} ;
int joueurs::list2[4] = {0, 0, 0, 0};
int joueurs::list3[4] = {0, 0, 0, 0};
//int joueurs::list4[4] = {0, 0, 0, 0};


joueurs::joueurs(QObject *parent)
    : QObject(parent)
{
    srand(time(0)) ;
// on stock des valeurs aleatoires qui ne depassent pas 40 , 'while' pour eviter la repitition de la carte
    do {
        carte_number1 = rand() % 40 ;
        carte_number2 = rand() % 40 ;
        carte_number3 = rand() % 40 ;
        carte_number4 = rand() % 40 ;
    } while (carte_number1 == carte_number2 || carte_number1 == carte_number3 || carte_number1 == carte_number4 ||
              carte_number2 == carte_number3 || carte_number2 == carte_number4 || carte_number3 == carte_number4
                || carte_number1 == 0 || carte_number2 == 0 || carte_number3 == 0 || carte_number4 == 0);

    do {
        carte_number5 = rand() % 40 ;
        carte_number6 = rand() % 40 ;
        carte_number7 = rand() % 40 ;
        carte_number8 = rand() % 40 ;
    } while (carte_number5 == carte_number1 || carte_number5 == carte_number2 || carte_number5 == carte_number3 || carte_number5 == carte_number4 ||
             carte_number6 == carte_number1 || carte_number6 == carte_number2 || carte_number6 == carte_number3 || carte_number6 == carte_number4 ||
             carte_number7 == carte_number1 || carte_number7 == carte_number2 || carte_number7 == carte_number3 || carte_number7 == carte_number4 ||
             carte_number8 == carte_number1 || carte_number8 == carte_number2 || carte_number8 == carte_number3 || carte_number8 == carte_number4
              || carte_number5 == 0 || carte_number6 == 0 || carte_number7 == 0 || carte_number8 == 0
             );

    do {
        carte_number9 = rand() % 40  ;
        carte_number10 = rand() % 40 ;
        carte_number11 = rand() % 40 ;
        carte_number12 = rand() % 40 ;
    } while (carte_number9 == carte_number1 || carte_number9 == carte_number2 || carte_number9 == carte_number3 || carte_number9 == carte_number4 ||
             carte_number9 == carte_number5 || carte_number9 == carte_number6 || carte_number9 == carte_number7 || carte_number9 == carte_number8 ||
             carte_number10 == carte_number1 || carte_number10 == carte_number2 || carte_number10 == carte_number3 || carte_number10 == carte_number4 ||
             carte_number10 == carte_number5 || carte_number10 == carte_number6 || carte_number10 == carte_number7 || carte_number10 == carte_number8 ||
             carte_number11 == carte_number1 || carte_number11 == carte_number2 || carte_number11 == carte_number3 || carte_number11 == carte_number4 ||
             carte_number11 == carte_number5 || carte_number11 == carte_number6 || carte_number11 == carte_number7 || carte_number11 == carte_number8 ||
             carte_number12 == carte_number1 || carte_number12 == carte_number2 || carte_number12 == carte_number3 || carte_number12 == carte_number4 ||
             carte_number12 == carte_number5 || carte_number12 == carte_number6 || carte_number12 == carte_number7 || carte_number12 == carte_number8
                  || carte_number9 == 0 || carte_number10 == 0 || carte_number11 == 0 || carte_number12 == 0
             )

        ;

// on divison le nombre obtenu sur 4 et on ajoutant 1 on peut obtenir la valeur reel de la carte
    num1 = carte_number1/4 +1 ;
    num2 = carte_number2/4 +1 ;
    num3 = carte_number3/4 +1 ;
      num4 = carte_number4/4 +1 ;


    num5 = carte_number5/4 +1 ;
    num6 = carte_number6/4 +1 ;
    num7 = carte_number7/4 +1 ;
    num8 = carte_number8/4 +1 ;

    num9 = carte_number9/4 +1 ;
    num10 = carte_number10/4 +1 ;
    num11 = carte_number11/4 +1 ;
    num12 = carte_number12/4 +1 ;

//on Initiale les liste par les valeurs correspondants

    joueurs::list1[0] = num1 ;
    joueurs::list1[1] = num2 ;
    joueurs::list1[2] = num3 ;
    joueurs::list1[3] = num4 ;


    joueurs::list2[0] = num5 ;
   joueurs::list2[1] = num6 ;
    joueurs::list2[2] = num7 ;
    joueurs::list2[3] = num8 ;

    joueurs::list3[0] = num9 ;
    joueurs::list3[1] = num10 ;
   joueurs::list3[2] = num11 ;
    joueurs::list3[3] = num12;



}

