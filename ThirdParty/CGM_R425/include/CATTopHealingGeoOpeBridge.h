/* -*-C++-*- */

#ifndef CATTopHealingGeoOpeBridge_H
#define CATTopHealingGeoOpeBridge_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// Class and functions are @nodoc and will soon be destroyed : Do not use

//=============================================================================
//=============================================================================
//
// CATTopHealingGeoOpeBridge : Pile "Topo" du Pont logiciel
//                             permettant l'utilisation du Healing (geometrique)
//                             dans le fw Topo.
//
// Classe abstraite qui permet d'appeler les fonctions du Healing
// via le pont
// + definition de la fonction de chargement dynamique de la librairie
//
//=============================================================================

//=============================================================================
// Jan  2003  Creation                                        D. Prevost
//=============================================================================
//=============================================================================

// Pour le ExportBy
#include "Thick.h"

// Includes 
#include "CATCGMVirtual.h"
#include "ListPOfCATEdge.h"
#include "CATMathDef.h"
#include "CATGeoToTopOperator.h"


//--------------------------------------------------------------------
// Signature CallBack de Nettoyage
//--------------------------------------------------------------------
class CATTopHealingGeoOpeBridge;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATEdge;

typedef CATTopHealingGeoOpeBridge*  (*CATTopHealingGeoOpeCreator)  
       (CATGeoFactory *iFactory, CATTopData *iTopData, CATBody *iBodyToHeal);


class ExportedByThick CATTopHealingGeoOpeBridge : public CATCGMVirtual
{

public :
//===========================================================================================================

 //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATTopHealingGeoOpeBridge() {};

  //------------------------------------------------------------------------------
  // Sets pour piloter le Healing
  //------------------------------------------------------------------------------
  
  // Appends another edge to be healed.
  // 0 for a G0 continuity 
  // 1 for a G1 continuity (le G1 inclue le G0)
  virtual int Add(CATEdge * iE, const short iOrder)=0 ;
  
  // Defines the global default for the G0 continuity tolerance required 
  virtual void SetG0Tolerance(const double iTolG0)=0 ;
  
  // Defines the maximum G0 default for selecting the edges to be healed 
  virtual void SetMaxG0Tolerance(const double iTolG0Max)=0 ;	
  
  // Defines the maximum G1 default for selecting the edges to be healed 
  virtual void SetMaxG1Tolerance(const double iTolAngular)=0 ;	
  
  //Defines the global default for the G1 continuity tolerance.
  virtual void SetG1Tolerance(const double iTolAngular)=0 ;
  
  // Defines the Sharpness tolerance. 
  // -> pour l'application d'une vivicite logique
  virtual void SetSharpnessTolerance(const double iTolSharpness)=0 ;
  
  // Defines whether the resulting body must be frozen.
  virtual void SetFreezeMode(CATBodyFreezeMode iFreezeMode=CATBodyFreezeOn)=0 ;
  
  //------------------------------------------------------------------------------
  // Lancement et recuperation du resultat
  //------------------------------------------------------------------------------
  
  // METHODE D'EXECUTION
  virtual int Run()=0 ;
  
  // Returns the pointer to the resulting healed body.
  virtual CATBody * GetResult()=0 ;
  
  // Tests whether the continuity constraint is satisfied for a given edge relatively 
  virtual int IsSatisfied(CATEdge * iE , CATBoolean & ioIsSatisfied)=0 ;
  
  // The list of the pointers to the Edges that have not been corrected.
  virtual int GetOpenEdges(ListPOfCATEdge & ioListOfEdges)=0 ;


private:
//===========================================================================================================

};

#endif

