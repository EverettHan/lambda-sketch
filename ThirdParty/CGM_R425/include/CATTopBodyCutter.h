//=========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003 
//=========================================================================
//
// CATTopBodyCutter
// interface for Body Cutter Operateur
//
//=========================================================================
//
// Usage notes:
//
//========================================================================= 
// Aug 03     Creation                       AOV 
//========================================================================= 

#ifndef CATTopBodyCutter_h
#define CATTopBodyCutter_h

#include "CATTopOperator.h"
#include "CATListOfDouble.h"
#include "CATFace.h"
#include "CATBody.h"
#include "CATCGMJournalList.h"
#include "CATListOfCATCuttingElt.h"

#include "Primitives.h"


/**
* Class defining the topological operator that cut a body at isopar curves.  
* A CATTopBodyCutter operator is created with the CATCreateTopBodyCutter 
* global method;
* it must be directly deleted after use.  
* The resulting body is retrieved with the GetResult method.
*/

class ExportedByPrimitives CATTopBodyCutter : public CATTopOperator
{

  public:

  CATTopBodyCutter(CATGeoFactory * iFacto,CATTopData * iData);
  virtual ~CATTopBodyCutter();

  /**
  * Defines whether the surface must be cloned in the result or if we keep the same surface under face
  */
  virtual void      SetSurfaceCuttingMode(const int iMode)=0;

  /**
  * Activate Active Clone ie cut surface 
  * Only nurbs will be cut, others surfaces will be cloned
  * Not activated
  */
#ifdef TASKC1_CUTTING_CLONEACTIF
  virtual void      SetActiveCloneMode(const int iMode=1)=0;
#endif

  /**
  * Retrieve the face which leads to iFace in result of body cutter
  */
  virtual CATFace * GetOriginalFace(CATFace * iFace)=0;


  virtual int       RunOperator()                                =0;

  virtual CATBody * GetResult()                          =0;
  virtual CATBody * GetResult(CATCGMJournalList * iJourn)=0;

};
 

ExportedByPrimitives
CATTopBodyCutter * CATCreateTopBodyCutter(CATGeoFactory * iFacto,CATTopData * iData,
                                              CATBody * iBodyToCut,
                                              CATLISTP(CATCuttingElt) & iListOfCutting);
#endif 


