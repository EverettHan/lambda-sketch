#ifndef IVISUILicenceManager_H
#define IVISUILicenceManager_H

// COPYRIGHT Dassault Systemes 2017

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"


/**
 * IVISUILicenceManager
 *
 * Interface to propose services around the licence / role
 *
 * @example
 * <pre>
 *
 * // Get SUI Licence Manager
 * IVISUILicenceManager* pSUIManager = IVISUILicenceManager::GetManager();
 */
class ExportedByIVInterfaces IVISUILicenceManager : public CATBaseUnknown
{

  CATDeclareClass;

public:

  /**
  * Retrieves the unique @href IVISUILicenceManager instance.
  *
  * @return
  *     The @href IVISUILicenceManager instance.
  *
  * <br><strong>Lifecycle rules deviation</strong>:
  * The @href IVISUILicenceManager is a Singleton. Its lifecycle is automatically handled by the iV framework.
  * The returned pointer should never be <tt>NULL</tt>, and the caller should <strong>never</strong> try and delete it.
  */
  static IVISUILicenceManager* GetManager();

  /**
  * Allow access to IVISUIScenario from IVSUIScenarioServices.
  *
  * @param iAccess [in]
  *   A boolean vlaue
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>true</dt>
  *     <dd>The access is autorized</dd>
  *     <dt>false</dt>
  *     <dd>The access is not autorized</dd>
  *   </dl>
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The request succeeds</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The request doesn't succeed</dd>
  *   </dl>
  */
  virtual HRESULT SetIVSUIScenarioCAAAccess(bool iAccess) = 0;

  /**
  * Get access autorisation to IVISUIScenario from IVSUIScenarioServices.
  *
  * @param iAccess [out]
  *   A boolean vlaue
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>true</dt>
  *     <dd>The access is autorized</dd>
  *     <dt>false</dt>
  *     <dd>The access is not autorized</dd>
  *   </dl>
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The request succeeds</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The request doesn't succeed</dd>
  *   </dl>
  */
  virtual HRESULT GetIVSUIScenarioCAAAccess(bool& oAccess) = 0;

protected:

  // Instantiation not allowed
  IVISUILicenceManager();

  virtual ~IVISUILicenceManager();

private:

  // Copy not allowed
  IVISUILicenceManager(const IVISUILicenceManager&);

  // Operator = not allowed
  IVISUILicenceManager& operator=(const IVISUILicenceManager&);

};

#endif
