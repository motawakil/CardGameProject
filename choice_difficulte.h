#ifndef CHOICE_DIFFICULTE_H
#define CHOICE_DIFFICULTE_H

#include <QDialog>

namespace Ui {
class choice_difficulte;
}

class choice_difficulte : public QDialog
{
    Q_OBJECT

public:
    explicit choice_difficulte(QWidget *parent = nullptr);
    ~choice_difficulte();
     static int diff_choice;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::choice_difficulte *ui;
};

#endif // CHOICE_DIFFICULTE_H
