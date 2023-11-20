QT       += core gui
QT += sql
QT +=core
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    site_ajout.cpp \
    site_modifie.cpp \
    site_supprimer.cpp \
    visite_ajout.cpp \
    visite_modifie.cpp \
    visite_supprimer.cpp \
    visiteur_ajout.cpp \
    visiteur_modifie.cpp \
    visiteur_supprimer.cpp

HEADERS += \
    connexion.h \
    mainwindow.h \
    site_ajout.h \
    site_modifie.h \
    site_supprimer.h \
    visite_ajout.h \
    visite_modifie.h \
    visite_supprimer.h \
    visiteur_ajout.h \
    visiteur_modifie.h \
    visiteur_supprimer.h

FORMS += \
    mainwindow.ui \
    site_ajout.ui \
    site_modifie.ui \
    site_supprimer.ui \
    visite_ajout.ui \
    visite_modifie.ui \
    visite_supprimer.ui \
    visiteur_ajout.ui \
    visiteur_modifie.ui \
    visiteur_supprimer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Assets.qrc
