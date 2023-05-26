#ifndef CATOmbLinkPointingBehavior_h
#define CATOmbLinkPointingBehavior_h

// COPYRIGHT DASSAULT SYSTEMES 2006
/**
 * @level Private
 * @usage U2
 */

 // SpecialAPI
#include "CATDataType.h"
// SystemTS
#include "CATBoolean.h"
#include "IUnknown.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATOmbBundle;
class CATOmbLinkFactory;
class CATOmbLinkSource;
class CATUnicodeString;

// Virtual class to have access to the pointing behaviour of a CATOmbLink.
class ExportedByCATObjectModelerBase CATOmbLinkPointingBehavior : public IUnknown
{
public:
  // Osm link type.
  enum CATLinkSourceType { StartupLink, ReferenceLink, ComponentLink, SpecObjectLink, ExternalLink };
  virtual CATLinkSourceType GetType() const = 0;

  // Access to the CATOmbLinkSource. 
  virtual CATOmbLinkSource * GetSource() = 0;

  // The name of the pointing object.
  virtual CATUnicodeString GetDisplayName() const = 0;

  // If true, the synchronization status of the link will take the update status of the target into account.
  virtual bool IsPointingAsInput() const = 0;

  // The bundle of the pointing object in the factory. 
  virtual CATOmbBundle * GetBundle(CATOmbLinkFactory & iLinkFactory) const = 0;
};

#endif
