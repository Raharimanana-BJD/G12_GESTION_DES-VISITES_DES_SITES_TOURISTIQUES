#include "site_ajout.h"
#include "ui_site_ajout.h"
#include "connexion.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

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


void site_ajout::on_site_ajouter_clicked()
{
    Connexion m_db;
    if(!m_db.connOpen())
    {
        qDebug() << "Failed to open database";
        return;
    }
    m_db.connOpen();

   QString Nom = ui->nomDuSiteAjout->text();
   QString lieu = ui->lieuDuSiteAjout->text();
   QString tarifJournalie = ui->tarifJournalieDuSiteAjout->text();

   if(Nom.isEmpty() || lieu.isEmpty() || tarifJournalie.isEmpty())
   {
       qDebug() << "Veuille remplir tous les champs";
   }else {
    QSqlQuery requ;
    QString verifProd = "SELECT COUNT(*) FROM Site WHERE Nom = :Nom";
    requ.prepare(verifProd);
    requ.bindValue(":Nom", Nom);
    requ.exec();
    if(requ.next())
    {
        if(requ.value(0).toInt() > 0)
        {
            qDebug() << Nom +" est déjà saisi";
        }else {
        QSqlQuery req;
        QString requete = "INSERT INTO Site(Nom, lieux, tarifeJournalier) VALUES(:Nom, :lieu, :tarifJournalie)";
        req.prepare(requete);
        req.bindValue(":Nom", Nom);
        req.bindValue(":lieux", lieu);
        req.bindValue(":tarifeJournalie", tarifJournalie);
        req.exec();
        m_db.connClose();
        this->close();
        }
    }
}
}

