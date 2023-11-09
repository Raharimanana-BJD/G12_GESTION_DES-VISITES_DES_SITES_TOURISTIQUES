#include "visiteur_ajout.h"
#include "ui_visiteur_ajout.h"

visiteur_ajout::visiteur_ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visiteur_ajout)
{
    ui->setupUi(this);
}

visiteur_ajout::~visiteur_ajout()
{
    delete ui;
}

void visiteur_ajout::on_visiteur_annuler_clicked()
{
    this->close();
}


