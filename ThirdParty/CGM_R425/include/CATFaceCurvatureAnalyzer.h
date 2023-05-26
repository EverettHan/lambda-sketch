/* -*-C++-*- */

#ifndef CATFaceCurvatureAnalyzer_H
#define CATFaceCurvatureAnalyzer_H 

// COPYRIGHT DASSAULT SYSTEMES 2021

//=============================================================================
//
// CATFaceCurvatureAnalyzer : operator evaluating curvatures on a CATFace
//                            returning mathematical values
//                            supporting both exact and polyhedral geometries
//
// The main motivation of this operator consists in hiding to the caller
// the geometrical type (CATSurface / CATGeoPolySurface ...) of the CATFace
//
//=============================================================================
// Usage notes:
//
// This operator can be used to retrieve the curvatures from any point of a CATFace
// This operator is a multi-Run operator, in order to compute curvatures from several points
// The caller has to call Run() as many times he has defined a point on face
//
// All the returned curvature values are signed
// The gaussian curvature, as product of minimal and maximal curvatures, 
// is negative in case of change of convexity between the 2 principal directions, else positive.
// The other curvatures (Min, Max, Mean, Border, Inward, SpecDir) are 
// - null if the surface is locally planar (infinite radius)
// - positive if the local normal points to the center of the local circle (concave configuration),
// - negative if the center of the local circle is opposite to the local normal (convex configuration)
//
//=============================================================================
// November  2021  Creation                                                DPS
//=============================================================================

#include "GMPolyGeoUtil.h"  // ExportedBy
#include "CATCGMOperator.h" // derivation

#include "CATTopDefine.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATGMFaceCurvatureEvalExt;
class CATSoftwareConfiguration;
class CATFace;
class CATEdge;
class CATVertex;
class CATPoint;
class CATCrvParam;
class CATSurParam;
class CATCGMODTScaleManager;


