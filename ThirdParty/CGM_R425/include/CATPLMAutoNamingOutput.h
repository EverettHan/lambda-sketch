/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATPLMAutoNamingOutput_H
#define CATPLMAutoNamingOutput_H

#include "CATBaseUnknown.h"
#include "CATPLMServicesItf.h"
#include "CATUnicodeString.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxOrderedSet.h"

class CATPLMAutoNamingInput;
class CATPLMAutoNamingOutputElem;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMAutoNamingOutputElem*>::manager();
template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATOmxOrderedSet<CATPLMAutoNamingOutputElem> >::manager();
typedef CATOmxOMap< CATUnicodeString, CATOmxOrderedSet<CATPLMAutoNamingOutputElem> > OutputElementMap;

/**
* Class to use as Output of CATPLMProtectedAutoNamingServices.
*/
class ExportedByCATPLMServicesItf CATPLMAutoNamingOutput : public CATBaseUnknown
{
  friend class CATPLMCompAutoNamingService;

public:
  CATPLMAutoNamingOutput (CATBoolean iUsePhysicalRepositoryIdForInputKey = FALSE);
  ~CATPLMAutoNamingOutput ();

  /**
  * Adds an auto name for an input.
  *
  * @param iInput [in]
  *   The input.
  * @param iMode [in]
  *   The auto name mode.
  * @param iNamingString [in]
  *   The auto name string.
  *
  * @return
  *   <code>S_OK</code> The auto name is correctly added.
  *   <code>E_FAIL</code> iInput is NULL.
  */
  HRESULT AddOutput(const CATPLMAutoNamingInput* iInput, const int iMode, const CATUnicodeString& iNamingString);

  /**
  * Adds auto names for an input.
  *
  * @param iInput [in]
  *   The input.
  * @param iElems [in]
  *   The auto names to add.
  *
  * @return
  *   <code>S_OK</code> The auto names are correctly added.
  *   <code>E_FAIL</code> iInput is NULL.
  */
  HRESULT AddOutputs(const CATPLMAutoNamingInput* iInput, const CATOmxOrderedSet<CATPLMAutoNamingOutputElem>& iElems);

  /**
  * Retrieves first available (ordered) auto name for an input.
  *
  * @param iInput [in]
  *   The input.
  * @param oMode [out]
  *   The auto name mode returned.
  * @param oNamingString [out]
  *   The auto name string returned
  *
  * @return
  *   <code>S_OK</code> The auto name is correctly retrieved.
  *   <code>E_FAIL</code> iInput or oMode are NULL. Cannot find an auto name for this input.
  */
  HRESULT GetOutput(const CATPLMAutoNamingInput* iInput, int* oMode, CATUnicodeString& oNamingString);

  /**
  * Retrieves all available auto names for an input.
  *
  * @param iInput [in]
  *   The input.
  * @param oModeoElems [out]
  *   The auto names returned.
  *
  * @return
  *   <code>S_OK</code> The auto names are correctly retrieved.
  *   <code>E_FAIL</code> iInput or oMode are NULL. The returned set is empty.
  */
  HRESULT GetOutputs(const CATPLMAutoNamingInput* ipInput, CATOmxOrderedSet<CATPLMAutoNamingOutputElem>& oElems);

  /**
  * Returns the available unique names for the given input.
  *
  * @return
  *   Available names count.
  */
  int GetAvailableNameCount(const CATPLMAutoNamingInput* ipInput);

  /**
  * Copy constructor. Clone output elements map.
  */
  CATPLMAutoNamingOutput(const CATPLMAutoNamingOutput &iOutput);

private:
  // Enable or disable the use of the PhysicalRepositoryId when input key is computed
  void _SetUsePhysicalRepositoryIdForInputKey(CATBoolean iUsePhysicalRepositoryIdForInputKey) { _UsePhysicalRepositoryIdForInputKey = iUsePhysicalRepositoryIdForInputKey; }

  // key -> input key; value -> set of outputElem (used as First In First Out collection)
  OutputElementMap _OutputElements;

  // FALSE by default but it can be turned on to split names by server id (note that you must provide the physical repository id when GetOutput(s)).
  CATBoolean _UsePhysicalRepositoryIdForInputKey;
};

/**
* From CATAdpAutoNamingOutput.h :
*   enum NamingMode { Suffix = 1, Prefix = 2, Replace = 3 };
*/
class ExportedByCATPLMServicesItf CATPLMAutoNamingOutputElem : public CATBaseUnknown
{
  friend class CATPLMAutoNamingOutput;
  friend class CATPLMAutoNamingCache;
  friend class CATPLMCompAutoNamingService;

public:
  CATPLMAutoNamingOutputElem (CATUnicodeString iInputKey, int iMode, const CATUnicodeString& iNamingString)
    :_InputKey(iInputKey), _Mode(iMode), _NamingString(iNamingString) {};

  /**
  * Compares current element to the other element.
  *
  * @param ipOther [in]
  *   The other element.
  *
  * @return 
  *   -1    this < ipOther
  *    0    this == ipOther
  *    1    this > ipOther
  */
  int CompareTo(const CATPLMAutoNamingOutputElem* ipOther) const;

  /**
  * Returns the hash code of the element.
  *
  * @return
  *   unsigned int: the computed hash code.
  */
  CATHashKey Hash() const;

private:
  CATUnicodeString _InputKey;
  int _Mode;
  CATUnicodeString _NamingString;
};
#endif
