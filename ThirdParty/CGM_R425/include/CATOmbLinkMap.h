#ifndef CATOmbLinkMap_H_
#define CATOmbLinkMap_H_

// COPYRIGHT DASSAULT SYSTEMES	2009

/**
 * @level Private
 * @usage U1
 */
#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"

class CATComponentId;
struct CATOmbLinkMapImpl;
class CATOmbLinkVisitor;
class CATOmbLink;

/** a bad CATOmbLink* => CATOmbLink* map*/
class CATOmbLinkMap
{
public:
  ExportedByCATObjectModelerBase HRESULT Insert(const CATOmbLink & iLinkFrom, const CATOmbLink & iLinkTo);

  enum MapOrientation { From }; //yep one single value, the second one "To" was absolutely useless

  ExportedByCATObjectModelerBase HRESULT ReadMapping(MapOrientation iStartingOrientation, const CATOmbLink & iStartingLink, CATOmbLink *& oResultingLink) const;

  inline HRESULT Flush() { m_letter = NULL; return S_OK; }

private:
  CATOmxSR<CATOmbLinkMapImpl> m_letter;
};

#endif




