/**
 * @level Private
 * @usage U1
 */

#ifndef CATPLMVariantHelpers_H
#define CATPLMVariantHelpers_H

#include "CATPLMServicesItf.h"

#include "AttrTypes.h"

#include "CATBoolean.h"
#include "CATListOfDouble.h"
#include "CATSysErrorDef.h"
#include "CATVariant.h"
#include "CATListOfInt.h"
#include "CATBinary.h"
#include "CATOmxArray.h"

typedef HRESULT (*pMarshallBinaryFunc)(const CATBinary & iData,CATUnicodeString& oMarshalledBin);

typedef CATUnicodeString (*pMarshallBinaryFunc2)(const CATBinary & iData);

class CATString;
class CATUnicodeString;
class CATTime;
class CATBinary;
class CATPLMID;
#include "CATCollec.h"
class CATLISTV(CATPLMID);
class CATPLMID_Simple;
class CATLISTV(CATBoolean);
class CATLISTV(CATBinary);
class CATLISTV(CATUnicodeString);
class CATLISTV(CATTime);
class CATOmxAny;

class ExportedByCATPLMServicesItf CATPLMVariantHelpers
{
  friend class CATPLMFilterAttribute;
public:
  enum Type{
      integer_val,
      double_val,
      string_val,
      time_val,
      binary_val,
      boolean_val,
      userdefined_val,
      undefined};

  static void Init(CATVariant& oVariant);

  static void Clear(CATVariant& iVariant);

  static CATPLMVariantHelpers::Type GetType(const CATVariant& iVariant);

  static AttrTypes GetAttrType(const CATVariant& iVariant);

  /**
   * @href CATPLMVariantHelpers#GetSize
   */
  static HRESULT GetSize(const CATVariant& iVariant,unsigned int & oSize);

  /**
   * @href CATPLMVariantHelpers#IsMulti
   */
  static CATBoolean IsMulti(const CATVariant& iVariant);

  /**
   * @href CATPLMVariantHelpers#GetIntValue
   */
  static HRESULT GetIntValue(const CATVariant& iVariant,int & oValue, unsigned int index=1);

  /**
  * @href CATPLMVariantHelpers#GetIntValue
  */
  static HRESULT GetIntValue(const CATVariant& iVariant,CATListOfInt& oValues);

  /**
   * @href CATPLMVariantHelpers#GetDoubleValue
   */
  static HRESULT GetDoubleValue(const CATVariant& iVariant,double & oValue, unsigned int index=1);

  /**
   * @href CATPLMVariantHelpers#GetDoubleValue
   */
  static HRESULT GetDoubleValue(const CATVariant& iVariant,CATListOfDouble& oValues);

  /**
   * @href CATPLMVariantHelpers#GetStringValue
   */
  static HRESULT GetStringValue(const CATVariant& iVariant,CATUnicodeString & oValue, unsigned int index=1);

  /**
   * @href CATPLMVariantHelpers#GetStringValue
   */
  static HRESULT GetStringValue(const CATVariant& iVariant,CATListOfCATUnicodeString & oValues);

  /**
   * @href CATPLMVariantHelpers#GetTimeValue
   */
  static HRESULT GetTimeValue(const CATVariant& iVariant,CATTime & oValue, unsigned int index=1);

  /**
   * @href CATPLMVariantHelpers#GetTimeValue
   */
  static HRESULT GetTimeValue(const CATVariant& iVariant,CATLISTV(CATTime)& oValues);

  /**
   * @href CATPLMVariantHelpers#GetBinaryValue
   */
  // Have a look to CATPLMDataSetQueryAttrRead::GetVariantValue() when CATPLMAdpAPIMigration::CATVariantMigration() is activated: An horrible _pListBinToDelete is kept...
  // Same thing made in CATPLMValue::SetValue(const CATBinary &iValue) with _binary data member
  static HRESULT GetBinaryValue(const CATVariant& iVariant,CATBinary & oValue, unsigned int index=1);

  /**
   * @href CATPLMVariantHelpers#GetBinaryValue
   */
  static HRESULT GetBinaryValue(const CATVariant& iVariant,CATLISTV(CATBinary)& oValues);

