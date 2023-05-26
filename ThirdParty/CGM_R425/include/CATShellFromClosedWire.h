/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//===================================================================
//  Create a CATBody containing CATShell limited by closed CATWire
//  of Input CATBody.
//
//  - Input CATBody must only contains closed CATWire.
//  - Each CATEdge of CATWire must have a CATPCurve on Input CATSurface.
//-------------------------------------------------------------------
//  Usage Notes :
//  - one constructor with one CATBody and one CATSurface.
//  - one constructor with a list of CATBody and a list of CATSurface.
//-------------------------------------------------------------------
//  WARNING :
//  --------
//  Operator can generate invalid topology if inputs are confused or 
//  intersecting wires. Thus, user have to check the empty intersection
//  between every input wires.
//===================================================================
#ifndef CATSHELLFROMCLOSEDWIRE_H
#define CATSHELLFROMCLOSEDWIRE_H
#include "CATDynOperator.h"
//#include "Primitives.h"
#include "BONEWOPE.h"
#include "CATTopDef.h"
#include "CATMathDef.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATDomain.h"
#include "CATListOfCATSurfaces.h"
#include "CATString.h"


class CATGeoFactory;
class CATBody;
class CATWire;
class CATFace;
class CATSurface;
class CATCGMJournalList;
class LoopFSFCW;
class EdgeFSFCW;


class ExportedByBONEWOPE CATShellFromClosedWire : public CATDynOperator
{
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATShellFromClosedWire);
public:
  //-------------------------------------------------------------------
  CATShellFromClosedWire(CATGeoFactory      * iFactory,
    CATBody            * inputBody,
    CATSurface         * iSupport,
    CATCGMJournalList  * iReport=NULL);
  
  CATShellFromClosedWire(CATGeoFactory         * iFactory,
    ListPOfCATBody        * inputBodies,
    CATLISTP(CATSurface)  * iSupports,
    CATCGMJournalList     * iReport=NULL);
  
  ~CATShellFromClosedWire();
  
  int  Run();

  //
  // this method is deprecated use SetCheckAutocrossing
  // Return number of auto - crossing problem found ( 0 if no auto crossing ).
  //
  // If this method is called before the "GetResult()" method and after the "Run()" method, 
  // in some situation the body can be repared 
  // ( In this case method return 0 , but warning can be output on demand ).
  //

  CATLONG32 CheckAutoCrossing ();

  //
  // To be called before run for modelisation organisation.
  //
  // It allows the computation of autocrossing during the Run method. It can 
  // repair the result
  // if this activated, the number of autocrossing can get after run
  // iAutoCrossing = 3 check on input with repair and inactivate the treatment
  //                 2 check on result without repair
  //                 1 check on result with repair of result
  //                 0 inactivated 
  //                 else error
  //
  void SetCheckAutoCrossing (CATLONG32 iAutoCrossing);

  //
  // To be called after run .
  //
  // Get the number of autocrossing detected if setCheckAutoCrossing is activated
  //
  CATLONG32 GetNbAutoCrossing ();

  void  CheckBodyValidity(const CATBody *iBody);

  virtual CATBody * GetResult();

  void Get_surfaces(CATLISTP(CATSurface)& SurfacesList) { SurfacesList = _surfaces; }
  void GetListOfWires(ListPOfCATBody& WireBodiesList) { WireBodiesList = _WireBodies; }
   
  /** @nodoc @nocgmitf CATCGMReplay ...*/
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };
  
  /** @nodoc @nocgmitf CATCGMReplay ...*/
   static CATShellFromClosedWire *Load(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);

  CATShellFromClosedWire(CATGeoFactory         * iFactory,
    CATTopData            * iReport,
    ListPOfCATBody        * inputBodies,
    CATLISTP(CATSurface)  * iSupports);

protected : 
  CATShellFromClosedWire(CATGeoFactory      * iFactory,
    CATTopData         * iReport,
    CATBody            * inputBody,
    CATSurface         * iSupport);
  

  /** @nodoc CATCGMReplay ...*/
  const CATString * GetOperatorId();
  
  /** @nodoc CATCGMReplay ...*/
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  
  /** @nodoc CATCGMReplay ...*/
  int RunOperator();
  
  /** @nodoc CATCGMReplay ...*/
  void Dump( CATCGMOutput& os ) ;
  
  /** @nodoc CATCGMReplay ... */
  void WriteInput(CATCGMStream  & ioStream);
  
  /** @nodoc CATCGMReplay ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  // Hybrid Management
  // Exact only
  virtual int RunExactOperator();
  // With Polyhedral data
  virtual int RunPolyOperator();
  
  /** @nodoc CATCGMReplay ...*/
  static CATString _OperatorId;
  void  InitEnd();
  void  FinishBegin();

  //-------------------------------------------------------------------
  void  InitLoopsFromWires();
  void  BuildGraph();
  void  MergeLoops(LoopFSFCW &iLoopToAdd, LoopFSFCW &iBigLoop);
  void  MakeShells();
  void  MakeLoop(LoopFSFCW& Loop, CATLocation InnerOrOuterLoop);
  CATLocation CompareLoopPosition(LoopFSFCW & LoopToCheck,
    LoopFSFCW & LoopRef);
  
  CATLocation CompareLoopPosition(EdgeFSFCW * EdgeToCheck,
    LoopFSFCW & LoopRef, const double & iResolution);
  
  CATLISTP(CATSurface)    _surfaces;            // liste des fonds donnes par USER
  ListPOfCATBody          _WireBodies;          // liste des body donnes par USER
  CATBody               * _DraftBody;           // le body contenant les nouveaux shells
  CATBody               * _HealedWireBody;      // body contenant les wires heales ( auto - intersection )

  CATSurface            * _surface;             // le fond de la face en cours
  CATFace               * _face;                // la face en cours de construction
  LoopFSFCW             * _loops;               // le tableau des Loops
  int                     _nbwires;             // nb de wires donnes par user
  ListPOfCATDomain        _wires;               // liste des wires donnes par USER
  int                     _nbloopsStillToBuild; // nbloop qu'il reste a construire
  short                   _Level;

  short                   _VersionOfClose;
  short                   _OperatorStage;       // = 0 : no run done , = 1 : Run done , =2 : GetResult done
  CATLONG32               _CheckAutoCrossing;   // = 0  pas de check d'autocrossing dans le run, = 1 : faire le check d'autocrossing
  CATLONG32               _NbAutoCrossing;      // nb de wires donnes par user
};

ExportedByBONEWOPE CATShellFromClosedWire * CATCreateShellFromClosedWire(
                                                                         CATGeoFactory      *iFactory,
                                                                         CATTopData         *iData,
                                                                         const CATBody      *iBody,
                                                                         const CATSurface   *iSupport);


ExportedByBONEWOPE CATShellFromClosedWire * CATCreateShellFromClosedWire(
                                                                         CATGeoFactory         *iFactory,
                                                                         CATTopData            *iData,
                                                                         ListPOfCATBody        *iBodies,
                                                                         CATLISTP(CATSurface)  *iSupports);
#endif
