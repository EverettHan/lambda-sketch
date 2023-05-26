/* -*-C++-*- */

#ifndef CATTopRibGeoNuplet_H
#define CATTopRibGeoNuplet_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibGeoNuplet
// Classe virtuelle definissant la geometrie d'un morcau de ruban
// associe a un Nuplet d'appuis
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//===================================================================
//#include "ExportedByRIB.h"
#include "ExportedByRIBLight.h"

#include "CATTopRibObject.h"
#include "CATMathDef.h" 
#include "CATMathInline.h"
#include "CATTopRibDef.h" 

#include "CATCell.h"

class CATGeoFactory;
class CATCrvParam;
class CATGeometry;
class CATPoint;
class CATPCurve;
class CATSurface;
class CATTopRibSupport;
class CATCrvParam;
class CATSurParam;
class CATMathVector2D;
class CATMathDirection;
class CATSoftwareConfiguration;
class CATMathSetOfLongs;
class CATLISTP(CATCrvParam);
class CATMathSetOfVectors;

#include "ListPOfCATVertex.h"

#include "CATSafe.h"
CATSafeDefine(CATTopRibGeoNuplet);

class ExportedByRIBLight CATTopRibGeoNuplet  : public CATTopRibObject
{
 protected:

  CATLONG32            _NbOfUsers;
  CATOrientation  _CommonTrackOrientation; // Orientation des traces par rapport
                                           // a leurs geometrie
  CATTopRibType   _Type;                   // Indique si les traces sont fermees sur leurs parties utiles
  CATLONG32            _IndexOfUsedInit;        // -1 or 0
  CATLONG32            _IndexOfUsedExit;        // -1 or 1 thru NbExits

  CATBoolean      _FoldBackward;           // Indique si on termine par un rebroussement
  CATBoolean      _FoldForward;            // en Backward, ou en Forward

  CATTopRibGeoNuplet *_StartLink;          // Ds le cadre geometrie C1
  CATTopRibGeoNuplet *_EndLink;            // Ds le cadre geometrie C1
  int                 _SReverse;           // 0 : non; 1 : oui; 2/3 : non/oui en lien double           
  int                 _EReverse;           // idem

 private:
   CATBoolean     _EnableCloning;

 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATTopRibGeoNuplet();


  //------------------------------------------------------------------------------
  // Constructor based on an initial GeoNuplet
  //
  // Please note: Data is only copied if it is independent of external objects,
  //              i.e. the number of users of the new GeoNuplet is set 0
  //------------------------------------------------------------------------------

  CATTopRibGeoNuplet(CATTopRibGeoNuplet *iGeoNuplet);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------

  virtual ~CATTopRibGeoNuplet();



  //------------------------------------------------------------------------------
  // Clean Method after dummy creation operation
  //------------------------------------------------------------------------------
  virtual void CleanAfterCreateFaces();

  //------------------------------------------------------------------------------
  // Increase number of users by one
  //------------------------------------------------------------------------------

  void AddUser();


  //------------------------------------------------------------------------------
  // Decrease number of users by one
  //------------------------------------------------------------------------------

  void RemoveUser();


  //------------------------------------------------------------------------------
  // Get the number of users of the GeoNuplet
  //------------------------------------------------------------------------------

  INLINE CATLONG32 GetNbOfUsers() { return _NbOfUsers; };


  //------------------------------------------------------------------------------
  // Read data
  //------------------------------------------------------------------------------

  virtual CATLONG32                GetDimension        () const        = 0;
  virtual CATGeometry        *GetTrack            (CATLONG32 iNumSupp) = 0;
  virtual CATPCurve          *GetReference        (CATLONG32 iNumSupp);
  virtual CATLONG32                GetSuppReference    ();
  virtual CATTopRibDimension  GetTrackDimension   (CATLONG32 iNumSupp) = 0;

