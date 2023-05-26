//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//=============================================================================
//
// CATClash2D:
//    Header file for the CATClash2D operator.
//
//=============================================================================
// Usage notes:
//=============================================================================
// 17/03/14 : XMH : Creation
// 02/07/14 : XMH : AddBody, Caller body id
// 25/07/14 : XMH : Implement 2D transform
// 10/07/15 : XMH : Interface changes to allow instances of bodies
//                  caller body id compulsory, inquiry using ID rather than body pointer
// 26/08/15 : XMH : Remove deprecated methods.
// 10/01/17 : F1Z : Region option review.
// 22/02/21 : R1Y : Added functionality to obtain containment data.
// 22/04/22 : R1Y : Added functionality to obtain body data.
//=============================================================================
#ifndef CATClash2D_H
#define CATClash2D_H

// Misc
#include "Clash2D.h" // for ExportedByClash2D

#include "CATCGMClash2DDef.h"
#include "CATGeoOperator.h"
#include "CATTopDefine.h" // for CATOrientation

// Mathematics
#include "CATMathDirection2D.h"
#include "CATMathPoint2D.h"

// Geometry
#include "CATCrvParam.h"

// Lists
#include "CATLISTV_CATMathPoint2D.h"

class CATMathTransformation2D;
class CATClash2DCrossing;
class CATGeoFactory;
class CATClash2DClashRegion;
class CATEdge;
class CATClashRegionOption;


#undef CLASH2D_PLANES_TEST


/**
* Class defining the operator for clashing 2D geometries.
* <br> The operator returns 1 for success and 0 for failure.
*<ul>
*<li>The CATClash2D operator is created with the <tt>CreateGeoOpTemplate</tt> method and 
* directly <tt>delete</tt>d with the usual C++ delete operator.
*<li>In case of <tt>BASIC</tt>
* mode, the operation is automatically performed at the operator creation. 
* In case of <tt>ADVANCED</tt>
* mode, options can be selected with the <tt>Set</tt> methods, before
* asking for the computation with the <tt>Run</tt> method.ExportedByClash2D
*<li>In both cases, the result is accessed using <tt>GetResult()</tt>.
*</ul>
*/
class ExportedByClash2D CATClash2D : public CATGeoOperator
{
  CATCGMVirtualDeclareClass(CATClash2D);

public:

  // CATClash2DClassification describes how a pair of bodies clash
  // Warning: Since the enum is captured in the replay file DO NOT change the order or values of the items.
  /** Clash classification of a pair of bodies.
  * @param <tt>CATClash2D_Unknown</tt>
  * The classification is unknown.
  * @param <tt>CATClash2D_Error</tt>
  * The classification is not set as the operator encountered an error.
  * @param <tt>CATClash2D_NoClash</tt>
  * The bodies do not clash.
  * @param <tt>CATClash2D_Clash</tt>
  * The bodies clash in a region of penetration.
  * @param <tt>CATClash2D_Clash_Abut</tt>
  * The bodies clash along an edge of penetration.
  * @param <tt>CATClash2D_Contained</tt>
  * One body is entirely contained in the other body, and the borders do not touch.
  * @param <tt>CATClash2D_Contained_Abut</tt>
  * One body is entirely contained in the other body, and there is contact at a border.
  * @param <tt>CATClash2D_Clash_MaxPenDepthExceeded</tt>
  * The operator terminated early as the maximum penetration depth set by the user has been exceeded. 
  * Only some clashes have been computed so the result is incomplete.
  */
    /** @nodoc @nocgmitf */
  typedef enum 
  { 
    CATClash2D_Unknown                       = CATCGMClash2D_Unknown , //  -2,
    CATClash2D_Error                         = CATCGMClash2D_Error   , //  -1
    CATClash2D_NoClash                       = CATCGMClash2D_NoClash , //   0
    CATClash2D_Clash                         = CATCGMClash2D_Clash   , //   1
    CATClash2D_Clash_Abut                    = CATCGMClash2D_Clash_Abut , //   2
    CATClash2D_Contained                     = CATCGMClash2D_Contained  , //   3
    CATClash2D_Contained_Abut                = CATCGMClash2D_Contained_Abut,// 4
    CATClash2D_Clash_MaxPenDepthExceeded     = CATCGMClash2D_Clash_MaxPenDepthExceeded //5
  } CATClash2DClassification;

