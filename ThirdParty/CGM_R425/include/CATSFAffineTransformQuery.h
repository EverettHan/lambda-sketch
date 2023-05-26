#ifndef CATSFAffineTransformQuery_H
#define CATSFAffineTransformQuery_H

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
 * CATSFAffineTransformQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFAffineTransformQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFAffineTransformQuery>      UPtr;
  typedef std::shared_ptr<CATSFAffineTransformQuery>      Ptr;

  /**
   * dtor
   */
  virtual ~CATSFAffineTransformQuery();

  /**
   * Retrieve the values of the Mat44 associated with the affine transformation
   */
  virtual HRESULT GetCoefficients(double m[16]) const = 0;

protected:
    /**
   * ctor
   *
   */
  CATSFAffineTransformQuery();
};

#endif // CATSFDagNodeQuery_H
