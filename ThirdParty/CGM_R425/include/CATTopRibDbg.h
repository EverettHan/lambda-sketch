/* -*-C++-*- */

#ifndef CATTopRibDbg_H
#define CATTopRibDbg_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//------------------------------------------------------------------------------
//
// Debug utilities for CATTopRib
//
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Feb. 98    Creation                         A. State
//------------------------------------------------------------------------------
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibDbgLight.h"

#include "CheckPointDebugUtilities.h"

class CATGeometry;
class CATGeoFactory;
class CATSoftwareConfiguration;

class CATTopRib;
class CATTopRibNuplet;
class CATDumpAsBodies;

class CATBody;
class CATShell;
class CATFace;
class CATEdge;
class CATVertex;
class CATCurve;

class CATICGMObject;
class CATSurface;
class CATSurParam;
class CATSurLimits;
class CATCrvLimits;

class CATCGMOutput;

#include "CATCGMActivateDebug.h"         // pour que CATTopRibDbg suffise a l appelant

#include "ListPOfCATDomain.h"
#include "CATListOfCATGeometries.h"
#include "CATListOfInt.h"
#include "CATTopRibDef.h"
#include "CATMathDef.h"

#define TopRibDbgUndefined             -1
#define DontShowVertices       0
#define ShowStartVertex        1
#define ShowEndVertex          2
#define ShowBothVertices       3
#define DontShowOrientation    0
#define ShowOrientation        1
#define DontStopAfterShow      0
#define StopAfterShow          1
#define TemporaryDisplay       1
#define PseudoPermanentDisplay 2
#define PermanentDisplay       3
#define OldElementType         0
#define NewElementType         1
#define RelimNupletDisplay     1
#define DraftNupletInDisplay   2
#define DraftNupletOutDisplay  3
#define SewingDisplay          4
#define ExportDisplay          5
#define ExtraDisplay           6

// If "BreakPoints" has been defined before including CATTopRibDbg.h
// then the constant MyStop is set to Stop
// It can be used when calling the Show method or the Constructor
//---------------------------------------------------------------
#ifdef BreakPoints
#define MyStop StopAfterShow
#else
#define MyStop DontStopAfterShow
#endif

// If "DeleteVisu" has been defined before including CATTopRibDbg.h
// then the constant MyDisplayMode is set to TemporaryDisplay
// It can be used when calling the Show method or the Constructor
//---------------------------------------------------------------
#ifdef DeleteVisu
#define MyDisplayMode TemporaryDisplay
#else
#define MyDisplayMode PermanentDisplay
#endif

typedef struct CATTopDbgAttribut
{
  unsigned int r;
  unsigned int g;
  unsigned int b;

} CATTopDbgAttribut;

//------------------------------------------------------------------------------

ExportedByRIBLight void ClearDebugGeometry(CATLISTP(CATGeometry) & iObjects);

ExportedByRIBLight void ShowGeometry(CATGeometry* iObjectToDisplay, const int iRed, const int iGreen, const int iBlue) ;

//------------------------------------------------------------------------------
ExportedByRIBLight void ShowNormal( CATGeoFactory *iGeoFactory, CATSurface* iSurface, 
                                const CATSurParam & iParam, const int iOrientation, 
                                const int iRed, const int iGreen, const int iBlue) ;

//------------------------------------------------------------------------------
// Show edge on face
//------------------------------------------------------------------------------

ExportedByRIBLight void ShowEdgeOnFace (CATSoftwareConfiguration* iConfig,
                                        CATGeoFactory *           iGeoFactory,
                                        CATEdge       *           iEdge,
                                        CATFace       *           iFace        = NULL,
                                        CATLONG32                 iStop        = TopRibDbgUndefined,
                                        CATLONG32                 iDisplayMode = TopRibDbgUndefined,
                                        int                       iStandardDisplay = TopRibDbgUndefined,
                                        CATVertex     *           iStart=NULL,
                                        CATVertex     *           iEnd=NULL,
                                        CATLISTP(CATGeometry) *   oCreatedObjects=NULL,
                                        CATTopDbgAttribut *       att=NULL,
                                        CATTopRibSol              iTypSol=SolTypeUnknown,
                                        char          *           iText=NULL,
                                        CATOrientation            iSupportOrientation=CATOrientationUnknown,
                                        CATSide                   iSideToKeep=CATSideUnknown);
