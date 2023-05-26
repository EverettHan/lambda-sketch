#ifndef CATUFOToolboxForPLMID_H
#define CATUFOToolboxForPLMID_H
/**
 * @level Protected
 * @usage U1       
 */

#include "IUnknown.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATBoolean.h"

class CATPLMID;
class CATPLMID_Simple;
class CATUnicodeString;

class ExportedByCATPLMIdentification CATUFOToolboxForPLMID
{
public:
  /**
  * Get the last PLMID of a complex Id.
  * @param iComplexId
  *  The complex Id
  * @param oLastInstanceId
  *  The last PLMID of the complexId
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT GetLastPLMIDFromComplexPLMID(const CATPLMID & iComplexID, CATPLMID & oLastId, CATBoolean iOnlyInstance = TRUE);
  static CATPLMID GetLastElement(const CATPLMID& iPLMID,CATBoolean iOnlyInstance = TRUE);
  /**
  * Computes if a path is a longer version of another, with same ending.
  * @param iShortPath
  *  The shorter Id
  * @param iLongPath
  *  The longer Id
  * @param iMinorSensitive
  *  Minor sensitivity
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT IsPathSubPathOfPath(const CATPLMID & iShortPath,const CATPLMID & iLongPath, CATBoolean iMinorSensitive = TRUE);

  /**
  * Gets the first instances of a path, compared to another.
  * @param iShortPath
  *  The shorter Id
  * @param iLongPath
  *  The longer Id
  * @param oFirstInstances
  *  The first instances, that are in longer Id and not in shorter Id
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT GetFirstInstances(const CATPLMID & iShortPath,const CATPLMID & iLongPath, CATPLMID & oFirstInstances);
  
  /**
  * Add instances at the beginning of a PLMID.
  * @param iShortPath
  *  The shorter Id
  * @param iFirstInstances
  *  The instances to add
  * @param oLongPath
  *  The result
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT AddFirstInstances(const CATPLMID & iShortPath,const CATPLMID & iFirstInstances, CATPLMID & oLongPath);
  
  /**
  * Get the same PLMID without its last instance.
  * @param iLongPath
  *  The full Id
  * @param oShortPath
  *  The result
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT RemoveLastInstance(const CATPLMID & iLongPath, CATPLMID & oShortPath);
  
  /**
  * Complex transformation: gets the first instances between short and long id, and puts them at the beginning of the short id.
  * @param iShortPath
  *  The short Id
  * @param iLongPath
  *  The long Id
  * @param oLongPath
  *  The result
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT TransformShortPathWithFirstInstances(const CATPLMID & iShortPath,const CATPLMID & iLongPath,CATPLMID & oLongPath);
    
  /**
  * Substitute part of an Id with another id
  * @param iPLMID
  *  The input Id
  * @param iFirst
  *  Index of the first instance to replace
  * @param iLast
  *  Index of the last instance to replace
  * @param iReplacement
  *  Replacement Id
  * @param oReplaced
  *  The result
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT Substitute(const CATPLMID & iPLMID, unsigned int iFirst, unsigned int iLast,const CATPLMID & iReplacement,CATPLMID & oReplaced);

  /**
  * Check the coherency of the given occurrence
  * @param iPLMID
  *  The input Id
  *
  * @Return
  *  S_FALSE if empty or size 1
  *  S_OK if the occurrence is coherent
  *  E_FAIL otherwise
  */
  static HRESULT CheckOccurrenceCoherency(const CATPLMID & iOccurrence);

  /**
  * Substitute beginning of an Id with another id
  * @param iPLMID
  *  The input Id
  * @param iLast
  *  Index of the last instance to replace
  * @param iReplacement
  *  Replacement Id
  * @param oReplaced
  *  The result
  * @Return
  *  S_OK if Id was retrieved
  *  E_FAIL otherwise
  */
  static HRESULT SubstituteWithContextChange(const CATPLMID & iPLMID, unsigned int iLast,const CATPLMID & iReplacement,CATPLMID & oReplaced);

  /**
  * Show the PLMID as string of hash keys
  * For debug purpose ONLY.
  * @param iPLMID
  *   The plmid
  * @param oDisplay
  *   The result
  * @return
  *   S_OK if success
  *   E_FAIL otherwise
  */
  static HRESULT ShowPathAsString(const CATPLMID &iPLMID, CATUnicodeString & oDisplay);

  //warning, this awful debug code returns E_FAIL
  static HRESULT GetAlias(const CATPLMID &iPLMID, CATUnicodeString &oAlias);

  static HRESULT GetEntityTag(const CATPLMID &iPLMID, CATUnicodeString &oTag);


};

#endif
