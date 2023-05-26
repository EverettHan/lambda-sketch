#ifndef CATDlgFileProtected_H
#define CATDlgFileProtected_H

#include "DI0PANV2.h"

class CATDlgFile;
class CATDlgStdFile;
#include "CATBoolean.h"

/**
 * This class provides access to non public API over CATDlgFile
 */
class ExportedByDI0PANV2 CATDlgFileProtected
{
public:
  /**
   * Request 
   * @param iFile
   * @param iBool 
   */
  static void IgnoreSetDirectory(CATDlgFile * iFile, CATBoolean iBool=FALSE);
  static void IgnoreSetDirectory(CATDlgStdFile * iFile, CATBoolean iBool=FALSE);
};

#endif
