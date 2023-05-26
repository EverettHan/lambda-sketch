#ifndef CATCVMColor_h
#define CATCVMColor_h

#include "CATCVMAttribute.h"
#include "CATCVMColorRef.h"
#include "CATCVMSysObjects.h"
#include "CATCVMSysStream.h"
#include "CATCGMNewArray.h"

class ExportedByCATCVMSysObjects CATCVMColor : public CATCVMAttribute
{
public:
  CATCVMColor(CATCVMObject * iOwner, CATCVMColorRef * iColorRef = NULL);
  CATCGMNewClassArrayDeclare;
  virtual ~CATCVMColor();

  // Get/Set divers
	HRESULT GetRVBAlpha (double &oR, double &oG, double &oB, double &oAlpha);
	HRESULT SetRVBAlpha (double iR, double iG, double iB, double iAlpha);

  // Copy
  CATCVMAttribute * CopyCVMAttribute(CATCVMObject * iOwner);

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream); 

private:
 	//CATCVMColor(CATCVMColor&);
 	//void operator =(CATCVMColor&);

	double _Red, _Green, _Blue, _Alpha;

};
#endif