   // CATClash2DTransformMode describes how a transformation should be applied to a body
  // Warning: Since the enum is captured in the replay file DO NOT change the order or values of the items.
  /** Clash transformation mode.
  * @param <tt>CATClash2D_TransformReplace</tt>
  * The transform should replace the transform currently applied to the body.
  * @param <tt>CATClash2D_TransformConcatenate</tt>
  * The transform should be concatentated with the transform currently applied to the body.
  */
   /** @nodoc @nocgmitf */
  typedef enum 
  { 
    CATClash2D_TransformReplace     =  CATCGMClash2D_TransformReplace      ,// 0,
    CATClash2D_TransformConcatenate =  CATCGMClash2D_TransformConcatenate   // 1  
  } CATClash2DTransformMode;

  /** 
  * @nodoc
  * Do not use this constructor. Use the creation method
  * <tt>CreateClash2D</tt>.
  */
  /** @nodoc @nocgmitf */
  CATClash2D();

  /** @nodoc @nocgmitf */
  CATClash2D( CATGeoFactory * iUserFactory );

  virtual ~CATClash2D();

  //-----------------------------------------------------------------------
  //- Get methods
  //-----------------------------------------------------------------------

  /**
  * Returns the software configuration.
  * @return
  * The software configuration.
  */
  /** @nodoc @nocgmitf */
  virtual CATSoftwareConfiguration * GetConfig() const = 0;

    
  /**
  * Returns the tolerance to be used in the clash computation.
  * @return
  * The clash tolerance.
  */
  virtual double GetClashTolerance() const = 0;


  /**
  * Retrieve the region options.
  * /!\The regionOption point to the operator attributs.
  * So they won't be avalaible if the operator is destroyed or the options has changed anymore.
  */
  /** @nodoc @nocgmitf */
  virtual void GetRegionComputationOption(const CATClashRegionOption * & oRegionOptions) = 0;

  /**
  * Returns the active state of an input body.
  * @param iBody1D
  * The ID of the body (instance).
  * @return
  * The active state of the body (instance).
  */
  virtual CATBoolean GetActivateState( CATLONG32 iBody1D_ID ) const = 0;

#ifdef CLASH2D_PLANES_TEST
  /**
  * Gets the number of bodies that are considered by the CATClash2D computation.
  * @return
  * The number of bodies that are considered by the CATClash2D computation.
  */
  virtual CATLONG32 GetNumberOfBodyInstances() const = 0;
 #endif
 
  /**
  * Returns the option that indicates whether containment data is to be calculated.
  * @return
  * TRUE if containment data is to be calculated, FALSE if it is not to be caclulated.
  */
  virtual CATBoolean GetCalcContainmentData() const = 0;

#ifdef CLASH2D_PLANES_TEST
  /**
  * Gets the bodies that are considered by the CATClash2D computation (and the factory into which they were cloned).
  * Instances of a body can share a body pointer but must be given a distinct ID and transform.
  * @param oFactory
  * The factory that contains the bodies (which were cloned from another factory).
  * @param oBodies1D
  * Array of 1D bodies that were added.
  * @param oCallerBodyIDs
  * Caller assigned array of integer tags to identity the body instance (e.g. index in array of body)
  * @param oTransforms
  * Array of corresponding 2D transforms to be applied to the bodies.
  * @param oOrientations
  * Array of corresponding orientations of the bodies.
  * @param oActives
  * Array of corresponding active states of the bodies.
  * @return
  * Whether the bodies were successfully obtained.
  */
  virtual CATBoolean GetBodies(CATGeoFactory            *& oFactory,
                               CATBody                 **& oBodies1D,
                               CATLONG32                *& oCallerBodyIDs,
                               CATMathTransformation2D  *& oTransforms,
                               CATOrientation           *& oOrientation,
                               CATBoolean               *& oActive) const = 0;
#endif

