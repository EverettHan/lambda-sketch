// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : LAP
//
// DESCRIPTION  : BRep Modeling Operator for SolidWork.
//                
//=============================================================================
// Creation LAP January 2009
//=============================================================================

#ifndef CATGMTransformFaceOpe_H
#define CATGMTransformFaceOpe_H

#include "AdvTrimOpe.h"
#include "CATTopOperator.h"

#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "CATSurLimits.h"
#include "CATTopDefine.h"
#include "CATTopFacReplSurfDef.h"

class CATGMTransformFaceImpl;
class CATBody;
class CATPersistentBody;
class CATString;
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;
class CATEdgeCurve;
class CATMathPoint;
class CATSurface;
class CATMathTransformation;
class CATGMLiveShapeRunOptions;
class CATPersistentCellInfra;

// @nocgmitf (do not create phase 2 interface)
class ExportedByAdvTrimOpe CATGMTransformFaceOpe : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATGMTransformFaceOpe);

  public:

  	//-------------------------------------------------
    // Constructor: use the methode CATCreateRemoveFace
    //-------------------------------------------------
    CATGMTransformFaceOpe(CATGeoFactory         * iFactory,
                          CATTopData            * iTopData,
                CATGMTransformFaceImpl          * iImpl);
  	
    //------------------
    // Destructor
    //------------------
	  virtual ~CATGMTransformFaceOpe();

/**
 * Method to call in order to specify the surface to be changed in the input body
 * for a specific Face, and the replacing surface which will appear in the result body
 * for this Face only.
 * @param iOldFace
 * The pointer of an existing face in the input body.
 * @param iNewSurf
 * The pointer to the replacing surface for iOldFace.
 * @param iWorkingDomain
 * The limits of iNewSurf that are useful for the operation
 * These limits have to correctly match with its use in the result body, but
 * the operator may perform an extrapolation on the surface if necessary
 * Please refer to the below pictures for more explanations
 * @param iOrientation
 * The orientation of the face in the new Body towards the new surface
 * (see picture below)
 */
  virtual void ReplaceWith( CATFace        & iOldFace, 
                            CATSurface     & iNewSurf,
                            CATSurLimits   & iWorkingDomain,
                            CATOrientation   iOrientation );
  
/**
 * Method to call in order to specify a new Curve for a given edge.
 * @param iOldEdge
 * The pointer of an existing edge in the input body.
 * @param iNewEdgeCurve
 * The pointer to the replacing EdgeCurve for iOldEdge. This new curve will
 * include only one PCurve on surfaces associated to the faces bounding
 * iOldEdge
 * @param iWorkingDomain
 * The limits of iNewEdgeCurve that are useful for the operation.
 * These limits have to correctly match with its use in the result body, but
 * the operator may perform an extrapolation on the curve if necessary
 */
  virtual void ReplaceWith(	CATEdge        & iOldEdge, 
                            CATEdgeCurve   & iNewEdgeCurve,
                            CATCrvLimits   & iWorkingDomain,
                        	  CATOrientation   iOrientation);
/**
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
  virtual void SetCanonicalTangentEdge(CATEdge & iOldEdge);

  /**
 * Method to call in order to compute the new EdgeCurve of the specified edge
 * with report of its current parametrization on the new surface(s).
 * @param iOldEdge
 * The pointer of an existing edge in the input body.
 * There must be a new surface specified for at least one of the adjacent faces 
 * (Throw otherwise).
 * The parametrization of the new surface(s) must fit the parametrization of
 * the old EdgeCurve : the new PCurve computed with report of the old PCurve 
 * parametrization must be included in the WorkDomain given for the new surface.
 */
  virtual void SetIsoParametricCurve(CATEdge & iOldEdge);

/**
 * Method to call in order to specify a new target point for a given vertex.
 * This method is optionnal, but is required for some special cases (see picture below)
 * @param iOldVertex
 * The pointer of an existing vertex in the input body.
 * @param iNewTargetPoint
 * The location of the new vertex in the result body. This MathPoint should
 * be close enough (less than Tolerance) of all the replacing surfaces of the 
 * faces bordering iOldVertex
 */
  virtual void ReplaceWith( CATVertex    & iOldVertex, 
                            CATMathPoint & iTargetPoint);

