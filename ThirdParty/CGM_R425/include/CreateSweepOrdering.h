// COPYRIGHT DASSAULT SYSTEMES 1998
//=========================================================================
//
// CreateSweepOrdering :
// 
//=========================================================================
// 24 02 00 ALM Creation
// 07 11 01 NLD Argument *iTolOnGuides: tolerance a laquelle les guides
//              ont ete approchees
// 12 11 02 NDN Ajout de la software dans CATFrFDistanceMinCcvCcv et par effet de bord 
//              dans CATSweepOrdering.
//=========================================================================
#ifndef CreateSweepOrdering_H
#define CreateSweepOrdering_H 

#include "FrFAdvancedOpeCrv.h"
#include "CATSweepOrdering.h"
#include "CATSkillValue.h"
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATSoftwareConfiguration;

ExportedByFrFAdvancedOpeCrv
CATSweepOrdering* CreateSweepOrdering(CATGeoFactory * iFactory,
                                      CATLONG32 iNbGuides,
                                      CATFrFCompositeCurve ** iGuides,
                                      CATLONG32 iNbProfiles,
                                      CATFrFCompositeCurve** iProfiles,
                                      const CATSkillValue iMode=BASIC,
                                      double* iTolOnGuides=0,
                                      const CATSoftwareConfiguration * iConfig=NULL);
ExportedByFrFAdvancedOpeCrv
void Remove(CATSweepOrdering *& iSweepOrdering);
#endif




