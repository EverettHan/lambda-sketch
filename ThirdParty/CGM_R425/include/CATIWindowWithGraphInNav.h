#ifndef CATIWindowWithGraphInNav_H
#define CATIWindowWithGraphInNav_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

#include <list>

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIWindowWithGraphInNav;
#else
extern "C" const IID IID_CATIWindowWithGraphInNav;
#endif

//------------------------------------------------------------------
/**
 * This interface is meant to be implemented by windows in explore/navigation context
 * (Product Finder for instance where CATView fw is used and not CATGraph fw).
 * It allows to determine which kind of window we are in. It matches 
 * CATIWindowWithGraph, used for authoring context.
 */

class ExportedByCATAfrItf CATIWindowWithGraphInNav : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /*
   * Used to retrieve an ordered copy of the HSO. However, nodes are directly stored
   * in the list, to prevent a new computation of matching node later on.
   * See CATCenterGraphForNavigationHeader for more information.
   */
  virtual void GetOrderedElements(std::list<CATBaseUnknown*>* iList) = 0;

  /*
   * Used to center the Graph on a specific element. The element is a node.
   * See CATCenterGraphForNavigationHeader for more information.
   */
  virtual void CenterGraphOnElement(CATBaseUnknown *ipElement) = 0;
};

//------------------------------------------------------------------

CATDeclareHandler(CATIWindowWithGraphInNav, CATBaseUnknown);

#endif // CATIWindowWithGraphInNav_H
