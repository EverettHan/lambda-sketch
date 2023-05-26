// COPYRIGHT Dassault Systemes 2007

#ifndef CATOmbSessionBehaviorsProvider_H
#define CATOmbSessionBehaviorsProvider_H

/**
* @level Private
* @usage U3
*/

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATListPV.h"
#include "CATSysMacros.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbSessionBehaviorsProvider;
#else
extern "C" const IID IID_CATIOmbRelationalBrowsePCCServices;
#endif


// FunctionCall Factories and Proxy Factories utilities
#include "CATOmbUniversalLinkFactoryRegisterKey.h"
#include "CATUnicodeString.h"
struct CATOmbBehavior;
class CATIOmbFunctionCallFactory_var;
class CATIOmbProxyFactory_var;
class CATIOmbFunctionCall;


/**
* @nodoc
* Runtime prereq utilities.
*/
class CATIOmbSessionBehaviorsProvider : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  enum ComputingMethod { InstantiateComponent = 0, GetSessionDataExt = 1 };

  /** @nodoc */
  virtual HRESULT GetBehavior(const IID & iInterfaceIID, void ** ippiImpl,
    const ComputingMethod & iComputingMethod = InstantiateComponent) = 0;
};

/**
* @nodoc
* Runtime prereq utilities.
* Session Data Extention.
*/
class CATEOmbSessionBehaviorsProvider : public CATIOmbSessionBehaviorsProvider
{
  CATDeclareClass;

public:

    /** @nodoc */
  ExportedByCATObjectModelerBase static CATIOmbSessionBehaviorsProvider * GetSingleton();
  inline static CATEOmbSessionBehaviorsProvider * GetSessionBehaviorsProvider() { return (CATEOmbSessionBehaviorsProvider *)GetSingleton(); };

  /** @nodoc */
  HRESULT GetBehavior(const IID & iInterfaceIID, void ** oppiImpl, const ComputingMethod & iComputingMethod = InstantiateComponent);

/** @nodoc */
  HRESULT ChangeComponentState(ComponentState iFromState, ComponentState iToState,
    const CATSysChangeComponentStateContext * iContext);

/** @nodoc */
  int IsNull() const;



private:

  CATEOmbSessionBehaviorsProvider();
  ~CATEOmbSessionBehaviorsProvider();

  CATBoolean Locate(const IID & iInterfaceIID, void ** const oppiImpl) const;

  void Insert(const IID & iInterfaceIID, CATBaseUnknown * ipiImpl);

  int _isRemoved;

  static CATIOmbSessionBehaviorsProvider * _piSingleton;

  CATOmbBehavior * _pBehaviors;







///////////////////////////////////////////////////////////////////////////////
// FunctionCall Factories and Proxy Factories utilities
///////////////////////////////////////////////////////////////////////////////


public:
  ExportedByCATObjectModelerBase HRESULT GetFunctionCallFactory(const int iID, CATIOmbFunctionCallFactory_var &oFactory);
  ExportedByCATObjectModelerBase HRESULT GetProxyFactory(const int iID, CATIOmbProxyFactory_var &oFactory);

private:
  void InitFactoriesUtilities();
  void RemoveFactoriesUtilities();
  HRESULT CreateFactory(const int iID, const IID iInterface);

  static const int _Size = CATOmbFactoryRegisterKeySize;
  CATUnicodeString *_LateTypes;
  CATBaseUnknown **_Factories;

};



#endif
