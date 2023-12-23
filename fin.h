#ifndef FIN_H
#define FIN_H

#include <QDialog>

namespace Ui {
class fin;
}

class fin : public QDialog
{
    Q_OBJECT

public:
    explicit fin(QWidget *parent = nullptr);
    ~fin();

private slots:




    void affiche_winner() ;

    void on_rejouer_clicked();

    void on_Quitter_1_clicked();

private:
    Ui::fin *ui;
};

#endif // FIN_H
