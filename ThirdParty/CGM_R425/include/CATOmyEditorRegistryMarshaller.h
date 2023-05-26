#ifndef CATOmyEditorRegistryMarshaller_h
#define CATOmyEditorRegistryMarshaller_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"

class CATOmyEditorRegistry;
class CATUnicodeString;
class CATStorage;
class CATOmyEditor;

class ExportedByCATOMYBaseSession CATOmyEditorRegistryMarshaller
{
public:
  CATOmyEditorRegistryMarshaller(CATOmyEditorRegistry * iRegistry);
  ~CATOmyEditorRegistryMarshaller();
  HRESULT StreamRegistry(const CATUnicodeString & iFilePath);
private:
  CATOmyEditorRegistry * _registry;
	HRESULT _StreamCurrentEditor(CATStorage* iRootStg, CATOmyEditor*& iEditor);
	HRESULT _StreamFileHeader(CATStorage* iRootStg);
};
#endif
