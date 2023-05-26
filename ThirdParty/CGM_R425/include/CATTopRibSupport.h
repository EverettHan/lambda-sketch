/* -*-C++-*- */

#ifndef CATTopRibSupport_H
#define CATTopRibSupport_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibSupport
// Classe definissant un element d'appui au niveau topologique pour  
// le calcul d'un morceau de ruban 
//
//===================================================================


//===================================================================
// Usage notes:
//
// Convention sur l'orientation des supports :
// - Support Face :
// - Support Edge :
//   L'orientation est remplie a posteriori, lors de la creation de la track.
//   Elle indique si la track (edge) va dans le meme sens que son support (edge).
//
// Convention sur l'orientation des bumpers :
//   L'orientation du bumper est a utiliser directement comme l'orientation d'un support
//   Ex : En rolling edge, on peut remplace l'edge support par un des bumpers. Pour avoir
//        l'orientation de ce pseudo-support, on lira directement l'orientation du
//        bumper (au lieu de faire GetOrientation)
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//===================================================================

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"

#include "CATTopRibObject.h"
#include "CATTopRibDef.h"
#include "CATMathDef.h"
#include "GeometricUtilities.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "CATCell.h" 
#include "CATThrowForNullPointer.h"
#include "CATCGMNewArray.h"
#include "CATMathInline.h"
#include <stdio.h>

class CATTopRibMacroTool;
class CATTopRibTool;
class CATSupContact;
class CATLoopExtension;

class CATBody;
class CATShell;
class CATFace;
class CATLoop;
class CATEdge;
class CATVertex;

class CATMacroPoint;
class CATEdgeCurve;
class CATCrvLimits;
class CATSurLimits;

class CATSoftwareConfiguration;

#define TouchInitialFacesOfUsedLoopExtensionsOnly

#include "CATSafe.h"
CATSafeDefine(CATTopRibSupport);

class ExportedByRIBLight CATTopRibSupport : public CATTopRibObject
{
  public:
  //------------------------------------------------------------------------------
  // Constructors (to be replaced by static Create function to allow CATTopRibSupport class derivation)
  //------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare; // Pool allocation
  CATTopRibSupport(CATCell*            iSuppCell, 
                   const CATTopRibSign iOrientation,
                   const CATTopRibSupp iTypeOfSupport, 
                   const CATTopRibSol  iSolType = SolTypeUnknown);
  CATTopRibSupport (const CATTopRibSupport* iSupport, const CATTopRibSol iSolType);
  CATTopRibSupport(const CATTopRibSupport & iToCopy);
  CATTopRibSupport & operator = (const CATTopRibSupport & iToCopy);
  CATTopRibSupport();
  
  //------------------------------------------------------------------------------
  // Rolling Sharp Edge, constructor with "bumpers" (faces in most cases)
  // Convention sur l'orientation des bumpers :
  //   voir entete 
  //------------------------------------------------------------------------------
  CATTopRibSupport( CATEdge* iEdge, 
                    CATCell* iFirstBumper,  const CATTopRibSign iFirstBumperOrientation,
                    CATCell* iSecondBumper, const CATTopRibSign iSecondBumperOrientation);
  
  //------------------------------------------------------------------------------
  // Creates a new Support with Limits Extension on the iContact side.
  //------------------------------------------------------------------------------
  static CATTopRibSupport* Create(const CATTopRibSupport   *iSupport, 
                                  const CATSupContact      *iContact,
                                  CATSoftwareConfiguration *iConfig) ;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATTopRibSupport ();

  //------------------------------------------------------------------------------
  // Duplication with sub type
  //------------------------------------------------------------------------------
  CATTopRibSupport* Clone() const ;

