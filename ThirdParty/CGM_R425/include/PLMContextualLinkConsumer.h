// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// PLMContextualLinkConsumer.h
// Header definition of PLMContextualLinkConsumer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2009  Creation: Code generated by the CAA wizard  LVT
//===================================================================
#ifndef PLMContextualLinkConsumer_H
#define PLMContextualLinkConsumer_H

/**
 * @level Protected
 * @usage U1 
 */

#include "PLMModelerContextualLinkItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

//-----------------------------------------------------------------------

/**
 * Class representing a consumer of a contextual link.
 */
class ExportedByPLMModelerContextualLinkItf PLMContextualLinkConsumer
{
public:

  /**
   *  @param  ipConsumer
   *    A contextual link consumer
   *  @param  iAttributeName
   *    The consumer attribute that will point the contextual link.
   *  @param  iIndexInList
   *    The index in the list. <br>
   *    0 by default (which will add the contextual link at the end of the list, unsed on single values)
   */
  PLMContextualLinkConsumer(CATBaseUnknown *ipConsumer, CATString &iAttributeName, int iIndexInList = 0);
  virtual ~PLMContextualLinkConsumer ();

  /**
   * Returns the contextual link consumer.
   *
   *  @return
   *    The consumer.
   */
  CATBaseUnknown *GetConsumer();

  /**
   *  Returns the consumer attribute name that will point the contextual link.
   *
   *  @return
   *    An attribute name.
   */
  CATString GetConsumerAttributeName();

  /**
   *  Returns the index in the consumer attribute list that will point the contextual link.
   *
   *  @return
   *    An attribute list index.
   */
  int GetAttrIndex();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  PLMContextualLinkConsumer (PLMContextualLinkConsumer &);
  PLMContextualLinkConsumer& operator=(PLMContextualLinkConsumer&);

  CATBaseUnknown *m_pConsumer;
  CATString m_AttrName;
  int m_IndexInList;
};

//-----------------------------------------------------------------------

#endif