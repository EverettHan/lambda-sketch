/* -*-C++-*- */

#ifndef CATIntRibGeoNuplet_H
#define CATIntRibGeoNuplet_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//------------------------------------------------------------------------------
//
// CATIntRibGeoNuplet
// Class definition for the geometry of a single surface-surface intersection
// ribbon element
//
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// August 1997    Creation                         A. State
//                Responsable                      P. Rossignol
//------------------------------------------------------------------------------

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "CATTopRibGeoNuplet.h"

#include "ListPOfCATTopRibGeoNuplet.h"

class CATGeoFactory;
class CATGeometry;
class CATSurface;
class CATCurve;
class CATEdgeCurve;
class CATTopRibSupport;
class CATCrvParam;
class CATEdge;

class ExportedByRIBLight CATIntRibGeoNuplet : public CATTopRibGeoNuplet
{
 protected:
  CATGeoFactory *_GeoFactory;
  CATSurface    *_LeftSurface;
  CATSurface    *_RightSurface;
  CATTopRibSign  _LeftSurfaceOrientation;
  CATTopRibSign  _RightSurfaceOrientation;
  CATEdgeCurve  *_EdgeCurve;
  CATTopRibSign  _MatterSideOnLeftSurface;
  CATTopRibSign  _MatterSideOnRightSurface;
  CATCrvParam   *_StartParam;
  CATCrvParam   *_EndParam;
  CATPCurve     *_RefPCurve[2];
  CATBoolean     _PropagationBeyondExtrRibCheck;

 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------

  CATIntRibGeoNuplet ();

  //------------------------------------------------------------------------------
  // Constructor based on an initial GeoNuplet
  //
  // Please note: Data is only copied if it is independent of external objects,
  //              i.e. the number of users of the new GeoNuplet is set 0
  //------------------------------------------------------------------------------

  CATIntRibGeoNuplet (CATIntRibGeoNuplet *iGeoNuplet);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------

  virtual ~CATIntRibGeoNuplet ();

  //------------------------------------------------------------------------------
  // Read & write methods
  //------------------------------------------------------------------------------

  virtual void                SetGeoFactory               (CATGeoFactory    *iGeoFactory);
  virtual void                SetLeftSurface              (CATSurface       *iLeftSurface);
  virtual void                SetRightSurface             (CATSurface       *iRightSurface);
  virtual void                SetLeftSurfaceOrientation   (CATTopRibSign     iLeftSurfaceOrientation);
  virtual void                SetRightSurfaceOrientation  (CATTopRibSign     iRightSurfaceOrientation);
  virtual void                SetEdgeCurve                (CATEdgeCurve     *iEdgeCurve);
  virtual CATEdgeCurve       *GetEdgeCurve                ();
  virtual void                SetMatterSideOnLeftSurface  (CATTopRibSign     iMatterSideOnLeftSurface);
  virtual void                SetMatterSideOnRightSurface (CATTopRibSign     iMatterSideOnRightSurface);
  virtual CATLONG32                GetDimension                () const;
  virtual CATGeometry        *GetTrack                    (CATLONG32 iNumSupp);
          void                SetReference                (CATLONG32 iNumSupp, CATPCurve * iReference);
          CATPCurve          *GetReference                (CATLONG32 iNumSupp);
  virtual CATTopRibDimension  GetTrackDimension           (CATLONG32 iNumSupp);
  virtual CATCrvParam        *GetEndParam                 (CATLONG32          iNumSupp,
                                                           CATTopRibSign iDirection);
  void                        SetEndParam                 (CATTopRibSign  iDirection,
                                                           CATCrvParam   &iEndParam);
  virtual void                SetPropagationBeyondExtrRibCheck(CATBoolean iCheckToDo);
  virtual CATBoolean          GetPropagationBeyondExtrRibCheck();

  //------------------------------------------------------------------------------
  // Set the geometry on a support.
  //------------------------------------------------------------------------------
  void SetTrack (int          iNumSupp,
                 CATGeometry *iTrack);

  //------------------------------------------------------------------------------
  // Get the matter side of a geometric track on support
  //------------------------------------------------------------------------------

  virtual CATTopRibSign GetSide (CATLONG32 iNumSupp);

  //------------------------------------------------------------------------------
  // Check whether a given curve is contained in the intersection GeoNuplet's
  // track curve
  //
  // Please note: oOrientation is an optional output that indicates the relative
  //              orientation between the GeoNuplet (which isn't necessarily
  //              oriented like its track curve!) and
  //              iCurve
  //------------------------------------------------------------------------------

  CATBoolean IsContaining (CATCurve      *iCurve,
                           CATTopRibSign *oOrientation = NULL);

  //------------------------------------------------------------------------------
  // Get the relative orientation between the
  // common edge and the N-uplet(s) that will
  // be created based on the GeoNuplet
  //------------------------------------------------------------------------------

  CATTopRibSign GetRelativeOrientation (CATEdge *iEdge);

  //------------------------------------------------------------------------------
  // Set/Get tangent design info on the geometric track
  //------------------------------------------------------------------------------
  void SetTangentDesignInfo(CATLONG32 iTangentDesignInfo);
  CATLONG32 GetTangentDesignInfo();

private:
//===========================================================================================================
  
  //------------------------------------------------------------------------------
  // Juste pour eviter que le compilo ne definisse par lui-meme ces operateurs
  //------------------------------------------------------------------------------    
  CATIntRibGeoNuplet(CATIntRibGeoNuplet& iOperator);
  CATIntRibGeoNuplet& operator=(const CATIntRibGeoNuplet & iOperator);

  CATLONG32 _TangentDesignInfo;
};
#endif
