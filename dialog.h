#ifndef DIALOG_H
#define DIALOG_H
#include <QTime>
#include <QTimer>
#include <QDialog>
#include"time_choice.h"
#include<vector>
#include<QLabel>
#include<QPushButton>
#include<QPropertyAnimation>
using namespace std ;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

 int rand_num;
 int count ;
 int i ;
 int k ;
 static int pos ;
 static int pos_bot ;
 static int pos_bord ;
 static int turn ;

 static int skip_num ;

private slots:


    void setText(const QString &text);
    void to_move_image(QPushButton *button ) ;
    void to_move_nonselected_image(QPushButton *button) ;
    void to_move_image_bot(QLabel *label)  ;
    void test_exist_plus_bot(int valeur4) ;
    void test_exist_bot()  ;
    void finish_game()  ;
    void bot_turn() ;
    void show_score() ;
    void to_hide_bot(int num3) ;
    void add_bord(QPushButton *button , int valeur);
    void add_bord_bot(QLabel* label, int valeur2) ;
    bool test_exist( int num) ;
    bool test_exist_plus( int num4) ;
    void  to_hide(int num2) ;
    void choix_alea_defficile() ;
    void choix_alea() ;
    void turn_play() ;
    bool is_empty() ;
    void to_show() ;


    void on_jouer_clicked();
    void  updateTimer() ;
   void stopTimer() ;
    void resetTimer() ;
    void on_continuer_clicked();
    void on_image_5_clicked();
    void on_image_6_clicked();
    void on_image_7_clicked();
    void on_image_8_clicked();
    void on_skip_clicked();
   // void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
int secondsRemaining;

     QTimer *timer;
QPropertyAnimation *animation  ;
//QTimer *gameTimer ;
};

#endif // DIALOG_H
