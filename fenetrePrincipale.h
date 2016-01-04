/***************************************************************************************************
Copyright [Rémi Matthieu RODRIGUES], ([15 JANVIER 2012])

[remi_rodrigues@hotmail.com]

Ce logiciel est un programme informatique servant à générer automatiquement des lettres
de motivation à destination des étudiants recherchant un stage ou un premier emploi.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
************************************************************************************************/

/* Logiciel Réalisé à l'aide de la bibliothèque QT */

/* Mon site : http://www.smartful.fr/  */

#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QRadioButton>
#include <QTextEdit>
#include <QSpinBox>

class fenetrePrincipale : public QWidget
{
    Q_OBJECT

    public:
    fenetrePrincipale();

    private slots:
    void genererCode();

    private:
    /*Les boutons*/
    QPushButton *m_bouton1;
    QPushButton *m_bouton2;

    /*Le layout principal*/
    QVBoxLayout *layoutPrincipal;

    /*Les conteneurs*/
    QGroupBox *Vous;
    QGroupBox *Entreprise;
    QGroupBox *Taches;


    /*Les champs en ligne de texte*/

    //Le chercheur d'emploi
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *adresse;
    QLineEdit  *postal;
    QLineEdit *ville;
    QLineEdit *courriel;
    QLineEdit *telephone;
    QLineEdit *diplome;
    QLineEdit *formation;

    //L'entreprise
    QLineEdit *nom_entreprise;
    QLineEdit *adresse_entreprise;
    QLineEdit  *postal_entreprise;
    QLineEdit *ville_entreprise;


    /*Le champ texte*/
    QTextEdit *taches_stages;

    /*Champ de la date*/
    QDateEdit *date;

    /*Les champs à cocher*/
    QRadioButton *homme;
    QRadioButton *femme;
    QRadioButton *emploi1;
    QRadioButton *stage;

};



#endif // FENETREPRINCIPALE_H
