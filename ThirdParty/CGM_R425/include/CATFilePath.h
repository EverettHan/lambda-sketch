#ifndef CATFilePath_H
#define CATFilePath_H

#include <CATView.h>
#include <CATUnicodeString.h>

class CATFilePath;
#define CATLISTV_Append
#define CATLISTV_QuickSort
#define CATLISTV_RemoveAll
#define CATLISTV_RemovePosition
#include <CATLISTV_Declare.h>
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByCATView
CATLISTV_DECLARE(CATFilePath)
typedef CATLISTV(CATFilePath) CATListOfCATFilePath;
#undef CATCOLLEC_ExportedBy

/**
 * A String class for file (or directory) names manipulation.
 * CATFilePath is only a handler on a string buffer with a reference counter.
 * Because of this <b>it is more safe an efficient to use this object by value
 * instead of by pointers</b>.<p>
 * A cast operator exist to (const char *) so that you can use CATFilePath instances
 * in place of const char * strings.<p>
 * This class manage translation of / and \ to operating system file separator.
 * + and += operator exist to add names, a file separator is inserted.<p>
 * Sample of code for filename generation :
 *<pre> CATFilePath filename( "directory/filename" );
 *     => "directory/filename" on Unix, "directory\filename" on NT
 * CATFilePath path= filename.dirname();
 *     => "directory"
 * CATFilePath name= filename.basename();
 *     => "filename"
 * CATFilePath filename2= path+name;
 *     => "directory/filename" on Unix, "directory\filename" on NT</pre>
 *
 */
class ExportedByCATView CATFilePath: public CATUnicodeString
{
public:

  /**
   * Search in path concatenation
   */
  static CATFilePath Search(const CATFilePath& iPath, const char* iPathList=NULL);

  /**
   * Default constructor.
   */
  CATFilePath();

  /**
   * Constructor from a CATString (CATString is a macro on CATString).<p>
   * / and \ are translated to current operating system file separator.
   */
  CATFilePath(CATString iPath);

  /**
   * Constructor from a CATUnicodeString.<p>
   * / and \ are translated to current operating system file separator.
   */
  CATFilePath(const CATUnicodeString& iPath);

  /**
   * Constructor from a const char *, null terminated string.<p>
   * / and \ are translated to current operating system file separator.
   */
  CATFilePath(const char* iPath);

  /**
   * Constructor from a const char *, length specified string.<p>
   * / and \ are translated to current operating system file separator.
   */
  // CATFilePath(const char* iPath, int iLength);

  /**
   * Copy constructor.
   */
  CATFilePath(const CATFilePath& iFileName);

  /**
   * Destructor
   */
  ~CATFilePath();

  /**
   * Get current working directory.
   */
  static CATFilePath GetWorkDir();

  /**
   * Generate a temporary and unique file name
   */
  static CATFilePath GetTemporaryFileName();

  /**
   * Compare two CATFilePath instances.<p>Same return value than strncmp.
   */
  static int Compare(CATFilePath* iFile1, CATFilePath* iFile2);

  /**
   * Change current working directory.
   */
  static int SetWorkDir(const CATFilePath& iPath);

  /**
   * Create a directory.
   */
  int CreateDirectory();

  /**
   * Create a directory and all its fathers as required (same as mkdir -p).
   */
  int CreateRecursiveDirectory();

  /**
   * Test is filename correspond to an existing file.
   */
  int IsFile() const;

  /**
   * Test is filename correspond to a read-only file.
   */
  int IsReadOnly () const;

  /**
   * Test is filename correspond to an existing directory.
   */
  int IsDirectory() const;

  /**
   * Compare to another filename.<p>
   * This method returns 1 if filenames are the same, 0 otherwise.
   */
  int IsEqual(const CATFilePath& iFileName) const;

  /**
   * Test if the filename is under 'iPath' directory.
   */
  int IsUnderDirectory(const CATFilePath& iPath);

  /**
   * Convert filename to its full path and name.<p>
   * If the object correspond to a relative path it is translated to an absolute
   * path and name.
   */
  CATFilePath GetFullPath();

  /**
   * Get file size in bytes.
   */
  int GetFileSize();

  /**
   * Get file timestamp
   */
  CATLONG32 GetTime();

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
   */
  CATFilePath basename(int iN=1) const;

  /**
   * Get the parent directory path of the filename.<p>
   * Optional parameter iN can be use to get the directory of one of the parent
   * directories.<p>
   * For <code>Dir3/Dir2/Dir1/Name</code> :<br>
   * dirname() = 'Dir3/Dir2/Dir1'<br>
   * dirname(1) = 'Dir3/Dir2/Dir1'<br>
   * dirname(2) = 'Dir3/Dir2'<br>
   * dirname(3) = 'Dir3'<br>
   */
  CATFilePath dirname(int iN=1) const;

  /**
   * Test filename extension.<p>
   * This method returns 1 if file extension is 'iExtension', 0 otherwise.
   */
  int HasExtension(const char* iExtension) const;

  /**
   * Get filename extension.<p>
   */
  CATString GetExtension() const;

  /**
   * Add a filename extension.<p>
   */
  void AddExtension(CATString iExtension);

  /**
   * Set the filename extension.<p>
   */
  void SetExtension(CATString iExtension);

  /**
   * Set file modification time to reference modification time
   */
  void SetTime(const CATFilePath& iReference);

  /**
   * Compare file modification time to reference modification time
   */
  int CompareTime(const CATFilePath& iReference) const;

  /**
   * Add execution right to the file
   */
  void SetAsExecutable();

  /**
   * Remove the file
   */
  int Delete();

  /**
   * Cast operator to const char *.
   */
  operator const char*() const;

  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   */
  CATFilePath operator+(const char*) const;

  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   */
  CATFilePath operator+(const CATString&) const;

  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   */
  CATFilePath operator+(const CATUnicodeString&) const;

  /**
   * + operator. Added names are separeted by / or \ depending on operating system.
   */
  CATFilePath operator+(const CATFilePath&) const;

  /**
   * += operator. Added names are separeted by / or \ depending on operating system.
   */
  CATFilePath& operator += (const char*);
  CATFilePath& operator=(const char*);
  CATFilePath& operator=(const CATString&);
  CATFilePath& operator=(const CATUnicodeString&);
  CATFilePath& operator=(const CATFilePath&);
  int operator==(const char* string) const;
  int operator!=(const char* string) const;
  int operator==(const CATFilePath& ref) const;
  int operator!=(const CATFilePath& ref) const;

  /**
   * Get list of files matching a pattern
   */
  int ReadDirectory(CATListOfCATFilePath& oList);

  const int IsNull() const
  {
    return CATUnicodeString::IsNull();
  }

protected:
  void Normalize();
  int TestMatchNoCase(const CATUnicodeString& string, const CATUnicodeString& pattern);
  int TestMatch(const CATUnicodeString& string, const CATUnicodeString& pattern);
};

#endif
