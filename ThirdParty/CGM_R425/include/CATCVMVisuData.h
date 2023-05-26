#ifndef CATCVMVisuData_h
#define CATCVMVisuData_h

// Class to define a shared texture 
// This shared texture will be use as reference of texture attributes

#include "CATCVMAttrRef.h"
#include "CATCVMContainer.h"
#include "CATCVMGeoObjects.h"
#include "CATMathConstant.h"
#include "CATUnicodeString.h"
#include "CATMathTransformation.h"
#include "CATCVMSysStream.h"
#include "CATCVMImage.h"
#include "CATCGMNewArray.h"

class ExportedByCATCVMGeoObjects CATCVMVisuData
{


public:
	CATCVMVisuData ();
	CATCGMNewClassArrayDeclare; // Pool allocation
	virtual ~CATCVMVisuData();

public:

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream); 

  // Comparaison
  CATBoolean IsEqualTo(CATCVMVisuData * iVisuDataRef);

//	CATCVMVisuData(CATCVMVisuData&);
//	void operator =(CATCVMVisuData&);

public:

  float         _Size;
	float         _DiffuseCoef;
	float         _DiffuseColorR;
	float         _DiffuseColorV;
	float         _DiffuseColorB;
	float         _SpecularCoef;
	float         _RoughnessCoef;
	float         _SpecularColorR;
	float         _SpecularColorV;
	float         _SpecularColorB;
	float         _TransparenceCoef;
	float         _ReflectionCoef;
	float         _FresnelCoef;
	float         _BumpCoef;
  float         _ColorSaturation;
	float         _ReflectionFactor;
	float         _ReflectionConstant;
};
#endif

