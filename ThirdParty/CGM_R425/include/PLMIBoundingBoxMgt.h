#ifndef PLMIBoundingBoxMgt_H
#define PLMIBoundingBoxMgt_H

// ================================
// COPYRIGHT Dassault Systèmes 2017
//
// --------------------------------
// * Full review 31:01:2017 @RSR7
// --------------------------------
// @level : Protected
// @usage : U3
// --------------------------------
// Usage notes :
//    Defines an interface to access the RepRef's BoundingBox points.
// Supported LateTypes :
//    - PccMemVPMRepReference
//    - PccMemRFLVPMLogical3DRepReference
// ================================


// include(s)
#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"

// extern(s)
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerBaseInterfaces IID IID_PLMIBoundingBoxMgt;
#else
extern "C" const IID IID_PLMIBoundingBoxMgt;
#endif

class ExportedByCATPLMModelerBaseInterfaces PLMIBoundingBoxMgt 
  : public CATBaseUnknown
{

  CATDeclareInterface;

  public:

    /**
     *  Retrieves the 2 points defining the BoundingBox
     *  
     *  @param ioPoint1XYZ
     *    The container of the first point to retrieve. Returns an array of size 3.
     *  @param ioPoint2XYZ
     *    The container of the first point to retrieve. Returns an array of size 3.
     *
     *  @return 
     *      <ul>
	   *        <li>S_OK if the operation has been successfull.</li>
	   *        <li>E_FAIL if an unexpected error occured.</li>
     *      </ul>
     *  @example
     *      double * point1 = NULL;
     *      double * point2 = NULL;
     *      PLMIBoundingBoxMgt_var spBBMgt = spRepRef;
     *      HRESULT HR = spBBMgt->GetAbstract3DRepRefBBPoints( &point1, &point2 );
     */
    virtual HRESULT GetAbstract3DRepRefBBPoints(double **ioPoint1XYZ, double **ioPoint2XYZ) = 0;

     /**
     *  Retrieves the 2 points defining the BoundingBox
     *  
     *  @param ioPoint1XYZ
     *    The container of the first point to retrieve. Returns an array of size 3.
     *  @param ioPoint2XYZ
     *    The container of the first point to retrieve. Returns an array of size 3.
     *
     *  @return 
     *      <ul>
	   *        <li>S_OK if the operation has been successfull.</li>
	   *        <li>E_FAIL if an unexpected error occured.</li>
     *      </ul>
     *  @example
     *      double point1[3] = {1., 2., 3.};
     *      double point2[3] = {6., 7., 9.};
     *      PLMIBoundingBoxMgt_var spBBMgt = spRepRef;
     *      HRESULT HR = spBBMgt->SetAbstract3DRepRefBBPoints( point1, point2 );
     */
    virtual HRESULT SetAbstract3DRepRefBBPoints(const double *iPoint1XYZ, const double *iPoint2XYZ) = 0;


};

CATDeclareHandler ( PLMIBoundingBoxMgt, CATBaseUnknown );

#endif
