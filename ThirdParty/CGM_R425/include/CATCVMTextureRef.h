#ifndef CATCVMTextureRef_h
#define CATCVMTextureRef_h

// Class to define a shared texture 
// This shared texture will be use as reference of texture attributes

// 07:08:20 FDN : Ajout de la methode GetRef (ref de la ref !)

#include "CATCVMAttrRef.h"
#include "CATCGMNewArray.h"

#include "CATCVMContainer.h"
#include "CATCVMGeoObjects.h"
#include "CATMathConstant.h"
#include "CATUnicodeString.h"
#include "CATMathTransformation.h"
#include "CATCVMSysStream.h"
#include "CATCVMImage.h"
class CATCVMVisuData;

class ExportedByCATCVMGeoObjects CATCVMTextureRef  : public CATCVMAttrRef
{

public:
  // Please only create this class with THIS API !!!!!!!!!!!!!!!!!!!
  static CATCVMTextureRef * GetOrCreateCVMTextureRef(CATCVMContainer * iContainer, 
                                                     CATCVMImage     * iImage,
                                                     CATCVMVisuData  * iVisuData = NULL,
                                                     CATCVMImage     * iBumpImage = NULL);
  // Deprecated (old odt only)
  static CATCVMTextureRef * GetOrCreateCVMTextureRef(CATCVMContainer * iContainer, CATUnicodeString iPath);

public:
	CATCVMTextureRef (CATCVMContainer * iContainer);

  CATCGMNewClassArrayDeclare; // Pool allocation

protected:
	virtual ~CATCVMTextureRef();

public:

  HRESULT GetImage (CATCVMImage *& oImage);
  HRESULT GetTexturePath (CATUnicodeString & oPath) const ;
  HRESULT SetTexturePath (CATUnicodeString iPath) ;
  HRESULT SetVisuData (CATCVMVisuData * iVisuData);
  HRESULT GetVisuData (CATCVMVisuData *& oVisuData);
  HRESULT GetBumpImage (CATCVMImage *& oImage);

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream, CATCVMContainer * iContainer); 

  // Comparaison
  CATBoolean IsEqualTo(CATCVMAttrRef * iAttrRef);

  static void InitPath(CATUnicodeString & Path);

  CATULONG32 GetRef(ListPOfCATCVMAttrRef * ioListe);

private:
//	CATCVMTextureRef(CATCVMTextureRef&);
//	void operator =(CATCVMTextureRef&);

  HRESULT SetImage (CATCVMImage * iImage);
  HRESULT SetBumpImage (CATCVMImage * iImage);

#define version04
#ifdef version04
  CATCVMImage * _Image;
#else
  CATUnicodeString _Path;
#endif
  CATCVMVisuData * _VisuData;
  CATCVMImage    * _BumpImage;
};
#endif

