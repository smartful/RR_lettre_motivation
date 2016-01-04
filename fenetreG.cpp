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

#include "fenetreG.h"


fenetreG::fenetreG(QString &code, QWidget *parent=0): QDialog(parent)
{
    m_code = code;

    //Création du bouton
    m_bouton3 = new QPushButton("fermer",this);
    m_bouton4 = new QPushButton("sauvegarder",this);

    //On balance le code
    codeGenerer = new QTextEdit;
    codeGenerer->setPlainText(code);
    codeGenerer->setReadOnly(true);
    codeGenerer->setFont(QFont("Courier"));
    codeGenerer->setLineWrapMode(QTextEdit::NoWrap);


    //Mise en forme
    QVBoxLayout *layoutP = new QVBoxLayout;
    layoutP->addWidget(codeGenerer);
    layoutP->addWidget(m_bouton4);
    layoutP->addWidget(m_bouton3);

    resize(700, 650);
    setLayout(layoutP);

    //Connection du bouton
    QObject::connect(m_bouton3,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(m_bouton4,SIGNAL(clicked()),this,SLOT(sauvegarder()));
}



void fenetreG::sauvegarder()
{
    createFile(m_code);
}


void fenetreG::createFile(QString &code)
{
    //On permet de sauvegarder le document

    QFile file("lettre_motivation.odf");
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out << code;
    }

    file.close();
}

