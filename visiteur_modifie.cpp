#include "visiteur_modifie.h"
#include "ui_visiteur_modifie.h"
#include "connexion.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>


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

void visiteur_modifie::getInfo(QString name, QString adress, QString prov){
    QMessageBox::warning(this, "", "Le nom" + name + "Adreese" + adress + "Prov" + prov );

}


void visiteur_modifie::getMod(QString nom, QString adresse, QString provenance){
    ui->visiteurModifNom->setText(nom);
    ui->visiteurModifAdresse->setText(adresse);
    ui->visiteurModifProvenance->setText(provenance);

    QMessageBox::warning(this, "", "Le nom" + nom + "Adreese" + adresse + "Prov" + provenance );


}

void visiteur_modifie::on_visiteur_modifier_clicked() //    BOUTON CONFIRMER CLIC
{
    Connexion m_db;
    if(!m_db.connOpen()){
        qDebug() << "Failed to open database";
        return;
    }
    m_db.connOpen();

    QString nom = ui->visiteurModifNom->text();
    QString adresse = ui->visiteurModifAdresse->text();
    QString provenance = ui->visiteurModifProvenance->text();

    if(nom.isEmpty() || adresse.isEmpty() || provenance.isEmpty()){
        qDebug() <<"Veuillez remplir tous les champs";
    }

    QSqlQuery requ;
    QString verifProd = "select count(*) from visiteurs where nom = :nom";
    requ.prepare(verifProd);
    requ.bindValue(":nom", nom);  // Utiliser la variable correcte ici
    requ.bindValue(":adresse", adresse);  // Utiliser la variable correcte ici
    requ.bindValue(":provenance", provenance);  // Utiliser la variable correcte ici
    QSqlQuery req;
    QString requete = "UPDATE visiteurs SET nom = :nom, adresse = :adresse, provenance = :provenance";
    req.prepare(requete);
    req.bindValue(":nom", nom);
    req.bindValue(":adresse", adresse);
    req.bindValue(":provenance", provenance);
    req.exec();
    m_db.connClose();
    this->close();

}

void visiteur_modifie::on_visiteur_annuler_clicked()
{
    this->close();
}
