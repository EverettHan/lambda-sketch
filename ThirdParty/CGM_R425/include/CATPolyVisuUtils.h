// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuUtils.h
//
//===================================================================
//
// April 2009  Creation: NDO
// April 2013  Modification JXO: GetSag
// January 2016 Modification JXO: 2D Reps and GPs
// December 2019 Modification JXO: externs for debug
//===================================================================
#ifndef CATPolyVisuUtils_H
#define CATPolyVisuUtils_H

#include "PolyVizUtils.h"
#include "CATPolyMutex.h"
#include "CATBoolean.h"
#include "CATMutex.h"
#include "CATErrorDef.h"

#include "CATIAV5Level.h"


class CATMathTransformation;
class CATMathTransformation2D;
class CAT4x4Matrix;
class CAT3x3Matrix;
class CATRep;
class CAT3DRep;
class CAT3DBagRep;
class CATGraphicPrimitive;
class CATVizPrimitive;
class Vis3DNodeGroupRep;
class CATGraphicMaterial;
class CATRepPath;
class CATGraphicAttributeSet;
class CATPolyBody;
class CATIPolyMesh;
class CATUnicodeString;
class CATIDataStreamer;

class ExportedByPolyVizUtils PolyRepType
{
public:
  ~PolyRepType();
public:
  const char * GetType() const;
  static PolyRepType New(const char *);
protected:
  PolyRepType(const char*);
private:
  const char* _type;
};


/**
 * Various services used to parse and identify CATRep.
 */
class ExportedByPolyVizUtils CATPolyVisuUtils
{

public:

  /**
   * Fills a CATMathTransformation from a CAT4x4Matrix.
   */
  static void Fill (const CAT4x4Matrix& iMatrix, CATMathTransformation& oTransfo);

  /**
   * Fills a CAT4x4Matrix from a CATMathTransformation.
   */
  static void Fill (const CATMathTransformation& iTransfo, CAT4x4Matrix& oMatrix);

  /**
   * Fills a CATMathTransformation2D from a CAT3x3Matrix.
   */
  static void Fill (const CAT3x3Matrix& iMatrix, CATMathTransformation2D& oTransfo);

  /**
   * Fills a CAT4x4Matrix from a CAT3x3Matrix.
   */
  static void Fill (const CAT3x3Matrix& iMatrix, CAT4x4Matrix& oMatrix);

public:

  /**
   * Returns <tt>TRUE</tt> if the rep is a CAT3DRep.
   */
  inline static CATBoolean Is3DRep (const CATRep& iRep);

  /**
   * Returns <tt>TRUE</tt> if the rep is a CAT3DBagRep.
   */
  inline static CATBoolean Is3DBagRep (const CATRep& iRep);

  /**
   * Returns <tt>TRUE</tt> if the rep is a Vis3DNodeGroupRep.
   */
  inline static CATBoolean IsVis3DNodeGroupRep (const CATRep& iRep);

  /**
   * Returns <tt>TRUE</tt> if the rep is a CAT2DRep.
   */
  inline static CATBoolean Is2DRep (const CATRep& iRep);

  /**
   * Returns <tt>TRUE</tt> if the rep is a CAT2DBagRep.
   */
  inline static CATBoolean Is2DBagRep (const CATRep& iRep);

  // Return TRUE if iVizFace is a UV Face and FALSE otherwise.
  static CATBoolean IsVizUVFace (const CATVizPrimitive& iVizFace);

  // Return TRUE if iVizEdge is a UV Edge and FALSE otherwise.
  static CATBoolean IsVizUVEdge (const CATVizPrimitive& iVizEdge);

  // Return TRUE if iVizLine is a UV Line and FALSE otherwise.
  static CATBoolean IsVizUVLine (const CATVizPrimitive& iVizLine);

	// Return TRUE if iVizLine is a Line and FALSE otherwise.
  static CATBoolean IsVizLine (const CATVizPrimitive& iVizLine);

	// Return TRUE if iVizEdge is a Edge and FALSE otherwise.
  static CATBoolean IsVizEdge (const CATVizPrimitive& iVizEdge);

