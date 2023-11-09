#ifndef SITE_MODIFIE_H
#define SITE_MODIFIE_H

#include <QDialog>

namespace Ui {
class site_modifie;
}

class site_modifie : public QDialog
{
    Q_OBJECT

public:
    explicit site_modifie(QWidget *parent = nullptr);
    ~site_modifie();

private slots:
    void on_pushButton_2_clicked();

    void on_site_annuler_clicked();

private:
    Ui::site_modifie *ui;
};

#endif // SITE_MODIFIE_H