  //-----------------------------------------------------------------------
  //- Set methods
  //-----------------------------------------------------------------------

  /**
  * Sets the tolerance to be used in the clash computation.
  * @param iClashTol
  * The tolerance.
  */
  virtual void SetClashTolerance( double iClashTol ) = 0;

  /**
   * Remove previous region option and set the provided one.
   * The data is duplicated inside the operator.
   */
  /** @nodoc @nocgmitf */
  virtual CATBoolean SetRegionComputationOption(const CATClashRegionOption * iRegionOption ) = 0;

  /**
  * Sets the pairs of clash bodies which are to be considered by the clash Run.
  * To be called after the bodies have been added, otherwise it will fail.
  * If not called, or unset, then Run will consider all possible pairs of bodies.
  * To unset call UnsetClashBodyPairs.
  * @param iClashBodyIDs1
  * A list of clash body IDs, first of each pair
  * @param iClashBodyIDs2
  * A list of clash body IDs, second of each pair
  * @return
  * TRUE if the ClashBody IDs were valid and the pairs were successfully added
  * FALSE, otherwise.
  */
  virtual CATBoolean SetClashBodyPairs( const CATListOfInt & iClashBodyIDs1, 
                                        const CATListOfInt & iClashBodyIDs2 ) = 0;

  /**
  * Unsets the pairs of clash bodies which are to be considered by the clash Run.
  */
  virtual void UnsetClashBodyPairs() = 0;

#ifdef CLASH2D_PLANES_TEST
  /**
  * Removes all clash bodies which are to be considered by the clash Run.
  * Warning: This function is to be used for internal testing only.
  */
  virtual void Test_RemoveAllBodies() = 0;
#endif

  /**
  * Sets the option that indicates whether containment data is to be calculated.
  * @param iCalcContainmentData
  * TRUE if containment data is to be calculated, FALSE if it is not to be calculated
  */
  virtual void SetCalcContainmentData( const CATBoolean iCalcContainmentData ) = 0;

  //-----------------------------------------------------------------------
  //- Add/Remove methods
  //-----------------------------------------------------------------------
  /**
  * Adds a 1D body to be considered in the CATClash2D computation.
  * Instances of a body can share a body pointer but must be given a distinct ID and transform.
  * @param iBody1D
  * The 1D body to be added.
  * @param iCallerBodyID
  * Caller assigned integer tag to identity the body instance (e.g. index in array of body)
  * @param iTransform
  * The 2D transform to be applied to the body.
  * @param iOrientation
  * The orientation of the body.
  * @param iActive
  * The active state of the body; default is TRUE (active).
  * @return
  * Whether the body was successfully added; failure may indicate that the body was previously added.
  */
  virtual CATBoolean AddBody( CATBody                 * iBody1D,
                              CATLONG32                 iCallerBodyID,
                              CATMathTransformation2D * iTransform, 
                              CATOrientation            iOrientation,
                              CATBoolean                iActive = TRUE ) = 0;

  /**
  * Adds multiple bodies to be considered by the CATClash2D computation.
  * Instances of a body can share a body pointer but must be given a distinct ID and transform.
  * @param iNumberOfClashEntities
  * The number of bodies to be added.
  * @param iBodies1D
  * Array of 1D bodies to be added.
  * @param iCallerBodyIDs
  * Caller assigned array of integer tags to identity the body instance (e.g. index in array of body)
  * @param iTransforms
  * Array of corresponding 2D transforms to be applied to the bodies.
  * @param iOrientations
  * Array of corresponding orientations of the bodies.
  * @param iActives
  * Array of corresponding active states of the bodies.
  * @return
  * Whether the bodies was successfully added; failure may indicate that a body was previously added.
  */
  virtual CATBoolean AddBodies( CATLONG32                  iNumberOfClashEntities,
                                CATBody                 ** iBodies1D,
                                CATLONG32                * iCallerBodyIDs,
                                CATMathTransformation2D ** iTransforms, 
                                CATOrientation           * iOrientation, 
                                CATBoolean               * iActive ) = 0;

