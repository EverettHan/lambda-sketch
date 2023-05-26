/* -*-C++-*- */

#ifndef CATTopRibNupletConnexion_H
#define CATTopRibNupletConnexion_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
// Usage notes:
// CATTopRibNupletConnexion
// Definit la connexion "objectif" entre deux nuplets, i.e l'endroit 
// (topologique et geometrique) ou les traces sur les supports de 
// deux Nuplets doivent se raccorder pour maintenir l'etancheite du 
// B-Rep 
//
//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibDef.h"   
#include "CATMathDef.h"   
#include "CATCGMNewArray.h" // Pool allocation

class CATTopRibSuppConnexion;
class CATCell;

#include "CATSafe.h"
CATSafeDefine(CATTopRibNupletConnexion);

class ExportedByRIBLight CATTopRibNupletConnexion 
{
 public: 

  //-----------------------------------------------------------------
  // Constructor
  //-----------------------------------------------------------------
  CATTopRibNupletConnexion(int iNbSupp);

  /*
  CATTopRibNupletConnexion(const CATTopRibNupletConnexion * iToCopy);
  */

  CATCGMNewClassArrayDeclare; // Pool allocation

  //-----------------------------------------------------------------
  // Destructor
  //-----------------------------------------------------------------
  ~CATTopRibNupletConnexion();

  //-----------------------------------------------------------------
  // Reading methods 
  //-----------------------------------------------------------------
  CATTopRibSuppConnexion* GetSupp(int iNumSupp);

  //-----------------------------------------------------------------
  // Setting methods 
  //-----------------------------------------------------------------
  void SetSupp(int iNumSupp, CATTopRibSuppConnexion* iSuppConnexion);

  //-----------------------------------------------------------------
  // Is healing required 
  // if required, then for which support
  //-----------------------------------------------------------------
  CATBoolean IsHealingNeeded(CATBoolean oHealingSupp[CATTopRibMaxSupp]);
  
  void                     RemoveSupp(int iNumSupp);
  void                     Completed();
  CATBoolean               HasDefGeo();
  void                     UnLock();

 public: // a rendre privées

  //-----------------------------------------------------------------
  // _TypeDef : _TypeDef[0] et _TypeDef[1] = Gap entre fin de la trace et bord du support.
  //	        _TypeDef[2]                = Gap entre les deux supports succesifs.
  //-----------------------------------------------------------------
  CATTopRibConnexion        _TypeDef[3];

  //-----------------------------------------------------------------
  // _Gap : _Gap[0] et _Gap[1]  = Gap entre fin de la trace et bord du support.
  //        _Gap[2]             = Surestimation du Gap entre les deux supports succesifs 
  //                            = racine (GapTangentiel^2 + GapNormal^2).
  //        _Gap[3]             = Composante tangentielle du _Gap[2], i.e. seul Gap recuperable par deformation.
  //-----------------------------------------------------------------
  double                    _Gap[4];

  //-----------------------------------------------------------------
  // Is a deformation needed ?
  //-----------------------------------------------------------------
  CATBoolean                _DefNeeded;

  //-----------------------------------------------------------------
  // Donnees et Methodes pour l'hermetisation
  //-----------------------------------------------------------------
  CATBoolean                _HermetisationNeeded;

private:
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Donnees privees
  //------------------------------------------------------------------------------    
  CATTopRibSuppConnexion ** _TabSuppConnexion;
  int                       _NbSuppConnexion;
  CATBoolean                _UpToDate;

  //------------------------------------------------------------------------------
  // Juste pour eviter que le compilo ne definisse par lui-meme ces operateurs
  //------------------------------------------------------------------------------    
  CATTopRibNupletConnexion();
  CATTopRibNupletConnexion(CATTopRibNupletConnexion& iOperator);
  CATTopRibNupletConnexion& operator=(const CATTopRibNupletConnexion & iOperator);

};

#endif

