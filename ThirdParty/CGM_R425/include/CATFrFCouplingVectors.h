//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFCouplingVectors:
// c est une classe contenant un ensemble de vecteurs dont les 
// coordonnees renseignent sur les couplages entre CCVs. 
//
// Pour remplir la liste de CATFrFCouplingVectors, faire des NEW 
// sur des CATFrFCouplingPts. 
// les deletes sont geres dans le destructeur de CATFrFCouplingVectors.
//
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// April,   2005 : ANR/FZA : Creation 
//==========================================================================

#ifndef CATFrFCouplingVectors_H
#define CATFrFCouplingVectors_H

#include "CATFrFNetSurface.h"

#include "CATFrFCoupling.h"
#include "CATFrFCouplingPts.h"
#include "CATListOfCATFrFCouplingPts.h"

//-----------------------------------------------------------------------------
class ExportedByCATFrFNetSurface CATFrFCouplingVectors 
{
  public :

//-------------------  CopyConstructeur ------------------- 
   CATFrFCouplingVectors (CATFrFCouplingVectors &iloftvalues); 

   //CATFrFCouplingVectors (CATFrFCouplingVectors iloftvalues); 

//-------------------  Constructeur ------------------- 
    CATFrFCouplingVectors();


//-------------------  Destructor ---------------------
    virtual ~CATFrFCouplingVectors();

//------------------- Les methodes --------------------    
// Lecture de la liste des points couples
   CATLISTP(CATFrFCouplingPts) * GetListePtsCouples();
/* Coverage
// Ecriture de la liste des points couples
   void SetListePtsCouples(CATLISTP(CATFrFCouplingPts) * liste);
*/
// Insertion au sein de la liste d un CATFrFCouplingPts en prenant en 
// compte un parametre generalise le CATLONG32 de la monopare et w croissant,
// si le mapping n est pas connu, alors les valeurs w sont incluses dans
// les donnees CATFrFCouplingPts.
// si, ni le mapping ni w ne sont connus alors Point est place a la
// fin de la liste.
// 
// Si le status de retour est a true, le "CATFrFCouplingPts * Point" a bien ete
// ajoute. Dans le cas contraire, il n'a pas ete ajoute, l'appelant doit 
// le detruire (pour ne pas provoquer de mlk). 
// 
    CATBoolean InsertMappingCouplingPt(double iEpsParam, CATFrFCouplingPts * Point,
                                       CATFrFCoupling    * mapping=NULL);
/* Coverage
// report des limites sur les autres CCVs du reseau et de la 
// topologie de la dominante sur les autres . 
// si inumdom < 0 pas de report de la dominante. 
    void SetType(CATLONG32 inumdom);

  // dump de la liste contenu dans l objet CATFrFCouplingVectors
    void Dump();
*/
    // rend la taille de la CATLISTP
    CATLONG32 Size();

  private :

    CATLISTP(CATFrFCouplingPts) * _CouplingPts ;

};

#endif





