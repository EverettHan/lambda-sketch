// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
// Creation EDS  09/10/2000
// 06/09/2022  G5S  For IR966182, to improve performance when there are lots of diagnosis objects, 
//                  we can choose to count them but not keep them with the option KeepDiagnosisObjects.
//
// Operateur de check d'auto-intersection de frontieres (loops) de face
//=============================================================================

#ifndef __CATFaceBoundaryIntersectionChecker_h__
#define __CATFaceBoundaryIntersectionChecker_h__

#include "CheckOperators.h"
#include "CATIntersectionChecker.h"

class CATGeoFactory;
class CATTopData;
class CATCXFaceBoundaryIntersectionChecker;
class CATShell;
class CATFace;


class ExportedByCheckOperators CATFaceBoundaryIntersectionChecker: public CATIntersectionChecker
{
  CATCGMVirtualDeclareClass(CATFaceBoundaryIntersectionChecker);
   public: // Methodes a usage externe
     
      //============================
      // Constucteur et destructeurs
      //============================

      CATFaceBoundaryIntersectionChecker(CATGeoFactory                        * iFactory,
                                         CATTopData                           * iData,
                                         CATCXFaceBoundaryIntersectionChecker * iImplementation);
      
      virtual ~CATFaceBoundaryIntersectionChecker();


      //======================================
      // Methodes specifiques a CATTopOperator
      //======================================


      //====================================
      // Parametrisation de l'operateur
      //====================================

      void SetFaceToCheck(CATFace * iFaceToCheck);
      void SetShellToCheck(CATShell * iShellToCheck);

      void SetKeepDiagnosisObjects(CATBoolean iToKeep);
      CATBoolean GetKeepDiagnosisObjects();
      int GetNbDiagnosesNoObject();
};

#endif
