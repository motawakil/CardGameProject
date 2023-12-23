#ifndef JOUEURS_H
#define JOUEURS_H

#include <QObject>

class joueurs : public QObject
{
    Q_OBJECT
public:

    explicit joueurs(QObject *parent = nullptr);
    static int score1; // Static class variable for player 1
    static int score2;
    int num1 , num2 , num3 , num4 ,
        num5 , num6 , num7 , num8 ,
        num9 , num10 , num11 , num12
        ;
    int carte_number1 , carte_number2 , carte_number3 , carte_number4 ,
        carte_number5 , carte_number6 , carte_number7 , carte_number8,
        carte_number9 , carte_number10 , carte_number11 , carte_number12;

    static int list1[8];
   static int list2[4] ;
      static  int list3[4] ;

    /*
    static std::vector<int> list1;
    static std::vector<int> list2;
    static std::vector<int> list3;

*/

signals:


private:

};

#endif // JOUEURS_H
