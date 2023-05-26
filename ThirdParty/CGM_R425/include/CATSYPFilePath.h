#ifndef CATSYPFilePath_H
#define CATSYPFilePath_H

#include <UIVCoreTools.h>
#include <CATUnicodeString.h>

class CATSYPFilePath;
#define CATLISTV_Append
#define CATLISTV_QuickSort
#define CATLISTV_RemoveAll
#define CATLISTV_RemovePosition
#include <CATLISTV_Declare.h>
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByUIVCoreTools
CATLISTV_DECLARE(CATSYPFilePath)
typedef CATLISTV(CATSYPFilePath) CATListOfCATSYPFilePath;
#undef CATCOLLEC_ExportedBy

/**
 * A String class for file (or directory) names manipulation.
 * CATSYPFilePath is only a handler on a string buffer with a reference counter.
 * Because of this <b>it is more safe an efficient to use this object by value
 * instead of by pointers</b>.<p>
 * A cast operator exist to (const char *) so that you can use CATSYPFilePath instances
 * in place of const char * strings.<p>
 * This class manage translation of / and \ to operating system file separator.
 * + and += operator exist to add names, a file separator is inserted.<p>
 * Sample of code for filename generation :
 *<pre> CATSYPFilePath filename( "directory/filename" );
 *     => "directory/filename" on Unix, "directory\filename" on NT
 * CATSYPFilePath path= filename.dirname();
 *     => "directory"
 * CATSYPFilePath name= filename.basename();
 *     => "filename"
 * CATSYPFilePath filename2= path+name;
 *     => "directory/filename" on Unix, "directory\filename" on NT</pre>
 *
 **/
class ExportedByUIVCoreTools CATSYPFilePath : public CATUnicodeString
{
public:
  /**
   * Search in path concatenation
   **/
  static CATSYPFilePath Search(const CATSYPFilePath &iPath, const char *iPathList = NULL);
  /**
   * Default constructor.
   **/
  CATSYPFilePath(void);
  /**
   * Constructor from a CATString (CATString is a macro on CATString).<p>
   * / and \ are translated to current operating system file separator.
   **/
  CATSYPFilePath(CATString iPath);
  /**
   * Constructor from a CATUnicodeString.<p>
   * / and \ are translated to current operating system file separator.
   **/
  CATSYPFilePath(const CATUnicodeString &iPath);
  /**
   * Constructor from a const char *, null terminated string.<p>
   * / and \ are translated to current operating system file separator.
   **/
  CATSYPFilePath(const char *iPath);
  /**
   * Copy constructor.
   **/
  CATSYPFilePath(const CATSYPFilePath &iFileName);
  /**
   * Destructor
   **/
  virtual ~CATSYPFilePath(void);
  /**
   * Get current working directory.
   **/
  static CATSYPFilePath GetWorkDir(void);
  /**
   * Generate a temporary and unique file name
   **/
  static CATSYPFilePath GetTemporaryFileName(void);
  /**
   * Compare two CATSYPFilePath instances.<p>Same return value than strncmp.
   **/
  static int Compare(CATSYPFilePath *iFile1, CATSYPFilePath *iFile2);
  /**
   * Change current working directory.
   **/
  static int SetWorkDir(const CATSYPFilePath &iPath);
  /**
   * Create a directory.
   **/
  int CreateDirectory(void);
  /**
   * Create a directory and all its fathers as requiered (same as mkdir -p).
   **/
  int CreateRecursiveDirectory(void);
  /**
   * Test is filename correspond to an existing file.
   **/
  int IsFile(void) const;
  /**
   * Test is filename correspond to a read-only file.
   **/
  int IsReadOnly(void) const;
  /**
   * Test is filename correspond to an existing directory.
   **/
  int IsDirectory(void) const;
  /**
   * Compare to another filename.<p>
   * This method returns 1 if filenames are the same, 0 otherwise.
   **/
  int IsEqual(const CATSYPFilePath &iFileName) const;
  /**
   * Test if the filename is under 'iPath' directory.
   **/
  int IsUnderDirectory(const CATSYPFilePath &iPath);
  /**
   * Convert filename to its full path and name.<p>
   * If the object correpond to a relative path it is transleted to an absolut
   * path and name.
   **/
  CATSYPFilePath GetFullPath(void);
  /**
   * Get file size in bytes.
   **/
  int GetFileSize(void);
  /**
   * Get file timestamp
   **/
  CATLONG32 GetTime(void);
  /**
   * Get the name part of the filename.<p>
   * This method returns the 'end' of the filename.
   * Optional parameter iN can be used to get the name part of one of the file name
   * parent directory.<p>
   * For <code>Dir4/Dir3/Dir2/Name<code> :<br>
   * basename() = 'Name'<br>
   * basename(1) = 'Name'<br>
   * basename(2) = 'Dir2'<br>
   * basename(3) = 'Dir3'<br>
   * basename(4) = 'Dir4'<br>
   **/
  CATSYPFilePath basename(int iN = 1) const;
  /**
   * Get the parent directory path of the filename.<p>
   * Optional parameter iN can be use to get the directory of one of the parent
   * directories.<p>
   * For <code>Dir3/Dir2/Dir1/Name</code> :<br>
   * dirname() = 'Dir3/Dir2/Dir1'<br>
   * dirname(1) = 'Dir3/Dir2/Dir1'<br>
   * dirname(2) = 'Dir3/Dir2'<br>
   * dirname(3) = 'Dir3'<br>
   **/
  CATSYPFilePath dirname(int iN = 1) const;

