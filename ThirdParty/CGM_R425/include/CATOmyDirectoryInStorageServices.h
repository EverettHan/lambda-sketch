#ifndef CATOmyDirectoryInStorageServices_h
#define CATOmyDirectoryInStorageServices_h

/**
 * @level Protected
 * @usage U4
 */
#include "CATUnicodeString.h"
#include "IUnknown.h"
#include "CATLibEx.h"
#include "CATOMYBaseSession.h"

class CATStorage;
class CATStream;
class CATILockBytes2; 
class CATHashDico;
class ExportedByCATOMYBaseSession CATOmyDirectoryInStorageServices
{
public:
  /** 
  * Archive the content of a directory into a storage. Only the whole directory is archived,
  * including the directory itself (in opposition to archiving on ly its content)
  *
  * @param iFromDirectoryPath [in]
  *   The path to the directory to be archived
  * @param ioToStorage [out]
  *   The storage where to archive the data. It must be opened in readwrite mode and it is
  *   your responsability to close it after calling this method
  * @param iAlreadyOpenedFiles [in]
  *   A hash table containing the full path the already opened file as key and the corresponding ILockBytes2 as data.
  *   Only files are taken into account.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, E_* otherwise...
  *
  */
  static HRESULT ReplicateDirectoryToStorage(const CATUnicodeString & iFromDirectoryPath, CATStorage * ioToStorage,
    CATHashDico * iAlreadyOpenedFiles=NULL);

  /** 
  * Unarchive the content of a storage to a directory. The expected format is the one provided by ReplicateDirectoryToStorage.
  * Note that the given path should contain the the directory name corresponding to the given storage.
  *
  * @param iFromStorage [in]
  *   The storage where to find the data. It should be opened in read mode and it is your responsability to close it after
  *   calling this method.
  * @param iToDirectoryPath [out]
  *   The directory where to unpack the found data. If not existing, the target directory is created.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, E_* otherwise...
  *
  */
  static HRESULT ReplicateStorageToDirectory(CATStorage * iFromStorage, const CATUnicodeString & iToDirectoryPath);

  /** 
  * Replicates the content of a stream to a file
  *
  * @param iFromStream [in]
  *   The stream to extract
  * @param iToFilePath [in]
  *   The path where to put the result. If the file already exists, it will be overridden
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, E_* otherwise...
  *
  */
  static HRESULT ReplicateStreamToFile(CATStream * iFromStream, const CATUnicodeString & iToFilePath);

  /**
   * Empties the content of a storage.
   *
   * @param iStorage [in]
   *   The storage to clean
   *
   * @return
  *   <code>S_OK</code> if everything ran ok, E_* otherwise...
   */
  static HRESULT CleanStorage(CATStorage * iStorage);
};
#endif
