#ifndef VISITE_MODIFIE_H
#define VISITE_MODIFIE_H

#include <QDialog>

namespace Ui {
class visite_modifie;
}

class visite_modifie : public QDialog
{
    Q_OBJECT

public:
    explicit visite_modifie(QWidget *parent = nullptr);
    ~visite_modifie();

private slots:
    void on_visite_annuler_clicked();

private:
    Ui::visite_modifie *ui;
};

#endif // VISITE_MODIFIE_H
