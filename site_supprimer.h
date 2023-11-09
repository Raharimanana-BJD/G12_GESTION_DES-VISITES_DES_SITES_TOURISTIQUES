#ifndef SITE_SUPPRIMER_H
#define SITE_SUPPRIMER_H

#include <QDialog>

namespace Ui {
class site_supprimer;
}

class site_supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit site_supprimer(QWidget *parent = nullptr);
    ~site_supprimer();

private slots:
    void on_pushButton_2_clicked();

    void on_site_annule_clicked();

private:
    Ui::site_supprimer *ui;
};

#endif // SITE_SUPPRIMER_H
