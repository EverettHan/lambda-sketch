#ifndef CATOmbImportExportParameters_H
#define CATOmbImportExportParameters_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATOmbImportExport.h"
#include "CATOmxOHMap.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATBaseUnknown.h"


class CATUnicodeString;
class CATListValCATUnicodeString;
class CATOmxKeyValueBlock;

/**
 * 
 */
class ExportedByCATOmbImportExport CATOmbImportExportParameters: public CATBaseUnknown
{

  public:
  
  /**
   * Constructor
   */
  CATOmbImportExportParameters();

  /**
   * Destructor
   */
  virtual ~CATOmbImportExportParameters();

  /**
   * Declares a Parameter and its value
   * @param iParameterName
   * The Parameter Name
   * @param iValue
   * The  Value
   * @return
   * S_OK if it has been added , 
   * S_FALSE Parameter already exist and has been replaced 
   * E_INVALIDARG if iParameterName nor valuated
   * otherwise E_FAIL if it has failed.
   */
  HRESULT RegisterParameter(const CATUnicodeString& iParameterName,const CATUnicodeString& iValue);
  /**
   * Declares a Parameter and its value
   * @param iParameterName
   * The Parameter Name
   * @param iValue
   * The  Value
   * @return
   * S_OK if it has been added , 
   * S_FALSE Parameter already exist and has been replaced 
   * E_INVALIDARG if iParameterName not valuated or one of the reserved names: "EXPORT_STATUS", "CATOmbRole"
   * otherwise E_FAIL if it has failed.
   */
  HRESULT RegisterAnyParameter(const CATUnicodeString& iParameterName,CATOmxAny iValue);
  /**
   * Return the value of a Parameter
   * @param iParameterName
   * The Parameter Name
   * @param oValue
   * The returned Value
   * @return
   * S_OK if it all OK  
   * E_INVALIDARG if iParameterName  not valuated or one of the reserved names: "EXPORT_STATUS", "CATOmbRole"
   * E_FAIL if it has failed or if the parameter doesn't exist..
   */
  HRESULT GetParameterValue(const CATUnicodeString& iParameterName, CATUnicodeString& oValue) const;
  /**
   * Return the value of a Parameter
   * @param iParameterName
   * The Parameter Name
   * @param oValue
   * The returned Value
   * @return
   * S_OK if it all OK  
   * E_INVALIDARG if iParameterName nor valuated
   * E_FAIL if it has failed or if the parameter doesn't exist..
   */
  HRESULT GetAnyParameterValue(const CATUnicodeString& iParameterName, CATOmxAny& oValue) const;

  /**
   * List Parameters Name
   * @return
   * S_OK if it all OK  
   * E_FAIL if it has failed.
   */
  HRESULT ListParametersName(CATListValCATUnicodeString& oParametersName); 

  /**
   * Return an iterator on all registered parameters
   * @return
   *  the iterator
   */
  CATOmxArray<CATUnicodeString> ListParameterKeys();

  int GetParameterListSize();

  HRESULT ExportToKeyValueBlock(CATOmxKeyValueBlock& oBlock);

  /**
  * return TRUE if the 2 objects contains exactly the same parameter couples key/value
  * else it will return FALSE
  */
  CATBoolean operator==(const CATOmbImportExportParameters& iArg) const;
  CATBoolean operator!=(const CATOmbImportExportParameters& iArg) const;

  private :
	CATOmxOHMap<CATUnicodeString,CATOmxAny> _Table;

  CATOmbImportExportParameters(const CATOmbImportExportParameters &iObject); // Prohibited
  CATOmbImportExportParameters &operator=(const CATOmbImportExportParameters &iObject); // Prohibited
};

#endif
