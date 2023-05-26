/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxHexConverter_h__
#define __CATOmxHexConverter_h__
#include "CATOmxKernel.h"
#include "CATOmxPortability.h"

class CATUuid;
class CATBinary;
class CATUnicodeString;

namespace CATOmx {

  /**Use lower characters in hexadecimal output*/
#define OMX_HEX_LOWER 0x10

  /**
   * Convert a bytes array into hex strings.
   * @param iBytes the input byte array
   * @param iBytesLg the input byte length
   * @param oHex the output string
   * @param oHexLg the output length
   * @param iFlags: @see OMX_HEX_XXX flags
   * @return the number of written bytes (or -1 if failed)
   */
  ExportedByCATOmxKernel int BytesToHex(const unsigned char iBytes[], int iBytesLg, char oHex[], int oHexLg, unsigned int iFlags = 0);
  /** Convert an hex string into a bytes array.
   * @param iHex the input hex string
   * @param iHexLg the input hex string length
   * @param oBytes the converted output buffer
   * @param oBytesLg the converted output buffer leng
   * @param iFlags: reserved for future usage
   * @return the number of written bytes (or -1 if failed)
   */
  ExportedByCATOmxKernel int HexToBytes(const char iHex[], int iHexLg, unsigned char oBytes[], int oBytesLg, unsigned int iFlags = 0);
  /** Convert an uuid into a hex strings.
   * @param iUuid the uuid to convert
   * @param oHex the output string
   * @param oHexLg the output length
   * @param iFlags: @see OMX_HEX_XXX flags
   * @return the number of written bytes (or -1 if failed)
   */
  ExportedByCATOmxKernel int UuidToHex(const CATUuid & iUuid, char oHex[], int oHexLg, unsigned int iFlags = 0);
  ExportedByCATOmxKernel CATUnicodeString UuidToHex(const CATUuid & iUuid, unsigned int iFlags = 0);
  /** Convert an hex string into an uuid.
   * @param iHex the input hex string
   * @param iHexLg the input hex string length
   * @param oUuid the converted uuid
   * @param iFlags: reserved for future usage
   * @return the number of written bytes (or -1 if failed)
   */
  ExportedByCATOmxKernel int HexToUuid(const char iHex[], int iHexLg, CATUuid & oUuid, unsigned int iFlags = 0);
  /**
  * warning, this one returns an HRESULT
  */
  ExportedByCATOmxKernel HRESULT HexToUuid(const CATUnicodeString& iHex, CATUuid & oUuid, unsigned int iFlags = 0);

  /**
   * Convert a string-slice containing an optionally dashed hexadecimal string.
   * @param oTarget the resulting binary
   * @param oTargetLen the maximal number of byte
   * @param iHexString the hexadecimal string (Warning: invalid chars are skipped)
   * @param iHexStringLen the hexadecimal string len
   * @return the number of converted bytes
   */
  ExportedByCATOmxKernel int MapBinary(unsigned char *oTarget, int oTargetLen, const char *iHexString, int iHexStringLen);

  /**Convert an hexadecimal string to a CATBinary, CAN FAIL*/
  ExportedByCATOmxKernel HRESULT HexToBinary(const char* str, CATBinary& oBinary, unsigned int iFlags = 0);
  /**Convert a binary buffer to an hexadecimal string*/
  ExportedByCATOmxKernel CATUnicodeString BytesToHex(const void* iBytes, size_t iLen, unsigned int iFlags = 0);
  /**Convert a binary buffer to an hexadecimal string*/
  ExportedByCATOmxKernel CATUnicodeString BinaryToHex(const CATBinary& iBinary, unsigned int iFlags = 0);
}
#endif
