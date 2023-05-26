#ifndef __CATOmbLinkSource_h__
#define __CATOmbLinkSource_h__ 

/**
* @level Private
* @usage U2
 * COPYRIGHT DASSAULT SYSTEMES 2005
*/

// System
#include "CATUnicodeString.h"
// SystemTS
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxSR.h"
// ObjectModelerBase
#include "CATOmbLinkPointingBehavior.h"

class CATBaseUnknown;
class CATDocument;
class CATIComponent;
class CATIContainer;
class CATIOmbUniversalLink;
class CATOmbBundle;
class CATOmbBundleKingHandler;
class CATOmbLink;
class CATOmbLinkFactory;
class CATOmbRelationMetaData;

class ExportedByCATObjectModelerBase CATOmbLinkSource : public CATOmbLinkPointingBehavior
{
public:
  // Getters.
  CATOmbLinkSource * GetSource() override;

  CATOmbBundle * GetBundle(CATOmbLinkFactory & iLinkFactory) const override;
  virtual CATOmxSR<CATOmbBundleKingHandler> GetBundleKingHandler() const = 0;

  virtual CATOmbRelationMetaData & GetRelationMetaData() const = 0;

  virtual bool GetSavingMode() const = 0;

  // For external links, the OSM aggregation tree is used (CATIOmbComponentObject::GetComponent => S_FALSE means "not in a component")
  // For reference links, if the document is an authoring one, returns the rep, else E_INVALIDARG, meaning "unknown".
  // Indeed, the aggregation tree cannot be used DURING THE CREATION OF THE LINK (OSM limitation).
  virtual HRESULT GetComponent(CATOmxSR<CATIComponent> & oComponent);

  virtual CATDocument & GetDocument() const = 0;
  virtual CATOmxSR<CATIContainer> GetContainer() = 0;

  virtual CATOmxSR<CATBaseUnknown> GetPointingObject() const = 0;
  virtual CATUnicodeString GetPointingAttribute() const = 0;

  virtual CATOmbLink * GetLink() const = 0;

  // Listeners.
  virtual void OnBind() = 0;
  virtual void OnUnload() = 0;
  virtual void OnReroute(CATOmbLink & iNewLink) = 0;
  virtual void OnUnset() = 0;
  virtual void OnLinkAvailable(CATOmbLink & iLink) = 0;
  virtual void OnLinkUnavailable() = 0;

  virtual HRESULT Synchronize() = 0;

  // To isolate link in Edit/Links.
  virtual HRESULT Break() = 0;

  virtual void PerformReroute(CATIOmbUniversalLink & iUniversalLink) = 0;

  virtual HRESULT PerformUnset() = 0;

  virtual HRESULT GetPosition(unsigned int & oPosition) const = 0;

  // Specific to "connections without stream" : compute SemanticRelation.AppIndex attribute value so that link order can be stored on SRs.
  virtual int ComputeAppIndex() const;

  virtual bool NeedsOldRetrieveAll();

  virtual bool IsUnderRemoveForCloseContext() const;
};
#endif 
