#ifndef TIME_CHOICE_H
#define TIME_CHOICE_H

#include <QDialog>
#include<QTime>
#include<QTimer>

namespace Ui {
class time_choice;
}

class time_choice : public QDialog
{
    Q_OBJECT

public:
    explicit time_choice(QWidget *parent = nullptr);
    ~time_choice();
public:
QTime selectedTime() const;

    static int staticMinutes;
    static int staticSeconds;





private slots:
    void on_suivant_clicked();
   void onTimeEditValueChanged(const QTime &time);
private:
    Ui::time_choice *ui;

};

#endif // TIME_CHOICE_H
