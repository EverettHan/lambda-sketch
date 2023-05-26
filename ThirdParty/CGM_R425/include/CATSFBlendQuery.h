#ifndef CATSFBlendQuery_H
#define CATSFBlendQuery_H

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
 * CATSFBlendQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFBlendQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFBlendQuery>      UPtr;
  typedef std::shared_ptr<CATSFBlendQuery>      Ptr;

  /**
   * dtor
   */
  virtual ~CATSFBlendQuery();

  /**
   * Return the offset value in Euclidean length unit. 
   */
  virtual double GetBlendValue() = 0;

protected:
    /**
   * ctor
   *
   */
  CATSFBlendQuery();
};

#endif // CATSFBlendQuery_H
