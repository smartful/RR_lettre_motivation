/***************************************************************************************************
Copyright [R�mi Matthieu RODRIGUES], ([15 JANVIER 2012])

[remi_rodrigues@hotmail.com]

Ce logiciel est un programme informatique servant � g�n�rer automatiquement des lettres
de motivation � destination des �tudiants recherchant un stage ou un premier emploi.

Ce logiciel est r�gi par la licence CeCILL-B soumise au droit fran�ais et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffus�e par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilit� au code source et des droits de copie,
de modification et de redistribution accord�s par cette licence, il n'est
offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les conc�dants successifs.

A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
associ�s au chargement,  � l'utilisation,  � la modification et/ou au
d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
avertis poss�dant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
logiciel � leurs besoins dans des conditions permettant d'assurer la
s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.

Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accept� les
termes.
************************************************************************************************/

/* Logiciel R�alis� � l'aide de la biblioth�que QT */

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

    /*Les champs � cocher*/
    QRadioButton *homme;
    QRadioButton *femme;
    QRadioButton *emploi1;
    QRadioButton *stage;

};



#endif // FENETREPRINCIPALE_H
