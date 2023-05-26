#ifndef _CATPLMIDLogicalFamilyCollection_H
#define _CATPLMIDLogicalFamilyCollection_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
 * @level Private
 * @usage U1
 */
 // ----------------------------------------------------------------------------------------------------------------------

#include "CATLib.h"
#include "IUnknown.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATOmxOrderedSet.h"

class CATPLMIDLogicalFamily;
class CATSysSimpleHashTable;
class CATPLMID;
struct CATOxLogicalFamily;

class ExportedByCATPLMIdentification CATPLMIDLogicalFamilyCollection
{
public:

  CATPLMIDLogicalFamilyCollection();
  virtual ~CATPLMIDLogicalFamilyCollection();

  /**
  * Register an identifier in logical family assembler
  *
  * @param iIdentifier
  *   Value of identifier
  *
  * @return
  *   S_OK     request succeeded <br>
  *   E_FAIL   if request failed for unknown reason<br>
  */
  HRESULT Register(const CATPLMID & iIdentifier);

  /**
  * Access to logical family
  *
  * @param oLogicalFamily
  *   Returns the associated logical family
  *
  * @return
  *   S_OK     request succeeded <br>
  *   E_FAIL   if request failed for unknown reason<br>
  */
  HRESULT GetLogicalFamily(const CATPLMID & iIdentifier, CATPLMIDLogicalFamily & oLogicalFamily) const;

  /**
  * Returns the number of logical families
  *
  * @return
  *   The number of logical families
  */
  unsigned int Size() const;

  /**
  * Remove all identifiers in the Table
  *
  * @return
  *   S_OK     request succeeded <br>
  *   E_FAIL   if request failed for unknown reason<br>
  */
  HRESULT RemoveAll();

private:

  void Init();

  // Forbidden operators 
  CATPLMIDLogicalFamilyCollection(CATPLMIDLogicalFamilyCollection&) = delete;
  CATPLMIDLogicalFamilyCollection& operator=(CATPLMIDLogicalFamilyCollection&) = delete;

  CATOmxOrderedSet<CATOxLogicalFamily, sharable_manager> m_families;
};

#endif
