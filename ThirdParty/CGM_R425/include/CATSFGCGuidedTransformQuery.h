#ifndef CATSFGCGuidedTransformQuery_H
#define CATSFGCGuidedTransformQuery_H

#include "GMScalarFieldsOperators.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM
#include "CATICGMObject.h"

// Scalar Fields
#include "CATSFDagNodeQuery.h"

// STD
#include <memory>

namespace SF
{
  class SFDagNode;
  class SFGCGuidedTransform;

  using  SFDagNodePtr = std::shared_ptr<SFDagNode>;
  using  SFGCGuidedTransformPtr = std::shared_ptr<SFGCGuidedTransform>;
}

/**
 * CATSFGCGuidedTransformQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFGCGuidedTransformQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFGCGuidedTransformQuery>      UPtr;
  typedef std::shared_ptr<CATSFGCGuidedTransformQuery>      Ptr;

  /**
   * dtor
   */
  virtual ~CATSFGCGuidedTransformQuery();


protected:
  /**
   * ctor
   *
   */
  CATSFGCGuidedTransformQuery();
};


#endif // CATSFGCGuidedTransformQuery_H
