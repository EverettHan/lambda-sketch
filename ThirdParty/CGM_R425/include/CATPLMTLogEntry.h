// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATPLMTLogEntry.h
// Define the CATPLMTLogEntry interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMTLogEntry_H
#define CATPLMTLogEntry_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATOmxOMap.h"
#include "CATDataType.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATSysErrorDef.h"

class CATOmxAny;
class CATUnicodeString;
class CATPLMID;
class CATTime;

class ExportedByCATPLMServicesItf CATPLMTLogEntry: public CATBaseUnknown
{
  friend class xMQLTLogEntriesWriter;
public:
  virtual ~CATPLMTLogEntry();

  /**
  * Get the number of data inside the log entry.
  * @return
  *    Number of data.
  */
  int GetNbData();

  /**
  * Get an allready added data.
  * @param iIndice
  *   Indice of the desired data.
  *   From 0 to GetNbData()-1
  * @param oKey
  *   The data identification key.
  * @param oValue
  *   The data value.
  * @return
  *    S_OK  : Data correctly returned.
  *    E_FAIL: Otherwise.
  */
  HRESULT GetData(int iIndice, const char *&oKey, CATOmxAny &oValue);

  HRESULT GetData(int iIndice, CATUnicodeString& oKey, CATOmxAny &oValue);

  HRESULT GetValue(const CATOmxKeyString& iKey,CATOmxAny& oValue);

  CATBoolean KeyExists(const CATOmxKeyString &iKey);

  /**
  * Key used to order log entries inside a save transaction.
  * If not used, log entries are order the way they are added to the save transaction.
  * Log entries will be ordered from lowest to highest value.
  * @param iKey
  *   Any non null value.
  */
  void SetOrderingKey(unsigned int iKey);

  /**
  * Key used to order log entries inside a save transaction.
  * If not used, log entries are order the way they are added to the save transaction.
  * Log entries will be ordered from lowest to highest value.
  * @return
  *   Oredering key.
  */
  unsigned int GetOrderingKey() const;

protected:
  CATPLMTLogEntry();

  HRESULT AddData(const char *iKey,const CATPLMID &iValue);
  HRESULT AddData(const char *iKey,const CATTime &iValue);
  HRESULT AddData(const char *iKey,const CATUnicodeString &iValue);
  HRESULT AddData(const char *iKey,int iValue);
  HRESULT AddDataAny(const char *iKey,const CATOmxAny &iValue);

private:
  CATOmxKeyValueBlock _kvb;
  CATOmxOMap<int,CATOmxKeyString> _mPosToKey;
  int _Pos;
  //CATOmxArray<CATUnicodeString> keys;
  //CATOmxArray<CATOmxAny> values;
  unsigned int orderKey;
};


// Clean previous functions requests
#include "CATLISTP_Clean.h"

// Required functions
/** @nodoc INTERNAL */
#define CATLISTP_Append
#define CATLISTP_Size
#define CATLISTP_InsertAt
#define CATLISTP_RemoveAll

// Get macros
// Generate interface of collection-class
#include "CATLISTP_Declare.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMServicesItf
CATLISTP_DECLARE(CATPLMTLogEntry)

  // Typedef declaration for users easy identification.
  typedef CATLISTP(CATPLMTLogEntry) CATListPtrCATPLMTLogEntry;

#endif