  virtual CATCrvParam        *GetEndParam         (CATLONG32          iNumSupp,
                                                   CATTopRibSign iDirection);
  virtual CATTopRibGeoNuplet *GetStartLink        (int &oReverse);
  virtual CATTopRibGeoNuplet *GetEndLink          (int &oReverse);  

  //------------------------------------------------------------------------------
  // Set data
  //------------------------------------------------------------------------------
  virtual void SetStartLink        (CATTopRibGeoNuplet *iStartLink, int iReverse);
  virtual void SetEndLink          (CATTopRibGeoNuplet *iEndLink, int iReverse);  

  //------------------------------------------------------------------------------
  // Set the geometry on a support.
  //------------------------------------------------------------------------------
  virtual void SetTrack(int          iNumSupp,
                        CATGeometry *iTrack) = 0;

  //------------------------------------------------------------------------------
  // Set the common track orientation with respect to the geometry
  //------------------------------------------------------------------------------

  virtual void SetCommonTrackOrientation (CATOrientation iCommonTrackOrientation);


  //------------------------------------------------------------------------------
  // Get the common track orientation with respect to the geometry
  //------------------------------------------------------------------------------

  virtual CATOrientation GetCommonTrackOrientation ();

  //------------------------------------------------------------------------------
  // Get the guide orientation with respect to the CommonTrackOrientation
  // (always 1, exept specific case in derivated classes)
  //------------------------------------------------------------------------------
  
  virtual CATOrientation GetTrackOrientation (int iNumTrack);

  //------------------------------------------------------------------------------
  // Check if the geometry is closed
  //------------------------------------------------------------------------------
  
  virtual CATBoolean IsClosed();
  void    SetClosed();

  //------------------------------------------------------------------------------
  // Report a point on the track geometry from one support to another 
  //------------------------------------------------------------------------------

  virtual void GetPointOnTrack(CATLONG32              iNumCurSupp,
			       CATCrvParam      &iParam,
			       CATLONG32              iNumNextSupp,
			       CATCrvParam      &oRepParam);


  //------------------------------------------------------------------------------
  // Analyze a list of CrvParam values on the geometrical tracks
  // and find out if any points have to be merged together
  //
  // argument explanation:
  //
  // Input:
  //           NbPoints            number of parameter values in ListOfParams
  //           ListOfParams[i]     parameter value at index i
  //
  // Output:
  //           NbMerge             number of cases where groups of parameter
  //                               points should be merged
  //           MergeList[j]        parameter points ranging from indices
  //                               MergeList[j][0] to MergeList[j][1] should be
  //                               merged together
  //           MergeParam[j]       Common parameter value at merge point
  //------------------------------------------------------------------------------

  virtual void AnalyzeParams(CATBody          *iCreationBody,
                             CATSoftwareConfiguration* iConfig,
                             int               iNbPoints,
			     CATCrvParam      *iListOfParams,
                             ListPOfCATVertex &iListOfVertices,
			     CATLONG32             *iListOfSupport, 
			     int              &oNbMerge,
			     int            (*&oMergeList)[2],
			     CATCrvParam     *&oMergeParam);


  //------------------------------------------------------------------------------
  // Check if 2 points on track are equal (Numerical Precision)
  //------------------------------------------------------------------------------
  virtual CATBoolean IsEqual(CATCrvParam      & iParam1,
			     CATLONG32               iNumSupport1,
			     CATCrvParam      & iParam2,
			     CATLONG32               iNumSupport2);

//------------------------------------------------------------------------------
// Check if 2 vertices on track are identical or are lying on the same vertex
//------------------------------------------------------------------------------
   CATBoolean IsEqual(CATBody                  *iCreationBody,
                      CATSoftwareConfiguration *iConfig,
                      CATVertex                *iVertex1,
		      CATVertex                *iVertex2);

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  virtual void Dump( CATCGMOutput& ioOS );

  //------------------------------------------------------------------------------
  // Check internal validity of this object
  //------------------------------------------------------------------------------
  virtual void Check();

  //------------------------------------------------------------------------------
  // Get the matter side of a geometric track on support
  //------------------------------------------------------------------------------

