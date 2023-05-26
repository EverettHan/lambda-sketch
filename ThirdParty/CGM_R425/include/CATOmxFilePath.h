/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */
#ifndef __CATOmxFilePath_h__
#define __CATOmxFilePath_h__

// System
#include "CATLibEx.h"
// ObjectModelerCollection
#include "CATOmxKernel.h"
#include "CATOmxUTF8String.h"
ExportedByCATOmxKernel HRESULT CATFileAccess(const CATOmxUTF8String &iFileName,int iMod);
class CATOmxAny;

struct ExportedByCATOmxKernel CATOmxFilePath 
{
  CATOmxUTF8String FileName;  // FileName = Directory '/' + BaseName
  CATOmxUTF8String Directory; // 
  CATOmxUTF8String BaseName;  // = Radical '.' Extension
  CATOmxUTF8String Radical;
  CATOmxUTF8String Extension;

  inline CATOmxFilePath() {}
  inline CATOmxFilePath(const CATOmxUTF8String & iFileName) { Set(iFileName); }

  void Set(const CATOmxUTF8String & iFileName);
  HRESULT Set(const CATOmxAny & iFileName);
  
  inline CATBoolean Exists() const { return CATFileAccess(FileName, F_OK) == CATLibSuccess; }
  CATBoolean IsWritable() const;
  inline bool IsReadable() const { return CATFileAccess(FileName, R_OK) == CATLibSuccess; }
  inline bool IsOsm() const { return 0 != (Extension == "osm"); }
  inline bool IsCatalog() const { return Extension == "feat" || Extension == "CATfct"; }

  /**
   * build from Directory Radical and Extension
   * Directory + '/' + Radical + '.' + Extension.
   * @param iCanonical if true '/' is replaced by '\' on windows
   */
  CATOmxUTF8String Build(CATBoolean iCanonical=TRUE); 
  
  /**
   * use iPath as locator concatenation to locate first file
   *  (foreach PATH)/Radical'.'Extension stop on first existing file.
   * @param iConcat environment variable
   */
  CATBoolean FindPath(const CATOmxUTF8String &iConcat);
  /**
   * use iPath as locator concatenation to locate first file
   *  (foreach PATH)/Radical'.'Extension stop on first existing file.
   * @param iEnv environment variable
   * @param iRelativePath the relative path
   */
  CATBoolean BuildRelativePath(const CATOmxUTF8String &iConcat,const char *iRelativePath);
  /**
   * Remove FileName.
   * @return true on sucess 
   */
  CATBoolean Delete();
public:
  void ExtractNameAndExtensionFromDocumentName();
  HRESULT SetAbsolutePath();
};
#endif
