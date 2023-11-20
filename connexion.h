#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QDebug>

class Connexion{
public:

    QSqlDatabase mydb;

    void connClose() {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen() {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Bray/Desktop/copy-G12-Gestion-des-visites-des-sites-touristiques/dbase.db");
        if (!mydb.open()) {
            qDebug() << "Échec d'ouverture de la base de données" << mydb.databaseName();
            return false;
        } else {
            qDebug() << "Connexion réussie à la base de données" << mydb.databaseName();
            return true;
        }
    }
};

#endif // CONNECTION_H