//------------------------------------------------------------------------------
// Show vertex on edge
//------------------------------------------------------------------------------
ExportedByRIBLight void ShowVertexOnEdge (CATGeoFactory *iGeoFactory,
                                      CATVertex     *iVertex,
                                      CATEdge       *iEdge,
                                      CATLONG32           iStop,
                                      CATLONG32           iDisplayMode,
                                      int            iStandardDisplay,
                                      CATLISTP(CATGeometry) *oCreatedObjects,
                                      CATTopDbgAttribut *att);

//------------------------------------------------------------------------------
// Show limits on a surface or a curve
//------------------------------------------------------------------------------
ExportedByRIBLight void ShowLimits (CATGeoFactory     *iGeoFactory,
                                CATSurface            *iSurface,
                                const CATSurLimits    &iSurLimits,
                                CATLONG32                   iStop        = TopRibDbgUndefined,
                                CATLONG32                   iDisplayMode = TopRibDbgUndefined,
                                int                    iStandardDisplay = TopRibDbgUndefined,
                                char                  *iText=NULL,
                                CATLISTP(CATGeometry) *oCreatedObjects=NULL,
                                CATTopDbgAttribut     *att=NULL);

ExportedByRIBLight void ShowLimits (CATGeoFactory     *iGeoFactory,
                                CATCurve              *iCurve,
                                const CATCrvLimits    &iCrvLimits,
                                CATLONG32                   iStop        = TopRibDbgUndefined,
                                CATLONG32                   iDisplayMode = TopRibDbgUndefined,
                                int                    iStandardDisplay = TopRibDbgUndefined,
                                char                  *iText=NULL,
                                CATLISTP(CATGeometry) *oCreatedObjects=NULL,
                                CATTopDbgAttribut     *att=NULL);

//------------------------------------------------------------------------------
// Show N-uplet tracks on their nth support
//------------------------------------------------------------------------------
ExportedByRIBLight void ShowNuplet (CATGeoFactory   *iGeoFactory,
                              CATTopRibNuplet       *iNuplet,
                              CATLONG32              iSupportIndex,
                              CATLONG32              iStop            = TopRibDbgUndefined,
                              CATLONG32              iDisplayMode     = TopRibDbgUndefined,
                              int                    iStandardDisplay = TopRibDbgUndefined,
                              char                  *iText=NULL,
                              CATLISTP(CATGeometry) *oCreatedObjects=NULL,
                              CATTopDbgAttribut     *att=NULL);

ExportedByRIBLight void ShowNupletReport(CATGeoFactory* iGeoFactory, 
                                         CATTopRibNuplet *iNuplet, 
                                         CATLISTP(CATGeometry)* oCreatedObjects) ;

//------------------------------------------------------------------------------
// Indique les distances entre le premier POEC et les suivants
// au sein du vertex donne
//------------------------------------------------------------------------------
ExportedByRIBLight CATBoolean RibDbgCheckIsOK(CATVertex* iVertex);

//------------------------------------------------------------------------------
// Show ribbon tracks on their nth support
//------------------------------------------------------------------------------
ExportedByRIBLight void ShowRibbon(CATCGMActivateDebug& iBrkPntMngr, CATTopRib& iRib, const int iNumSupp, CATTopDbgAttribut* iDbgAtt=NULL);

ExportedByRIBLight void ShowRibbon (CATGeoFactory *iGeoFactory,
                                    CATTopRib     *iRibbon,
                                    CATLONG32           iSupportIndex,
                                    CATLONG32           iStop        = TopRibDbgUndefined,
                                    CATLONG32           iDisplayMode = TopRibDbgUndefined,
                                    int            iStandardDisplay = TopRibDbgUndefined,
                                    CATLISTP(CATGeometry) *oCreatedObjects=NULL,
                                    CATTopDbgAttribut *att=NULL);

