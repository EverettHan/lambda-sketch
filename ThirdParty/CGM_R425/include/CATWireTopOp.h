/* -*-C++-*- */
#ifndef CATWireTopOp_H
#define CATWireTopOp_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//----------------------------------------------------------------------------
//
// CATWireTopOp
// Topological construction of a wire on a shell
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Usage notes:
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Feb. 99    Creation                         N.Barrier
//----------------------------------------------------------------------------

#include "ParallelLight.h"
#include "CATRibTopOp.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATCellHashTable.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATWire.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATRibInit.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "CATCGMNewArray.h"
#define MaxNumberOfRib 10

class CATGeoFactory;
class CATBody;
class CATWire;
class CATShell;
class CATParallelRib;
class CATParallelMacroTool;
class CATRibInit;
class CATEdge;
class CATEdgeCurve;
class CATVertex;
class CATSupContact;
class CATCrvParam;

class CATPCurve;
class CATTopRibNuplet;
class CATLaw;
class CATCGMJournalList;
class CATSoftwareConfiguration;

#include "CATSafe.h"
CATSafeDefine(CATWireTopOp);

class ExportedByParallelLight CATWireTopOp : public CATRibTopOp
{
 public:

  //--------------------------------------------------------------------------
  // Constructor
  //--------------------------------------------------------------------------
  CATWireTopOp(CATSoftwareConfiguration * iConfig,
               CATGeoFactory     *iFactory,
               CATCGMJournalList *iJournal, 
               CATBody           *iCreationBody );

  CATCGMNewClassArrayDeclare; // Pool allocation
  
  //--------------------------------------------------------------------------
  // Destructor
  //--------------------------------------------------------------------------
  virtual ~CATWireTopOp();

  //--------------------------------------------------------------------------
  // Run method
  //--------------------------------------------------------------------------
  virtual void Run (int ShouldFreezeAndComplete=1);

  //---------------------------------------------------------------------------
  // Report a vertex on the parallel wire to the original wire 
  //---------------------------------------------------------------------------
  void ReportVertex( CATVertex *iToReport, int &oWireNumber, int &oEdgeNumber,
    CATCrvParam &oParam, CATEdgeCurve ** oEC=NULL, CATEdge **oOriginalEdge = NULL,
    CATVertex ** oOriginalVertex = NULL);

  //--------------------------------------------------------------------------
  // To get information for twisted edges of a given wire of iCreationBody
  // a list of number corresponding to the cell number of the twisted edge
  // in the wire provide this information.
  //--------------------------------------------------------------------------
  void GetTwistedEdges( int iWireNumber, CATListOfInt *oTwistedEdges );

  //--------------------------------------------------------------------------
  // To get information for overlapped edges in a given wire of iCreationBody
  // a list of number corresponding to the cell number of the overlapped edge
  // in the wire provide this information.
  //--------------------------------------------------------------------------
  void GetOverlappedEdges(int iWireNumber, CATListOfInt* oOverlappedEdges);

  CATTopRibNuplet* GetNupletFromEdge(int iWireNumber, int iEdgeNumber);

 protected :

  //--------------------------------------------------------------------------
  // Data
  //--------------------------------------------------------------------------
  CATGeoFactory *_Factory;

  ListPOfCATWire    _WireParallel;
   
  //--------------------------------------------------------------------------
  // Destruction des parties inutiles des rubans (par RemoveUnusedNuplets)
  //--------------------------------------------------------------------------
  void CleanUnusedNupletsFromRibbons();

  //--------------------------------------------------------------------------
  // Cleans shells before body is completed
  //--------------------------------------------------------------------------
  void SpecificCleanUp();
  
  //--------------------------------------------------------------------------
  // Check of bodies in entry for the operator ( continuity , ... )
  // return an exception, if an entry valdity problem is found.
  //--------------------------------------------------------------------------
  virtual void CheckBodies(); 
      
  //--------------------------------------------------------------------------
  // Removes bodies created for macro tool.
  //--------------------------------------------------------------------------
  void CleanBodies();

  //--------------------------------------------------------------------------
  // Compute the ribbon 
  //--------------------------------------------------------------------------
  int ComputeParallelRibbon();

  //--------------------------------------------------------------------------
  // Create the wire parallel
  //--------------------------------------------------------------------------
  CATDomain * CreateWireParallel();

/*
  //--------------------------------------------------------------------------
  // Supports for the research of the initial solution
  //--------------------------------------------------------------------------
  void GetSupports(CATListPV &LesSupports, CATListOfInt &sens);

  void GetSupports(ListPOfCATCell *cells, ListPOfCATFace *face, 
				 CATListPV &Supports, CATListOfInt &sens);

  //--------------------------------------------------------------------------
  // Modify the ribbon in order to match the edge
  //--------------------------------------------------------------------------
  int  RibbonAnalysis ( ListPOfCATTopRibNuplets &LNuplets,
			int &newFirstIn, int &newLastIn);
   
  //--------------------------------------------------------------------------
  // Search of solution on the adjacent (to the edge) faces
  //--------------------------------------------------------------------------
   CATBoolean FirstFaceInit();

  //--------------------------------------------------------------------------
  // Search of solution on the non adjacent (to the edge) faces
  //--------------------------------------------------------------------------
  CATBoolean OtherFacesInit();

  //--------------------------------------------------------------------------
  // To keep a Nuplet init inside the rib
  //--------------------------------------------------------------------------
   void SetInitSolution( int *newFirstIn, int *newLastIn );
   
  //--------------------------------------------------------------------------
  // Update initialisatio data
  //--------------------------------------------------------------------------
   CATBoolean InitValidation();

  //--------------------------------------------------------------------------
  // Getting a new levalof Adjacent Faces on the shell
  //--------------------------------------------------------------------------
  CATLONG32 NewAdjLevelInit ( ListPOfCATFace *aInitialFaces,
                         ListPOfCATFace UsedFaces,
                         ListPOfCATFace *aAdjacentFaces );

  //--------------------------------------------------------------------------
  // Init method
  //--------------------------------------------------------------------------
  virtual CATBoolean Init() = 0;
*/
  private :
                                               // of the unitary ribbons
  int _NumberOfComputedInits;
  CATBody * _OutsideBody;
  CATLONG32 _nbRibToClean;
  CATParallelRib ** _ListOfRibToClean;
  //------------------------------------------------------------------------------
  // Get next parallel ribbon to compute
  // the ribbons are produced by RibInits stocked in  _Inits (list of RibInits)
  // One RibInit can produce one to n parallel ribbons. 
  // The methode RibInit::GetNextRib is used to read the ribbons produced by a
  // RibInit. It increments a counter of the explored ribbons inside a Ribinit.
  // In the same way _NumberOfComputedInits is a counter of the explored RibInits.
  //------------------------------------------------------------------------------
  CATParallelRib *     GetNextParallelRib();
  CATListPV _TwistedWire;
  CATListPV _OverlappedEdges;
};

#endif









