#include "visiteur_supprimer.h"
#include "ui_visiteur_supprimer.h"
#include "mainwindow.h"
#include "connexion.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

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


void visiteur_supprimer::on_visiteur_supprime_clicked()
{
    Connexion m_db;
    if(!m_db.connOpen()){
        qDebug() <<"Failed to open data base";
    }

    m_db.connOpen();
    QSqlQuery req;
    QString requette = "DELETE FROM Visiteur WHERE NumeroVisiteur = :num";
    req.prepare(requette);
    req.bindValue(":num", numeroVisiteur);
    req.exec();
    this->close();
}

