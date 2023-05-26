#ifndef CATICVMTexture_h
#define CATICVMTexture_h


#include "CATBaseUnknown.h"

#include "CATCVMGeoObjects.h"
#include "CATCVMTextureRef.h"

extern ExportedByCATCVMGeoObjects IID IID_CATICVMTexture;

#include "CATMathConstant.h"
#include "CATUnicodeString.h"
#include "CATMathTransformation.h"
#include "CATBoolean.h"

class ExportedByCATCVMGeoObjects CATICVMTexture : public CATBaseUnknown
{
public:
	CATDeclareInterface; 

public:
	virtual HRESULT SetTextureReference (CATCVMTextureRef * iRef) = 0;
	//-----------------------------------
	// 
	//-----------------------------------
	virtual HRESULT GetTextureAxis (double oCoord[12]) const = 0;
	virtual HRESULT SetTextureAxis (double iCoord[12], unsigned char iRefresh=1) = 0;

	//-----------------------------------
	//
	//-----------------------------------
	virtual HRESULT GetScale (double &oScale) const = 0;
	virtual HRESULT SetScale (double iScale, unsigned char iRefresh=1) = 0;

	virtual HRESULT GetRepeat (unsigned char &oU, unsigned char &oV) const = 0;
	virtual HRESULT SetRepeat (unsigned char iU, unsigned char iV, unsigned char iRefresh=1) = 0;

	virtual HRESULT GetOrientation (CATAngle &oOrientation) const = 0;
	virtual HRESULT SetOrientation (CATAngle iOrientation, unsigned char iRefresh=1) = 0;

	virtual HRESULT GetTexturePath (CATUnicodeString &oPath) const = 0;
	virtual HRESULT SetTexturePath (CATUnicodeString &iPath, unsigned char iRefresh=1) = 0;
  virtual HRESULT SetVisuDataForPath (CATUnicodeString &iPath, void * iVisuData) = 0;
  virtual HRESULT GetVisuDataFromPath (CATUnicodeString &iPath, void *& oVisuData) = 0;

  virtual HRESULT GetUseTexture (unsigned char &oUse) const = 0;
  virtual HRESULT SetUseTexture (unsigned char iUse, unsigned char iRefresh=1) = 0;

  virtual HRESULT UpdateTransfo (const CATMathTransformation& iTransfo, unsigned char iRefresh=1) =0;
  virtual CATMathTransformation GetAbsTransfo() const = 0;


  //------------------------------------------------------------------------------
  // Integration UV Mapping (equivalent to Transfo2 TransfoUV)
  //------------------------------------------------------------------------------
   virtual HRESULT    GetTransfoUV(CATMathTransformation2D & oTransfo2D) const= 0; 

};
#endif

