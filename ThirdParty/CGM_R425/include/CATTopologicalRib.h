// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATTopoRib:
// Interface class of the TopologicalRib Operator.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// July  98 JBX Creation                                                 JBX
//          jhn introduction du TopData et du CreateTopologicalRib avec TopData
// 12/07/16 NLD Suppression du constructeur sans TopData
//              Deplacement du CreateTopologicalRib dans le fichier eponyme
//==========================================================================
//
#ifndef CATTopologicalRib_H
#define CATTopologicalRib_H
//
#include "FrFTopologicalOpe.h"
#include "CATMathDef.h"
#include "CATMathBox.h"
#include "CreateTopologicalRib.h"
//
class CATWire;
class CATCell;

//
//-----------------------------------------------------------------------------
class ExportedByFrFTopologicalOpe CATTopologicalRib : public CATTopOperator
{
  public :

    CATTopologicalRib(CATGeoFactory * iFacto, CATTopData * iData)          ;
//  CATTopologicalRib(CATGeoFactory * iFacto);
    virtual              ~CATTopologicalRib()          ;
 
    //    
    // Methodes en mode BASIC 
    //
  
    // Si un TargetBody est en entree du Createur (cf. signature du createur)
    // c est celui ci qui est retourne par cette methode, sinon un CATBody
    // est cree.
    virtual CATBody*     GetResult()=0;

    //
    // Methodes en mode ADVANCED
    //

    // Seulement la valeur absolue des offsets est gardee
    // La premiere valeur correspond a l offset dans la direction
    // NormalSupport ^ TgtWire
    // La seconde valeur a celui dans la direction -(NormalSupport^TgtWire)
    virtual void SetOffsetValues(double iVal1, double iVal2) = 0;
  
    // Cette methode extrapole le wire en entree avant de creer les wires
    // offsetes et ce suivant les specifications de l operateur 
    // CATExrapolateBody (cf. sa signature dans le FW TopologicalOperator)
    virtual void SetLimitToExtrapolate(CATCell    * iEndCell,
                                       CATMathBox * iSourceBox,
                                       CATMathBox * iTargetBox) = 0;

};
#endif


