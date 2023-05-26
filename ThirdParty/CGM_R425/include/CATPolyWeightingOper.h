// COPYRIGHT Dassault Systemes 2010, all rights reserved
//===================================================================
//
// CATPolyWeightingOperator.h
//
//===================================================================
//
// Usage notes: Edition of mesh with Laplacian Diffusion.
//
//===================================================================
//  May 2010 Creation: pmg
//===================================================================
#ifndef CATPolyWeightingOper_h
#define CATPolyWeightingOper_h

#include "CATPolyCanonicOperators.h"

#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "IUnknown.h"	// Get Unix HRESULT definition

class CATIPolyMesh;
class CATMathVector;
class CATMathPoint;


class ExportedByCATPolyCanonicOperators CATPolyWeightingOper 
{
public :


  virtual ~CATPolyWeightingOper ();
  
 
 
/**
*  Set A Bone
* <br><b>Role</b>: Set the definition of one bone 
* @param iNumBones
*  The Bone's num between 0 and NbBones-1
* @param iBeginJoint
*   The position of the bone begining
* @param iEndJoint
*   The position of the bone ending
*   If this position is equal to iBeginJoint, no weights are associted to this bone.
* @param iAttachedTriangle
*   The list of triangles indexes attached to this Bone (can be empty)
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
* 
*/
 virtual HRESULT  SetBones(const int iNumBones, 
                            CATMathPoint& iBeginJoint,  
                            CATMathPoint& iEndJoint, 
                            CATListOfInt& iAttachedTriangle)=0;

  

/**
*
* <br><b>Role</b>: Get the number of bone
* @return
* The number of Bone in this
*/
virtual int GetNbBones() const=0;


/**
*
* <br><b>Role</b>: Perform the Weighting Operation
* @return 
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
  * 
*/
  virtual HRESULT Run ()=0;

 
/**
*
* <br><b>Role</b>: Get Weights information for one vertex
* @param iNumVertex
*  The Vertex 
* @param oNbOfImpactingBones
*  The number of bone wich impact this vertex
* @param oNumBones
*  The array of bone's num impacting  this vertex : will be delete by this
* @param oWeights
*  The array of bone's weights impacting  this vertex : will be delete by this
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT GetWeights(const int iNumVertex, 
                       short& oNbOfImpactingBones, 
                       const short*& oNumBones, 
                       const float*& oWeights) const=0;


protected :
  CATPolyWeightingOper();

};



/**
*
* <br><b>Role</b>: Create one instance of the Weighting operator
* @param iPolyMesh
* 
* @param iNbBones
* 
* @return
*   the Weighting operator
*/

ExportedByCATPolyCanonicOperators CATPolyWeightingOper * CATCreatePolyWeightingOper(CATIPolyMesh * iPolyMesh, const int iNbBones);

#endif




