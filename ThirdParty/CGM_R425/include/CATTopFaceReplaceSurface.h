#ifndef CATTopFaceReplaceSurface_H_
#define CATTopFaceReplaceSurface_H_

// COPYRIGHT DASSAULT SYSTEMES  2009

/**
 * Tags CAA :  a voir... 
 */ 

//
#include "FacRepSur.h"
#include "CATTopOperator.h"
#include "CATExtCGMReplay.h"
#include "CATTopDefine.h"

//
#ifndef NULL
#define NULL 0
#endif

//
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;

class CATEdgeCurve;
class CATMathPoint;
class CATSurface;
class CATMathTransformation;
class CATGMLiveShapeRunOptions;

#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATTopFacReplSurfDef.h"

/**
* Class defining the operator which replaces the surfaces of faces in a body with the given surfaces.
*<br>
* The <tt>CATTopFaceReplaceSurface</tt> operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input bodies are not modified. A new resulting body 
* is created, possibly sharing data with the input body.
*<ul>
* <li>A <tt>CATTopFaceReplaceSurface</tt> operator is created with the <tt>CATCreateFaceReplaceSurfaceOperator</tt> global function:
* It must be directly deleted after use with the usual C++ <tt>delete</tt> operator. It is not streamable. 
*<li>Options can be set with the <tt>SetXxx</tt> methods, before
* calling the operator's <tt>Run</tt> method. In particular, an optimized mode
* allows you to do some local operations in union mode.
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometry factory. 
*</ul>
*/
class ExportedByFacRepSur CATTopFaceReplaceSurface : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopFaceReplaceSurface);
  
 public:

/**
 * Virtual constructor of a <tt>CATTopFaceReplaceSurface</tt> operator.<br>
 * Do not call this constructor, instead use the <tt>CATCreateFaceReplaceSurfaceOperator</tt> global function
 * to create a CATTopFaceReplaceSurface operator.
 */
  CATTopFaceReplaceSurface (CATGeoFactory*     iContainer,
                            CATTopData*        iData,
                            CATExtTopOperator* iExtensible = NULL);

/**
 * Destructor.
 */
  virtual ~CATTopFaceReplaceSurface();

/**
 * Specifies the face in the input body whose surface should be replaced in the result body.
 * @param iOldFace
 * The pointer of an existing face in the input body.
 * @param iNewSurf
 * The pointer to the replacing surface for iOldFace.
 * If iNewSurf is a canonical surface, it may be replaced by an equivalent
 * surface (for closure management purpose).
 * @param iWorkingDomain
 * The limits of iNewSurf that are useful for the operation
 * These limits have to correctly match with its use in the result body, but
 * the operator may perform an extrapolation on the surface if necessary.
 * @param iOrientation
 * The orientation of the face in the new Body with respect to the new surface. 
 */
  virtual void ReplaceWith( CATFace*       iOldFace, 
                            CATSurface*    iNewSurf,
                            CATSurLimits&  iWorkingDomain,
                            CATOrientation iOrientation );
  
/**
 * Specifies the edge in the input body whose edge curve should be replaced in the result body.
 * @param iOldEdge
 * The pointer of an existing edge in the input body.
 * @param iNewEdgeCurve
 * The pointer to the replacing <tt>CATEdgeCurve</tt> for iOldEdge. This new curve will
 * include only one PCurve on surfaces associated to the faces boundary.
 * iOldEdge
 * @param iWorkingDomain
 * The limits of iNewEdgeCurve that are useful for the operation.
 * These limits have to correctly match with its use in the result body, but
 * the operator may perform an extrapolation on the curve if necessary
 * @param iOrientation
 * The orientation of the edge in the new Body with respect to the new edge curve. 
 */
  virtual void ReplaceWith(	CATEdge*       iOldEdge, 
                            CATEdgeCurve*  iNewEdgeCurve,
                            CATCrvLimits&  iWorkingDomain,
                          	CATOrientation iOrientation);