  // Return S_OK if iRep contains only UVReps,
  // Return S_FALSE if iRep contains no UVReps,
  // Return E_FAIL if iRep is hybrid
  static HRESULT IsUVRep (const CATRep& iRep, double * sag = 0);

  // Return TRUE if iRep is infinite, FALSE otherwise.
  static CATBoolean IsInfinite (const CATRep& iRep);

  // return TRUE iif iRep is of type MonoWireRep, VizMonoWireRep, 3DPointRep or 3DLineRep
  static CATBoolean IsWire (const CATRep& iRep);

  /**
   * Returns <tt>TRUE</tt> if the graphic primitive is 2D.
   */
  static CATBoolean Is2DGP (const CATGraphicPrimitive& iGP);

  /**
   * Returns <tt>TRUE</tt> if the input rep is a kind of iType.
   * It is thread safe but with object-modeler limitations.
   * You can safely call this method in parallel in several threads but
   * nothing else should be done with the object-modeler in the mean time.
   */
  static CATBoolean PolyIsAKindOf (const CATRep & iRep, const PolyRepType & iType);

  /**
   * Returns <tt>TRUE</tt> if the input graphic primitive is a kind of iType.
   * It is thread safe but with object-modeler limitations.
   * You can safely call this method in parallel in several threads but
   * nothing else should be done with the object-modeler in the mean time.
   */
  static CATBoolean PolyIsAKindOf (const CATGraphicPrimitive & iGP, const PolyRepType & iType);
  /**
   * Returns <tt>TRUE</tt> if the input viz primitive is a kind of iType.
   * It is thread safe but with object-modeler limitations.
   * You can safely call this method in parallel in several threads but
   * nothing else should be done with the object-modeler in the mean time.
   */
  static CATBoolean PolyIsAKindOf (const CATVizPrimitive & iVP, const PolyRepType & iType);


  // Use one of these types for the method PolyIsAKindOf ().
  static const PolyRepType Type3DRep;
  static const PolyRepType Type3DBagRep;
  static const PolyRepType TypeSurfacicRep;
  static const PolyRepType TypeVizVertexBufferRep;
  static const PolyRepType Type3DCylinderRep;
  static const PolyRepType Type3DCurvedPipeRep;
  static const PolyRepType Type3DCurveRep;
  static const PolyRepType Type3DCustomRep;
  static const PolyRepType TypeMonoWireRep;
  static const PolyRepType TypeVizMonoWireRep;
  static const PolyRepType Type3DPointRep;
  static const PolyRepType Type3DLineRep;
  static const PolyRepType Type3DPlanRep;
  static const PolyRepType Type3DAxisSystemRep;
  static const PolyRepType TypeVizUV3DRep;
  static const PolyRepType Type3DGeomRep;
  static const PolyRepType TypeVisPrimitiveGroupRep;
  static const PolyRepType TypeVis3DNodeGroupRep;
  static const PolyRepType Type3DLodRep;
  static const PolyRepType Type3DBagRepWithToleranceScale;
  static const PolyRepType Type3DFilterBagRepWithToleranceScale;
  static const PolyRepType Type3DPointCloudRep;
  static const PolyRepType Type3DCanonicalRep;

  // 2D
  static const PolyRepType Type2DTo3DRep;
  static const PolyRepType Type2DRep;
  static const PolyRepType Type2DBagRep;
  static const PolyRepType Type2DArcCircleRep;
  static const PolyRepType Type2DArcEllipseRep;
  static const PolyRepType Type2DCustomRep;
  static const PolyRepType Type2DLineRep;
  static const PolyRepType Type2DPointRep;
  static const PolyRepType Type2DPolygonRep;

  // GPs:
  static const PolyRepType Type3DLineGPWithCrvParams;
  static const PolyRepType Type3DFaceGP;
  static const PolyRepType Type3DPlanarFaceGP;
  static const PolyRepType Type3DCylinderGP;
  static const PolyRepType Type3DCurvedPipeGP;
  static const PolyRepType Type3DEdgeGP;
  static const PolyRepType Type3DLineGP;
  static const PolyRepType Type3DMarkerGP;
  static const PolyRepType Type3DFixedPlanGP;
  static const PolyRepType Type3DEdgeGPWithCrvParams;
  static const PolyRepType Type3DBoundingGP;

