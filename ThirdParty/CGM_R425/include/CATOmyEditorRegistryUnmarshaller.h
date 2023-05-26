#ifndef CATOmyEditorRegistryUnmarshaller_h
#define CATOmyEditorRegistryUnmarshaller_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATOMYBaseSession.h"
#include "CATListOfCATUnicodeString.h"

class CATOmyEditorRegistry;
class CATStorage;
class CATStream;

class ExportedByCATOMYBaseSession CATOmyEditorRegistryUnmarshaller
{
public:
  CATOmyEditorRegistryUnmarshaller(const CATUnicodeString & iFilePath);
  ~CATOmyEditorRegistryUnmarshaller();
  HRESULT UnstreamRegistry(CATOmyEditorRegistry * iRegistry);
  HRESULT GetNumberOfRegistries(CATLONG32 &oNumberOfEditors);
private:
  CATUnicodeString _filePath;
 
  HRESULT _UnstreamFileHeader(CATStorage* iRootStg, CATLONG32 & oStreamVersion, CATLONG32& oNbStoredEditors);
  HRESULT _RetrieveEditorsStreamNames(CATStorage* iRootStg, CATListOfCATUnicodeString& ioEdtStreamNameList);
  HRESULT _UnstreamCurrentEditor(CATOmyEditorRegistry * iRegistry,CATStorage* iRootStg, const CATUnicodeString& iEditorStreamName);
  HRESULT _UnstreamEditorFromStream(CATOmyEditorRegistry * iRegistry, CATStream* iStream);
  HRESULT _UnmarshallEditorFromData(CATOmyEditorRegistry * iRegistry, const CATUnicodeString& iLateType, int iEditorId,
  CATLONG32 iDataSize, unsigned char  * iData);
};
#endif
