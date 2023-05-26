#ifndef CATOmbObjectStreamsDocumentHandler_H
#define CATOmbObjectStreamsDocumentHandler_H

// System
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATOmxSet.h"
#include "CATOmxSharable.h"
// CATVirtualVaultSystem
#include "CATVVSURLConnection.h"
#include "CATVVSUrl.h"
// ObjectModelerBase
// CATPLMStreamDescriptor
#include "CATOmyCioGenerator.h"
#include "CATOmbIPCS.h"
#include "CATOmbImportExportParameters.h"
#include "CATOmbStreamDescriptorDefinitionQualifiers.h"
#include "CATDocument.h"
#include "CATIOmyIncidentCollector.h"
#include "CATOmxArray.h"
#include "CATAsyncTrace.h"
#include "CATOmxCxxPortability.h"

enum ObjectStreamsDocumentStatus
{
  Unconstructed = 0,
  FirstTime = 1,
  UpdateCase = 2,
  OnlyPrereqLinkableSet = 3,
  BothLinkableSet = 4,
  ReattachementDone = 5,
};

class CATOmbStreamDescriptorObjectImpl;

class ExportedByCATOmbIPCS CATOmbObjectStreamsDocumentHandler
{
  friend class CATOmbObjectStreamsCollection;

private:
  CATOmbObjectStreamsDocumentHandler();
  virtual ~CATOmbObjectStreamsDocumentHandler();

  HRESULT ConstructFromComponents(CATBaseUnknown *ipComponent, CATBaseUnknown *ipPreqComponent);

  HRESULT DetachDocumentOfComponent();

  HRESULT ReattachDocumentToComponent(const CATVVSUrl &iIndexUrl = CATVVSUrl());
  
  HRESULT CompareCATParts();

  void SetLinkableSD(CATBaseUnknown *iSD);

  CATDocument *GetLinkableDoc();

  CATOmbObjectStreamsDocumentHandler(CATOmbObjectStreamsDocumentHandler &) OMX_Cxx11_DELETE;
  CATOmbObjectStreamsDocumentHandler &operator=(CATOmbObjectStreamsDocumentHandler &) OMX_Cxx11_DELETE;


  inline CATBoolean IsFirstTime() { return m_Status == FirstTime; }

  inline CATBoolean MustGenerateSD() { return (m_Status == FirstTime || m_Status == OnlyPrereqLinkableSet); }

  CATBaseUnknown *m_PreqComponent; // For unload
  CATDocument *m_LinkableDoc;
  CATDocument *m_PreqLinkableDoc;
  CATOmbStreamDescriptorObjectImpl *m_LinkableSD;
  CATOmbStreamDescriptorObjectImpl *m_PreqLinkableSD;
  ObjectStreamsDocumentStatus m_Status;
};

#endif
