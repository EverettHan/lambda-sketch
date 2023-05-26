#ifndef CATOmbOleObjectHandler_h
#define CATOmbOleObjectHandler_h


// COPYRIGHT DASSAULT SYSTEMES 2007


/**
 * @level Private
 * @usage U1
 */


#ifdef _WINDOWS_SOURCE  

// OS
#include <ole2.h>
#include <windows.h>
// SystemTS
#include "CATBoolean.h"
// ObjectModelerCollection
#include "sequence_octet.h"
// ObjectModelerBase
#include "AC0WINLNK.h"
#include "CATInsertDeclarations.h"

class CATUnicodeString;
class CATOmbOleLinkable;
class CATClientSite;
class CATILinkableObject;
class CATDocument;


class CATOleEventListener
{
public:
  virtual void OnDataChange() = 0;
  virtual void OnViewChange() = 0;
  virtual void OnRename(CATUnicodeString& iNewFilePath) = 0;
  virtual void OnSave() = 0;
  virtual void OnClose() = 0;
  virtual void OnLinkSrcChange(CATUnicodeString& iNewFilePath) = 0;
};


class CATOmbOleListener : public CATOleEventListener
{
public:
  virtual CATILinkableObject* GetOleLinkable() = 0;
  virtual void SetOleLinkable(CATILinkableObject*) = 0;
};


class ExportedByAC0WINLNK CATOmbOleObjectHandler
{
public:

  virtual ~CATOmbOleObjectHandler() = 0;

  // CATIOleInsertedObject
  virtual IOleObject*	GetOLEInsertedObject() = 0;
  virtual CATUnicodeString GetServerCLSID() = 0;
  virtual CATUnicodeString GetOleLinkedObjectPath() = 0;
  virtual HRESULT	CreateBitmapInFile(const CATUnicodeString& iFileName, int Hatched = 0, int IntAspect = 1) = 0;
  virtual HRESULT	CreateBitmap(unsigned char *& Buffer, int& Length, int Hatched = 0, int IntAspect = 1) = 0;

  // CATIInsertedObject
  virtual HRESULT	LaunchServerApplication() = 0;
  virtual HRESULT	CloseServerApplication() = 0;
  virtual	CATContentObjectType GetContentObjectType() = 0;
  virtual void SaveObject() = 0;
  virtual void Update(boolean SaveContentObject = FALSE) = 0;

  // OSM access
  virtual HRESULT GetData(SEQUENCE(octet)& oSeq) const = 0;
  virtual void SetHostName(const CATUnicodeString& iName) = 0;
  static void UpdateFilePath(CATDocument& iEmbeddingDoc, CATUnicodeString& iOldFilePath, CATUnicodeString& iNewFilePath);
  virtual CATBoolean IsOleLinkValid() const = 0;

  // Creation
  static CATOmbOleObjectHandler* CreateOleLinkedH(CATOmbOleListener& iListener, const CATUnicodeString& iFilePath, CATBoolean iPreview = TRUE);
  static CATOmbOleObjectHandler* CreateOleLinkedH(CATOmbOleListener& iListener, IDataObject* ipiObject, CATBoolean iPreview = TRUE);
  static CATOmbOleObjectHandler* CreateOleEmbeddedH(CATOmbOleListener& iListener, const CATUnicodeString& iFilePath, CATBoolean iPreview = TRUE);
  static CATOmbOleObjectHandler* CreateOleEmbeddedH(CATOmbOleListener& iListener, IDataObject* ipiObject, CATBoolean iPreview = TRUE);
  static CATOmbOleObjectHandler* CreateOleEmbeddedH(CATOmbOleListener& iListener, const GUID& iId, CATBoolean iPreview = TRUE);

  // Load
  static CATOmbOleObjectHandler* LoadOleH(CATOmbOleListener& iListener, SEQUENCE(octet)& iSeq);
  static HRESULT RecreateLinkedAsEmbedded(CATOmbOleListener & iListener, CATOmbOleObjectHandler& iLinkHander, CATOmbOleObjectHandler *& oEmbeddedHandler);

  // Data migration service
  static SEQUENCE(octet)* ExtractDataFromOldSequence(SEQUENCE(octet)& iOldSeq); // Extracts data from the "AddInfos" field in the old link sequence.
  static void UpdateFilePathFromOldSequence(CATDocument& iEmbeddingDoc, CATUnicodeString& ioOldFilePath); // Converts old paths with composition notation "!...!..." to normal file paths: CATIPointedSymbols::ReplaceLink is called (OMB replacement).
  // static HRESULT ConvertPathFromOldSequence( SEQUENCE(octet)& iOldSeq ); // Could be used to convert paths from OSM, with a new link creation (SetExternalObjectName).

  static HRESULT IsEmbeddedSequence(SEQUENCE(octet) & iSeq);

};


#endif 

#endif
