#ifndef  __CATOMYDBAbstractionServices
#define  __CATOMYDBAbstractionServices

/**
* @level Protected
* @usage U3
*/
#include "ObjectModelerSystem.h"

#include "CATUnicodeString.h"
#include "CATBoolean.h"

/**
 * Helper class for PLM basic operations.
 */
class ExportedByObjectModelerSystem CATOMYDBAbstractionServices
{
public:
  /**
  * Returns a string representing a float in C locale.
  * FLOAT precision used to store the double :int dig =7, int prec = 7
  * @param iDouble
  *  The double to convert to string.
  * @param oString
  *  The output string encoded in C locale. Empty string if service fails.
  *  At least 0 if service succeeds.
  * @return
  *  S_OK: The conversion was OK.
  *  E_FAIL: The conversion failed.
  */
  //static HRESULT GetCEncodedFloat (double iDouble, CATUnicodeString &oString);

  /**
  * Returns a string representing a double in C locale.
  * MAXIMUM precision used to store the double :int dig =15, int prec = 15
  * @param iDouble
  *  The double to convert to string.
  * @param oString
  *  The output string encoded in C locale. Empty string if service fails.
  *  At least 0 if service succeeds.
  * @return
  *  S_OK: The conversion was OK.
  *  E_FAIL: The conversion failed.
  */
  static HRESULT GetCEncodedDouble(double iDouble, CATUnicodeString &oString);

  /**
  * Gets a double from a string representing a double in C charset.
  * The string must be like "234234523452345.12313e-10".
  * @param iString
  *  The string to convert to double.
  * @param oDouble
  *  The output double if the string is correct.
  * @return
  *  S_OK: The string has been correctly converted to double.
  *  E_FAIL: The string can't be converted to double.
  */
  static HRESULT GetDoubleFromCEncodedString(const CATUnicodeString &iString, double &oDouble);

  /*
   * If maxUlps=1, we accept difference only on 1 bit (<=> best precision int dig = 15, int prec = 15).
  */
  static CATBoolean IsAlmostEqual(double A, double B, int maxUlps = 1);

private:
  /*
   *@deprecated
  */
  static HRESULT _DeprecatedGetCEncodedDouble(double iDouble, CATUnicodeString &oString, char *format);
};

#endif
