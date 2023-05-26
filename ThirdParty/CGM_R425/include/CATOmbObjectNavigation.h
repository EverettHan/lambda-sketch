#ifndef __CATOmbObjectNavigation_H
#define __CATOmbObjectNavigation_H

#include "AC0XXLNK.h"
#include "CATOmxSR.h"
#include "CATBaseUnknown.h"

class CATDocument;

/**
 * @level Private
 * @usage U1       
  */

/**
 * class allowing easy navigation on session objects aggregation tree:
 * PLM Component
 *   +-- Stream descriptor
 *      +-- document
 *         +-- container
 *            +-- "applicative" objects
 * All returned pointers are kept AddRef'ed internally.
 * As a consequence:
 *   they must not be released
 *   they are valid until the end of the scope of the CATOmbObjectNavigation instance.
 * Do not use pattern:
 *   CATBaseUnknown* ptr = CATOmbObjectNavigation(something).GetXXX();
 *   ptr->YYY(); //possible core-dump as the CATOmbObjectNavigation has been deleted.
 */
class ExportedByAC0XXLNK CATOmbObjectNavigation
{ 
  CATOmxSR<CATBaseUnknown> m_in,m_out;
public:
  /**ctor, @param iObject: object to work on.
  * iObject could be any type of object described in enum 'Type' below
  */
  CATOmbObjectNavigation(const CATBaseUnknown* iObject);

  /***/
  enum Type {Container,Document,StreamDescriptor,Component,Unknown,Null};

  /**return the type of the object*/
  Type GetType();

  /**
   * return container aggregating object if any (or object itself if it is a container)
   */
  CATBaseUnknown* GetContainer();

  /**
   * return document (directly/indirectly) aggregating object if any (or object itself if it is a document), 
   * works also if object is a loaded stream descriptor (1<->1 relation)
   */
  CATDocument* GetDocument();

  /**
   * return stream descriptor (directly/indirectly) aggregating object if any (or object itself if it is a stream descriptor)
   */
  CATBaseUnknown* GetStreamDescriptor();

  /**
   * return component (directly/indirectly) aggregating object if any (or object itself if it is a component)
   */
  CATBaseUnknown* GetComponent();

  /**
   * return component (directly/indirectly) aggregating object if any (or object itself if it is a component)
   */
  class CATComponentId GetComponentId();

  //default dtor, copy ctor, assignment operator OK
};

#endif