  //------------------------------------------------------------------------------
  // Reading
  //------------------------------------------------------------------------------
  INLINE CATCell*      GetSuppCell         () const { if (NULL==_SuppCell) CATThrowForNullPointerReturnValue(NULL); return _SuppCell ; } ;
  INLINE CATBoolean    HasSuppCell         () const { return _SuppCell != NULL         ; } ;
  INLINE CATTopRibSupp GetSupportType      () const { return _TypeOfSupp               ; } ;
  INLINE CATTopRibSign GetOrientation      () const { return _Orientation              ; } ;
  INLINE CATTopRibSol  GetPartingType      () const { return _TypeOfSolVsParting       ; } ;
  INLINE int           GetDimension        () const { if (NULL==_SuppCell) CATThrowForNullPointerReturnValue(0); return _SuppCell->GetDimension() ; } ;
  INLINE CATBoolean    IsSplitWithFaceMode () const { return _SplitWithFaceMode        ; } ;
  INLINE CATTopRibSol  GetSolType          () const { return _TypeOfSol; };

  CATFace*      GetComplementaryFace() const ;
  int           GetNbComplementaryFaces() ;
  CATFace*      GetInitialFace      () const ;
  void          GetGeometry         (const double              iExtensionRatio,
                                     CATSoftwareConfiguration* iConfig,
                                     CATFace*                 &oSuppFace, // Throws exception whenever this dimension is not 2 or IsEmpty
                                     CATSurface*              &oSuppSurface,
                                     CATLONG32                     &oOriVsSurface,
                                     CATSurLimits             &oSurfaceLimits,
                                     CATBoolean                iSurfaceExtrapol=FALSE,
                                     CATSurLimits             *oFaceLimits     =NULL,
                                     CATSurParam              *iParamToInclude = NULL,
                                     int                      *oNeedUVSwitch = NULL,
                                     CATMathBox               *iWorkingBox = NULL) const ;
  // Modified By : SUH : 2004:3:22
  // iRatioMin/iRatioMax is the extrapolation ratio in min/max limit direction. These override iExtensionratio if provided.
  void          GetGeometry         (CATSoftwareConfiguration* iConfig, 
                                     CATEdge*        &oSuppEdge, // Throws exception whenever this dimension is not 1 or IsEmpty
                                     CATEdgeCurve*   &oSuppCurve,
                                     CATLONG32       &oOriVsCurve, 
                                     const double     iExtensionratio,
                                     CATCrvLimits    &oCurveLimits,
                                     CATBoolean       iCurveExtrapol=FALSE,
                                     double*          iRatioMin = NULL,
                                     double*          iRatioMax = NULL) const ;

  void          GetGeometry         (CATVertex*      &oSuppVertex,
                                     CATMacroPoint*  &oSuppPoint    ) const ;
  int           GetString           (char* iName) const;
  //----------------------------------------------------------------------

  INLINE CATLoopExtension*  GetLoopExtension()  { return _LoopExtension; };
  INLINE int                HasLoopExtension()  { return _LoopExtension!=NULL; };
  INLINE CATFace*           GetAllowedCovFace() { return _AllowedCovFace; };        
  CATFace*           GetOldSuppCell() const;
  int                HasComplFace ();

  //----------------------------------------------------------------------
  // Setting
  //----------------------------------------------------------------------
  void Set(CATCell*            iSuppCell,             // Also reset other attributes
           const CATTopRibSign iOrientation,
           const CATTopRibSupp iTypeOfSupport, 
           const CATTopRibSol  iSolType);

  void Update(CATCell*            iSuppCell,          // Does not change other attribures
              const CATTopRibSign iOrientation,
              const CATTopRibSol  iSolType);

  void SetSuppCell             (CATCell            *iSupport      );
  INLINE void SetSolType       (const CATTopRibSol  iNewSolType   )   { _TypeOfSol  = iNewSolType; };
  INLINE void SetSupportType   (const CATTopRibSupp iTypeOfSupport)   { _TypeOfSupp  = iTypeOfSupport; };
  INLINE void SetPartingType   (const CATTopRibSol  iNewSolType   )   { _TypeOfSolVsParting = iNewSolType; };
  INLINE void SetLoopExtension (CATLoopExtension *iLoopExtension  )   { _LoopExtension = iLoopExtension; };
  INLINE void SetAllowedCovFace(CATFace            *iFac          )   { _AllowedCovFace = iFac; };            
  INLINE void UnsetSplitWithFaceMode()                                {  _SplitWithFaceMode = FALSE ; };

