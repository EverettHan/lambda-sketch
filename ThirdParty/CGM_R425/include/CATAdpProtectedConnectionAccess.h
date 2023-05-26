/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpProtectedConnectionAccess_H
#define CATAdpProtectedConnectionAccess_H

#include "CATPLMIntegrationBase.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"
class CATString;
class CATIPLMCompConnectionInstance;
class CATUnicodeString;

class ExportedByCATPLMIntegrationBase CATAdpProtectedConnectionAccess
{
public:
  CATAdpProtectedConnectionAccess();
  virtual ~CATAdpProtectedConnectionAccess();

/**
 * Returns the Persistency Provider.
 * <br><b>Role:</b>Enables to retrieve, if one is connected, the Persistency provider.  
 * <ul>
 * <li>For the moment, only <code>TST</code> or <code>M1</code> provider can be returned.</li>
 * <li>If both <code>TST</code> or <code>M1</code> providers are connected (it shouldn't), <code>M1</code> is returned.</li>
 * </ul>
 * @param oPersistencyProvider
 *   The connected Persistency provider.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>if either <code>M1</code> or <code>TST</code> provider is connected as Persistency provider. </li> 
 *   <li><tt>S_FALSE</tt>if no Persistency Provider is currently connected.</li>
 *   <li><tt>E_FAIL</tt>if the execution of the service failed.</li>
 *  </ul>
 */
  HRESULT GetPersistencyConnectedProvider( CATString & oPersistencyProvider );

/**
 * Returns the Persistency connection.
 * <br><b>Role:</b>Enables to retrieve, if one is connected, the Persistency connection.
 * <ul>
 * <li>For the moment, only <code>TST</code>, <code>M1</code> or <code>PLMxT</code> provider can be returned.</li>
 * <li>If several providers are connected (it shouldn't), <code>M1</code> connection is returned.</li>
 * </ul>
 * @return
 *   <ul>
 *   <li><tt>A pointer to <code>M1</code> or <code>TST</code> or <code>PLMxT</code> connection instance if connected</li> 
 *  </ul>
 */
  CATOmxSR<CATIPLMCompConnectionInstance> GetPersistencyConnection();

/**
 * Returns the connected Provider.
 * <br><b>Role:</b>Enables to retrieve, if only one is connected, the provider.
 * 
 * @param oProvider
 *   The connected Provider.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>if a Privider is connected. </li> 
 *   <li><tt>S_FALSE</tt>if no or more than one Provider is currently connected.</li>
 *   <li><tt>E_FAIL</tt>if the execution of the service failed.</li>
 *  </ul>
 */
  HRESULT GetConnectedProvider( CATString & oProvider );

  /**
   * Returns the connected user.
   * <br><b>Role:</b>Enables to retrieve the user connected to the persistency repository.
   *
   * @param oConnectedUser
   *   The connected user.
   * @return
   *   <ul>
   *   <li><tt>S_OK</tt>if the user was retrieved</li>
   *   <li><tt>E_FAIL</tt>if no connection to a persistency repository is available</li>
   *  </ul>
   */
  HRESULT GetConnectedUser(CATUnicodeString & oConnectedUser);

private:
  CATAdpProtectedConnectionAccess( const CATAdpProtectedConnectionAccess & );
  CATAdpProtectedConnectionAccess & operator =( const CATAdpProtectedConnectionAccess & );
};
#endif
