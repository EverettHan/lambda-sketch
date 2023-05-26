#ifndef _CATPLMBag_H
#define _CATPLMBag_H
/**
* @level Private
* @usage U1
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"

class CATComponentId;
class CATOxBag;
class CATComponentIdVisitor;
class CATIOmbLifeCycleOwnerNLSInfo;

class ExportedByCATPLMTos CATPLMBag
{
public:

  /**
  * Constructs an empty bag.
  */
  CATPLMBag ();
  ~CATPLMBag ();

  /**
  * Inserts a PLM component as root object kept by this bag.
  * Only reference and RepReference can be inserted.
  * @param iComp
  *    The root component to insert in the bag.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The component was successfully inserted.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The component was previously inserted, thus the bag contains it.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The component has not been inserted.</dd>
  *   </dl>
  */
  HRESULT InsertRoot( const CATComponentId & iCID );

  /**
  * Removes a PLM component from this bag.
  * Every component which was kept in memory only because of this particular root will
  * be unloaded from the session.
  * @param iComp
  *    The root component to remove from the bag.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The component was successfully removed.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The component has not been removed. An internal error occurred.</dd>
  *   </dl>
  */
  HRESULT RemoveRoot( const CATComponentId & iCID  );

  /**
  * Visiting Roots.
  * @param iVisitor
  *        The visitor
  */
  void VisitRoots (CATComponentIdVisitor & iVisitor);

  /**
  * Empties this bag.
  * Every component which was kept in memory only because of this bag will
  * be unloaded from the session. See also RemoveRoot method.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>All components were successfully removed.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>An internal error occured.</dd>
  *   </dl>
  */
  HRESULT RemoveAll();

  /**
  * Constructs a new handle referencing the same bag.
  * The CATPLMBag C++ object is a handle on a shared internal bag.
  * The internal bag is deleted when the last handle is deleted.
  * 
  * @param iCopy
  *        An handle on the bag to be shared.
  */
  CATPLMBag(const CATPLMBag &iCopy);

  /**
  * Assign a new reference to an existing handle.
  * The CATPLMBag C++ object is a handle on a shared internal bag.
  * If the handle was assigned to an existing bag, it will be released.
  *
  * @param iCopy
  *        An handle on the bag to be shared.
  * @return
  *        The current handle.
  */
  CATPLMBag& operator=(const CATPLMBag &iCopy);

  /**
  * Checks if handle is referencing a bag.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>TRUE</dt>
  *     <dd>handle is not referencing a bag.</dd>
  *     <dt>FALSE</dt>
  *     <dd>handle is referencing a bag.</dd>
  *   </dl>
  */
  inline CATBoolean operator!() const {return !_ImplUsage;}

  /**
  * ChangeOwnerInfo:
  * Set bag role use for debug information.
  * The bag must have been initialized first
  * before calling this method.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>the role was successfully set</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>the bag has not yet been initialized</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>An internal error occured.</dd>
  *   </dl>
  */
  HRESULT ChangeOwnerInfo( CATIOmbLifeCycleOwnerNLSInfo & iNLSInfo );

  void SetUsage(CATOxBag * iHandle );
private:

  CATOmxSR<CATOxBag> _ImplUsage;
};

#define CATPLMBag_Null CATPLMBag()

#endif
