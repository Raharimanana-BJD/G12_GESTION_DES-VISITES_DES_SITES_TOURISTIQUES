#include "visite_ajout.h"
#include "ui_visite_ajout.h"

visite_ajout::visite_ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visite_ajout)
{
    ui->setupUi(this);
}

visite_ajout::~visite_ajout()
{
    delete ui;
}

