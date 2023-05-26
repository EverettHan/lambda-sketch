// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMVisualFilterViewpoint.h
// Define the CATIPLMVisualFilterViewpoint interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Oct 2012  Creation: Code generated by the CAA wizard  dti
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMVisualFilterViewpoint_H
#define CATIPLMVisualFilterViewpoint_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#include "CATPLMID.h"
#include "CATMathPointf.h"
#include "CATMathDirection.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMVisualFilterViewpoint;
#else
extern "C" const IID IID_CATIPLMVisualFilterViewpoint ;
#endif

class CATPLMPosition;

/**
* Interface to retrieve a Viewpoint query
*/
class ExportedByCATPLMServicesItf CATIPLMVisualFilterViewpoint: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** 
  * Get and set the Density.
  * The Density goes from 0 to 9.
  * 9 will cause the best quality, but it wont cause a perfect quality !
  */
  virtual HRESULT GetDensity ( int &oDensity ) = 0;
  virtual HRESULT SetDensity ( const int iDensity ) = 0;

  /** 
  * Get and set all the needed attributes of the Viewpoint.
  */
  virtual HRESULT GetMathematicalViewpointAttributes ( CATMathPointf &oOrigin, CATMathDirection &oSightDirection, CATMathDirection &oUpDirection, float &oFocusDistance, float &oNearPlane, float &oFarPlane, float &oAngle ) = 0;

  /** 
  * Get and set all the needed attributes of the Support.
  */
  virtual HRESULT GetMathematicalSupportAttributes ( float &oWidth, float &oHeight,	float &oMMInSupportUnit, float &oRatioWH ) = 0;

  // don't lose precision
  virtual HRESULT GetViewpointAttributes (	CATPLMPosition &oOrigin, CATPLMPosition &oSightDirection, CATPLMPosition &oUpDirection, double &oFocusDistance, double &oNearPlane, double &oFarPlane, double &oAngle )=0;
  virtual HRESULT SetViewpointAttributes (	const CATPLMPosition &iOrigin, const CATPLMPosition &iSightDirection, const CATPLMPosition &iUpDirection, const double iFocusDistance, const double iNearPlane, const double iFarPlane, const double iAngle )=0;

  virtual HRESULT GetSupportAttributes (	double &oWidth, double &oHeight, double &oMMInSupportUnit, double &oRatioWH ) =0;
  virtual HRESULT SetSupportAttributes (	const double iWidth,	const double iHeight, const double iMMInSupportUnit, const double iRatioWH ) =0;
}; 

#endif