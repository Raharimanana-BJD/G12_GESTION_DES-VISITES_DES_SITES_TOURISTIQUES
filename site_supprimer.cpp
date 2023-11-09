#include "site_supprimer.h"
#include "ui_site_supprimer.h"

site_supprimer::site_supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::site_supprimer)
{
    ui->setupUi(this);
}

site_supprimer::~site_supprimer()
{
    delete ui;
}


void site_supprimer::on_site_annule_clicked()
{
    this->close();
}

