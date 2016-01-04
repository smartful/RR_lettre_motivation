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

#include "fenetrePrincipale.h"
#include "fenetreG.h"



fenetrePrincipale::fenetrePrincipale()
{
    //Cr�ation des groupBox
    Vous = new QGroupBox("Votre description",this);
    Entreprise = new QGroupBox("Description de l'entreprise",this);
    Taches = new QGroupBox("T�ches r�alis�es en stages ou en projet d�crivant vos comp�tences",this);

    //Cr�ation des champs textes

    /*champ relatif au chercheur d'emploi*/
    nom = new QLineEdit;
    prenom = new QLineEdit;
    adresse = new QLineEdit;
    ville = new QLineEdit;
    courriel = new QLineEdit;
    telephone = new QLineEdit;
    diplome = new QLineEdit;
    formation = new QLineEdit;

    /*champ relatif � l'entreprise*/
    nom_entreprise = new QLineEdit;
    adresse_entreprise = new QLineEdit;
    ville_entreprise = new QLineEdit;

    //Cr�ation du champ des chiffres
    postal = new QLineEdit;
    postal_entreprise = new QLineEdit;

    //Cr�ation du champs de la date
    date = new QDateEdit;
    date->setDate(QDate::currentDate());

    //Cr�ation des champs � cocher
    homme = new QRadioButton("Masculin",this);
    femme = new QRadioButton("F�minin",this);
    emploi1 = new QRadioButton("1er emploi",this);
    stage = new QRadioButton("Stage",this);

    homme->setChecked(true);
    emploi1->setChecked(true);

    //Cr�ation du champs d'�nonciation des t�ches
    taches_stages = new QTextEdit;

    //formation du box Vous
    QFormLayout *vbox_Vous = new QFormLayout;
    vbox_Vous->addRow("date de cr�ation :",date);
    vbox_Vous->addRow("pr�nom :",prenom);
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

    //formation du box de description des t�ches
    QFormLayout *vbox_Taches = new QFormLayout;
    vbox_Taches->addRow("t�ches effectu�es :",taches_stages);

    Taches->setLayout(vbox_Taches);

    //Cr�ation des boutons
    m_bouton1 = new QPushButton("Generation",this);
    m_bouton2 = new QPushButton("Quitter",this);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->setAlignment(Qt::AlignRight);
    hbox->addWidget(m_bouton1);
    hbox->addWidget(m_bouton2);

    //Cr�ation du Layout principal
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
    /*V�rification*/
    if(nom_entreprise->text().isEmpty())
    {
        QMessageBox::critical(this,"Erreur","Vous devez au moins renseigner le nom de l'entreprise");
        return; //arr�t de la m�thode
    }

    /*Si le nom de la classe est bien renseign�*/
    QString code;

    code += prenom->text() + " " + nom->text() + "\n";
    code += adresse->text()+ "\n";
    code += postal->text()+ " " + ville->text() + "\n";
    code += "courriel : "+courriel->text()+"\n";
    code += "t�l�phone : "+telephone->text()+"\n";

    code += "\t\t\t\t\t\t\t\t"+nom_entreprise->text()+"\n";
    code += "\t\t\t\t\t\t\t\t"+adresse_entreprise->text()+"\n";
    code += "\t\t\t\t\t\t\t\t"+postal_entreprise->text()+" "+ville_entreprise->text()+"\n\n";

    code += "\t\t\t\t\t\tle " + date->date().toString() + "\n\n\n";

    code += "Madame,Monsieur, \n\n";

    if(emploi1->isChecked())
    {
        code += "Titulaire d'un "+diplome->text()+", je suis actuellement � la recherche d'un premier ";
        code += "emploi dans votre secteur d'activit�.\n\n";
    }

    if(stage->isChecked())
    {
        code += "Pr�parant actuellement un "+diplome->text()+", je suis actuellement � la recherche d'un stage ";
        code += "dans votre secteur d'activit�.\n\n";
    }

    code += "Au cours de ma formation : "+formation->text()+", j'ai effectu� diff�rentes ";
    code += "exp�riences professionnelles, et r�alis� diff�rents projets, qui m'ont permis de mettre ";
    code += "en pratique mes connaissances et de d�velopper mes comp�tences � travers diff�rentes ";
    code += "t�ches dont les plus importantes �taient :\n"+taches_stages->toPlainText()+ "\n\n";

    if(homme->isChecked())
    {
        code += "Ma t�nacit� et mon sens de la rigueur sont de r�els atouts que je souhaite aujourd'hui ";
        code += "mettre au service de votre entreprise. Je serais heureux de vous exposer mon projet ";
        code += "professionnel, mais aussi de vous convaincre de l'int�r�t de ma collaboration au cours ";
        code += "d'un entretien.\n\n";
    }

    if(femme->isChecked())
    {
        code += "Ma t�nacit� et mon sens de la rigueur sont de r�els atouts que je souhaite aujourd'hui ";
        code += "mettre au service de votre entreprise. Je serais heureuse de vous exposer mon projet ";
        code += "professionnel, mais aussi de vous convaincre de l'int�r�t de ma collaboration au cours ";
        code += "d'un entretien.\n\n";
    }

    code += "Je vous remercie d'avoir consacr� du temps � la lecture de ma lettre, et je vous prie d'agr�er, ";
    code += "Madame, Monsieur, l'expression de mes sinc�res salutations.\n\n\n\n";
    code += "\t\t\t\t\t\t\t\t"+prenom->text()+" "+nom->text();


    /*Cr�ation et ex�cution de la fen�tre o� le code sera g�n�r�*/
    fenetreG *fenetreGenerer = new fenetreG(code,this);
    fenetreGenerer->exec();
}

