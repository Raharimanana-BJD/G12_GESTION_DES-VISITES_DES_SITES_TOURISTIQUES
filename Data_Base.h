#ifndef DATA_BASE_H
#define DATA_BASE_H
#include <QtSql/QSqlQuery>
#include <QDebug>

class Data_base{
public:

    QSqlDatabase myData;

    void connClose() {
        myData.close();
        myData.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen() {
        myData = QSqlDatabase::addDatabase("QSQLITE");
        myData.setDatabaseName(":/Data.db");
        if (!myData.open()) {
            qDebug() << "Échec d'ouverture de la base de données" << myData.databaseName();
            return false;
        } else {
            qDebug() << "Connexion réussie à la base de données" << myData.databaseName();
            return true;
        }
    }
};

#endif // DATA_BASE_H
