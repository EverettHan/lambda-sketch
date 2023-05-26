#ifndef IVISUIEntity_H
#define IVISUIEntity_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventArgs;

extern ExportedByIVInterfaces IID IID_IVISUIEntity;

/**
* Interface representing a SUI Entity.
* <strong>Role</strong>: This interface is the base interface for all SUI Entities.
*/
class ExportedByIVInterfaces IVISUIEntity: public CATBaseUnknown
{

  CATDeclareInterface;

public:

  /**
  * Get the name of the entity.
  *
  * @param [out] oName
  *   The name of the Entity, which can be used for a more intuitive identification and enumeration.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oName</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oName</tt> could not be retrieved</dd>
  *   </dl>
  */
  virtual HRESULT GetName(CATUnicodeString& oName) const = 0;

  /**
  * Get the name of the entity.
  *
  * @return
  *   The name of the Entity, which can be used for a more intuitive identification and enumeration.
  */
  virtual CATUnicodeString GetName() const = 0;

  /**
  * Add callbacks on events sent by the Entity.
  * @see IVSUIEvents
  *
  * @param iEvent [in]
  *   The Event to listen to. Event types are defined in @href IVSUIEvents.
  * @param iHandler [in]
  *   The Event Handler to use.
  * @return
  *   1 if succeeded
  */
  virtual int AddHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler, int iHandleConsumedEvents = 0) = 0;

  /**
  * Remove callbacks on events sent by the Entity.
  * @see IVSUIEvents
  *
  * @param iEvent [in]
  *   The Event to listen to. Event types are defined in @href IVSUIEvents.
  * @param iHandler [in]
  *   The Event Handler to use.
  * @return
  *   1 if succeeded
  */
  virtual int RemoveHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler) = 0;

  /**
  * @nodoc
  * Internal use only.
  */
  virtual int Dispatch(CATSYPEventArgs* iArgs) = 0;
};

CATDeclareHandler(IVISUIEntity, CATBaseUnknown);

#endif
