//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicGet_h
#define VPMIDicGet_h

#include "VPMIDicInterfaces.h"
#include "CATBaseUnknown.h"

class VPMIDicMgr;
class VPMIDicMgr_var;
class VPMIDicStream;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicGet;
#else
extern "C" const IID IID_VPMIDicGet;
#endif

class ExportedByVPMIDicInterfaces VPMIDicGet : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
   * internal API
   * @param oMgr : the dictionary manager
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT Get( VPMIDicMgr** oMgr ) = 0;

  /**
   * internal API
   * @param oDictionary : the dictionary controller
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT Get( VPMIDicMgr_var& oDictionary ) = 0;

  /**
   * internal API
   * @param oDictionary : the dictionary controller
   * @param iFromServer : the server controller
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT Get( VPMIDicMgr_var& oDictionary, VPMIDicStream& iFromServer ) = 0;
};

#endif /*VPMIDicGet_h*/