  //-----------------------------------------------------------------------
  //- Modification methods
  //-----------------------------------------------------------------------

  /**
  * Activates the input body so that it is considered by the CATClash2D computation.
  * @param iBody1D_ID
  * The ID of the body (instance) to be activated.
  * @return
  * Whether the body was successfully activated.
  */
  virtual CATBoolean ActivateBody( CATLONG32 iBody1D_ID ) = 0;

  /**
  * Deactivates the input body so that it is NOT considered by the CATClash2D computation.
  * @param iBody1D_ID
  * The ID of the body (instance) to be deactivated.
  * @return
  * Whether the body was successfully deactivated.
  */
  virtual CATBoolean DeActivateBody( CATLONG32 iBody1D_ID ) = 0;
  
  /**
  * Update the transform of an input body.
  * @param iBody1D
  * The ID of the body instance to be transformed.
  * @param iTransform
  * The 2D transform to be applied.
  * @param iTransformMode
  * The method to apply the new transform: 
  *   CATClash2D_TransformReplace      - replace the current transform with the new one
  *   CATClash2D_TransformConcatenate  - concatenate the current transform with the new one.
  * @return
  * Whether the transform was successfully applied.
  */
  /** @nodoc @nocgmitf */
  virtual CATBoolean UpdateTransform( CATLONG32                 iBody1D_ID, 
                                      CATMathTransformation2D * iTransform, 
                                      CATClash2DTransformMode   iTransformMode ) = 0;

  //-----------------------------------------------------------------------
  //- Results methods
  //-----------------------------------------------------------------------

  /**
  * Gets the resulting clash classification taking all body-body clashes into account.
  * @return
  * The clash classification.
  */
  /** @nodoc @nocgmitf */
  virtual CATClash2DClassification GetClashClassification() const = 0;
  
  /**
  * Gets the resulting clash classification of a pair of bodies taking all regions into account.
  * @param iBody1D_ID1
  * The ID of the first body instance.
  * @param iBody1D_ID2
  * The ID of the second body instance.
  * @return
  * The clash classification.
  */
  /** @nodoc @nocgmitf */
  virtual CATClash2DClassification GetClashClassification( CATLONG32 iBody1D_ID1,
                                                           CATLONG32 iBody1D_ID2  ) const = 0;

  //
  // Clash Regions
  //

  /**
  * Gets the number of clash regions.
  * @return
  * The number of clash regions.
  */
  virtual CATLONG32 GetNumberRegions() const = 0;

  /**
  * Initializes the results iterator.
  */
  virtual void BeginRegions() = 0;

  /**
  * Increments the results iterator to the next clash region.
  * @return
  * TRUE if there is a next region, FALSE if the end of the result regions is reached.
  */
  virtual CATBoolean NextRegion() = 0;

  /**
  * Gets the next clash result region.
  * @param oClashRegion
  * The clash result region. Caller takes responsibility for deletion.
  */
  virtual CATBoolean GetRegion( CATClash2DClashRegion *& oClashRegion ) const = 0;

  //
  // Clash Point-Regions
  //

  /**
  * Gets the number of clash points.
  * @return
  * The number of clash regions.
  */
  virtual CATLONG32 GetNumberPoints() const = 0;

  /**
  * Initializes the results iterator.
  */
  virtual void BeginPoints() = 0;

  /**
  * Increments the results iterator to the next clash point.
  * @return
  * TRUE if there is a next region, FALSE if the end of the result regions is reached.
  */
  virtual CATBoolean NextPoint() = 0;

  /**
  * Gets the next clash result point.
  * @param oBody1
  * The first body.
  * @param oCallerBodyID1
  * The user ID of the first body.
  * @param oEdge1
  * The first edge of the clash
  * @param oParam1
  * The parameter of the first edge-curve
  * @param oBody2
  * The second body.
  * @param oCallerBodyID2
  * The user ID of the second body.
  * @param oEdge2
  * The second edge of the clash
  * @param oParam2
  * The parameter of the second edge-curve
  * @param oClashPoint
  * The 2D clash point
  * @param oClashDirection
  * The 2D clash normal
  */
  virtual CATBoolean GetPoint( CATBody            *& oBody1,                               
                               CATLONG32           & oCallerBodyID1,
                               CATEdge            *& oEdge1, 
                               CATCrvParam         & oParam1, 
                               CATBody            *& oBody2,
                               CATLONG32           & oCallerBodyID2,
                               CATEdge            *& oEdge2, 
                               CATCrvParam         & oParam2,
                               CATMathPoint2D      & oClashPoint,
                               CATMathDirection2D  & oClashDirection ) const = 0;