//-----------------------------------------------------------------------------
// Dump the cells cutting on a face ( edges even borders and vertices )
//-----------------------------------------------------------------------------
ExportedByRIBLight void DumpCuttingOnFace(CATFace *iFaceToSplit,
                                    CATBody *iBody,
                                    CATSoftwareConfiguration* iConfig);

//------------------------------------------------------------------------------
// Check completness of Cutting inside a Shell
//------------------------------------------------------------------------------
ExportedByRIBLight void CheckInsideShellCutting(CATBody* iBody,
                                          CATSoftwareConfiguration* iConfig,
                                          CATShell* iShell, 
                                          CATFace* iFaceToCheck,
                                          CATCGMActivateDebug* iBreakPoint=NULL);

//------------------------------------------------------------------------------
// Dump
//------------------------------------------------------------------------------
ExportedByRIBLight void DumpFamily(CATICGMObject* iObject, CATCGMOutput &ios, const int iLevel=1);

//------------------------------------------------------------------------------
// Create 
//------------------------------------------------------------------------------
ExportedByRIBLight void DumpTracks(CATTopRib& iRib, CATDumpAsBodies& iInto, CATUnicodeString iBodyName, const int iNumSupp=0, const int iStart=0, const int iEnd=0);

//------------------------------------------------------------------------------
// Show end of ribbon geometry
// Please note: this method should always be called before
// exiting CATBlendRlm::CheckIfEnded
//------------------------------------------------------------------------------
ExportedByRIBLight void ShowRibbonEndGeometry (CATTopRibSign        iDirection,
                                           CATTopRib           *iRib,
                                           CATCGMActivateDebug *iBrkPntMngr = NULL);

//------------------------------------------------------------------------------
// Visualise an element of type CATGeometry
//
// Please note:
// 1) The iShowVertexOnEdge argument is used to visualise one or both
//    extremity vertices of an edge (this is only applied to iGeometry
//    itself, but not to any edges it might contain):
//    DontShowVertices - no vertex visualization (except if iGeometry
//                              is a vertex)
//    ShowStartVertex  - the start vertex is visualized
//    ShowEndVertex    - the end vertex is visualized
//    ShowBothVertices - both start and end vertices are visualized
// 2) The iShowOrientation argument is used to visualize a vertex located
//    near the end vertex of the edge to indicate its orientation (this is
//    only applied to iGeometry itself, but not to any edges it might contain)
//    valid values: DontShowOrientation and ShowOrientation
// 3) The iStop argument is used to ask the Show function to stop execution
//    after having visualzed the provided CATGeometry object
//    valid values: DontStopAfterShow and StopAfterShow
// 4) The iDisplayMode argument is used to stop displaying the provided
//    CATGeometry object at the end (e.g. for use in combination with
//    iStop, i.e. iStop = Stop and iDisplayMode = TemporaryDisplay)
//    valid values:
//    TemporaryDisplay       - display lasts only as CATLONG32 as the show method
//    PseudoPermanentDisplay - display lasts til the next show method with
//                             "TemporaryDisplay"
//    PermanentDisplay       - display lasts forever
//
//------------------------------------------------------------------------------

class ExportedByRIBLight CATShowGeometry
{

 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------

  CATShowGeometry (CATGeometry         *iGeometry          = NULL,
                   CATLISTP(CATGeometry) *oCreatedObjects  = NULL,
                   CATLONG32                 iRedColor          = 0,
                   CATLONG32                 iGreenColor        = 0,
                   CATLONG32                 iBlueColor         = 0,
                   CATLONG32                 iStop              = DontStopAfterShow,
                   char                *iBreakPointString1 = NULL,
                   char                *iBreakPointString2 = NULL,
                   CATCGMActivateDebug *iBreakPointManager = NULL,
                   CATLONG32                 iDisplayMode       = PermanentDisplay,
                   CATLONG32                 iShowVertexOnEdge  = DontShowVertices,
                   CATLONG32                 iShowOrientation   = DontShowOrientation,
                   CATBody             *iCreationBody      = NULL,
                   CATLONG32                 iElementType       = OldElementType);
  

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------

  virtual ~CATShowGeometry ();

  //------------------------------------------------------------------------------
  // Visualize another CATGeometry object
  //------------------------------------------------------------------------------

