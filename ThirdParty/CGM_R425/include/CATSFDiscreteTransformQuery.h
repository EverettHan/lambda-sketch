#ifndef CATSFDiscreteTransformQuery_H
#define CATSFDiscreteTransformQuery_H

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
  class SFDiscreteTransformNode;

  using  SFDagNodePtr = std::shared_ptr<SFDagNode>;
  using  SFDiscreteTransformNodePtr = std::shared_ptr<SFDiscreteTransformNode>;
}

/**
 * CATSFDiscreteTransformQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFDiscreteTransformQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFDiscreteTransformQuery>      UPtr;
  typedef std::shared_ptr<CATSFDiscreteTransformQuery>      Ptr;
  
  /**
   * dtor
   */
  virtual ~CATSFDiscreteTransformQuery();


protected:
  /**
   * ctor
   *
   */
  CATSFDiscreteTransformQuery();
};

#endif // CATSFDiscreteTransformQuery_H