/**
 * Method  with CATMathTransformation
 */
  virtual void TransformWith(const ListPOfCATFace        & iFacesToTransform,
                             const CATMathTransformation & iMathTransformation);

/**
 * Method  with CATMathTransformation
 */
  virtual void TransformWith(const ListPOfCATEdge        & iEdgesToTransform,
                             const CATMathTransformation & iMathTransformation);

/**
 * Method  with CATMathTransformation
 */
  virtual void TransformWith(const ListPOfCATVertex      & iVerticesToTransform,
                             const CATMathTransformation & iMathTransformation);

/**
 * Method to call in order to simplify faces.
 * This method is optionnal. The operator simplifies the face by default.
 * @param iSimplifyFace
 * To not simplifyFace set the value to FALSE.
 */
  virtual void SetSimplifyFaceMode(CATBoolean iSimplifyFace);

/**
 * Method to call in order to adjust the tolerance of internal operator (FlexibleBRep).
 * @param iTol
 */
  virtual void SetGapCreationTolerance(double iTol);

/**
  * Use only for CATIA Switch Geometry  
  */
  virtual void SetConfiguration(CATFacReplSurfConfigType iType);


/**
  * Method to set the Power Closed mode
  * @param iFaceToCloseList
  */
  virtual void SetPowerClosedMode(const ListPOfCATFace & iFaceToCloseList, CATPersistentBody & iInputPersistentBody2);


/**
 * Method to call for result from internal operator (FlexibleBRep).
 */
  virtual void GetModifiedEdge(CATEdge*   iOldEdge,
                               CATEdge*&  oNewEdge);

 /**
  * @nodoc
  * @nocgmitf (do not create phase 2 interface)
  * Use only for CATIA Live shape
  */
  virtual void SetRunOptions(CATGMLiveShapeRunOptions* iRunOptions);


    // Run
    int RunOperator();

    // ------------------------------------------------------------------------
    // GetTopologicalRebuildLevel
    //   0 : no result
    //   1 : isotopological rebuild level (Flexible)
    //   2 : non-isotopological rebuild level (classical V5: TrimSew, Thickness, Sew)
    //   3 : non-isotopological rebuild level (XTrim)
    // ------------------------------------------------------------------------
    CATLONG32 GetTopologicalRebuildLevel() const;

    //------------------
    // CGMReplay methods
    //------------------
    static const CATString *GetDefaultOperatorId();
    const CATString * GetOperatorId();
    CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
    void WriteInput(CATCGMStream  & Str);
    void ReadInput(CATCGMStream  & ioStr, int VersionOfStream, short iNumReplayVersion = 1);
    void Dump( CATCGMOutput& os ) ;
    void DumpOutput(CATCGMOutput &os);
    void RequireDefinitionOfInputAndOutputObjects();

  protected:

    CATGMTransformFaceImpl * GetTFImpl() const;

};

// ----------------------
// CATCreateXTrim
// ----------------------
ExportedByAdvTrimOpe CATGMTransformFaceOpe * CATCreateGMTransformFaceOpe(CATGeoFactory & iFactory,
                                                      CATTopData    & iTopData,
                                                      CATBody       & iInputBody); 

ExportedByAdvTrimOpe CATGMTransformFaceOpe * CATCreateGMTransformFaceOpeWithPowerClosed (CATGeoFactory             & iFactory,
                                                                                         CATTopData                  & iTopData,
                                                                                         CATPersistentBody       & iInputPersistentBody1,
                                                                                         CATPersistentBody       & iInputPersistentBody2,
                                                                                         const ListPOfCATFace  & iFacesToTransform,
                                                                                         CATPersistentCellInfra      & iPersistentInfra);

ExportedByAdvTrimOpe CATGMTransformFaceOpe * CATCreateGMTransformFaceOpeWithPowerClosed (CATGeoFactory           * iFactory,
                                                                                         CATTopData              * iTopData,
                                                                                         CATBody                 * iInputBody,
                                                                                         CATBody                 * iSupportBody,
                                                                                         const ListPOfCATFace    & iFacesToTransform);


#endif