  /**
   * @href CATPLMVariantHelpers#GetBooleanValue
   */
  static HRESULT GetBooleanValue(const CATVariant& iVariant,CATBoolean & oValue, unsigned int index=1);

  /**
   * @href CATPLMVariantHelpers#GetBooleanValue
   */
  static HRESULT GetBooleanValue(const CATVariant& iVariant,CATLISTV(CATBoolean)& oValues);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const int iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATListOfInt &iValue,CATVariant& oVariant);
  static HRESULT SetValue(const CATOmxArray<int>& iValue, CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const double iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATListOfDouble &iValue,CATVariant& oVariant);
  static HRESULT SetValue(const CATOmxArray<double>& iValue, CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATUnicodeString & iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATListOfCATUnicodeString &iValue,CATVariant& oVariant);

  /**
  * @href CATPLMVariantHelpers@SetValue
  */
  static HRESULT SetValue(const CATOmxArray<CATUnicodeString> &iValue, CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATTime &iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATLISTV(CATTime) &iValue,CATVariant& oVariant);
  static HRESULT SetValue(const CATOmxArray<CATTime>& iValue, CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  // Have a look to CATPLMDataSetQueryAttrRead::GetVariantValue() when CATPLMAdpAPIMigration::CATVariantMigration() is activated: An horrible _pListBinToDelete is kept...
  // Same thing made in CATPLMValue::SetValue(const CATBinary &iValue) with _binary data member
  static HRESULT SetValue(const CATBinary &iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATLISTV(CATBinary) &iValue,CATVariant& oVariant);
  static HRESULT SetValue(const CATOmxArray<CATBinary>& iValue, CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATBoolean &iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT SetValue(const CATLISTV(CATBoolean) &iValue,CATVariant& oVariant);
  static HRESULT SetValue(const CATOmxArray<CATBoolean>& iValue, CATVariant& oVariant);

   /**
    * @href CATPLMVariantHelpers@SetPhysicalId
    */
  static HRESULT SetPhysicalId(const CATPLMID& iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetListOfPhysicalId
   */
  static HRESULT SetListOfPhysicalId(const CATLISTV(CATPLMID)& ilValue,CATVariant& oVariant);

   /**
    * @href CATPLMVariantHelpers@SetLogicalId
    */
  static HRESULT SetLogicalId(const CATPLMID& iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetListOfLogicalId
   */
  static HRESULT SetListOfLogicalId(const CATLISTV(CATPLMID)& ilValue,CATVariant& oVariant);

     /**
    * @href CATPLMVariantHelpers@SetMajorId
    */
  static HRESULT SetMajorId(const CATPLMID& iValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetListOfMajorId
   */
  static HRESULT SetListOfMajorId(const CATLISTV(CATPLMID)& ilValue,CATVariant& oVariant);

  /**
   * @href CATPLMVariantHelpers@SetValue
   */
  static HRESULT Copy(const CATVariant &iValue,CATVariant& oVariant);
  static HRESULT SetValue(const CATVariant &iValue,CATVariant& oVariant);

  /**
   * Returns the value as a string
   * the format can not be guaranted nor be readable.
   * for binary, need to specify the pointeur of function else we fail.
   * Use for debug only!!! Use for debug only!!! Use for debug only!!!
   */
  //HRESULT CATPLMBinaryHelpers::GetHexaName
  static HRESULT AsString(const CATVariant& iVariant,CATUnicodeString & oString,pMarshallBinaryFunc iMyFunc=NULL);

  static HRESULT AsString(const CATVariant& iVariant, CATLISTV(CATUnicodeString)& oListString,pMarshallBinaryFunc2 iMyFunc=NULL);

  /**
   * @deprecated
   */
  static HRESULT IsMultiValuated(const CATVariant& iVariant) ;

private:
  static HRESULT _AsString(const CATVariant& iVariant, CATUnicodeString& oString, pMarshallBinaryFunc2 iMyFunc = NULL);

  static HRESULT _GetSimplePlmid(const CATPLMID& iPlmid,CATPLMID_Simple& oPlmidSimple);
};

#endif
