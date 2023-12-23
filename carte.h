#ifndef MACLASSE_H
#define MACLASSE_H
#include <QWidget>
#include<QString>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MaClasse; }
QT_END_NAMESPACE

class MaClasse : public QMainWindow
{
    Q_OBJECT

public:
    MaClasse(QWidget *parent = nullptr);
    ~MaClasse();

    static QString  name ;

private slots:

    void on_commencer_clicked();




private:
    Ui::MaClasse *ui;

};
#endif // MACLASSE_H
