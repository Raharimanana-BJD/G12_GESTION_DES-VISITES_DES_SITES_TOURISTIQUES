#include "site_modifie.h"
#include "ui_site_modifie.h"

site_modifie::site_modifie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::site_modifie)
{
    ui->setupUi(this);
}

site_modifie::~site_modifie()
{
    delete ui;
}

void site_modifie::on_site_annuler_clicked()
{
    this->close();
}

