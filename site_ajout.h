#ifndef SITE_AJOUT_H
#define SITE_AJOUT_H

#include <QDialog>

namespace Ui {
class site_ajout;
}

class site_ajout : public QDialog
{
    Q_OBJECT

public:
    explicit site_ajout(QWidget *parent = nullptr);
    ~site_ajout();

private slots:
    void on_pushButton_2_clicked();

    void on_site_annuler_clicked();

    void on_site_ajouter_clicked();

private:
    Ui::site_ajout *ui;
};

#endif // SITE_AJOUT_H