  // VPs
  static const PolyRepType TypeVizPrimitive;

  // 2D GPs
  static const PolyRepType Type2DLineGP;
  static const PolyRepType Type2DMarkerGP;
  static const PolyRepType Type2DPolygonGP;
  static const PolyRepType Type2DArcCircleGP;
  static const PolyRepType Type2DArcEllipseGP;
  static const PolyRepType Type2DQuadStripGP;
  static const PolyRepType Type2DRectangleGP;

public:

  /**
   * Get the dimension of the domain defined by a rep.
   *
   * @param iRep CATRep to test.
   * @param oDimension The dimension of the domain defined by the rep. Values can be:
   *                   0 the rep defines a point.
   *                   1 the rep defines a wire (contiguous curve).
   *                   2 the rep defines a skin (contiguous surface, a shell).
   *                   3 the rep defines a solid (contiguous volume, a lump).

   * @return S_OK if the dimension could be successfully fetched, S_FALSE
   *         if the result is unknown, E_FAIL if something terribly wrong happened.
   */
  static HRESULT GetRepDimension (const CATRep & iRep, int & oDimension);

  /**
   * Get the sag of a CAT3DRep, if any.
   * @param iRep CATRep to test.
   * @param oSag The sag
   * @return S_OK if the sag could be successfully fetched, S_FALSE otherwise.
   */
  static HRESULT GetSag(const CATRep & iRep, double & oSag);

  /**
   * Accumulates graphic attributes
   */
  static HRESULT GetGraphicAttributeSetFromRepPath(const CATRepPath & iRepPath, CATGraphicAttributeSet & oGA, const CATGraphicMaterial ** iMaterial = 0);

  /**
   * Accumulates graphic attributes
   */
  static void AccumulateGraphicAttributeSet(CATRep & iRep, CATGraphicAttributeSet & oGA,
                                            int & iInherit, int & iMaterialInherit, int & a,
                                            const CATGraphicMaterial ** iMaterial = 0);
  /**
   * Returns the texture matrix, from the Vis3DNodeGroupRep or the first CATMaterialApplication.
   * This matrix has to be released by caller.
   */
  static CAT4x4Matrix* GetTextureMatrix (const CAT3DBagRep& iBagRep);

public:

  static Vis3DNodeGroupRep* NewVis3DNodeGroupRep ();

private:

  static CATPolySpinLockMutex _mut;

};


inline CATBoolean CATPolyVisuUtils::Is3DRep (const CATRep& iRep)
{
  return PolyIsAKindOf (iRep, Type3DRep);
}

inline CATBoolean CATPolyVisuUtils::Is3DBagRep (const CATRep& iRep)
{
  return PolyIsAKindOf (iRep, Type3DBagRep);
}

inline CATBoolean CATPolyVisuUtils::IsVis3DNodeGroupRep (const CATRep& iRep)
{
  return PolyIsAKindOf (iRep, TypeVis3DNodeGroupRep);
}

inline CATBoolean CATPolyVisuUtils::Is2DRep (const CATRep& iRep)
{
  return PolyIsAKindOf (iRep, Type2DRep);
}

inline CATBoolean CATPolyVisuUtils::Is2DBagRep (const CATRep& iRep)
{
  return PolyIsAKindOf (iRep, Type2DBagRep);
}


// We expose a few functions for dynamic loading of some debug libraries (CATech_Monitor)

// CATHLRBodyInput_Get
extern "C" ExportedByPolyVizUtils HRESULT CATPolyBodyToCGRForHLR (CATPolyBody & iBody, const CATUnicodeString & iPath);
extern "C" ExportedByPolyVizUtils int CATWriteCgrForHLR (CAT3DRep * iRep, char * CGRFile);
// CATechStreamManager
extern "C" ExportedByPolyVizUtils HRESULT GetRepStreamerForCATech(CATIDataStreamer *& oRepStreamer);
// CATPolyLaplacianEditImp
extern "C" ExportedByPolyVizUtils HRESULT CATPolyMeshToCGR(const CATUnicodeString& iFileName, const CATIPolyMesh& iMesh);

#endif
