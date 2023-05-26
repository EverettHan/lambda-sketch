
#ifndef __CATOmxBase64Converter_h__
#define __CATOmxBase64Converter_h__


/**
 * @level Protected
 * @usage U1
 */
 
#include "CATOmxKernel.h"
#include <stdlib.h>

namespace CATOmx {
  /** 
   * Convert a bytes array into a Base64 encoded string.
   * @param iBytes the input byte array.
   * @param iBytesSize the input byte array Size.
   * @param oBase64String the output string, MUST be AT LEAST (((iBytesSize + 2) / 3) * 4 + 1) bytes long.
   * @return the number of written bytes (or -1 if failed).
   */
  ExportedByCATOmxKernel int BytesToBase64Here(const unsigned char iBytes[], size_t iBytesSize, char oBase64String[]);

  /**
   * Convert a bytes array into a Base64 encoded string.
   * @param iBytes the input byte array.
   * @param iBytesSize the input byte array Size.
   * @return a malloc'd string.
   */
  ExportedByCATOmxKernel const char * BytesToBase64(const unsigned char iBytes[], size_t iBytesSize);
}


#endif // __CATOmxBase64Converter_h__
