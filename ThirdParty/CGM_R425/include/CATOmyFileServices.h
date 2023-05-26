#ifndef CATOmyFileServices_h
#define CATOmyFileServices_h

/**
* @level Private
* @usage U1
*/

#include "CATOMYBaseSession.h"
#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATUniStd.h"
#include "CATLibEx.h"
#include "CATOmxAutoPtr.h"
class CATDirEnt;
class CATILockBytes2;
/**
 * 
* Class representing a directory entry.
*/
class ExportedByCATOMYBaseSession OmyDirectoryEntry
{
public:
  OmyDirectoryEntry(CATDirEnt & iEntry);
  OmyDirectoryEntry(const CATUnicodeString & iPath);
  OmyDirectoryEntry(const CATUnicodeString & iDirPath, const CATUnicodeString & iName);

  const CATUnicodeString _Name;
  const CATUnicodeString _Path;

  CATBoolean CanBeAccessed(int iMode = F_OK) const;
  CATBoolean IsADirectory() const;
  int GetSizeOnDisk() const;

  HRESULT CopyToDir(const CATUnicodeString & iPathToDir) const;
  HRESULT Delete() const;
  HRESULT CreateAsDirectory() const;
  CATUnicodeString GetContainingDirectory() const;
};

/**
* Visitor class for directory parsing. If you want to benefit from the
* CATOmyFileServices::VisitDirectory method foe parssing a directory
* you must inherit from this class.
*
* Here is basic example that count the number of entries in directory
* class CountVisitor: public OmyDirectoryVisitor
* {
* public:
*   int _count;
*   CountVisitor():_count(0){}
*   HRESULT VisitDirectoryEntry(const OmyDirectoryEntry & iEntry)
*   {
*     ++_count;
*     return S_OK;
*   }
* };
*/
class ExportedByCATOMYBaseSession OmyDirectoryVisitor
{
public:
  /**
  * Method called on each directory entry found during parsing.
  * Expected return values:
  *   S_OK    : treatment is OK, parse can continue
  *   S_FALSE : treatment is OK, parse should stop
  *   E_*     : treatment is KO, parse will be done on every valid entries
  * This will be the global return of the VisitDirectory method
  */
  virtual HRESULT VisitDirectoryEntry(const OmyDirectoryEntry & iEntry) = 0;
  virtual ~OmyDirectoryVisitor() {};
};

class ExportedByCATOMYBaseSession OmyDirectoryEntryIterator
{
  CATDIR m_dir;
  CATOmxAutoPtr<OmyDirectoryEntry> m_cur;
public:
  OmyDirectoryEntryIterator(const CATUnicodeString & iPath);
  ~OmyDirectoryEntryIterator(); //Directory "closed" at this time
  //Stop as soon as you get null.
  OmyDirectoryEntry* Next();
};

class ExportedByCATOMYBaseSession CATOmyFileServices
{
public:

  /**
  * Non recursively parses the directory content (jumping over . and .. directories)
  * @returns: the result of the various call to iVisitor. Visit on the various directory entries, ie.:
  *   S_OK         : all treatments are OK, parse ended normally
  *   S_FALSE      : treatments are OK, parse didn't go to the end
  *   E_INVALIDARG : the directory doesn't exist or can't be parsed
  *   E_*          : a treatment is KO, parse didn't go to the end

  * To continue the previous example on the number of entries in a directory
  * int CountDirectoryEnries(const CATUnicodeString & iDirPath)
  * {
  *   CountVisitor countVisitor;
  *   if(FAILED(VisitDirectory(iDirPath,countVisitor)))
  *     return 0;
  *   else
  *     return countVisitor._count;
  * }
  */
  static HRESULT VisitDirectory(const CATUnicodeString & iPathToDir, OmyDirectoryVisitor & iVisitor);

  /**
  * Gives an estimation of the total size (in octet) of a file or a directory
  */
  static int GetSizeOnDisk(const CATUnicodeString & ichemin);

  /**
  * Copy a specific directory content to the given target directory.
  * If the target directory doesn't exist, it will be created.
  */
  static HRESULT CopyDirectoryContent(const CATUnicodeString & iPathToSourceDir,
                                      const CATUnicodeString & iPathToTargetDir);

                                    /**
                                     * Joins a directory path to a file or directory name.
                                     */
  static CATUnicodeString Join(const CATUnicodeString & iDirPath, const CATUnicodeString & iName);

  /**
   * Retrieves the last name of the given path.
   */
  static CATUnicodeString LastName(const CATUnicodeString & iPath);

  /**
   * Retrieves the path of the containing directory.
   */
  static CATUnicodeString DirPath(const CATUnicodeString & iPath);
  
/**
 * @brief 
 * Open and lock a file on disk, file must not be opened already
 * The file must be kept open to keep the lock .. you can close to unlock (and delete the file if requested)
 * @param iCachePath     The path of the file
 * @param oILB           The FileLockByte that can be used to write read and close (destroy if requested)
 * @param iDeleteOnClose Delete the file when closed
 * @return S_OK if locked correctly and E_FAIL if already locked
 */
  static HRESULT TryLockFile(const CATUnicodeString& lockFilePath,CATILockBytes2 *&oILB,CATBoolean iDeleteOnClose=FALSE);
};
#endif
