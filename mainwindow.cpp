#include "mainwindow.h"
#include "ui_mainwindow.h"

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

#include "connexion.h"
#include <QtSql/QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    affichVisiteur(ui->visiteurTableWidget);
    affichSite(ui->siteTableWidget);
    affichVisite(ui->visiteTableWidget);
    affichHistogramme(ui->charts);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//AFFICHE
//visiteur
//ajouter
void MainWindow::affichVisiteur(QTableView *table){
    Connexion m_db;
    if(!m_db.connOpen())
    {
        qDebug() << "Failed to open database for visiteur";
    }
    m_db.connOpen();
    model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM visiteurs");
    model->setHeaderData(0,Qt::Horizontal,tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal,tr("provenance"));
//    ui->visiteur_modifie->setDisabled(true);
//    ui->visiteur_supprime->setDisabled(true);
    table->setModel(model);
}

//site
void MainWindow::affichSite(QTableView *table){
    Connexion m_db;
    if(!m_db.connOpen()){
        qDebug() << "Failed to open databese for site";
    }
    m_db.connOpen();
    model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Site");
    model->setHeaderData(0,Qt::Horizontal,tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,tr("lieux"));
    model->setHeaderData(3,Qt::Horizontal,tr("tarife journalier"));
    ui->site_modifie->setDisabled(true);
    ui->site_supprime->setDisabled(true);
    table->setModel(model);
}
//visite
void MainWindow::affichVisite(QTableView *table){
    Connexion m_db;
    if(!m_db.connOpen()){
        qDebug() << "Failed to open database for visite";
    }
    m_db.connOpen();
    model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Visite");
    model->setHeaderData(0,Qt::Horizontal,tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,tr("nom du site"));
    model->setHeaderData(2,Qt::Horizontal,tr("nombre du jour"));
    model->setHeaderData(3,Qt::Horizontal,tr("date de visite"));
    ui->visite_modifie->setDisabled(true);
    ui->visite_supprime->setDisabled(true);
    table->setModel(model);
}
//charts
void MainWindow::affichHistogramme(QWidget *charts){
    //Data pour les Chart
        QBarSet *set0 = new QBarSet("Visiteur");
        QBarSet *set1 = new QBarSet("Site");
        QBarSet *set2 = new QBarSet("Visite");

        *set0 << 30 << 40 << 10 << 20 << 10 << 60;
        *set1 << 25 << 58 << 60 << 40 << 10 << 100;
        *set2 << 80 << 100 << 70 << 13 << 60 << 45;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Histogramme");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Jan"<< "Fev"<< "Mar"<< "Avr"<< "Mai"<< "Jui"<< "Juil"<< "Auo"<< "Sep"<< "Nov"<< "Dec";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        QChartView *chartView = new QChartView();
        chartView->setParent(ui->charts);
        chartView->setChart(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    charts->show();
}

//MODIFICATION
//Visiteur



//SUPPRESSION
//Visiteur


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
    affichVisiteur(ui->visiteurTableWidget);
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




// AFFICHAGE FENETRE VISITEUR MODIFIER

void MainWindow::afficheVisiteur(){
    visiteur_modifie cg;
    cg.getMod(noms, adresses, provenances);
    cg.setModal(true);
    cg.exec();
    affichVisiteur(ui->visiteurTableWidget);
}

//MODIFIER
void MainWindow::on_visiteur_modifie_clicked()
{
    // Obtient l'index actuellement sélectionné dans la table
    QModelIndex index = ui->visiteurTableWidget->selectionModel()->currentIndex();

    // Vérifie si un index est sélectionné
    if (index.isValid()) {
        if (index.isValid()) {
            // Récupérer les données pour chaque colonne
            QVariant dataCol1 = ui->visiteurTableWidget->model()->data(ui->visiteurTableWidget->model()->index(index.row(), 1));
            QVariant dataCol2 = ui->visiteurTableWidget->model()->data(ui->visiteurTableWidget->model()->index(index.row(), 2));
            QVariant dataCol3 = ui->visiteurTableWidget->model()->data(ui->visiteurTableWidget->model()->index(index.row(), 3));


            // Convertir les données en chaînes de caractères
            noms = dataCol1.toString();
            adresses = dataCol2.toString();
            provenances = dataCol3.toString();
        }
        afficheVisiteur();

}
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
