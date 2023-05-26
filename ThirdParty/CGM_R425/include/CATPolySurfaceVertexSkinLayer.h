// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySurfaceVertexSkinLayer.h
// Header definition of CATPolySurfaceVertexSkinLayer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//October 2010 Creation: pmg
//===================================================================
#ifndef CATPolySurfaceVertexSkinLayer_H
#define CATPolySurfaceVertexSkinLayer_H

#include "CATPolyDeformOperators.h"

#include "CATPolyRefCounted.h"
#include "CATMapOfIntToPtr.h"
#include "IUnknown.h"	// Get Unix HRESULT definition
#include "CATMathStream.h"
#include "CATBoolean.h"


/**
* Class representing skin weights layer
* <br><b>Role</b>: Manage the skin weights'data
* @href CATIPolySurface, CATPolyDQSkinningOper
*/

class ExportedByCATPolyDeformOperators CATPolySurfaceVertexSkinLayer : public CATPolyRefCounted
{

public:

/**
*  IsAnimatedByJoint
* <br><b>Role</b>: Get the animation Mode.
* @return
* FALSE (default) : The weights are associated with the Bones
* TRUE  : The weights are associated with the Joints (or proxy-Bone)
*/
  CATBoolean IsAnimatedByJoint() const;

  
/**
*
* <br><b>Role</b>: Get (proxy)bone influence for one vertex
* @param iVertex
* Index of the Vertex.
* @param oNbOfImpactingBones
* Number of (proxy)bones wich impact the vertex
* @param oNumBones
* Array of impacting bones's indices (First indice is 0)
* @param oWeights
* Array of impacting bones's weights
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT GetWeights(const int iVertex, 
                     short& oNbOfImpactingBones, 
                     const short*& oNumBones, 
                     const float*& oWeights) const;


/**
*
* <br><b>Role</b>: Set (proxy)bone influence for one vertex
* @param iVertex
* Index of the Vertex.
* @param iNbOfImpactingBones
* Number of (proxy)bones wich impact the vertex
* @param iNumBones
* Array of impacting bones's indices (First indice is 0)
* @param iWeights
* Array of impacting bones's weights
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
  HRESULT SetWeights(const int iVertex, 
                     const short iNbOfImpactingBones, 
                     const short* iNumBones, 
                     const float* iWeights);

 
/**
*   SetModeAnimation
* <br><b>Role</b>: Define the animation mode 
* @param isAnimatedByJoint
* FALSE (default) : The weights are associated with the Bones
* TRUE  : The weights are associated with the Joints (or proxy-Bone)
* 
* 
*/
void SetModeAnimation(CATBoolean isAnimatedByJoint = FALSE);

/**
*  Stream Vertex Skin Layer
* <br><b>Role</b>: Write to stream the Vertex Skin Layer's data
* @param iStream
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
  HRESULT Stream(CATMathStream& iStream)const;
 
  
/**
*  Unstream Vertex Skin Layer
* <br><b>Role</b>: Read from stream the Vertex Skin Layer's data
* @param iStream
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT Unstream(CATMathStream& iStream);

  
/**
* Create a PolySurfaceVertexSkinLayer
* <br><b>Role</b>: 
* @return
* A CATPolySurfaceVertexSkinLayer object.
*/
static CATPolySurfaceVertexSkinLayer * CreatePolySurfaceVertexSkinLayer();

protected:
  virtual ~CATPolySurfaceVertexSkinLayer ();
  CATPolySurfaceVertexSkinLayer ();

private:

  void Clean();
#ifdef CATDebug_Trace
  void Dump();
#endif

  CATMapOfIntToPtr _MapPositionVertexToSkinInfo;
  short _NbBones;
  CATBoolean _IsAnimatedByJoint;

};


#endif
