#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStackedWidget"

//visiteur
#include "visiteur_ajout.h"
#include "visiteur_modifie.h"
#include "visiteur_supprimer.h"

//site
#include "site_ajout.h"
#include "site_modifie.h"
#include "site_supprimer.h"

//visite
#include "visite_ajout.h"
#include "visite_modifie.h"
#include "visite_supprimer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//AJOUTER
void MainWindow::on_visiteur_ajout_clicked()
{
    visiteur_ajout *visiteurAjout = new visiteur_ajout();
    visiteurAjout->setModal(true);
    visiteurAjout->exec();
}
void MainWindow::on_site_ajout_clicked()
{
    site_ajout *siteAjout = new site_ajout();
    siteAjout->setModal(true);
    siteAjout->exec();
}
void MainWindow::on_visite_ajout_clicked()
{
    visite_ajout *visiteAjout = new visite_ajout();
    visiteAjout->setModal(true);
    visiteAjout->exec();
}

//MODIFIER
void MainWindow::on_visiteur_modifie_clicked()
{
    visiteur_modifie *visiteurModifie = new visiteur_modifie();
    visiteurModifie->setModal(true);
    visiteurModifie->exec();
}
void MainWindow::on_site_modifie_clicked()
{
    site_modifie *siteModifie = new site_modifie();
    siteModifie->setModal(true);
    siteModifie->exec();
}
void MainWindow::on_visite_modifie_clicked()
{
   visite_modifie *visiteModifie = new visite_modifie();
   visiteModifie->setModal(true);
   visiteModifie->exec();
}

//SUPPRIMER
void MainWindow::on_visiteur_supprime_clicked()
{
    visiteur_supprimer *visiteurSupprime = new visiteur_supprimer();
    visiteurSupprime->setModal(true);
    visiteurSupprime->exec();
}
void MainWindow::on_site_supprime_clicked()
{
    site_supprimer *siteSupprime = new site_supprimer();
    siteSupprime->setModal(true);
    siteSupprime->exec();
}
void MainWindow::on_visite_supprime_clicked()
{
    visite_supprimer *visiteSupprime = new visite_supprimer();
    visiteSupprime->setModal(true);
    visiteSupprime->exec();
}

