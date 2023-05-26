#ifndef CATComponentIdAssociationSet_H
#define CATComponentIdAssociationSet_H

/**
* @level Protected
* @usage U1       
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATComponentId.h"
#include "CATOmxOHMap.h"

class CATComponentId;
class CATComponentIdAssociationVisitor;
class CATComponentIdAssociationSet;
class CATComponentIdAssociationSetImpl;
class CATOxJanus;
class CATPLMIDSet;

/** Obsolete, use CATOmxOrderedOSet, CATOmxOHMap etc...*/
class CATComponentIdAssociationSet
{
  CATOmxOHMap<CATComponentId,CATUINTPTR> m_map;
public:
  /**
  * Search if an identifier is already associated (by physical identifier)
  *
  * @param iHandle
  *        Component's handle
  * @param oPointer
  *        Associated pointer
  * @return
  *        S_OK    : if succeeded and found
  *        S_FALSE : if succeeded but not found
  *        E_FAIL  : if failure
  */
  ExportedByCATPLMTos HRESULT Locate (const CATComponentId & iHandle, CATUINTPTR & oPointer) const;
  inline HRESULT Locate (const CATOxJanus & iCell, CATUINTPTR & oPointer) const {return Locate(CATComponentId(const_cast<CATOxJanus&>(iCell)),oPointer);}
  inline HRESULT Locate (const CATComponentId & iHandle) const {CATUINTPTR dummy=0;return Locate(iHandle,dummy);}

  inline unsigned int Size () const {return m_map.Size();}

  /**
  * visit set contents
  *
  * @param iVisitor
  *        Object visiting each internal structure elements  
  * @return
  *        S_OK   : Result found
  *        E_FAIL : End of Enumerate
  */
  ExportedByCATPLMTos HRESULT Visit (CATComponentIdAssociationVisitor & iVisitor) const;

  /**
  * Insert a couple in the Table   
  *
  * @param iHandle
  *        Component's handle
  * @param iPointer
  *        associated pointer
  * @return
  *        S_OK    : Insertion done
  *        S_FALSE : still present in set
  *        E_FAIL  : Failure 
  */
  ExportedByCATPLMTos HRESULT Insert(const CATComponentId & iHandle, const CATUINTPTR iPointer = NULL);

  /**
  * Remove an identifier in the Table
  *
  * @param iHandle
  *   Value of identifier
  * @return
  *        S_OK    : Search succeeded
  *        S_FALSE : No result Found
  *        E_FAIL  : Failure
  */
  inline HRESULT Remove(const CATComponentId &iHandle ) {return m_map.Remove(iHandle) ? S_OK : S_FALSE;}

  /**
  * Extract a PLMIDSet from CIDSet
  *
  * @param oPLMIDSet
  *   The set to complete.
  * @return
  *        S_OK    : if succeeded
  *        E_FAIL  : Failure
  */
  ExportedByCATPLMTos HRESULT CompletePLMIDSet (CATPLMIDSet & ioPLMIDSet) const;

  /**
  * Flush
  *
  * @return
  *        S_OK    : if succeeded
  *        E_FAIL  : if failure
  */
  inline HRESULT Flush() {m_map.RemoveAll();return S_OK;}

  /**meaningless*/
  inline CATBoolean operator!() const {return Size() == 0;}
};

#endif
