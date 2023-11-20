#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//DEFAULT
#include <QMainWindow>

//TABLE
#include <QTableView>
#include <QString>

//SQL
#include <QSqlQueryModel>

//Charts
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void afficheVisiteur();

    //visiteur
    QString numeroVisiteurs;
    QString noms;
    QString adresses;
    QString provenances;
    //site
    QString Nom;
    QString lieu;
    QString tarifJournalie;

    QSqlQueryModel *model;

    //select row data
    QString NumeroVisite;
    QString NumeroSite;
    QString NombreJour;
    QString DateVisite;

    //Layout
    void affichVisiteur(QTableView *table);
    void affichSite(QTableView *table);
    void affichVisite(QTableView *table);
    void affichHistogramme(QWidget *charts);

private slots:
    void on_button_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_visiteur_ajout_clicked();

    void on_site_ajout_clicked();

    void on_visite_ajout_clicked();

    void on_visite_modifie_clicked();

    void on_visiteur_modifie_clicked();

    void on_visiteur_supprime_clicked();

    void on_site_modifie_clicked();

    void on_site_supprime_clicked();

    void on_visite_supprime_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
