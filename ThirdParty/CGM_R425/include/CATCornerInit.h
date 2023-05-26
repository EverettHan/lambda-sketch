/* -*-C++-*- */
#ifndef CATCornerInit_H
#define CATCornerInit_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//----------------------------------------------------------------------------
//
// CATCornerInit
// Definition of a wire at a given distance from a vertex on a shell
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Usage notes:
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Feb. 99    Creation                         N.Barrier
//----------------------------------------------------------------------------

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByPARLight.h"
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
#include "CATIntersectionSign.h"
#include "CATMathSetOfPointsND.h"


class CATGeoFactory;
class CATBody;
class CATVertexInVolume;
class CATWire;
class CATShell;
class CATParallelRib;
class CATParallelMacroTool;
class CATEdgeRibbon;
class CATEdge;
class CATSupContact;
class CATCrvParam;
class CATPCurve;
class CATTopRibNuplet;
class CATLaw;
class CATCGMJournalList;
class CATSetOfSurParams;

class ExportedByPARLight CATCornerInit : public CATParallelInitBase
{
 public:

  //--------------------------------------------------------------------------
  // Constructor
  //--------------------------------------------------------------------------
   
  CATCornerInit(CATCGMJournalList *iJournal, CATBody *iCreationBody,
                  CATBody *iBodyVertex, CATVertexInVolume *iVertexInVolume,
                                     CATBody *iBodyShell, CATShell *iShell,
                                              CATPositiveLength iDistance );
  /*
  CATCornerInit( CATGeoFactory *iFactory,
                    CATCGMJournalList *iJournal, CATBody *iCreationBody,
                  CATBody *iBodyVertex, CATVertexInVolume *iVertexInVolume,
                                     CATBody *iBodyShell, CATShell *iShell,
	                              CATLaw *iDistance, CATLaw *iMapping );
  */
  //--------------------------------------------------------------------------
  // Destructor
  //--------------------------------------------------------------------------
  virtual ~CATCornerInit();

  //--------------------------------------------------------------------------
  // to impose first point of corner
  //--------------------------------------------------------------------------
  void SetStartingPoints( CATSetOfSurParams &iSetOfInitParamsOnSurface,
                  CATIntersectionSign *iStartingSignatureOnSurface = NULL );

  void SetStartingPoints( CATSetOfSurParams &iSetOfInitParamsOnSurface,
                                                 CATFace *iInitialFace,
                  CATIntersectionSign *iStartingSignatureOnSurface = NULL );
  void SetEndingPoints( CATSetOfSurParams &iSetOfExitParamsOnSurface,
                                                CATFace **iEndingFace,
                    CATIntersectionSign *iEndingSignatureOnSurface = NULL );
  void SetEndingPoints( int NumberOfStartingPoints,CATSurParam * iSetOfExitParamsOnSurface,
                                                CATFace **iEndingFace,
                    CATIntersectionSign *iEndingSignatureOnSurface = NULL );

  virtual CATLONG32 GetTypeOfTool();
 private:

  //--------------------------------------------------------------------------
  // Data
  //--------------------------------------------------------------------------

  CATLength _Distance;
  CATTopSign _Sign;
  CATVertexInVolume *_VertexInVolume;
  //CATBody       *_BodyVertex;
  CATMathSetOfPointsND _InitPoints;
  CATMathSetOfPointsND _ExitPoints;
  CATFace ** _EndingFace;

  //--------------------------------------------------------------------------
  // Init method
  //--------------------------------------------------------------------------
  CATBoolean Init();

};

#endif
