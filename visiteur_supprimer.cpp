#include "visiteur_supprimer.h"
#include "ui_visiteur_supprimer.h"

visiteur_supprimer::visiteur_supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visiteur_supprimer)
{
    ui->setupUi(this);
}

visiteur_supprimer::~visiteur_supprimer()
{
    delete ui;
}



void visiteur_supprimer::on_visiteur_annule_clicked()
{
    this->close();
}

