#ifndef CATIKweAppResourceCriterion_h
#define CATIKweAppResourceCriterion_h

// COPYRIGHT Dassault Systemes 2007

// KnowledgeInterfaces framework
#include "CATICkeType.h"
#include "CATLifSpecs.h"

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweAppResourceCriterion;
#else
extern "C" const IID IID_CATIKweAppResourceCriterion;
#endif

/**
 * Interface used to represent a criterion used by a Table of Application Resources.
 * @see CATIKweAppResourcesTable
 */
class ExportedByCATLifSpecs CATIKweAppResourceCriterion : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:
	
	  /**
	   * Returns the criterion name.
	   */
	  virtual CATUnicodeString GetName() = 0;

	  /**
	   * Returns the criterion type.
	   */
	  virtual CATICkeType_var GetType() = 0;

	  /**
	   * Returns the criterion description.
	   */
	  virtual CATUnicodeString GetDescription() = 0;

	  /**
	   * Returns the criterion range (minimum and maximum value).
	   */
	  virtual HRESULT GetRange(double& oMinValue, double& oMaxValue) = 0;

	  /**
	   * Returns the criterion possible values if any.
	   */
	  virtual HRESULT GetPossibleValues(CATListOfCATUnicodeString& oValues) = 0;
};

CATDeclareHandler(CATIKweAppResourceCriterion, CATBaseUnknown);


#endif // CATIKweAppResourceCriterion_h

