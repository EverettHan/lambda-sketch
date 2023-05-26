#ifndef CATComponentIdHashTable_H
#define CATComponentIdHashTable_H
/* -*-c++-*- */
/**
 * @level Protected
 * @usage U1       
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATComponentId;
class CATComponentIdHashTable;

/**
* HTable managing a couple (CID, optional applicative pointer)
*/
class ExportedByCATPLMTos CATComponentIdHashTable : public CATBaseUnknown
{
public:

  /**
  * Create the htable
  *
  * @param oTable [out, CATBaseUnknown#Release]
  *        The association table
  * @param iEstimatedPopulation
  *         Estimated number of associations 
  * @return
  *        S_OK    : succeeded
  *        E_FAIL  : Failure
  */
  static HRESULT Create (CATComponentIdHashTable *& oTable, int iEstimatedPopulation = 1024 );

  /**
  * Search if an identifier is already associated (by physical identifier)
  *
  * @param iHandle
  *        Component's handle
  * @param oPointer
  *        Associated pointer
  * @return
  *        S_OK    : Search succeeded
  *        S_FALSE : No result Found
  *        E_FAIL  : Failure
  */
  virtual  HRESULT SearchById (const CATComponentId & iHandle, CATUINTPTR & oPointer) const = 0;

  /**
  * Determines the number of entries in the Table
  *
  * @param oNumber
  *        Number of entries
  * @return
  *        S_OK   : succeeded
  *        E_FAIL : Failure
  */
  virtual  HRESULT Size(unsigned int & oNumber) const = 0;

  /**
  * Enumerate entries in the Table
  *
  * @param ioHiddenKey
  *   Internal Identifier (input-Ouput) for enumeration
  *   Start with ZERO (0) as initial first value
  * @param oHandle
  *        Component's handle
  * @param oPointer
  *        Associated pointer
  * @return
  *        S_OK   : Result found
  *        E_FAIL : End of Enumerate
  */
  virtual  HRESULT Next(unsigned int & ioHiddenKey, CATComponentId & oHandle, CATUINTPTR & oPointer ) const = 0;

  /**
  * Insert a couple in the Table   
  *
  * @param iHandle
  *        Component's handle
  * @param iPointer
  *        associated pointer
  * @param iKeepValueOnAlreadyInserted
  *        Keep value on already inserted
  *
  * @return
  *        S_OK   : Insertion done
  *        E_FAIL : If still inserted or failure
  */
  virtual  HRESULT Insert(const CATComponentId & iIdentifier, 
                          const CATUINTPTR iValue,
                          const CATBoolean iKeepValueOnAlreadyInserted = FALSE ) = 0;


  /**
  * Remove an identifier in the Table
  *
  * @param iIdentifier
  *   Value of identifier
  *
  * @return
  *        S_OK    : Remove done
  *        S_FALSE : No association found in Table
  *        E_FAIL  : Failure
  */
  virtual  HRESULT RemoveById(const CATComponentId &iIdentifier ) = 0;


  /**
  * Remove all identifiers in the Table
  *
  * @return
  *        S_OK    : Remove done
  *        S_FALSE : No association found in Table
  *        E_FAIL  : Failure
  */
  virtual  HRESULT RemoveAll() = 0; 
};

/**
* Create the htable
*
* @param oTable [out, CATBaseUnknown#Release]
*        The association table
* @param iEstimatedPopulation
*         Estimated number of associations 
*
* @return
*      S_OK     request succeeded <br>
*      E_FAIL   if request failed for unknown reason<br>
*/
extern ExportedByCATPLMTos \
HRESULT CATPLMCreateComponentIdHashTable(CATComponentIdHashTable  ** oTable, int iEstimatedPopulation = 1024 );

#endif