  void SwitchOrientation();
  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump( CATCGMOutput& ioOS, int iRlm = 0);

  //------------------------------------------------------------------------------
  // Extrapolation methods
  //------------------------------------------------------------------------------
  public:
  void ExtrapolUpToMaxLimits();
  void ExtendSurfaceOnReducedLimits();

  void SetExtension(const CATSurLimits &iLimits);
  void SetExtension(const CATCrvLimits &iLimits);
  const void * GetExtension(int *oDimension);



  public:
  void ExtrapolOnBorder (double                    iRatio,
                         CATCell*                  iBorderCell, 
                         CATCell*                  iHigherBorderCell,
                         CATSoftwareConfiguration *iConfig,
                         double                    iFaceExtrapolRatioVsVolumeBox = 1.2,
                         CATEdgeCurve*             iCrossEdgeCurve = NULL,
                         CATCrvLimits*             iCrossLimits    = NULL,
                         CATShell*                 iInitShell      = NULL,
                         CATShell*                 iShellToCross   = NULL,
                         CATBoolean*               oExtrapolDone   = NULL,           // Si CATExtandSurLimits a ete appele
                         CATSurLimits*             oExtrapolResLimits = NULL);     // Value si oExtrapolDone a TRUE!

  //void SetExtension(const CATSurLimits &iLimits);
  //void SetExtension(const CATCrvLimits &iLimits);
  void SetExtension(); // Reset to default

  //------------------------------------------------------------------------------
  // Méthodes for Align Mode
  //------------------------------------------------------------------------------
  public:
    INLINE void SetSwitchForAlignMode(CATBoolean iSwitch = TRUE) {  _SwitchForAlign = iSwitch; };
    INLINE CATBoolean IsSwitchForAlignMode() {  return _SwitchForAlign; };
 
  //------------------------------------------------------------------------------
  // Switch the support to the loop extension support cell
  //------------------------------------------------------------------------------
  /*public:
  void SwitchToLoopExtension (CATTopRibTool *iTool,
                              CATLONG32           iSupportIndex,
                              CATCell       *iBorderCell,
                              CATEdgeCurve  *iCrossEdgeCurve = NULL,
                              CATCrvLimits  *iCrossLimits    = NULL);
  void SwitchToLoopExtension (CATTopRibMacroTool *iMacroTool,
                              CATLONG32                iSupportIndex,
                              CATCell            *iBorderCell,
                              CATEdgeCurve       *iCrossEdgeCurve = NULL,
                              CATCrvLimits       *iCrossLimits    = NULL);
  void SwitchToLoopExtension (CATLoopExtension   *iLoopExtension,
                              CATCell            *iBorderCell,
                              CATCell            *iBestComplCell = NULL);*/

  //------------------------------------------------------------------------------
  // Switch the support back to its initial support cell
  //------------------------------------------------------------------------------

  void SwitchBackToInitial (CATTopRibSol *iSolType = NULL);

  //------------------------------------------------------------------------------
  // Check if the support is equivalent to another support
  //------------------------------------------------------------------------------

  CATBoolean IsEquivalentTo (CATTopRibSupport *iSupport,CATBoolean IgnoreConfusion=FALSE) const;
  CATBoolean IsEqualTo (CATTopRibSupport *iSupport) const;
  CATBoolean HaveSameInputs (CATTopRibSupport *iSupport) const;