  virtual CATTopRibSign GetSide (CATLONG32 iNumSupp) = 0;

  //------------------------------------------------------------------------------
  // Set the index of the used init point
  //------------------------------------------------------------------------------

  void SetIndexOfUsedInit (CATLONG32 iIndexOfUsedInit);

  //------------------------------------------------------------------------------
  // Set the index of the used exit point
  //------------------------------------------------------------------------------

  void SetIndexOfUsedExit (CATLONG32 iIndexOfUsedExit);

  //------------------------------------------------------------------------------
  // Get the index of the used init point
  //------------------------------------------------------------------------------

  CATLONG32 GetIndexOfUsedInit ();

  //------------------------------------------------------------------------------
  // Get the index of the used exit point
  //------------------------------------------------------------------------------

  CATLONG32 GetIndexOfUsedExit ();

  //------------------------------------------------------------------------------
  // Check whether a non-degenerate topology can be created on the Track
  //------------------------------------------------------------------------------

  CATBoolean IsDegenerate (CATSoftwareConfiguration *iConfig,
                           int                       iNumSupp,
                           CATCrvParam              &iStartParam,
                           CATCrvParam              &iEndParam,
                           const double              iTolerance);

  //------------------------------------------------------------------------------
  // Deform the tracks.
  //------------------------------------------------------------------------------

  virtual CATLONG32 Deform(CATCrvParam ** ioStartRef, CATSurParam ** iStartPtTarget,
    CATCrvParam ** ioEndRef, CATSurParam ** iEndPtTarget,
    CATCrvParam ** ioStartClampRef=0, CATCrvParam ** ioEndClampRef=0,
    CATMathVector2D ** ioStartTgTarget=0,CATMathVector2D ** ioEndTgTarget=0);

  //------------------------------------------------------------------------------
  // Get the parameters to be used for the init/exit inclusion tests
  // on a given support
  //------------------------------------------------------------------------------
  void GetParamsForInclusionTest (CATLONG32         iSupportIndex,
                                  CATCrvParam &oLowParamOnTrack,
                                  CATCrvParam &oHighParamOnTrack);

  //------------------------------------------------------------------------------
  // EnableCloning
  //------------------------------------------------------------------------------
  CATBoolean EnableCloning();
  void       SetEnableCloning(CATBoolean iYesOrNo);

  //------------------------------------------------------------------------------
  // Analyze convexity
  // Cette methode est codee dans Draft Reflect et Neutral
  // Return False dans les autres cas
  //------------------------------------------------------------------------------
  virtual CATBoolean AnalyzeConvexity (CATSoftwareConfiguration * ipConfig,
                                       CATMathDirection &iDirection,      // 
                                       CATCrvParam      &iEvalParam,      // Parametre d'evaluation sur PCurve
                                       CATTopRibSign    &oSurfaceOrient,  // Orientation of the Draft surface
                                       CATTopConvexity  &oEdgeConvexity); // Indicates whether the edge

  //------------------------------------------------------------------------------
  // Detection de rebroussement dans une direction donnee
  //------------------------------------------------------------------------------
  virtual CATBoolean HasFold(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Indication de rebroussement dans une direction donnee
  // Attention, il s'agit ici de la direction du GeoNuplet, pas du Nuplet
  //------------------------------------------------------------------------------
  virtual void SetFold(CATTopRibSign iDirection);

  //---------------------------------------------------------------------------
  // This method computes the maximum gap possible between connect solutions
  // for given g0/g1 gaps in any of the support geometries
  //---------------------------------------------------------------------------
  virtual CATBoolean ComputeMaxGap( const CATMathSetOfLongs &iSupportIDs,
                            const CATLISTP(CATCrvParam) &iCrvParams,
                            const CATMathSetOfVectors &iG0Gaps,
                            const CATMathSetOfVectors &iG1Gaps,
                            const CATMathSetOfVectors &iAnglesOfIncidence,
                            CATListOfDouble &oMaxGaps
                            );
};
#endif