  /**
  * Gets the next clash result point.
  * @param oPoint
  * The clash result point.
  */
  virtual CATBoolean GetPoint( CATMathPoint2D & oPoint ) const = 0;

  /**
  * Gets all of the clash result points.
  * @param oPoint
  * The clash result point.
  */
  virtual CATBoolean GetPoints( CATLISTV(CATMathPoint2D) & oPointList ) const = 0;

  //
  // Containment Data
  //

  /**
  * Gets the data that indicates the containing body of each active body.
  * This method should only be used when there are at least two active bodies, and there are no clashes between them.
  * All pairs of active bodies are considered, including those that have been unset using the function UnsetClashBodyPairs().
  * For example, if there are four active bodies (B1, B2, B3, and B4), with B1 containing B2, B2 containing B3, and B4 being separate.
  * In this case, B1 and B4 would be classified as outer loops, with the containing bodies of B2 and B3 being B1 and B2 respectively.
  * @param oContainmentData
  * Each element of the list contains one of the following:-
  *   the identifier of the body that directly contains it, in the form of the caller assigned integer tag to identity the body instance (for
  *      the functions AddBody() and AddBodies());
  *   -1, which indicates that the body is an outer loop;
  *   -2, which indicates that the body is inactive.
  * For the above example, if the identifiers of B1, B2, B3, and B4 were 1, 2, 3, and 4 respectively, the contents of oContainmentData would be
  *   {-1, 1, 2, -1}.
  * Note that, although both B1 and B2 contain B3, the body that directly contains B3 is B2.
  * The list oContainmentData is emptied when this method is invoked. 
  * @return
  * TRUE if the containment data has been successfully obtained, in which case the data is returned in oContainmentData.
  * FALSE if the containment data has not been obtained, with the reason being one of the following:-
  *   there are fewer than two active bodies,
  *   there is at least one clash between the active bodies,
  *   an internal error has occurred.
  */
  virtual CATBoolean GetContainmentData( CATListOfInt & oContainmentData ) const = 0;

  //-----------------------------------------------------------------------
  //- Deprecated methods
  //-----------------------------------------------------------------------
  /**
  * @deprecated R419
  * Use GetRegionComputationOption.
  * Gets the maximum penetration depth.
  * Returns the maximum penetration depth.
  * @return
  * The maximum penetration depth.
  */
  /** @nodoc @nocgmitf */
  virtual double GetMaximumPenetrationDepth() const = 0;

  /**
  * @deprecated R419
  * Use SetRegionComputationOption with CATClashRegionPenetrationOption maxdepth information set.
  * Sets the maximum penetration depth. 
  * Operator may terminate early when the maximum penetration depth (must be greater than resolution) is exceeded.
  * To unset, call with a value less than resolution.
  * @param iMaxPenetrationDepth
  * The maximum penetration depth. 
  * @return
  * Whether a valid maximum depth is set.
  */
  /** @nodoc @nocgmitf */
  virtual CATBoolean SetMaximumPenetrationDepth( double iMaxPenDep ) = 0;

  //-----------------------------------------------------------------------
  //- Undocumented methods
  //-----------------------------------------------------------------------

  /**  
  *  @nodoc
  *    Setting a prefix for the replay mechanism
  */    
  /** @nodoc @nocgmitf */
  virtual void SetReplayPrefix( const char * iPrefix ) = 0;
};

ExportedByClash2D CATClash2D * CreateCATClash2D(CATGeoFactory * iUserFactory, CATSoftwareConfiguration * iConfig, double iClashTol);
#endif
