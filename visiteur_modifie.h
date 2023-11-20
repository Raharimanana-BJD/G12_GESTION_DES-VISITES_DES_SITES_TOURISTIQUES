#ifndef VISITEUR_MODIFIE_H
#define VISITEUR_MODIFIE_H

#include <QDialog>

namespace Ui {
class visiteur_modifie;
}

class visiteur_modifie : public QDialog
{
    Q_OBJECT

public:
    explicit visiteur_modifie(QWidget *parent = nullptr);
    void getMod(QString nom, QString adresse, QString provenance);

    void getInfo(QString name, QString adress, QString prov);
    ~visiteur_modifie();

private slots:
    void on_visiteur_annuler_clicked();

    void on_visiteur_modifier_clicked();

private:
    Ui::visiteur_modifie *ui;
};

#endif // VISITEUR_MODIFIE_H
