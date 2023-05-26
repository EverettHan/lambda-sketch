/* -*-C++-*- */

#ifndef CATBToD_Bdg_H
#define CATBToD_Bdg_H

// COPYRIGHT DASSAULT SYSTEMES 2022

// Class and functions are @nodoc and could be destroyed : Debug use only

//=============================================================================
//=============================================================================
//
// CATBToD_Bdg : Pile cote pauvre
//
//=============================================================================

//=============================================================================
// Nov  2022  Creation                                        P. Rossignol
//=============================================================================
//=============================================================================

// Pour le ExportBy
#include "TopExtrudeRecog.h"

// Derivation
#include "CATCGMVirtual.h"

// BtoD
#include "CATCGMConvergerDef.h"

//------------------------------------------------------------------------------
// Signature 
//------------------------------------------------------------------------------
class CATBToD_Bdg;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATFace;

typedef CATBToD_Bdg*  (*CATBToD_BdgAdvCreator)  
                      (CATGeoFactory     *iFactory, CATTopData        *iTopData, CATBody           *iBody) ;


class ExportedByMdlTopExtr CATBToD_Bdg : public CATCGMVirtual
{

public :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Creation d'un objet cree     comme un CATBToD_BdgAdv 
  //                     et rendu comme un CATBToD_Bdg 
  //------------------------------------------------------------------------------
  static CATBToD_Bdg* Create(CATGeoFactory     *iFactory, 
                             CATTopData        *iTopData,  
                             CATBody           *iBody);

  //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATBToD_Bdg() {};

  //------------------------------------------------------------------------------
  // Sets pour piloter le BtoD - On fait comme pour le Converger
  //------------------------------------------------------------------------------
  virtual void SetAppli             ( CATCVG_ApplicationName          iName) = 0;   
  virtual void AddRefFeature        ( CATCVG_FeatureType              iType) = 0;
  virtual void SetRefFaceForWalls   ( CATFace*                        iFace) = 0;
  
  //------------------------------------------------------------------------------
  // Lancement //et recuperation du resultat?
  //------------------------------------------------------------------------------
  virtual int  Run                  ()                                       = 0;  
  virtual void GetResult            (CATBody*& oResBody)                     = 0;

private:
//===========================================================================================================


};



#endif

