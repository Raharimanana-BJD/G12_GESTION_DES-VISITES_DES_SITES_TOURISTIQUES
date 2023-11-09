#include "visite_supprimer.h"
#include "ui_visite_supprimer.h"

visite_supprimer::visite_supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visite_supprimer)
{
    ui->setupUi(this);
}

visite_supprimer::~visite_supprimer()
{
    delete ui;
}

void visite_supprimer::on_visite_annule_clicked()
{
    this->close();
}