  //------------------------------------------------------------------------------
  // Bumpers access
  // Explanation on orientations : see constructor with bumpers
  //------------------------------------------------------------------------------
  // Get number of bumpers (0, 1 or 2)
  INLINE int GetNumberOfBumpers() const { return _Bumpers.Size(); } ;
  // Read a bumper
  CATCell* GetBumper(const int iBumperIndex, CATTopRibSign* oBumperOrientation=NULL);
  // Get/Set the number of the "covered" bumper
  void SetCoveredBumper(int iPos);
  int  GetCoveredBumper();
  // Add a bumper, returns the position of the new bumper (max=2)
  // Bumpers over 2 are refused (return 0)
  int AddBumper(CATCell* iBumper, CATTopRibSign iOrientation, int *iCovered=NULL);
  // Bumper is covered ?
  CATBoolean IsCoveredBumper (int i);


  //------------------------------------------------------------------------------
  // Get the extrapolation vertex search direction (with respect to
  // the support's orientation)
  //------------------------------------------------------------------------------
  public:
  CATTopRibSign GetExtrapolVertexSearchDirection() const;

  //------------------------------------------------------------------------------
  // Switch the extrapolation vertex search direction (with respect to
  // the support's orientation)
  //------------------------------------------------------------------------------
  public:
  void SwitchExtrapolVertexSearchDirection();

  //------------------------------------------------------------------------------
  // Find out if the surface must not be extended
  //------------------------------------------------------------------------------
  public:
  INLINE CATBoolean DoNotExtendSurface() const {  return _DoNotExtendSurface; };
  INLINE CATBoolean GetExtendSurfaceOnReducedLimits() const {   return _ExtendSurfaceOnReducedLimits; };

  INLINE void SetEquivalentSuppCell(CATCell *iEquivalentSuppCell) { _EquivalentSuppCell = iEquivalentSuppCell; };
  INLINE CATCell* ReadEquivalentSuppCell() {  return _EquivalentSuppCell; };

  //-----------------------------------------------------------------
  // Indicates if the NupletCand can be a single new candidate
  //-----------------------------------------------------------------
  INLINE CATBoolean IsInvalidIfSingleNewCandidate() { return _InvalidIfSingleNewCandidate; };
  INLINE void SetInvalidIfSingleNewCandidate()      { _InvalidIfSingleNewCandidate = TRUE; };

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCell            *_SuppCell;    // Support Cell
  CATLoopExtension   *_LoopExtension;
  CATTopRibSign       _Orientation; // Coef. a appliquer a l'orientation du support
  CATTopRibSupp       _TypeOfSupp;  // Type de support: guide,rolling, ...
  CATTopRibSol        _TypeOfSol;   // Solution cherchee: in, out, ...
  CATTopRibSol        _TypeOfSolVsParting;   // Solution cherchee: above, below, ...
  int                 _ExtensionDimension;
  void               *_Extension;   // Dim 2: CATSurLimits*, Optionally overides the 2DBoundingBox of the Face
                                    // Dim 1: CATCrvLimits*, Optionally overides the 1DBoundingBox of the Ege
                                    // NB: Objet pointe non partageable
  CATBoolean          _SplitWithFaceMode; //SplitEdge or SetCutting
  ListPOfCATCell      _Bumpers;
  CATListOfInt        _BumpersOrn;
  CATListOfInt        _BumpersAreCovered;

  int                 _CoveredBumperPos;

  CATTopRibSign       _ExtrapolVertexSearchDirection;

  CATBoolean          _DoNotExtendSurface;

  CATBoolean          _ExtendSurfaceOnReducedLimits;

  CATCell            *_EquivalentSuppCell;    // Equivalent Support Cell

  CATBoolean          _InvalidIfSingleNewCandidate; // Default = False

  CATBoolean          _SwitchForAlign;
  CATFace            *_AllowedCovFace;
  CATULONG32          _OrigSuppTag;

