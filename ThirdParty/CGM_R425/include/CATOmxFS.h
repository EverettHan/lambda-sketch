#ifndef CATOmxFS_H
#define CATOmxFS_H

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATUnicodeString.h"

/**
 * Several helpers for working with file system (alternative for CATLibEx.h and its zero documentation and awkward API)
 * What is not there:
 *  reading a text file: use CATOmxTextFileReader
 *  reading/writing binary files: use CATWOmxBinaryStream
 */
namespace CATOmxFS
{
  /**
   * Combine two paths adding required directory separator char (see CATOmxPortability.h: OMX_DIR_SEP_CHR or OMX_DIR_SEP_STR).
   * Alternative to CATMakePath
   *
   * CATOmxFS::Combine("dir","file") will return
   *   "dir/file" on unix
   *   "dir\file" on windows
   * CATOmxFS::Combine("dir/","file") will return
   *   "dir/file" on both unix and windows
   *   (contrarily to CATMakePath which would return "dir/\file" on windows)
   * CATOmxFS::Combine("","") will return
   *   "" on both unix and windows
   *   (contrarily to CATMakePath which would return "\" or "/")
   * CATOmxFS::Combine("","file") will return
   *   "file" on both unix and windows
   *   (contrarily to CATMakePath which would return "\file" or "/file")
   */
  ExportedByCATOmxKernel CATUnicodeString Combine(const CATUnicodeString& iPath1, const CATUnicodeString& iPath2);

  /** internal, do not use*/
  enum PathPart { ExtensionPart, FileNamePart, FileNameWithoutExtensionPart, DirectoryPart };
  ExportedByCATOmxKernel CATUnicodeString _GetPathPart(const CATUnicodeString& iPath, PathPart iPart);

  /**
   * Retrieve file extension
   *
   * GetExtension("file")          => ""
   * GetExtension("file.ext")      => "ext"
   * GetExtension("file.ext.1")    => "1"
   * GetExtension("dir/file.ext")  => "ext"
   * GetExtension("dir.ext1/file") => ""
   * GetExtension("")              => ""
   */
  inline CATUnicodeString GetExtension(const CATUnicodeString& iPath) { return _GetPathPart(iPath, ExtensionPart); }

  /**
   * Retrieve file "name"
   * Alternative to CATSplitPathEx
   *
   * GetFileName("file") => "file"
   * GetFileName("dir/file") => "file"
   * GetFileName("dir/") => ""
   */
  inline CATUnicodeString GetFileName(const CATUnicodeString& iPath) { return _GetPathPart(iPath, FileNamePart); }

  /**
  * Same as GetFileName but extension is trimmed
  *
  * GetFileNameWithoutExtension("file.ext") => "file"
  * GetFileName("dir/file.ext") => "file"
  * GetFileName("dir/") => ""
  * GetFileName(".ext") => "ext"
  */
  inline CATUnicodeString GetFileNameWithoutExtension(const CATUnicodeString& iPath) { return _GetPathPart(iPath, FileNameWithoutExtensionPart); }

  /**
  * Retrieve directory path of a path (opposite of GetFileName)
  *
  * examples:
  *   GetDirectory("file.ext") => ""
  *   GetDirectory("dir/file.ext") => "dir"
  *   GetDirectory("dir/") => "dir"
  *   GetDirectory("dir1/dir2/file") => "dir1/dir2"
  *
  * specific case:
  *   GetDirectory("/") => "/"
  *
  * windows only
  *   GetDirectory("C:\\windows") => "C:\\"
  */
  inline CATUnicodeString GetDirectory(const CATUnicodeString& iPath) { return _GetPathPart(iPath, DirectoryPart); }

  /**
  * Change extension of a path (see GetExtension)
  * Notice that
  *   ChangeExtension("file","ext") => "file" (there was no extension, extension has not been added)
  *   ChangeExtension("file.ext","") => "file" (extension has been removed)
  *   ChangeExtension("dir.ext/","") => "dir.ext/" (there was no extension, extension has not been added)
  */
  ExportedByCATOmxKernel CATUnicodeString ChangeExtension(const CATUnicodeString& iPath, const CATUnicodeString& iExtension);

  struct DirectoryReaderImpl;

  /**
   * Helper for scanning the content of a directory
   * Alternative to CATOpenDirectory/CATReadDirectory/CATCloseDirectory
   *
   * Windows specific:
   *   MAX_PATH limitations are bypassed
   *   Filtering on file extension or selecting only files should be more efficient than with CATOpenDirectory
   *
   * Notice that:
   *   undocumented/unspecified behaviors of CATOpenDirectory are inherited (for instance "DL names", http URLs)
   *   unlike CATOpenDirectory, "." and ".." entries are never returned
   *
   * Usage:
   *   DirectoryReader dir("e:/tmp/dir");
   *   HRESULT hr;
   *   CATUnicodeString entryName;
   *   while(S_OK = (hr = dir.Next(entryName) ))
   *   {
   *     //work with entryName which is a "file name" and not an absolute path
   *   }
   *   if(FAILED(hr)) {}
   *
   * In order to retrieve absolute path of files (not directories) having extension "ext":
   *   DirectoryReader dir("e:/tmp/dir");
   *   dir.SelectExtension("ext")                  //select extension "ext" (case insensitive)
   *      .SetMode(DirectoryReader::FileOnly)      //discard directories
   *      .SetMode(DirectoryReader::AbsolutePath); //retrieve absolute path (instead of default: name relative to directory)
   *   HRESULT hr;
   *   CATUnicodeString entryName;
   *   while(S_OK = (hr = dir.Next(entryName) ))
   *   {
   *     //work with entryName which is an absolute path of a file which extension is "ext"
   *   }
   *   if(FAILED(hr)) {}
   */
  class ExportedByCATOmxKernel DirectoryReader
  {
    DirectoryReaderImpl& m_impl;
  public:
    /** build object */
    DirectoryReader(const CATUnicodeString& iDir);

#ifdef _WINDOWS_SOURCE
#define OMX_FS_CASE_SENSITIVE false
#else
#define OMX_FS_CASE_SENSITIVE true
#endif
    /** select an extension (for files OR directories), you can select only ONE extension*/
    DirectoryReader& SelectExtension(const CATUnicodeString& iExtension, bool iCaseSensitive = OMX_FS_CASE_SENSITIVE);

    enum Mode
    {
      FileOnly = 1,      //discard directories
      DirectoryOnly = 2, //discard files
      AbsolutePath = 4,  //retrieve absolute path
    };
    /** Activate one of the previous modes*/
    DirectoryReader& SetMode(DirectoryReader::Mode iMode);

    /**
     * retrieve next entry name (relative path by default)
     * @return:
     *   S_OK: a matching entry has been found
     *   S_FALSE: no more entries
     *   E_XXX: failure, notice the HRESULT might be inaccurate (eg, CATLIBHRESULT(ERROR_FILE_NOT_FOUND) instead of CATLIBHRESULT(PATH_FILE_NOT_FOUND))
     */
    HRESULT Next(CATUnicodeString& oName);

    /** destructor */
    ~DirectoryReader();
  private:
    DirectoryReader();
    DirectoryReader(const DirectoryReader&);
    DirectoryReader& operator=(const DirectoryReader&);
  };
}


#endif
