#ifndef IVSUIScenarioServices_H
#define IVSUIScenarioServices_H

// COPYRIGHT Dassault Systemes 2017

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "CATErrorDef.h"
#include "IVInterfaces.h"

class IVISUIScenario;

/**
 * IVSUIScenarioServices proposes services around the IVISUIScenario.
 *
 * @see IVISUIScenario
 *
 */
class ExportedByIVInterfaces IVSUIScenarioServices
{
public:

  /**
   * Get the count of registered scenarii.
   *
   * @return
   *   The scenarii count
   */
  static unsigned int GetScenarioCount();

  /**
  * Get the scenario from its index.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oScenario</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oScenario</tt> could not be retrieved</dd>
  *   </dl>
  */
  static HRESULT GetScenario(const unsigned int iScenarioIndex, IVISUIScenario*& oScenario);

private:

  IVSUIScenarioServices();
};


#endif
