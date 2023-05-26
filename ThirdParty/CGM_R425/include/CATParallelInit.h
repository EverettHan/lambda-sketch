/* -*-C++-*- */
#ifndef CATParallelInit_H
#define CATParallelInit_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//----------------------------------------------------------------------------
//
// CATParallelInit
// Definition of a parallel of a wire on a shell
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Usage notes:
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Feb. 99    Creation                         N.Barrier
//----------------------------------------------------------------------------

#include "CATParallelInitBase.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATCellHashTable.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATTopRibNuplets.h"
#include "CATMathDef.h"
#include "CATTopDef.h"

class CATGeoFactory;
class CATBody;
class CATVertex;
class CATWire;
class CATShell;
class CATParallelRib;
class CATParallelMacroTool;
class CATEdgeRibbon;
class CATEdge;
class CATSupContact;
class CATCrvParam;
class CATPCurve;
class CATLaw;
class CATCompositeLaw;

class CATTopRibNuplet;
class CATDistanceTool;
class CATCGMJournalList;

class CATParallelInit : public CATParallelInitBase
{
 public:

  //--------------------------------------------------------------------------
  // Constructor
  //--------------------------------------------------------------------------
  CATParallelInit(CATCGMJournalList *iJournal, CATBody *iCreationBody,
                  CATBody *iBodyWire, CATWire *iWire,
                  CATBody *iBodyShell, CATShell *iShell,
                  CATDistanceTool *iDistance, CATLaw **iMapping, CATBoolean iIsPlanarBody = FALSE);

  //--------------------------------------------------------------------------
  // Destructor
  //--------------------------------------------------------------------------
  virtual ~CATParallelInit();

  virtual CATLONG32 GetTypeOfTool();
  /*
  //---------------------------------------------------------------------------
  // Report a vertex on the parallel wire to the original wire 
  //---------------------------------------------------------------------------
  void ReportVertex( CATVertex *iToReport, int &oWireNumber, int &oEdgeNumber,
                                                         CATCrvParam &oParam);
  */
 private:

  //--------------------------------------------------------------------------
  // Data
  //--------------------------------------------------------------------------
  CATWire *_Wire;
  CATLength _Distance;
  CATCompositeLaw *_DistanceLaw;
  CATLaw **_MappingLaw;
  CATDistanceTool *_DistanceTool;
  CATTopSign _Sign;
  CATLONG32 _CheckCurvature;

  CATBoolean  _IsPlanarBody;
  
  //--------------------------------------------------------------------------
  // Check if an init is already included insed a Rib
  //--------------------------------------------------------------------------
  int BelongToARib( int iInitIndex);

  //--------------------------------------------------------------------------
  // Check if an init is having falsely cut solution and replace that init nuplet with correct orientations.
  //--------------------------------------------------------------------------
  void ManageIncorrectConnectCut(int iInitIndex);

  //Check if NewInit is required.. specific to Euclidian Parallel only.
  CATBoolean IsNewInitRequired(CATOrientation iOriFirstEdge, double iTol);
  CATBoolean RevertToOriginalInit(CATBoolean & ioRibAlreadyCreated, double iTol);

 public:
  //--------------------------------------------------------------------------
  // 1:Autorisation 
  //--------------------------------------------------------------------------
  void CheckBodies();
  
  //--------------------------------------------------------------------------
  // set or unset Check of curvature of curve against offset of parallel
  //--------------------------------------------------------------------------
  void SetCheckCurvature(CATLONG32 iIsSet);
  void GetCheckCurvature (CATLONG32 & oIsSet);
  
  //--------------------------------------------------------------------------
  // Init method
  //--------------------------------------------------------------------------
  virtual CATBoolean Init();

};

#endif
