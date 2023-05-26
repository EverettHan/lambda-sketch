//===================================================================
// COPYRIGHT Dassault Systemes 2021/03/29
//===================================================================
// CATIVariabilityExpositionRootAdapter.cpp
// Header definition of class CATIVariabilityExpositionRootAdapter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2021/03/29 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIVariabilityExpositionRootAdapter_H
#define CATIVariabilityExpositionRootAdapter_H

#include "CATIVariabilityExpositionAdapter.h"


/**
* Adapter for CATIVariabiltyExposition interface dedicated for "root" objects that have some delegated expositions
* Currently, for VPMReference only...
* Its purpose is to provide a default implementation for the delegation mechanism (see CATIVariabilityExpositionDelegation)
*/

class ExportedByKnowledgeItf CATIVariabilityExpositionRootAdapter : public CATIVariabilityExpositionAdapter
{
  CATDeclareClass;
public:
  CATIVariabilityExpositionRootAdapter();
  virtual ~CATIVariabilityExpositionRootAdapter();

  /**
  * This needs to be overloaded for this adapter
  */
  virtual CATUnicodeString GetStringForDelegation() = 0;


  /**
  * Returns the list of attributes defining of children that themselves expose some chilren and variables
  * For each of the attributes, the call of GetChild with the attribute name should return a valid object
  *
  * Default implementation will look for delegated children and return them
  */
  virtual HRESULT GetChildrenAttributes(CATListValCATAttributeInfos &oAttributes);

  /**
  * Returns the list of attributes of variables exposed by this object
  * For each of the attributes, the call of GetVariableValue with the attribute name should return a literal value implemented as a volatile parameter
  *
  * Default implementation will look for delegated variable attributes and return them
  */
  virtual HRESULT GetVariableAttributes(CATListValCATAttributeInfos &oAttributes);

  /**
  * Returns a child based on its attribute key
  *
  * Default implementation will look for delegated child and return it
  */
  virtual HRESULT GetChild(const CATUnicodeString &iKey, CATIVariabilityExposition_var &oExposition);

  /**
  * Returns a variable value based on its attribute key
  *
  * Default implementation will look for delegated variable value and return it
  */
  virtual HRESULT GetVariableValue(const CATUnicodeString &iKey, CATICkeParm_var &oValue);

  /**
  * Sets a variable value. The type of the passed parameters should be compliant with the type of
  * the attribute declared in CATAttributeInfos.
  * The method shouldn't be called on attributes that are declared as children and not variables nor on variables
  * declared as read only
  *
  * Default implementation will look for delegated variable value and ask for its modification
  */
  virtual HRESULT SetVariableValue(const CATUnicodeString &iKey, const CATICkeParm_var &iValue);


protected:
  void ComputeDelegations();

private:

  CATBoolean _DelegationsComputed;
  CATLISTV(CATBaseUnknown_var) _Delegations;
};



#endif