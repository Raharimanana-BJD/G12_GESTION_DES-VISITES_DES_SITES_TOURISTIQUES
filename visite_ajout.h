#ifndef VISITE_AJOUT_H
#define VISITE_AJOUT_H

#include <QDialog>

namespace Ui {
class visite_ajout;
}

class visite_ajout : public QDialog
{
    Q_OBJECT

public:
    explicit visite_ajout(QWidget *parent = nullptr);
    ~visite_ajout();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::visite_ajout *ui;
};

#endif // VISITE_AJOUT_H
