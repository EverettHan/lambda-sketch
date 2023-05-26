#ifndef CATCVMTextureSkewData_h
#define CATCVMTextureSkewData_h

#include "CATCVMGeoObjects.h"

/*
#include "CATCVMAttribute.h"
#include "CATCVMGeoObjects.h"
#include "CATCVMSysStream.h"

#include "CATUnicodeString.h"
*/
#include "CATMathTransformation.h"
#include "CATMathTransformation2D.h"
#include "CATMathPoint2D.h"
#include "CATCGMNewArray.h"


//class CATMathTransformation2D;
class CATCVMImage;
class CATCVMSysStream;
class CATCVMContainer;

class ExportedByCATCVMGeoObjects CATCVMTextureSkewData
{
public:
  CATCVMTextureSkewData ();
  virtual ~CATCVMTextureSkewData();

  CATCGMNewClassArrayDeclare; // Pool allocation

public:
  double _Ratio;
  CATCVMImage * _SkewedImage;
  CATMathPoint2D _SourceSkewPoints[4];
  CATMathPoint2D _DestinationSkewPoints[4];
  CATMathTransformation2D _SkewImageTransfo;   // ajout PKC
  CATMath3x3Matrix _SkewHomographicTransfoMatrix;

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream, CATCVMContainer * iContainer); 

  CATCVMTextureSkewData * Clone();


};
#endif

