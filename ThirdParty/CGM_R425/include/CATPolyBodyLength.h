// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyLength.h
// 
//===================================================================
// January 2009  Creation: TL1
//===================================================================
#ifndef CATPolyBodyLength_H
#define CATPolyBodyLength_H

#include "PolyBodyMeasures.h"
#include "CATErrorDef.h"

//#include "CATMathVector.h"
//#include "CATMathPoint.h"
//#include "CATMath.h"
//#include "CATPolyBody.h"
//#include "CATPolyEdge.h"
//#include "CATIPolySurface.h"
//#include "CATIPolyMesh.h"

class CATPolyBody;
class CATPolyEdge;
class CATMathPoint;


/**
* Class providing a CATPolyEdge (set) length Operator
*
* <br><b>Role</b>: Provide a CATPolyEdge length Operator
* <p>
* Can be applied on a whole PolyBody
* @example
*  CATPolyBodyLength oper;
*  oper.ComputeEdgesLength(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByPolyBodyMeasures CATPolyBodyLength
{
public:

	CATPolyBodyLength (){}
	~CATPolyBodyLength(){}

public:

  /** 
  * Compute edges length of CATPolyBody.
  *
  * <br><b>Role</b>: Compute edges length of CATPolyBody.
  * The method takes into account all its PolyEdges
  * @param iPolyBody [in]
  *   The polyBody containing edges to measure
  * @param oPolyEdgesLength [out]
  *   the length result
  * @param oStartPoint oEndPoint  oMiddlePoint[out]
  *   start, end and middle point of edge
  * @return
  *   <code>S_OK</code> : always.
  *
  */
  HRESULT ComputeEdgesLength (const  CATPolyBody &iPolyBody, 
					                    double &oPolyEdgesLength,
                              CATMathPoint& oStartPoint, 
                              CATMathPoint& oEndPoint,
                              CATMathPoint& oMiddlePoint) const;

  /** 
  * Compute edges length and edges center of gravity for input CATPolyBody.
  *
  * <br><b>Role</b>: Compute edges length and edges center of gravity for input CATPolyBody.
  * The method takes into account all its PolyEdges
  * @param iPolyBody [in]
  *   The polyBody containing edges to measure
  * @param oPolyEdgesLength [out]
  *   the length result
  * @param oStartPoint oEndPoint  oMiddlePoint[out]
  *   start, end and middle point of edge
  * @param oCenterOfGravity [out]
  *   center of gravity of the edges
  * @return
  *   <code>S_OK</code> : always.
  *
  */
  HRESULT ComputeEdgesLength (const  CATPolyBody &iPolyBody, 
					                    double &oPolyEdgesLength,
                              CATMathPoint& oStartPoint, 
                              CATMathPoint& oEndPoint,
                              CATMathPoint& oMiddlePoint,
                              CATMathPoint& oCenterOfGravity) const;

  /** 
  * Compute length and center of gravity of a CATPolyEdge 
  *
  * <br><b>Role</b>: Compute length and center of gravity of a CATPolyEdge 
  *
  * @param iPolyEdge [in]
  *   The Edge to measure
  * @param oPolyEdgeLength [out]
  *   The length result
  * @param oStartPoint oEndPoint  oMiddlePoint[out]
  *   start, end and middle point of edge
  * @param oCenterOfGravity [out]
  *   center of gravity of the edge
  * @return
  *   <code>S_OK</code> : always;
  *
  */
  HRESULT ComputeEdgeLength (const  CATPolyEdge &iPolyEdge, 
						                 double &oPolyEdgeLength, 
                             CATMathPoint& oStartPoint, 
                             CATMathPoint& oEndPoint,
                             CATMathPoint& oMiddlePoint,
                             CATMathPoint& oCenterOfGravity) const;

};

#endif // !CATPolyBodyLength_H
