#include "visite_modifie.h"
#include "ui_visite_modifie.h"

visite_modifie::visite_modifie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visite_modifie)
{
    ui->setupUi(this);
}

visite_modifie::~visite_modifie()
{
    delete ui;
}

void visite_modifie::on_visite_annuler_clicked()
{
    this->close();
}

