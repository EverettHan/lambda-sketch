// COPYRIGHT DASSAULT SYSTEMES 1998 
//==========================================================================
//
// CATTopologicalDeviation:
// Interface class of the TopologicalDeviation Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for topological deviation operator
//
//========================================================================== 
//   May 98 OSN Creation                                   Olivier SCHOUTTETEN
// 22/06/01 jsx Tentative inaboutie de shunt par #define restant encore actif
// 21/06/16 NLD 15 ans apres
//              (la classe reste active avec ses tests au 21/06/16;
//               elle est meme interfacee avec CATPGMTopologicalDeviation)
//              commentaires. inversion des blocs de definition
//========================================================================== 
 
#ifndef CATTopologicalDeviation_H
#define CATTopologicalDeviation_H

#define CATTopologicalDev_OLD "(JSX220601) NLD210616: pas tout a fait a la nomenclature mais presque. Attention: nombreuses utilisations. classe+tests actifs"

#ifdef CATTopologicalDev_OLD

#include "CreateTopologicalDeviation.h"
#include "CATMathPoint.h"
#include "CATPGMTopologicalDeviation.h"

//-----------------------------------------------------------------------------
class ExportedByPowerTopologicalOpe CATTopologicalDeviation : public CATPGMTopologicalDeviation
{
  public :
  virtual       ~CATTopologicalDeviation();
//
//  Run : Compute Results
//
  virtual void   Run() = 0;
//
//  GetDistance
//
  virtual double GetDeviation() = 0;
//
//  SetThreshold
//
  virtual void   SetThreshold(double &iThreshold) = 0;
//
//  GetPointLocation
//
  virtual void   GetPointLocation(CATMathPoint &oPtB1,CATMathPoint &oPtB2) = 0;
};
#endif

#endif







