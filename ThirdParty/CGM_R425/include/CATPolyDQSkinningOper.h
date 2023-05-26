// COPYRIGHT Dassault Systemes 2010, all rights reserved
//===================================================================
//
// CATPolyDQSkinning.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//  Apr 2010 Creation: pmg
//===================================================================
#ifndef CATPolyDQSkinning_h
#define CATPolyDQSkinning_h


#include "CATPolyDeformOperators.h"
#include "CATPolyBaseOper.h"
#include "CATBoolean.h"
#include "CATMathTransformation.h"

class CATIPolySurface;
class CATPolyCorrectiveShape;

/**
* Class representing skinning operator.
*
* <br><b>Role</b>: Skinning of mesh with Dual Quaternion Implementation.
* see CATPolySurfaceVertexSkinLayer for manage skin weights.
* <p>
* Do not use the @href CATPolyDQSkinning constructor to
* do such and such but instead CATCreatePolyDQSkinning
*
* @example
*  CATIPolySurface * polySurf = xxxx;
*  int NbBones=a, ii=0, NbVerticies = polySurf->GetNbVertices();
*  CATPolyDQSkinningOper * pOper = CATPolyDQSkinningOper * CATCreatePolyDQSkinningOper(polySurf, NbBones);
*  if (Oper) {
*
*  for (ii=0; ii<NbVerticies; ii++)
*    pOper->AddWeight(....);
*    for (int iframe=1; iframe <= NbFrame; iframe++) {
*      for (ii=0; ii<NbBones; ii++) 
*        pOper->SetTransfo(ii, GetTransfo(iframe, ii), FALSE );
*       pOper->Run();
*       Display(polySurf);
*    }
*  }
*
* @href CATIPolySurface, CATMathTransformation, CATPolySurfaceVertexSkinLayer 
*/
 class ExportedByCATPolyDeformOperators CATPolyDQSkinningOper : public  CATPolyBaseOper
{
public :
  virtual ~CATPolyDQSkinningOper();

  /** 
  * Weight's definition
  *
  * <br><b>Role</b>: Define the linear impact of transformation for one vertex.
  *
  * @param iNumVertex [in]
  *   The impacted vertex's number : between 0 and NbVerticies-1.
  * @param iNbOfImpactingBones [in]
  *   The number of transformation which impact the vertex.
  * @param iNumBones [in]
  *   The rank number transformations which impact the vertex.
  * @param iWeights [in]
  *   The Weights for each transformation
  * @param isCheck [in]
  *   Check if the inputs are corrects.
  *
  * @return
  *   0 : OK
  *   >0 : One error has ocuured.
  *
  */
  virtual int AddWeight(const int iNumVertex, const short iNbOfImpactingBones, const short* iNumBones, 
                const float* iWeights, const CATBoolean isCheck = TRUE)=0;

 
  /** 
  * Set a transformation
  *
  * <br><b>Role</b>: Define one transformation (rigid if poosible) for the skinning
  *
  * @param iNumBone [in]
  *   The index of the transformation, from 0 to NbBones-1;
  * @param iTransfo [in]
  *   The Transformation to apply : Rotation are waiting.
  * @param isCheck [in]
  *   Check than the transformation is rigid.
   * @param isCheck [in]
  *   Check if the inputs are corrects
  *
  * @return
  *   0 : OK
  *   >0 : One error has ocuured.
  *
  */
  virtual int SetTransfo(const int iNumBone,  const CATMathTransformation& iTransfo, const CATBoolean isCheck = TRUE)=0;

  
/**
*  Set an additional global transfo
* <br><b>Role</b>: Set an global transo (for the all the mesh) to compose with the local transfo
* @param iTransfo
*   The Transformation to apply : 
* @return
* *   0 : OK
  *   >0 : One error has ocuured.
*/
virtual int SetGlobalTransfo(const CATMathTransformation& iTransfo)=0;

/**
*
* <br><b>Role</b>: Replace the surface to skin
* @param iNewPolySurf
* the new surface to skin in Skinning (and if necessary in the Corrective Shape)
* @return
* *   0 : OK
  *   >0 : One error has ocuured.
*/
virtual int ReplaceSurface(CATIPolySurface * iNewPolySurf)=0;



/**
* SetInRefPose
* <br><b>Role</b>: Restore the initial mesh's position
* 
* @return
*   0 : OK
*   >0 : One error has ocuured.
*/
virtual int SetInRefPose()=0;

  /** 
  * Run
  *
  * <br><b>Role</b>: Perform the skininng operation.
  *
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *
  */
  virtual HRESULT Run ()=0;



/**
*  Get skin's Weights 
* <br><b>Role</b>: Retrieves the linear impact of transformation for one vertex.
* @param iNumVertex [in]
*   The impacted vertex's number : between 0 and NbVerticies-1.
* @param oNbOfImpactingBone [out]
*    The number of transformation which impact the vertex.
* @param oNumBones [out]
*   The rank number transformations which impact the vertex.
* @param oWeights [out]
*  The Weights for each transformation
* @return
*    0 : OK
*   >0 : One error has ocuured.
* 
*/
virtual int GetWeight(const int iNumVertex, short& oNbOfImpactingBone, 
                      const short*& oNumBones, 
                      const float*& oWeights)const=0;

 


virtual int GetTransfo(const int iNumBone, CATMathTransformation& oTransfo)const=0;


virtual int GetNbBones()const =0;

virtual int GetSkinType() const =0;

protected :

  CATPolyDQSkinningOper();

};

/** 
* Skinning Constructor.
*
* <br><b>Role</b>: Create one skinning operator.
*
* @param ipolySurf [in]
*   The Surface to deform
* @param iNbBones [in]
*   The number of Bones (== transformation) wich parametrize the skinning.
* @param isSubSkeletalDeformation [in]
*   The algorithm used
*   if TRUE the standard Sub Skeletal Deformation (SSD) is used.
*   else the Dual Quaternion skinning is used.
* @param iCSData [in]
*   The corrective shape information, useful to improve quality in case of great local rotation.
* @return
*   One skinning operator.
*
*/
ExportedByCATPolyDeformOperators CATPolyDQSkinningOper * CATCreatePolyDQSkinningOper(CATIPolySurface * ipolySurf, const int iNbBones, 
                                                                                     const CATBoolean isSubSkeletalDeformation = FALSE, 
                                                                                     CATPolyCorrectiveShape * iCSData=NULL);

#endif




