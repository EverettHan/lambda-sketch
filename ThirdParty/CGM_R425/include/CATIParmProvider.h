
#ifndef CATIParmProvider_H
#define CATIParmProvider_H

// COPYRIGHT Dassault Systemes 2000
//===================================================================
//

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATProviderItf.h"
#include "CATBaseUnknown.h"

class CATListValCATBaseUnknown_var;

extern ExportedByCATProviderItf IID IID_CATIParmProvider;

/**
 * Interface used to retrieve the parameters aggregated by an extended object.
 * <br><b>See also:</b> <tt>CATIParmPublisher</tt> interface in KnowledgeInterfaces framework.
 */
class ExportedByCATProviderItf CATIParmProvider : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Returns the list of the parameters aggregated by a product's extension.
   * @param intfName
   *   The interface name.
   * @param oList
   *   The list of the direct children of the given object.
   * @param iObj
   *   The extended object whose direct children are to be retrieved.
   * @return
   *   The code error. 
   *   <dl>
   *   <dt><tt>S_OK</tt></dt><dd>the method is successful</dd>
   *   <dt><tt>E_FAIL</tt></dt><dd>otherwise</dd>
   *   </dl>
   */
  virtual HRESULT GetDirectChildren(CATClassId intfName, CATListValCATBaseUnknown_var * oList, CATBaseUnknown * iObj) = 0;
};

//------------------------------------------------------------------

#endif
