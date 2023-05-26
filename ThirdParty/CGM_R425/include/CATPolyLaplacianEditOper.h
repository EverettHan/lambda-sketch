// COPYRIGHT Dassault Systemes 2010, all rights reserved
//===================================================================
//
// CATPolyLaplacianEditOperator.h
//
//===================================================================
//
// Usage notes: Edition of mesh with Laplacian Diffusion.
//
//===================================================================
//  May 2010 Creation: pmg
//===================================================================
#ifndef CATPolyLaplacianEditOper_h
#define CATPolyLaplacianEditOper_h

#include "CATPolyCanonicOperators.h"

#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATMathVector.h"
#include "IUnknown.h"	// Get Unix HRESULT definition

class CATIPolyMesh;
class CATMathSparseMxNMatrix;
class CATMathVector;


class ExportedByCATPolyCanonicOperators CATPolyLaplacianEditOper 
{
public :


  virtual ~CATPolyLaplacianEditOper ();
  
  /**
  *
  * <br><b>Role</b>: Set a position constraint for one vertex, this methode is multi-run.
  *  It is possible to set different vector values for the same vertex along the time
  * @param iIdxVertex
  *   The Vertex 's index to move
  * @param Displacement
  *   The displacement vector
  * @return
  *  0 : OK
  *  >0 : Error
  */
  virtual HRESULT  SetConstraint(const int iIdxVertex, const CATMathVector& Displacement)=0;

  virtual void SetBiLaplacianRatio (const double iBiLaplacianRatio)=0;
    
  /**
  *
  * <br><b>Role</b>: Get the number of constraints
  * @return
  *   The number of constraints
  */
  virtual int GetNbConstraints() const=0;


  /**
  *
  * <br><b>Role</b>: Perform the deformation
  * @return
  * 
*/
  virtual HRESULT Run ()=0;

  virtual HRESULT  SelectArea(const CATMathPoint &iPoint, const int iVertexIdx, const double iDistMax, CATListOfInt& oSelectedIndexes) const=0;

  virtual HRESULT  ComputePointMeshMinDistance(const CATMathPoint &iPoint, CATMathPoint & oPoint, int& oNearestVertexIdx) const=0;

  static HRESULT  ComputeLaplacian(CATIPolyMesh* iMesh, const CATListOfInt& iListOfConstraintsIdx, 
                              CATMathSparseMxNMatrix *& oLaplacianMatrix, CATListOfInt& oIndecisToIndexesTable);

  
/**
* @pnodoc
*  internal usage.
*/
static int ReturnErrorNullPointer(const int iErrorCode,const char * iFile = 0, const int iLine = 0);

  static int GetVertices(CATIPolyMesh * iMesh, CATListOfInt& overtices);

protected :
  CATPolyLaplacianEditOper();

};


/**
*
* <br><b>Role</b>: 
* @param iPolyMeshToDeform
*    The Mesh to deform
* @return
*    The Deformation's operator.
*/
ExportedByCATPolyCanonicOperators CATPolyLaplacianEditOper * CATCreateLaplacianEditOper(CATIPolyMesh * iPolyMeshToDeform);

#endif




