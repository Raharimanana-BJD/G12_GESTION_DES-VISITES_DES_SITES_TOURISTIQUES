#ifndef VISITE_SUPPRIMER_H
#define VISITE_SUPPRIMER_H

#include <QDialog>

namespace Ui {
class visite_supprimer;
}

class visite_supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit visite_supprimer(QWidget *parent = nullptr);
    ~visite_supprimer();

private slots:
    void on_visite_annule_clicked();

private:
    Ui::visite_supprimer *ui;
};

#endif // VISITE_SUPPRIMER_H
