// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuPlanarSectionObserver.h
//
//===================================================================
// October 2012  Creation: NDO
//===================================================================
#ifndef CATPolyVisuPlanarSectionObserver_H
#define CATPolyVisuPlanarSectionObserver_H

#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATRep;
class CATBVHTree;
class CATBVHTreeSet;
class CATBVHNodeConst;
class CATMathPlane;
class CATMathTransformation;
class CATPolyVisuSectionResult;
class CATPolyBody;
class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyPolygonBar3DBoundingGPLayer;
class CATPolyPolygonBarVizPrimitiveLayer;


/**
 * Observer class to CATPolyVisuPlanarSectionOper.
 */
class CATPolyVisuPlanarSectionObserver
{

public:

  virtual ~CATPolyVisuPlanarSectionObserver () {}

public:

  virtual void Initialize (const CATBVHTree& iBVHTree, const CATMathTransformation* iPositionMatrix) = 0;

  virtual void Initialize (const CATBVHTreeSet& iBVHTreeSet) = 0;

public:

  virtual void BeforeRun (const CATMathPlane& iPlane) = 0;

  virtual void AfterRun (const CATPolyVisuSectionResult* iResult) = 0;

  virtual void AfterFlush () = 0;

  virtual void BeginProcessPolyBody (const CATBVHNodeConst& iNode,
                                     const CATPolyBody* iPolyBody, const CATMathTransformation* iPBPosition,
                                     const CATRep* iRep) = 0;

  virtual void EndProcessPolyBody (HRESULT iHR, const CATPolyPolygon2D* iPolygon, 
                                   const CATPolyPolygonVertex3DPositionLayer* iVertexPositionLayer,
                                   const CATPolyPolygonBar3DBoundingGPLayer* iBarGPLayer,
                                   const CATPolyPolygonBarVizPrimitiveLayer* iBarVizPrimitiveLayer) = 0;

};

#endif
