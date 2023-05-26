#ifndef CATSFOffsetQuery_H
#define CATSFOffsetQuery_H

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
  class SFAffineTransform;

  using  SFDagNodePtr = std::shared_ptr<SFDagNode>;
  using  SFAffineTransformPtr = std::shared_ptr<SFAffineTransform>;
}

/**
 * CATSFOffsetQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFOffsetQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFOffsetQuery>      UPtr;
  typedef std::shared_ptr<CATSFOffsetQuery>      Ptr;

  /**
   * dtor
   */
  virtual ~CATSFOffsetQuery();

  /**
   * Return the offset value in Euclidean length unit. 
   */
  virtual double GetOffsetValue() = 0;

protected:
    /**
   * ctor
   *
   */
  CATSFOffsetQuery();
};

#endif // CATSFOffsetQuery_H
