#include "visiteur_modifie.h"
#include "ui_visiteur_modifie.h"

visiteur_modifie::visiteur_modifie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visiteur_modifie)
{
    ui->setupUi(this);
}

visiteur_modifie::~visiteur_modifie()
{
    delete ui;
}

void visiteur_modifie::on_visiteur_annuler_clicked()
{
    this->close();
}

