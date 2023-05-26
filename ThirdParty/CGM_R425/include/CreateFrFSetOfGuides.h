// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFSetOfGuides :
// Declaration of global functions used to create and destroy
// an instance of the SetOfGuides operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// December 97  Creation                          CPL
// 14/03/07 NLD On recoit un CATFrFObject
//=============================================================================

#ifndef CreateFrFSetOfGuides_H 
#define CreateFrFSetOfGuides_H 
//
#include "FrFAdvancedObjects.h"
#include "CATFrFObject.h"
#include "CATSoftwareConfiguration.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
//
class CATCurve;
class CATFrFCompositeCurve;
class CATGeometry;
class CATFrFSetOfGuides;
//
ExportedByFrFAdvancedObjects
CATFrFSetOfGuides * CreateSetOfGuides(
                  CATFrFObject          & iFrFObject,
                  CATLONG32               iNumberOfLimitGuides,
                  CATLONG32               iNumberOfMiddleGuides,
                  CATLONG32               iNumberOfFunctionalGuides,
                  CATCurve             ** iLimitGuides,
                  CATCurve             ** iMiddleGuides,
                  CATGeometry          ** iFunctionalGuides
                  //CATSoftwareConfiguration * iSoftwareConfig=0
                  );
//
ExportedByFrFAdvancedObjects
CATFrFSetOfGuides * CreateSetOfGuides(
                  CATFrFObject          & iFrFObject,
                  CATLONG32               iNumberOfLimitGuides,
                  CATLONG32               iNumberOfMiddleGuides,
                  CATLONG32               iNumberOfFunctionalGuides,
                  CATFrFCompositeCurve ** iLimitGuides,
                  CATFrFCompositeCurve ** iMiddleGuides,
                  CATGeometry          ** iFunctionalGuides
                  //CATSoftwareConfiguration * iSoftwareConfig=0
                  );
//
ExportedByFrFAdvancedObjects
CATFrFSetOfGuides * CreateSetOfGuides(
                  CATFrFObject          & iFrFObject,
                  CATLONG32               iNumberOfLimitGuides,
                  CATFrFCompositeCurve ** iLimitGuides,
                  CATLONG32               iNumberOfMiddleGuides= 0,
                  CATFrFCompositeCurve ** iMiddleGuides= 0,
                  CATLONG32               iNumberOfFunctionalGuides= 0,
                  CATGeometry          ** iFunctionalGuides= 0
                  //CATSoftwareConfiguration * iSoftwareConfig=0
                  );
//
ExportedByFrFAdvancedObjects
void Remove(CATFrFSetOfGuides *&ioSetOfGuides );

#endif




