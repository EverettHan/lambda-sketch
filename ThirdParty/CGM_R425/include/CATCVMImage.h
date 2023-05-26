#ifndef CATCVMImage_h
#define CATCVMImage_h

#include "CATCVMAttribute.h"
#include "CATCVMAttrRef.h"
#include "CATCVMSysObjects.h"
#include "CATCVMSysStream.h"
#include "CATCGMNewArray.h"

class ExportedByCATCVMSysObjects CATCVMImage : public CATCVMAttrRef
{
public:
  static CATCVMImage * GetOrCreateCVMImage(CATCVMContainer * iContainer,
                                           CATUnicodeString iID, CATUnicodeString iPath);
public:
  CATCVMImage(CATCVMContainer * iContainer);
  CATCGMNewClassArrayDeclare;
  
protected:
  virtual ~CATCVMImage();

public:
  // Get/Set divers
	HRESULT SetPath (CATUnicodeString iPath);
	HRESULT GetPath (CATUnicodeString & oPath);
  HRESULT SetBuffer (CATULONG32 iBufferSize, unsigned char * iBuffer);
  CATULONG32 GetBuffer (unsigned char * oBuffer);

  HRESULT ToBeStreamed(); //If the image hes always to be streamed
  CATULONG32 GetRef(ListPOfCATCVMAttrRef * ioListe); // only return non-nul if the image is skewed

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream, CATCVMContainer * iContainer); 

  CATBoolean IsEqualTo(CATCVMAttrRef * iAttrRef);

private:
 	//CATCVMImage(CATCVMImage&);
 	//void operator =(CATCVMImage&);
  
  CATUnicodeString     _Path;
  CATULONG32           _BufferSize;
  unsigned char      * _Buffer;
  CATBoolean           _ToBeStreamed;
};
#endif

