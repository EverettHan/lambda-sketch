/* -*-C++-*- */

#ifndef CATTopCleanCrvOperatorBridge_H
#define CATTopCleanCrvOperatorBridge_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// Class and functions are @nodoc and will soon be destroyed : Do not use

//=============================================================================
//=============================================================================
//
// CATTopCleanCrvOperatorBridge : Pile "Topo" du Pont logiciel
//                                permettant l'utilisation de CleanCurve
//                                dans le fw Topo.
//
// Classe abstraite qui permet d'appeler les fonctions de CleanCurve
// via le pont
// + definition de la fonction de chargement dynamique de la librairie
//
//=============================================================================

//=============================================================================
// Jan  2003  Creation                                        P. Rossignol
//=============================================================================
//=============================================================================

// Pour le ExportBy
#include "RibbonLight.h"


// Includes 
#include "ListPOfCATVertex.h"
#include "CATTopRibDef.h"
#include "CATCGMVirtual.h"
#include "CATMathDef.h"
#include "CATTopCleanCrvOperatorDef.h"
#include "CATFreeFormDef.h"


//--------------------------------------------------------------------
// Signature CallBack de Nettoyage
//--------------------------------------------------------------------
class CATTopCleanCrvOperatorBridge;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATLISTP(CATCell);

typedef CATTopCleanCrvOperatorBridge*  (*CATTopCleanCrvOperatorCreator)  
 (CATGeoFactory     *iFactory, CATTopData        *iTopData,  CATBody           *iWireBody) ;



//class  ExportedByCATFDGImpl CATTopCleanCrvOperatorBridge
class ExportedByRibbonLight CATTopCleanCrvOperatorBridge : public CATCGMVirtual
{

public :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Creation d'un objet cree comme un CATAdvTopCleanCrvOperatorBridge 
  //                     etvu comme un CATTopCleanCrvOperatorBridge 
  //------------------------------------------------------------------------------
  static CATTopCleanCrvOperatorBridge* Create(CATGeoFactory     *iFactory, 
                                              CATTopData        *iTopData,  
                                              CATBody           *iWireBody);

  //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATTopCleanCrvOperatorBridge() {};

  //------------------------------------------------------------------------------
  // Sets pour piloter le cleancurve
  //------------------------------------------------------------------------------
  virtual CATLONG32 SetShell(CATBody* iShellBody)         = 0;
  virtual CATLONG32 SetConnexityGap(CATLength iVertexGap) = 0;
  virtual CATLONG32 SetLayDown(const int iLayDown = 1)    = 0;
  virtual CATLONG32 SetFixedCells(const CATLISTP(CATCell)& iFixedCells) = 0;

  virtual CATLONG32 SetLocalOptimization(const int iOptimization) = 0;
  virtual CATLONG32 SetCurvatureRatio(double iCurvatureRatio) = 0;
  virtual CATLONG32 SetPriorityMode(CatTopCleanCrvPriorityMode  iMode) = 0;
  virtual CATLONG32 SetContinuityLevel(CATFrFContinuity iLevel) = 0;
  virtual CATLONG32 SetCellReduction(CATBoolean iCellReduction) = 0;
  virtual CATLONG32 SetForceOneEdgeImprovement(CATBoolean iEnable) = 0;
  virtual CATLONG32 SetApplyMappingOfInitialVertices(const int iApplyMapping = 0) = 0;
  virtual CATLONG32 SetMaxDeformation(CATLength iMaxDeformation) = 0;
  virtual CATLength GetMaxReachedDeformation() = 0;

  //------------------------------------------------------------------------------
  // Lancement et recuperation du resultat
  //------------------------------------------------------------------------------
  virtual int      Run()       = 0;  
  virtual CATBody* GetResult() = 0;

private:
//===========================================================================================================


};



#endif