class ExportedByGMPolyGeoUtil CATFaceCurvatureAnalyzer : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATFaceCurvatureAnalyzer);

  public :

  //-----------------------------------------------------------------------
  //- Object management 
  //-----------------------------------------------------------------------

  // Constructor : do not use, Use CATCreateFaceCurvatureAnalyzer instead
  CATFaceCurvatureAnalyzer(CATGeoFactory & iFactory, CATGMFaceCurvatureEvalExt & iGeoExtension);

  // Destructor
  ~CATFaceCurvatureAnalyzer();


  //-----------------------------------------------------------------------
  //- Public Settings, to call before Run()
  //-----------------------------------------------------------------------
  // Different ways to define the point on face on which the operator will evaluate local curvatures
  // This point has to verify a semantic link with the input CATFace
  // -----------------------------------------------------------------------------------------------

  // The input CATSurParam has to reference the geometry of the CATFace
  void SetSurParam(const CATSurParam & iSurParam);
  
  // The input point has to reference the geometry of the CATFace
  void SetPoint(CATPoint * iPointOnFace);
  
  // The input vertex has to belong to the CATFace boundary, or to be lying on the CATFace
  void SetVertex(CATVertex * iVertexOnFace);
  
  // The input edge has to belong to the CATFace boundary, or to be lying on the CATFace
  void SetEdgeParam(CATEdge * iEdgeOnFace, const CATCrvParam & iCrvParam);
  
  // The input edge has to belong to the CATFace boundary, or to be lying on the CATFace
  // The input point has to reference the geometry of the CATEdge
  void SetEdgePoint(CATEdge * iEdgeOnFace, CATPoint * iPointOnEdge);


  // Sets a specific direction in addition of a specific point
  // ---------------------------------------------------------
  // Each time a new point is specified, this specific direction will be reset to null
  void SetSpecDirection(const CATMathDirection & iSpecDir);


  // Enables/Disables the curvature computation along the boundary from edges or vertices
  // The default mode is disabled
  // It's mandatory to enable this mode before Run() in order to get the Border Curvature after Run()
  // ---------------------------------------------------------
  void SetBorderDirectionMode(CATBoolean iEnableBorderMode);

  // Enables/Disables the curvature computation inward the face from bounded edges or vertices
  // The default mode is disabled
  // It's mandatory to enable this mode before Run() in order to get the Inward Curvature after Run()
  // ---------------------------------------------------------
  void SetInwardDirectionMode(CATBoolean iEnableInwardMode);


  //-----------------------------------------------------------------------
  //- Public Get Methods, to call after Run()
  //-----------------------------------------------------------------------

  // Returns the 2 principal signed curvatures (min and max)
  // The optional vectors are the directions which are tangent to the local circular arcs
  // These 2 vectors are othorgonal to the local normal, but not necessarily orthogonal to each other
  HRESULT GetPrincipalCurvatures(double & oMinCurvature, double & oMaxCurvature, 
                                 CATMathDirection * opMinDirection=NULL, CATMathDirection * opMaxDirection=NULL);

  // Returns the signed mean curvature
  HRESULT GetMeanCurvature(double & oMeanCurvature);

  // Returns the signed product of the 2 principal curvatures
  // This product is called "Gaussian curvature"
  HRESULT GetGaussianCurvature(double & oGaussianCurvature);


  // Additional curvatures from a specified edge or vertex (if any) belonging to the face boundary
  // ---------------------------------------------------------------------------------------------

  // The border curvature is computed from an edge (input edge or edge incident to an input vertex), 
  // following the positive/negative loop orientation according to iOrientationVsLoop
  HRESULT GetBorderCurvature(CATOrientation & iOrientationVsLoop, double & oBorderCurvature, CATMathDirection * opBorderDirection=NULL);
  

  // The inward curvature is computed from an edge or a vertex, following the vector inward the face
  HRESULT GetInwardCurvature(double & oInwardCurvature, CATMathDirection * opInwardDirection=NULL);


  // Additional curvature in a specific direction defined calling SetSpecDirection before Run()
  // ------------------------------------------------------------------------------------------

  // Returns the signed curvature observed locally in the specified direction
  HRESULT GetDirectionalCurvature(double & oLocalCurvature);


  //-----------------------------------------------------------------------
  //- Other Get Methods, to call after Run()
  //-----------------------------------------------------------------------

  // Returns the 3D point from which the computation has been done
  // Returns E_FAIL if the current point has no semantic link with the input CATFace
  HRESULT GetMathPoint(CATMathPoint & oMathPt);

  // Returns the normal direction computed on the current point,
  // taking into account the contextual orientation associated to the input CATFace
  // Returns E_FAIL if the current point has no semantic link with the input CATFace
  HRESULT GetNormal(CATMathDirection & oMathDir);


protected:

  //------------------------------------------------------
  // Run
  //------------------------------------------------------
  virtual int                                RunOperator();


  // ------------------
  // CGMReplay Methods
  // ------------------

public :
  /** @nodoc * @nocgmitf */
  virtual /* CATCGMOperator method */ const CATString * GetOperatorId();

  /** @nodoc * @nocgmitf
  * For CGMReplay only */
  void SetCGMODTScaleManager(CATCGMODTScaleManager * iScaleManager);


private :

  CATGMFaceCurvatureEvalExt & _FaceCurvatureEvalExtension;
};


/**
 * Creates the CATFaceCurvatureAnalyzer from a face
 * @param iFactory
 * The factory containing all the input geometric objects
 * @param iSoftwareConfiguration
 * The pointer to the software configuration for the Versioning management
 * @param iFaceToEvaluate
 * The face to evaluate the local curvatures from any point
 * <dd>Use the <tt>Run</tt> method to computes the operation.</dl>
 * @param iFaceOrientation
 * The contextual orientation (positive by default) to considerate the face
 * CATOrientationPositive and CATOrientationNegative are the 2 only expected values
 * In case of negative value, the face will be seen as inverted during the computation :
 * the sign of all the curvatures will be inverted, the normal direction will be inverted,
 * the minimal (resp. maximal) curvature value will be changed into the maximal (resp. minimal) value etc...
 * @return [out, IUnknown#Release]
 * The pointer to the created operator.
 */
ExportedByGMPolyGeoUtil CATFaceCurvatureAnalyzer * CATCreateFaceCurvatureAnalyzer(CATGeoFactory            * iFactory,
                                                                                  CATSoftwareConfiguration * iConfig,
                                                                                  CATFace                  * iFaceToEvaluate,
                                                                                  CATOrientation             iFaceOrientation = CATOrientationPositive);
#endif