/**
 * Specifies the edge in the input body whose edge curve should be replaced in the result body.
 * This method works for isotopological configurations (when there is a bijection between the cells
 * of input and result body). It will have no effect otherwise.
 * @param iOldEdge
 * The pointer of an existing edge in the input body. This edge must border a face with a new
 * surface specfied by the ReplaceWith method. An error is thrown if not.
 * @param iCurve
 * The pointer to the <tt>CATCurve</tt> to laydown in order to compute the new EdgeCurve
 * for iOldEdge. 
 * @param iWorkingDomain
 * The limits of iCurve that are useful for the operation.
 * These limits have to correctly match with its use in the result body, but
 * the operator may perform an extrapolation on the curve if necessary 
 * This method is not compatible with the TransformWith, SetSameSurfacesParametrization
 * and ReplaceWith(iNewEdgeCurve) methods.
 */
  virtual void SetLaydownEdge( CATEdge*       iOldEdge, 
                               CATCurve*      iNewCurve,
                               CATCrvLimits&  iWorkingDomain);


/**
 * @nodoc
 * Method to call in order to compute the new EdgeCurve of the specified edge
 * with a canonical tangent intersection.
 * @param iOldEdge
 * The pointer of an existing edge in the input body.
 * iOldEdge must have two adjacent faces : Face1 and Face2 (Throw otherwise).
 * The result surfaces of Face1 and Face2 must be canonical (Plane/Cylinder/Cone/Sphere/Torus)
 * in the result body (Throw otherwise).
 * The result surfaces of Face1 and Face2 must be tangent (Throw otherwise). 
 * If there is an ambiguity in the result of the intersection (for example if the two
 * surfaces are confused, or if there are two 3D solution lines), the method
 * "ReplaceWith( CATVertex*     iOldVertex, CATMathPoint&  iTargetPoint) has to be
 * called for both vertices of iOldEdge (Throw otherwise).
 * There must be a new surface specified for at least one a these faces (Throw otherwise).
 */
  virtual void SetCanonicalTangentEdge(CATEdge* iOldEdge);

/**
 * @nodoc
 * Method to call in order to compute the new EdgeCurve of the specified edge
 * with report of its current parametrization on the new surface(s).
 * @param iOldEdge
 * The pointer of an existing edge in the input body.
 * There must be a new surface specified for at least one of the adjacent faces 
 * (Throw otherwise).
 * The parametrization of the new surface(s) must be the same as the old ones.
 * As a consequence, the new PCurve computed with report of the old PCurve parametrization  
 * must be included in the WorkDomain given for the new surface.
 */
  virtual void SetSameSurfacesParametrization(CATEdge* iOldEdge);

/**
 * Specifies a new target point for a given vertex in the input body.
 * This method is optionnal, but is required for some special cases where all adjacent
 * new EdgeCurves are tangent, and so the new point location can't be computed without
 * external information.
 * @param iOldVertex
 * The pointer of an existing vertex in the input body.
 * @param iNewTargetPoint
 * The location of the new vertex in the result body. This MathPoint should
 * be close enough (less than Tolerance) to all replacing surfaces of the 
 * faces bordering iOldVertex.
 */
  virtual void ReplaceWith( CATVertex*     iOldVertex, 
                            CATMathPoint&  iTargetPoint);

/**
 * Method to call in order to specify the tansformation to apply to a list of faces
 * in the input body. 
 * An error is thrown if the same <tt>CATFace</tt> is given with several Transformations.
 * An error is thrown if the following other methods are called with this one :
 *  - All ReplaceWith methods 
 *  - SetCanonicalTangentEdge
 *  - SetSameSurfacesParametrization
 * @param iListFaces
 * The list of faces to be tranformed.
 * @param iTransfo
 * The 3D trandformation to apply to theses faces.
 */
  virtual void TransformWith( ListPOfCATFace&        iListFaces, 
                              CATMathTransformation& iTransfo);

