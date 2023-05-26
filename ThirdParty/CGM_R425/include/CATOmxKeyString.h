#ifndef __CATOmxKeyString_h__
#define __CATOmxKeyString_h__
/**
 * @level Private
 * @usage U1
 */
#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATOmxDeprecated.h"
#include "CATDataType.h"
class CATUnicodeString;
class CATString;
class CATOmxKeyNS;
class CATOmxUTF8String;
namespace CATOmx
{
  unsigned int ExportedByCATOmxKernel ComputeHashKeyV2(const char* str);
}

/**
 * A very specific string class.
 * It ensures full sharing of the string (there is only one "undestructible" instance in memory)
 * If used correctly, this can allow:
 *   low memory usage
 *   fast destruction (never destroyed !)
 *   fast hashing/comparison
 *
 * Use it for constants (string literals that appears in source code like class names, attributes names etc...)
 * Never use it for numbers/uuids/user data.
 *
 * It is thread-safe.
 *
 * @href http://osmwebdsy/wiki/index.php/CATOmxKeyString
 */
class ExportedByCATOmxKernel CATOmxKeyString
{
private:
  /**
   * The character encoding of "id" is:
   * - UTF-8 if this object is created from a CATUnicodeString or a CATOmxUTF8String
   * - the same as the "const char*" in the constructor
   */
  const char* id;
  static const char* put(const char*);
  bool Test(const char*) const;
public:
  inline CATOmxKeyString() : id(null().id) {}
  inline CATOmxKeyString(const char* n) : id(put(n)) {}
  /** Create a string in a separate namespace with a specified length.*/
  CATOmxKeyString(CATOmxKeyNS &ns, const char *n, int len);
  /** Create a string in a separate namespace .*/
  CATOmxKeyString(CATOmxKeyNS &ns, const char *n);
  CATOmxKeyString(CATOmxKeyNS &ns, const CATUnicodeString &n);
  CATOmxKeyString(CATOmxKeyNS & ns, CATOmxUTF8String const & iUTF8String);
  CATOmxKeyString(const CATUnicodeString &n);
  CATOmxKeyString(CATOmxUTF8String const & iUTF8String);
  explicit CATOmxKeyString(const CATString &n);
  inline CATOmxKeyString(const CATOmxKeyString& n) : id(n.id) {}

  inline CATOmxKeyString& operator=(const char* n) { id = put(n); return *this; }
  CATOmxKeyString& operator=(const CATUnicodeString &n);
  CATOmxKeyString& operator=(CATOmxUTF8String const & iUTF8String);
  inline CATOmxKeyString& operator=(const CATOmxKeyString& n) { id = n.id; return *this; }

  /**return C string*/
  inline const char* asChar() const { return id; }
  inline const char* AsChar() const { return id; }
  inline const char* ConvertToChar() const { return id; }

  /** Test empty string*/
  inline bool IsNull() const { return 0 == *id; }
  inline int isNull() const { return 0 == *id; }

  /** Comparison */
  inline bool operator==(const CATOmxKeyString& n) const { return id == n.id; }
  inline bool operator!=(const CATOmxKeyString& n) const { return id != n.id; }
  inline bool operator==(const char* n) const { return Test(n); }
  inline bool operator!=(const char* n) const { return !Test(n); }

  /** return hash, this is the fastest way but it is not compatible with CATUnicodeString::ComputeHashKey*/
  inline CATHashKey Hash() const { return  CATPtrToUINT32(id); }
  inline CATHashKey hash() const { return  CATPtrToUINT32(id); }

  /** return hash key ( CATUnicodeString  algorithm) */
  CATHashKey GetHashKey() const;

  /**
   * Return the utf8 string length.
   * Prefer IsNull() if you want to check length() == 0
   */
  int length() const;

#ifndef CATIAR418
  inline OMX_DEPRECATED("Use length") int get_len() const { return length(); }
#endif
  /**
   * Return the CATUnicodeString view of identifier.
   * WARNING about encoding: the returned CATUnicodeString is build with the idea that given data
   * in constructor are UTF-8 encoded, which is not always the case with the "const char*" constructor.
   * If you used a "const char*" constructor and wish to get the original encoding version, use "asChar".
   */
  const CATUnicodeString &asCUS() const;
  inline const CATUnicodeString& AsCUS() const { return asCUS(); }
  inline const CATUnicodeString& AsString() const { return asCUS(); }

  CATUnicodeString asString() const;

  /**
   * Return the empty id.
   */
  static inline const CATOmxKeyString& Null() { return null(); }
  static const CATOmxKeyString& null();

  /**
   * comparison function by internal pointer
   */
  static int Compare(const CATOmxKeyString& ks1, const CATOmxKeyString& ks2);

  /**
   * comparison function by hash key and then by ascii order
   */
  static int HashCompare(const CATOmxKeyString& k1, const CATOmxKeyString& k2);

  /**
   * comparison function by byte content.
   */
  static int StrCompare(const CATOmxKeyString& ks1, const CATOmxKeyString& ks2);

};

#endif
