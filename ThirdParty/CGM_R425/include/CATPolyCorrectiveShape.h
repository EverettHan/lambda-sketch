// COPYRIGHT Dassault Systemes 2011, all rights reserved
//===================================================================
//
// CATPolyCorrectiveShapeLinear.h
//
//===================================================================
//
// Usage notes: Corrective data for Skinning. 
//
//===================================================================
//  Aug 2011 Creation: pmg
//===================================================================
#ifndef CATPolyCorrectiveShape_h
#define CATPolyCorrectiveShape_h

#include "CATPolyDeformOperators.h"

#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATPolyRefCounted.h"
#include "IUnknown.h"	// Get Unix HRESULT definition


class CATIPolySurface;
class CATMathPoint;
class CATMathVector;
class CATMathStream;


class  ExportedByCATPolyDeformOperators CATPolyCorrectiveShape : public CATPolyRefCounted
{
public :


  virtual int Init(CATIPolySurface * ipolySurf)=0;

  virtual int ReplaceSurface(CATIPolySurface * iNewPolySurf)=0;

  
/**
*
* <br><b>Role</b>: 
* @param iNumCF
*  Index of correction coeficient form 1 to GetNbCoeffs()
* @param iCoef
*  Corection coeficient.
* @return
* 
*/
virtual int SetCoeff(const int iNumCF,  const double iCoef)=0;

  virtual int ResetCoeffs()=0;

  virtual int GetNbCoeffs()const=0;

  
/**
*
* <br><b>Role</b>: 
* @param iNumCF
* Index of correction coeficient form 1 to GetNbCoeffs()
* @return
* Corection coeficient.
*/
virtual double GetCoeffs(const int iNumCF)const=0;

  virtual const CATMathPoint * GetVertices()const=0;

  virtual const CATMathVector * GetNormales()const=0;

  /**
*  Stream Polyhedral corrective shape 
* <br><b>Role</b>: Write to stream the Polyhedral corrective shape 's data
* @param iStream
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
  virtual HRESULT Stream(CATMathStream& iStream)const=0;

  
/**
*
* <br><b>Role</b>: 
* @param iMeshName
* 
* @return
* 
*/
virtual const char* GetMeshName() const=0;

  
/**
*
* <br><b>Role</b>: Get the skin type associated with this 
* 
* @return
* Skin type (0) DQ (1) SSD
*/
virtual short GetTypeSkinning() const=0;

protected :
  CATPolyCorrectiveShape();
  virtual ~CATPolyCorrectiveShape ();
};

 
/**
* 
* <br><b>Role</b>: Create a Linear CATPolyCorrectiveShape
* @param iNbCoefficients
* 
* @param iIndexesTab
* 
* @param iTabOfCSPoint
* 
* @param iTabOfCSNormal=NULL
* 
* @param iTypeofSkinning
*   An optional kind of skinning (useful for consistence check with skinning operator)
* @param iMeshName
*   An optional name for the associated mesh (useful for multi-mesh management)
* @return
* 
*/
ExportedByCATPolyDeformOperators CATPolyCorrectiveShape * 
   CATCreateCATPolyCorrectiveShapeLinear (const int iNbCoefficients, 
                                          const CATListOfInt* iIndexesTab, 
                                          const CATListOfDouble* iTabOfCSPoint,
                                          const CATListOfDouble* iTabOfCSNormal=NULL,
                                          const short iTypeofSkinning = 0,
                                          const char* iMeshName = NULL);

 
/**
*
* <br><b>Role</b>: Unstream a CATPolyCorrectiveShape
* @param ioReadStream
* The stream where the CATPolyCorrectiveShape is stored.
* @return
*  CATPolyCorrectiveShape instance
*/
ExportedByCATPolyDeformOperators CATPolyCorrectiveShape * 
   CATUnstreamPolyCorrectiveShape(CATMathStream& ioReadStream);

#endif




