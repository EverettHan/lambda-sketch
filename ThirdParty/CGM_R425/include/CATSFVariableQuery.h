#ifndef CATSFVariableQuery_H
#define CATSFVariableQuery_H

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
 * CATSFVariableQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFVariableQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFVariableQuery>      UPtr;
  typedef std::shared_ptr<CATSFVariableQuery>      Ptr;

  /**
   * ctor
   *
   */
  CATSFVariableQuery();

  /**
   * ctor
   *
   */
  CATSFVariableQuery(const CATSFVariableQuery& iOther);

  /**
   * dtor
   */
  virtual ~CATSFVariableQuery();

  /**
   * Return the offset value in Euclidean length unit. 
   */
  virtual double GetParameterValue() = 0;

protected:

};

#endif // CATSFVariableQuery_H
