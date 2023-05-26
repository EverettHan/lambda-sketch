#ifndef _CATPLMIDLogicalFamilyVisitor_H
#define _CATPLMIDLogicalFamilyVisitor_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U1       
 */
#include "IUnknown.h"
#include "ExportedByCATPLMIdentification.h"

class CATPLMID;

// This class is an iterator on all the log entries in a save log
class ExportedByCATPLMIdentification CATPLMIDLogicalFamilyVisitor
{
public:

  CATPLMIDLogicalFamilyVisitor(){}
  virtual ~CATPLMIDLogicalFamilyVisitor(){}

  /**
  * CATBehaviour_continue : visit next component 
  * CATBehaviour_break    : stop iteration
  */
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};

  virtual CATBehaviour Visit(CATPLMID & iPLMID) = 0;

private:

  // Forbidden operators 
  CATPLMIDLogicalFamilyVisitor (CATPLMIDLogicalFamilyVisitor&);
  CATPLMIDLogicalFamilyVisitor& operator=(CATPLMIDLogicalFamilyVisitor&);
  void * operator new(size_t, CATPLMIDLogicalFamilyVisitor&);
};

#endif