/**
 * Method to call in order to specify the tansformation to apply to a list of edges in the input body.  
 * @param iListEdges
 * The list of edges to be tranformed.
 * @param iTransfo
 * The 3D trandformation to apply to theses edges.
 */
  virtual void TransformWith( ListPOfCATEdge&        iListEdges, 
                              CATMathTransformation& iTransfo);

/**
 * @nodoc
 * Method to call in order to simplify the specified faces (in the
 * ReplaceWith method) and their neighbors in the inuput body.
 * Please note that simplifications between faces lying on surface’s
 * with closure may not be performed.
 */
  virtual void SimplifyReplacedFaces ();

 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Live shape
  */
  virtual void SetRunOptions(CATGMLiveShapeRunOptions* iRunOptions,
                             CATBoolean                iDeleteByDestructor=FALSE); // second parameter : use only for CGMReplay

 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Switch Geometry
  * Throw an error if SetSameSurfacesParametrization is not called 
  */
  virtual void SetGapCreationTolerance(double iTol) ;

 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Switch Geometry  
  */
  virtual void SetConfiguration(CATFacReplSurfConfigType iType) ;

/**
 * @nodoc 
 */
  virtual void LaydownAllSmoothBorderEdges(CATBoolean iAllReplacingSurfacesAreConfusedWithOriginalSurfaces = FALSE,
                                           CATBoolean iReplacingSurfacesMayBeRecreated                     = FALSE);

/**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Internal use only
  */
  virtual void ReplaceByGeoRep_InternalUse();

  
 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Switch Geometry  
  * To call after Run, Throw otherwise
  * Throw an error if SetSameSurfacesParametrization is not called 
  * (this restiction is done because result body has to be isotopological 
  *  in order to get a correct result)
  */
  virtual void GetModifiedEdge(CATEdge*   iOldEdge,
                               CATEdge*&  oNewEdge);

 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Switch Geometry  
  * Use only with Configuration "CATFacReplSurfIsoTopological", Throw otherwise
  * @param iLevel
  *   CATFacReplSurfNone         Default mode, no diagnosis
  *   CATFacReplSurfFirstError   Throw after first error, problematic cell is stored
  *   CATFacReplSurfSameFamily   Throw after first error family, the related problematic cells are stored
  */
  virtual void SetErrorDiagnosisLevel(CATFacReplSurfDiagLevel iLevel) ;
 
 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Switch Geometry  
  * Use only with Configuration "CATFacReplSurfIsoTopological", Throw otherwise
  * To call after Run, Throw otherwise
  * Throw an error if SetErrorDiagnosisLevel is not called   
  * @param oPbCells 
  * The list of problematic cells encountered during operator's Run
  * The list is empty if Run is successful
  * The list contains only one element with Level CATFacReplSurfFirstError
  */
  virtual void GetUncomputedCells(ListPOfCATCell& oPbCells);


  // -----------------------------------------------------------------------------------
  // CGM Internal Use
  // -----------------------------------------------------------------------------------

private:

/** 
 * @nodoc 
 */
  virtual int RunOperator();

/** 
 * @nodoc 
 */
  virtual CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

/** 
 * @nodoc 
 */
  virtual const CATString * GetOperatorId();

/** 
 * @nodoc 
 */
  virtual const CATString * GetDefaultOperatorId();

/** 
 * @nodoc 
 */
  virtual void RequireDefinitionOfInputAndOutputObjects();
  
/** 
 * @nodoc 
 */
  virtual void WriteInput(CATCGMStream &Str);
  
/** 
 * @nodoc 
 */
  virtual void Dump( CATCGMOutput& os );


};


/**
 * Creates a <tt>CATTopFaceReplaceSurface</tt> operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iBody
 * The pointer to the body where the surface’s replacement will be performed.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByFacRepSur CATTopFaceReplaceSurface* CATCreateFaceReplaceSurfaceOperator 
  ( CATGeoFactory*     iFactory,                                                                                     
    CATTopData*        iData,                                                                              
    CATBody*           iBody);



#endif

