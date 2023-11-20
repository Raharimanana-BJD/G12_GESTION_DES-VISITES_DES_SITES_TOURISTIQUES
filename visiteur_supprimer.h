#ifndef VISITEUR_SUPPRIMER_H
#define VISITEUR_SUPPRIMER_H

#include <QDialog>

namespace Ui {
class visiteur_supprimer;
}

class visiteur_supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit visiteur_supprimer(QWidget *parent = nullptr);
    ~visiteur_supprimer();

    QString numeroVisiteur;

private slots:
    void on_visiteur_annule_clicked();

    void on_visiteur_supprime_clicked();

private:
    Ui::visiteur_supprimer *ui;
};

#endif // VISITEUR_SUPPRIMER_H
