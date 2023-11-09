#include "site_ajout.h"
#include "ui_site_ajout.h"

site_ajout::site_ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::site_ajout)
{
    ui->setupUi(this);
}

site_ajout::~site_ajout()
{
    delete ui;
}

void site_ajout::on_site_annuler_clicked()
{
    this->close();
}

