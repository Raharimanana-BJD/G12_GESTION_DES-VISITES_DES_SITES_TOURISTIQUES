#ifndef VISITEUR_AJOUT_H
#define VISITEUR_AJOUT_H

#include <QDialog>
#include <QTableWidget>
#include <QSqlQueryModel>

namespace Ui {
class visiteur_ajout;
}

class visiteur_ajout : public QDialog
{
    Q_OBJECT

public:
    explicit visiteur_ajout(QWidget *parent = nullptr);


    void afficheVisiteur (QTableWidget *visiteurTableWidget);
    ~visiteur_ajout();

    QSqlQueryModel *tabVisiteur;

public slots:
    void on_visiteur_ajouter_clicked();


private slots:
    void on_visiteur_annuler_clicked();

private:
    Ui::visiteur_ajout *ui;
};

#endif // VISITEUR_AJOUT_H
