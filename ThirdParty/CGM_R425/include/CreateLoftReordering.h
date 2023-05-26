// COPYRIGHT DASSAULT SYSTEMES 1998
//=========================================================================
//
// CreateLoftReordering :
// reordering of 2 sets of curves (guides and bases) for the loft feature
// check to see if they are compatible for the loft : 
// 
//=========================================================================
// July   98 PRG   Design                                               PRG
// May  2001 PRG   Suppression du code remplace par le sweepOrdering
//=============================================================================
//#define LoftReorderingInactif
#ifdef LoftReorderingInactif

#ifndef CreateLoftReordering_H
#define CreateLoftReordering_H 

#include "FrFAdvancedOpeCrv.h"
#include "CATLoftReordering.h"
#include "CATSkillValue.h"
class CATGeoFactory;
class CATFrFCompositeCurve;

ExportedByFrFAdvancedOpeCrv
CATLoftReordering* CreateLoftReordering(      CATGeoFactory        * factory,
                                              CATLONG32              nbOfGuides,
                                              CATFrFCompositeCurve** guideCCVs,
                                              CATLONG32              nbOfBases,
                                              CATFrFCompositeCurve** baseCCVs,
                                        const CATSkillValue          iMode = BASIC);

ExportedByFrFAdvancedOpeCrv
void Remove(CATLoftReordering *&iLoftReordering);
#endif
#endif




