/* -*-C++-*- */
#ifndef CATParallelInitBase_H
#define CATParallelInitBase_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//----------------------------------------------------------------------------
//
// CATParallelInitBase
// Definition of a wire on a shell from another wire 
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
#include "CATRibInit.h"
#include "CATWireTopOp.h"
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
#include "CATArrayOfNupletsLists.h"

class CATGeoFactory;
class CATBody;
class CATVertex;
class CATDomain;
class CATShell;
class CATParallelRib;
class CATParallelMacroTool;
class CATEdgeRibbon;
class CATEdge;
class CATSupContact;
class CATCrvParam;
class CATPCurve;
class CATTopRibNuplet;
class CATCGMJournalList;

#include "CATSafe.h"
CATSafeDefine(CATParallelInitBase);

class ExportedByPARLight CATParallelInitBase : public CATRibInit
{
 public:

  //--------------------------------------------------------------------------
  // Constructor without wire on shell
  //--------------------------------------------------------------------------
  CATParallelInitBase( CATCGMJournalList *iJournal, CATBody *iCreationBody,
               CATBody *iBodyDomain , CATDomain *iDomain,  // wire and its body
               CATBody *iBodyShell,   CATShell *iShell);   // target shell and its body
  
  //--------------------------------------------------------------------------
  // Constructor with wire on shell
  //--------------------------------------------------------------------------
  CATParallelInitBase( CATCGMJournalList *iJournal,
               CATBody           *iCreationBody,
               CATBody           *iBodyDomain,          // body of the wire
               CATDomain         *iDomain,              // wire
               CATBody           *iBodyDomainSupport,   // body of the support of the wire
               CATShell          *iDomainSupport,       // support of the wire
               CATBody           *iBodyShell,           // body of the target shell
               CATShell          *iShell             ); // target shell
  //--------------------------------------------------------------------------
  // Destructor
  //--------------------------------------------------------------------------
  virtual ~CATParallelInitBase();

  //--------------------------------------------------------------------------
  // Check Wire continuity
  //--------------------------------------------------------------------------
  virtual void CheckBodies();

  //--------------------------------------------------------------------------
  // Removes bodies created for macro tool.
  //--------------------------------------------------------------------------
  virtual void CleanBodies();

  //--------------------------------------------------------------------------
  // Research of a new initial solution (redundance treatement) 
  //--------------------------------------------------------------------------
  virtual CATTopRib * GetNextRib();

  //--------------------------------------------------------------------------
  // Type of Tool : Parallel(1) or corner(2) or undefined (0)
  //--------------------------------------------------------------------------
  virtual CATLONG32 GetTypeOfTool();

 protected :

  CATBody           *_BodyDomain;
  CATDomain         *_Domain;

  CATBody           *_BodyDomainSupport;
  CATShell          *_DomainSupport;

  CATBody           *_BodyShell;
  CATShell          *_Shell;

  // For intialisation solution search

  CATCell           *_InitialCell;     // cell (vertex or edge)
                                       // for the starting point
  CATCell           * _pInitialEdgeSupport; //The very first cell support
  CATFace           *_InitialFace;     // face for the starting point
  ListPOfCATFace    _InitialFaces;

  ListPOfCATCell    *_SupportsTab;     // Cell (Edge Or Vertex) and Face
                                       // for FindInitialNuplet
  CATArrayOfNupletsLists _InitNupletsListsArray; // to keep non connex parts
                                                  // not computed by propagation
  
  // Modified By : MQZ : 2004:7:22
  CATListOfInt _FirstNupletIn;         // Storage for first nuplet of type "in"
  CATListOfInt _LastNupletIn;          // Storage for last nuplet of type "in"

  int _ValidInit;                      // Nuplet number for propagation init
  int _FirstInit;
  int _Complete;                       // Inits have been searched on all cells

  //--------------------------------------------------------------------------
  // Donne un body de travail: Methode a supprimer car on doit pouvoir s'en
  //                           sortir differemment en detruisant ce que l'on ne
  //                           veut pas dans le _creationbody comme dans fillet
  //--------------------------------------------------------------------------
  CATBody *GetWorkingBody();
  
  //--------------------------------------------------------------------------
  // Init method
  //--------------------------------------------------------------------------
  virtual CATBoolean Init();

  //--------------------------------------------------------------------------
  // Search of solution on the adjacent (to the edge) faces
  //--------------------------------------------------------------------------
  virtual CATBoolean FirstFaceInit();

  //--------------------------------------------------------------------------
  // Search of solution on the non adjacent (to the edge) faces
  //--------------------------------------------------------------------------
  virtual CATBoolean OtherFacesInit();
  virtual CATBoolean AllOtherFacesInit();
  virtual CATBoolean OtherEdgesInit();
  virtual CATBoolean GetSupportEdges(ListPOfCATCell *cells,
                                     ListPOfCATEdge *edges, 
                                     CATListPV &Supports, 
                                     CATListOfInt &sens,
                                     ListPOfCATEdge & usefulEdges);

  //--------------------------------------------------------------------------
  // Get the initial Face Support for the last support number
  // according to _InitialCell
  //--------------------------------------------------------------------------
  virtual CATFace * FindFaceSupport( CATOrientation *oGeomVsCell = 0,
                                     CATOrientation *oSurfaceVsShell = 0 );

  //--------------------------------------------------------------------------
  // Create a new rib, virtual method to allow the derivate type creation 
  //--------------------------------------------------------------------------
  virtual CATTopRib *CreateNewRib( CATTopRibMacroTool *MacroTool);

 protected:

  //--------------------------------------------------------------------------
  // Update initialisatio data
  //--------------------------------------------------------------------------
  virtual CATBoolean InitValidation();

 private:

  CATBody *_BodyForMacroTool;

  //--------------------------------------------------------------------------
  // Supports for the research of the initial solution
  //--------------------------------------------------------------------------
  virtual void GetSupports(CATListPV &LesSupports, CATListOfInt &sens);

  virtual void GetSupports(ListPOfCATCell *cells, ListPOfCATFace *face, 
				 CATListPV &Supports, CATListOfInt &sens);

  //--------------------------------------------------------------------------
  // Modify the ribbon in order to match the edge
  //--------------------------------------------------------------------------
  virtual int  RibbonAnalysis ( ListPOfCATTopRibNuplets &LNuplets,
			int &newFirstIn, int &newLastIn, int ListNumber);// Modified By : MQZ : 2004:7:22
   
  //--------------------------------------------------------------------------
  // To keep a Nuplet init inside the rib
  //--------------------------------------------------------------------------
  virtual void SetInitSolution( int *newFirstIn, int *newLastIn );
   
  //--------------------------------------------------------------------------
  // Getting a new levalof Adjacent Faces on the shell
  //--------------------------------------------------------------------------
  virtual CATLONG32 NewAdjLevelInit ( ListPOfCATFace *aInitialFaces,
                         ListPOfCATFace & UsedFaces,
                         ListPOfCATFace *aAdjacentFaces );

  //--------------------------------------------------------------------------
  // A cell in the wire support already entirely belongs to a Rib
  //--------------------------------------------------------------------------
  CATBoolean CellBelongToARib();
	
 protected:
  //--------------------------------------------------------------------------
  // Check if an init is already included insed a Rib
  //--------------------------------------------------------------------------
  virtual int BelongToARib( int iInitIndex);
  
  //--------------------------------------------------------------------------
  // Check if an init is having falsely cut solution and replace that init nuplet with correct orientations.
  //--------------------------------------------------------------------------
  virtual void ManageIncorrectConnectCut(int iInitIndex);
};

#endif
