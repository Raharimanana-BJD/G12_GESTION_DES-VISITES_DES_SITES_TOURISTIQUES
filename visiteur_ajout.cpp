#include "visiteur_ajout.h"
#include "ui_visiteur_ajout.h"
#include "connexion.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

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



void visiteur_ajout::on_visiteur_ajouter_clicked()
{
    Connexion m_db;
    if(!m_db.connOpen())
    {
        qDebug() << "Failed to open database";
        return;
    }

    m_db.connOpen();

   QString nom = ui->nomDuVisiteurAjout->text();
   QString adresse = ui->adresseVisiteurAjout->text();
   QString provenance = ui->provenanceVisiteurAjout->text();

   if(nom.isEmpty() || adresse.isEmpty() || provenance.isEmpty())
   {
       qDebug() << "Veuille remplir tous les champs";
   }else {
    QSqlQuery requ;
    QString verifProd = "SELECT COUNT(*) FROM visiteurs WHERE nom = :nom";
    requ.prepare(verifProd);
    requ.bindValue(":nom", nom);
    requ.exec();
    if(requ.next())
    {
        if(requ.value(0).toInt() > 0)
        {
            qDebug() << nom +" est déjà saisi";
        }else {
        QSqlQuery req;
        QString requete = "INSERT INTO visiteurs(nom, adresse, provenance) VALUES(:nom, :adresse, :provenance)";
        req.prepare(requete);
        req.bindValue(":nom", nom);
        req.bindValue(":adresse", adresse);
        req.bindValue(":provenance", provenance);
        req.exec();
        m_db.connClose();
        this->close();
        }
    }
}
}