  virtual void Show (CATGeometry *iGeometry,
                     CATLISTP(CATGeometry) *oCreatedObjects,
                     CATLONG32         iRedColor          = TopRibDbgUndefined,
                     CATLONG32         iGreenColor        = TopRibDbgUndefined,
                     CATLONG32         iBlueColor         = TopRibDbgUndefined,
                     CATLONG32         iStop              = TopRibDbgUndefined,
                     char        *iBreakPointString2 = NULL,
                     CATLONG32         iDisplayMode       = TopRibDbgUndefined,
                     CATLONG32         iShowVertexOnEdge  = TopRibDbgUndefined,
                     CATLONG32         iShowOrientation   = TopRibDbgUndefined,
                     CATBody     *iCreationBody      = NULL,
                     CATLONG32         iElementType       = OldElementType);

 protected:

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------

  CATLONG32              _RedColor;
  CATLONG32              _GreenColor;
  CATLONG32              _BlueColor;
  CATLONG32              _Stop;
  char                  *_BreakPointString1;
  char                  *_BreakPointString2;
  CATCGMActivateDebug   *_BreakPointManager;
  int                    _IOwnBreakPointManager;
  CATLONG32              _DisplayMode;
  CATLONG32              _ShowVertexOnEdge;
  CATLONG32              _ShowOrientation;
  CATBody               *_CreationBody;
  CATLISTP(CATGeometry)  _GeometryToUnColor;
  CATListOfInt           _OldRedColor;
  CATListOfInt           _OldGreenColor;
  CATListOfInt           _OldBlueColor;
  CATLISTP(CATGeometry)  _GeometryToRemove;
  ListPOfCATDomain       _CreatedDomain;

  //------------------------------------------------------------------------------
  // Type de resultat pour Colorize
  //------------------------------------------------------------------------------

  enum UndoType {Nothing = 0, ResetColors = 1, RemoveGeometry = 2};

  //------------------------------------------------------------------------------
  // Set the colors
  //------------------------------------------------------------------------------

  virtual void SetColors (CATLONG32 iRedColor,
                          CATLONG32 iGreenColor,
                          CATLONG32 iBlueColor);

  //------------------------------------------------------------------------------
  // Get the old colors of an object
  //------------------------------------------------------------------------------

  virtual void GetColors (CATGeometry *iGeometry,
                          CATLONG32        &oRedColor,
                          CATLONG32        &oGreenColor,
                          CATLONG32        &oBlueColor);

  //------------------------------------------------------------------------------
  // Add a new CATGeometry object to the _GeometryToRemove array
  //------------------------------------------------------------------------------

  virtual void AddGeometryToRemove (CATGeometry *iGeometry);

  //------------------------------------------------------------------------------
  // Add a new CATGeometry object to the _GeometryToUnColor array
  //------------------------------------------------------------------------------

  virtual void AddGeometryToUnColor (CATGeometry *iGeometry,
                                     CATLONG32         iRedColor,
                                     CATLONG32         iGreenColor,
                                     CATLONG32         iBlueColor);

  //------------------------------------------------------------------------------
  // Colorize a CATGeometry object in the current colors
  // (the method returns ResetColors, RemoveGeometry or Nothing,
  // depending on whether its necessary to reset the color, remove
  // the created geometry (which is returned in ioGeometry, or
  // nothing at all)
  //------------------------------------------------------------------------------

  virtual UndoType Colorize (CATGeometry *&ioGeometry,
                             CATLONG32          iRedColor,
                             CATLONG32          iGreenColor,
                             CATLONG32          iBlueColor);

  //------------------------------------------------------------------------------
  // Create and visualize an arrowpoint on a given edge
  //------------------------------------------------------------------------------

  virtual void CreateArrowPoint(CATEdge   *iEdge,
                                CATVertex *iStartVertex,
                                CATVertex *iEndVertex);

  //------------------------------------------------------------------------------
  // Remove CATGeometry objects in _GeometryToRemove
  //------------------------------------------------------------------------------

  virtual void RemoveGeometries();

  //------------------------------------------------------------------------------
  // Create a break point manager
  //------------------------------------------------------------------------------

  virtual void CreateBreakPointManager();

};


#endif