  //------------------------------------------------------------------------------
  // Expendable data
  //------------------------------------------------------------------------------
  //CATEdge            *_BoundedEdge; // Edge de buttee quand on "roule" sur un vertex 
  //CATTopRibSign       _SideOfEdge;  // Orientation de l'edge buttee  
  //CATFace            *_BoundedFace; // face buttee quand on "roule" sur une edge  
  //CATTopRibSign       _SideOfFace;  // orientation de la face buttee 

  //------------------------------------------------------------------------------
  // Analyze a track's end on its support's underlying geometry and
  // extrapolate the geometry if needed
  //------------------------------------------------------------------------------

  private:

    static CATPositionOnLimits GetPosition(CATGeoFactory * iGeoFactory, 
                                           CATSoftwareConfiguration *iConfig,
                                           CATSurParam &param, 
                                           CATSurLimits &limits, 
                                           CATSurface * iSurface,
                                           double iTol);

    static CATPositionOnLimits GetNearestLimit(CATGeoFactory * iGeoFactory, 
                                               CATSoftwareConfiguration *iConfig,
                                               CATSurParam &param, 
                                               CATSurface* surface,
                                               CATSurLimits &limits);

    static CATPositionOnLimits GetNearestLimits(CATSurParam &param, 
                                                CATSurface* surface,
                                                CATSurLimits &limits,
                                                double iTol);

  //------------------------------------------------------------------------------
  // Determine the location of an Edge with respect to the given box limits on a
  // Face's surface
  //
  // Please note: The method may also determine the location(s) of the start or
  //              end vertex (or both) with respect to the surface's maximum
  //              limits, as well as the corresponding CATSurParam values
  // The method does not yet take the tolerance value iTol into account
  //------------------------------------------------------------------------------
  public:

  static CATPositionOnLimits GetEdgeLocationVsSurfaceBoxLimits(CATGeoFactory            *iGeoFactory,
                                                               CATSoftwareConfiguration *iConfig,
                                                               CATEdge                  *iEdge,
                                                               CATFace                  *iFace,
                                                               CATSurLimits             &iBoxLimits,
                                                               double                    iTol,
                                                               CATPositionOnLimits      &oStartPosition,
                                                               CATPositionOnLimits      &oEndPosition,
                                                               CATSurParam              &oStartSurParam,
                                                               CATSurParam              &oEndSurParam);

/*
  CATPositionOnLimits  SupportGeoEnded (CATTopRibSign        iDirection,
					                              CATCell             *TrackOnSupport,
					                              CATVertex           *iContactVertex);

  CATCell             *SupportGeoExtr  (CATBody             *iBody,
					                              CATTopRibSign        iDirection,
					                              CATPositionOnLimits  iPosition);

ExportedByRibbonLight CATPositionOnLimits  GetPosition         (CATCrvParam  &param,
                                                           CATCrvLimits &limits);

ExportedByRibbonLight CATPositionOnLimits  GetPosition         (CATSurParam  &param,
                                                           CATSurLimits &limits);
*/

  public :
    INLINE void SetIsoTopoSpecMatching(int iValue=1)           {  _IsoTopoSpecMatching = iValue; };
    INLINE CATBoolean IsIsoTopoSpecMatching()                  { return _IsoTopoSpecMatching==1 ; };
    INLINE CATBoolean IsIsoTopoSpecMatchingSet()               {  return _IsoTopoSpecMatching!=-1 ; };
    INLINE void SetSplitWithMoreThanOneFace(CATBoolean iValue) { _SplitWithMoreThanOneFace = iValue; };
    INLINE CATBoolean GetSplitWithMoreThanOneFace()            {  return _SplitWithMoreThanOneFace; };


  private :
    int    _IsoTopoSpecMatching;
    CATBoolean _SplitWithMoreThanOneFace;
    
  public :
    CATBoolean IsInfinite();

  private:
    CATBoolean CheckIfExtrapolationIsNeeded(CATSoftwareConfiguration *iConfig,
                                            CATMathBox &iWorkingBox, 
                                            CATSurface * iSurface, 
                                            const CATSurLimits &iSurLimits) const;

};

#endif
