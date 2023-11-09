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
    ~visiteur_modifie();

private slots:
    void on_visiteur_annuler_clicked();

private:
    Ui::visiteur_modifie *ui;
};

#endif // VISITEUR_MODIFIE_H
