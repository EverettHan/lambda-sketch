#ifndef CATOxRelationalDescriptor_H 
#define CATOxRelationalDescriptor_H
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
* @level Private
* @usage U1
*/
#include "ExportedByCATPLMTos.h"
#include "CATTosMacros.h"
#include "CATComponentId.h"
#include "IUnknown.h"
#include "CATPLMRelationDirection.h"

class CATOxRelationVisitor;
class CATOxRelationalDescriptors;
class CATOxRelationalDescriptorTransaction;

/**
* Relational view access
*/
class ExportedByCATPLMTos CATOxRelationalDescriptor : public IUnknown
{
public:

  CATComponentId GetId() const;

  virtual CATPLMRelationDirection GetDirection() const  = 0;

  virtual CATBoolean IsValid() const;

  /**
  *
  * Returns a pointer to a given interface.
  * @param iIID
  *   The interface identifier for which a pointer is requested.
  * @param oPPV
  *   The address where the returned pointer to the interface is located.
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the query succeeds
  *   <dt><tt>E_NOINTERFACE</tt> <dd>If the interface does not exist
  *   <dt>Other                  <dd>If the query fails for any other reason.
  *   </dl>
  */
  HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);
  /**
  * Increments the reference count for the given interface.
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
  */
  ULONG __stdcall AddRef();
  /**
  * Decrements the reference count for the given interface.
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
  */
  ULONG __stdcall Release();

protected:

  CATOxRelationalDescriptor();
  virtual ~CATOxRelationalDescriptor();

private:

  friend class CATOxRelationalDescriptors;
  friend class CATOxRelationalDescriptorTransaction;

  virtual HRESULT Init (const CATComponentId & iCID) = 0;

  void Connect(CATOxRelationalDescriptors * iDescriptors);
  void Disconnect();

  // TRUE : if effective deletion
  CATBoolean DeleteIfUseless();

#ifndef CNEXT_CLIENT
  static unsigned int           _tagCounter;
  unsigned int                  _tag;
#endif
  CATOxRelationalDescriptors  * _Descriptors;   // NULL if descriptor has been INVALIDATED !!!
  unsigned int                  _McRef;
};

#endif
