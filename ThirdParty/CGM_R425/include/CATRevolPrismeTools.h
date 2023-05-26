/* -*-C++-*- */

#ifndef CATRevolPrismeTools_H
#define CATRevolPrismeTools_H

// COPYRIGHT DASSAULT SYSTEMES 2009

//===================================================================
//===================================================================
//
// CATSweepUtilities
//
// Internal ????? utilities for ?????
// 
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2009    Creation                         KY1
//===================================================================



//========================================================================================================================================
//  INCLUDES :
//========================================================================================================================================

#include "BO0SWEEPLight.h"
#include "CATSweepBasic.h"
#include "CATMathAxis.h"
#include "CATMathLine.h"
#include "BO0SWEEPLight.h"
#include "CATListOfCATCells.h"
#include "CATListOfCATCrvParams.h"

class CATGeoFactory;
class CATBody;
class CATVertex;
class CATEdge;
class CATFace;
class CATDomain;
class CATPointOnEdgeCurve;
class CATMergedCurve;
class CATEdgeCurve;
class CATMathDirection;
class CATTopData;

//========================================================================================================================================


class ExportedByBO0SWEEPLight CATRevolPrismeTools
{

  //----------------------------------------------------------------------------------
  // Dans les cas non plan ou plan non colinieaires avec l'axe : on analyse
  // la position du profil par rapport a l'axe ( vertex et edge confondus avec l'axe )
  //----------------------------------------------------------------------------------
  static int IsAEdgeOnAxis(CATGeoFactory  *iGeoFactory, CATFace        *iFace,
                    CATMathLine    &iMainLine  , ListPOfCATCell &oDegenerateCells );

  //----------------------------------------------------------------------------------------------------
  // Check if the Revol Axis intersect the face (The Revol axis has to be in the same plane of the face)
  // Qd checkMode = 1 on check si on peut faire le revolv
  // Qd checkMode = 0 on renvoie également la face redécoupée dans l'arg. oFace
  //
  // Cette methode remplace CATRevolBasic::SafeVersion(CATFace *iFace, ... (qui utilisait deja deux
  // journaux: iCGMJournalList et le journal de iTopData)
  //----------------------------------------------------------------------------------------------------
  public:
	static CATBoolean CheckIfRevolAxisCutsFace(CATTopData &iTopData, CATCGMJournalList *iCGMJournalList, 
                                             CATFace *iFace, CATDomain *iOldDomain, CATDomain *iNewDomain, CATBody *iNewBody, 
                                             CATGeoFactory *iGeoFactory, CATMathAxis &iRevolAxis, CATMathLine &iMainLine,
                                             ListPOfCATCell &oDegenerateCells, CATFace *&oSafeFace, CATBoolean iCheckMode);
  

  private:
  CATRevolPrismeTools();
  ~CATRevolPrismeTools();
  CATRevolPrismeTools(CATRevolPrismeTools &iRevolPrismTools);
};
#endif

