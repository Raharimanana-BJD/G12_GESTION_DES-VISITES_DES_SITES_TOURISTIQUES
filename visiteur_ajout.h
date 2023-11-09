#ifndef VISITEUR_AJOUT_H
#define VISITEUR_AJOUT_H

#include <QDialog>

namespace Ui {
class visiteur_ajout;
}

class visiteur_ajout : public QDialog
{
    Q_OBJECT

public:
    explicit visiteur_ajout(QWidget *parent = nullptr);
    ~visiteur_ajout();

private slots:
    void on_visiteur_annuler_clicked();

    void on_visiteur_ajouter_clicked();

private:
    Ui::visiteur_ajout *ui;
};

#endif // VISITEUR_AJOUT_H