  /**
   * Test filename extension.<p>
   * This method returns 1 if file extension is 'iExtension', 0 otherwise.
   **/
  int        HasExtension(const char *iExtension) const;
  /**
   * Get filename extension.<p>
   **/
  CATString   GetExtension(void) const;
  /**
   * Add a filename extension.<p>
   **/
  void       AddExtension(CATString iExtension);
  /**
   * Set the filename extension.<p>
   **/
  void       SetExtension(CATString iExtension);
  /**
   * Set file modification time to reference modification time
   **/
  void SetTime(const CATSYPFilePath &iReference);
  /**
   * Compare file modification time to reference modification time
   **/
  int CompareTime(const CATSYPFilePath &iReference) const;
  /**
   * Add execution right to the file
   **/
  void SetAsExecutable(void);
  /**
   * Remove the file
   **/
  int Delete(void);
  /**
   * Cast operator to const char *.
   **/
  operator const char * () const;
  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   **/
  CATSYPFilePath operator + (const char *)     const;
  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   **/
  CATSYPFilePath operator + (const CATString &) const;
  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   **/
  CATSYPFilePath operator + (const CATUnicodeString &) const;
  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   **/
  CATSYPFilePath operator + (const CATSYPFilePath &) const;
  /**
   * += operator. Added names are separeted by / or \ depending on operating system.
   **/
  CATSYPFilePath & operator += (const char *);
  CATSYPFilePath & operator = (const char *);
  CATSYPFilePath & operator = (const CATString &);
  CATSYPFilePath & operator = (const CATUnicodeString &);
  CATSYPFilePath & operator = (const CATSYPFilePath &);
  int operator == (const char *string) const;
  int operator != (const char *string) const;
  int operator == (const CATSYPFilePath &ref) const;
  int operator != (const CATSYPFilePath &ref) const;

  /**
   * Get list of files matching a pattern
   **/
  int ReadDirectory(CATListOfCATSYPFilePath &oList);

  const int IsNull(void) const
  {
    return CATUnicodeString::IsNull();
  }
protected:
  void Normalize(void);
  int TestMatchNoCase(const CATUnicodeString &string, const CATUnicodeString &pattern);
  int TestMatch(const CATUnicodeString &string, const CATUnicodeString &pattern);
};

#endif
