#ifndef CATOmbBundleKingHandler_H
#define CATOmbBundleKingHandler_H

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
* @level Private
* @usage U2
*/

// SpecialAPI
#include "CATDataType.h" // For CATULONG32
// SystemTS
#include "IUnknown.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATDocument;
class CATIOmbComponentObject;


/**
 * Abstract class related to the king feature of a bundle
 * <br><b>Role:</b> Used to set or get the identifier of the bundle.
 */
class ExportedByCATObjectModelerBase CATOmbBundleKingHandler : public IUnknown
{
public:

  /**
   * Retrieves the bundle identifier.
   * @param oId
   *  The bundle identifier that is stored on the current king feature.
   * @return
   *	An HRESULT value:
   *	<dl>
   *   <dt>S_OK</dt>
   *     <dd>The bundle identifier has been retrieved successfully.</dd>
   *		<dt>S_FALSE</dt>
   *     <dd>The bundle has not been valuated yet.</dd>
   *   <dt>E_FAIL</dt>
   *     <dd>The current feature is not a bundle king feature.</dd>
   *	</dl>
   */
  virtual HRESULT GetBundleId(CATULONG32 & oId) const = 0;

  /**
   * Returns the document of the current king feature.
   * @return
   *  The document.
   */
  virtual CATDocument & GetDocument() const = 0;

  /**
   * Retrieves the component of the current king feature.
   * @param opiComp
   *  The component.
   * @return
   *	<dl>
   *   <dt>S_OK</dt>
   *     <dd>The component has been retrieved successfully.</dd>
   *   <dt>E_FAIL</dt>
   *     <dd>The component can't be retrieved.</dd>
   *	</dl>
   */
  virtual HRESULT GetComponent(CATIOmbComponentObject *& opiComp) = 0;

  /**
   * Event called after creation of the bundle which the current feature is the king of.
   * @param iId
   *  The identifier of the bundle.
   */
  virtual void OnBundleCreation(CATULONG32 iId) = 0;

  /**
   * Event called when the current king feature is physically removed.
   * This method must not be overloaded by derived classes.
   */
  void OnBundleKingDestroyed();
};

#endif
