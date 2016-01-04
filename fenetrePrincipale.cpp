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

#include "fenetrePrincipale.h"
#include "fenetreG.h"



fenetrePrincipale::fenetrePrincipale()
{
    //Création des groupBox
    Vous = new QGroupBox("Votre description",this);
    Entreprise = new QGroupBox("Description de l'entreprise",this);
    Taches = new QGroupBox("Tâches réalisées en stages ou en projet décrivant vos compétences",this);

    //Création des champs textes

    /*champ relatif au chercheur d'emploi*/
    nom = new QLineEdit;
    prenom = new QLineEdit;
    adresse = new QLineEdit;
    ville = new QLineEdit;
    courriel = new QLineEdit;
    telephone = new QLineEdit;
    diplome = new QLineEdit;
    formation = new QLineEdit;

    /*champ relatif à l'entreprise*/
    nom_entreprise = new QLineEdit;
    adresse_entreprise = new QLineEdit;
    ville_entreprise = new QLineEdit;

    //Création du champ des chiffres
    postal = new QLineEdit;
    postal_entreprise = new QLineEdit;

    //Création du champs de la date
    date = new QDateEdit;
    date->setDate(QDate::currentDate());

    //Création des champs à cocher
    homme = new QRadioButton("Masculin",this);
    femme = new QRadioButton("Féminin",this);
    emploi1 = new QRadioButton("1er emploi",this);
    stage = new QRadioButton("Stage",this);

    homme->setChecked(true);
    emploi1->setChecked(true);

    //Création du champs d'énonciation des tâches
    taches_stages = new QTextEdit;

    //formation du box Vous
    QFormLayout *vbox_Vous = new QFormLayout;
    vbox_Vous->addRow("date de création :",date);
    vbox_Vous->addRow("prénom :",prenom);
    vbox_Vous->addRow("nom :",nom);
    vbox_Vous->addRow("adresse :",adresse);
    vbox_Vous->addRow("code postal :",postal);
    vbox_Vous->addRow("ville :",ville);
    vbox_Vous->addRow("courriel :",courriel);
    vbox_Vous->addRow("telephone :",telephone);
    vbox_Vous->addRow("diplome :",diplome);
    vbox_Vous->addRow("formation :",formation);
    vbox_Vous->addWidget(homme);
    vbox_Vous->addWidget(femme);

    Vous->setLayout(vbox_Vous);

    //formation du box Entreprise
    QFormLayout *vbox_Entreprise = new QFormLayout;
    vbox_Entreprise->addWidget(emploi1);
    vbox_Entreprise->addWidget(stage);
    vbox_Entreprise->addRow("nom :",nom_entreprise);
    vbox_Entreprise->addRow("adresse :",adresse_entreprise);
    vbox_Entreprise->addRow("code postale :",postal_entreprise);
    vbox_Entreprise->addRow("ville :",ville_entreprise);

    Entreprise->setLayout(vbox_Entreprise);

    //formation du box de description des tâches
    QFormLayout *vbox_Taches = new QFormLayout;
    vbox_Taches->addRow("tâches effectuées :",taches_stages);

    Taches->setLayout(vbox_Taches);

    //Création des boutons
    m_bouton1 = new QPushButton("Generation",this);
    m_bouton2 = new QPushButton("Quitter",this);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->setAlignment(Qt::AlignRight);
    hbox->addWidget(m_bouton1);
    hbox->addWidget(m_bouton2);

    //Création du Layout principal
    layoutPrincipal = new QVBoxLayout;
            layoutPrincipal->addWidget(Vous);
            layoutPrincipal->addWidget(Entreprise);
            layoutPrincipal->addWidget(Taches);
            layoutPrincipal->addLayout(hbox);

    setLayout(layoutPrincipal);
    setWindowTitle("RR_TextGenerator");
    resize(400,500);

    //Connection des boutons
    connect(m_bouton1,SIGNAL(clicked()),this,SLOT(genererCode()));
    connect(m_bouton2,SIGNAL(clicked()),qApp,SLOT(quit()));
}



void fenetrePrincipale::genererCode()
{
    /*Vérification*/
    if(nom_entreprise->text().isEmpty())
    {
        QMessageBox::critical(this,"Erreur","Vous devez au moins renseigner le nom de l'entreprise");
        return; //arrêt de la méthode
    }

    /*Si le nom de la classe est bien renseigné*/
    QString code;

    code += prenom->text() + " " + nom->text() + "\n";
    code += adresse->text()+ "\n";
    code += postal->text()+ " " + ville->text() + "\n";
    code += "courriel : "+courriel->text()+"\n";
    code += "téléphone : "+telephone->text()+"\n";

    code += "\t\t\t\t\t\t\t\t"+nom_entreprise->text()+"\n";
    code += "\t\t\t\t\t\t\t\t"+adresse_entreprise->text()+"\n";
    code += "\t\t\t\t\t\t\t\t"+postal_entreprise->text()+" "+ville_entreprise->text()+"\n\n";

    code += "\t\t\t\t\t\tle " + date->date().toString() + "\n\n\n";

    code += "Madame,Monsieur, \n\n";

    if(emploi1->isChecked())
    {
        code += "Titulaire d'un "+diplome->text()+", je suis actuellement à la recherche d'un premier ";
        code += "emploi dans votre secteur d'activité.\n\n";
    }

    if(stage->isChecked())
    {
        code += "Préparant actuellement un "+diplome->text()+", je suis actuellement à la recherche d'un stage ";
        code += "dans votre secteur d'activité.\n\n";
    }

    code += "Au cours de ma formation : "+formation->text()+", j'ai effectué différentes ";
    code += "expériences professionnelles, et réalisé différents projets, qui m'ont permis de mettre ";
    code += "en pratique mes connaissances et de développer mes compétences à travers différentes ";
    code += "tâches dont les plus importantes étaient :\n"+taches_stages->toPlainText()+ "\n\n";

    if(homme->isChecked())
    {
        code += "Ma ténacité et mon sens de la rigueur sont de réels atouts que je souhaite aujourd'hui ";
        code += "mettre au service de votre entreprise. Je serais heureux de vous exposer mon projet ";
        code += "professionnel, mais aussi de vous convaincre de l'intérêt de ma collaboration au cours ";
        code += "d'un entretien.\n\n";
    }

    if(femme->isChecked())
    {
        code += "Ma ténacité et mon sens de la rigueur sont de réels atouts que je souhaite aujourd'hui ";
        code += "mettre au service de votre entreprise. Je serais heureuse de vous exposer mon projet ";
        code += "professionnel, mais aussi de vous convaincre de l'intérêt de ma collaboration au cours ";
        code += "d'un entretien.\n\n";
    }

    code += "Je vous remercie d'avoir consacré du temps à la lecture de ma lettre, et je vous prie d'agréer, ";
    code += "Madame, Monsieur, l'expression de mes sincères salutations.\n\n\n\n";
    code += "\t\t\t\t\t\t\t\t"+prenom->text()+" "+nom->text();


    /*Création et exécution de la fenètre où le code sera généré*/
    fenetreG *fenetreGenerer = new fenetreG(code,this);
    fenetreGenerer->exec();
}

