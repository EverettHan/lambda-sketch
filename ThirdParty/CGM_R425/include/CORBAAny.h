/* -*-c++-*- */
#ifndef __CORBAAny_h__
#define __CORBAAny_h__ 
/** @CAA2Required */

// COPYRIGHT DASSAULT SYSTEMES 1999
#include "CATOmxCAAPortability.h" // Avoid cross platform typical build errors.

class CATListValCATBaseUnknown_var;

class CATBaseUnknown;
class CATUnicodeString;


class _SEQUENCE_CORBAAny; 
class _SEQUENCE_octet;

/**
* Class to define generic types of objects.
*/
class ExportedByCATOmxKernel CORBAAny
{
public:
  /** @nodoc*/
  enum TCKind {tk_null,tk_void,tk_short,tk_long,tk_ushort,tk_ulong,
    tk_double,tk_boolean,tk_char,tk_octet,
    tk_objref,tk_string,tk_sequence,tk_binary,tk_unicodestring};

	/**
	* Constructs an any.
	*/
	CORBAAny();
 
	/** @nodoc */
  CORBAAny(TCKind tc, void* value, boolean release = FALSE);
  
  ~CORBAAny();
  /**
   * Copy constructor.
   * @param iAny
   *   The any to copy
   */
  CORBAAny(const CORBAAny& iAny);
  /**
   * Assignment operator.
   * @param iAny
   *   The any to assign to the current one
   * @return 
   *   The any resulting from the assignment
   */
  CORBAAny& operator = (const CORBAAny& iAny);

	/**
	* Constructs a CORBAAny from a short.
	*/
  CORBAAny(short);
	/**
	* Constructs a CORBAAny from a unsigned short.
	*/
  CORBAAny(unsigned short);
	/**
	* Constructs a CORBAAny from a short.
	*/
  CORBAAny(CATLONG32);
	/**
	* Constructs a CORBAAny from a CATLONG32.
	*/
  CORBAAny(CATULONG32 );
	/**
	* Constructs a CORBAAny from a CATULONG32 .
	*/
  CORBAAny(double);
	/**
	* Constructs a CORBAAny from a double.
	*/
  CORBAAny(const char*);
	/**
	* Constructs a CORBAAny from a char*.
	*/
  CORBAAny(const CATUnicodeString&);
	/**
	* Constructs a CORBAAny from a CATUnicodeString.
	*/
  CORBAAny(CATBaseUnknown*);

  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a short value to a CORBAAny: corbaVal << shortVal.
   */
  void operator <<(short);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns an unsigned short value to a CORBAAny: corbaVal << uShortVal.
   */
  void operator <<(unsigned short);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a CATLONG32 value to a CORBAAny: corbaVal << longVal.
   */
  void operator <<(CATLONG32);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns an CATULONG32  value to a CORBAAny: corbaVal << uLongVal.
   */
  void operator <<(CATULONG32 );
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b>Assigns a double value to a CORBAAny: corbaVal << doubleVal.
   */
  void operator <<(double);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to another CORBAAny: corbaVal2 << corbaVal1.
   */
  void operator <<(const CORBAAny&);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a char* value to a CORBAAny: corbaVal << charVal.
   */
  void operator <<(const char *);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a CATUnicodeString value to a CORBAAny: corbaVal << catUniCodeVal.
   */
  void operator <<(const CATUnicodeString&);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a _SEQUENCE_CORBAAny value to a CORBAAny: corbaVal << seqCorbaVal.
   */
  void operator <<(const _SEQUENCE_CORBAAny&);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a _SEQUENCE_octet value to a CORBAAny: corbaVal << seqOctetVal.
   */
  void operator <<(const _SEQUENCE_octet&);
  /**
   * Bitwise left shift operator.
   * <br><b> Role: </b> Assigns a CATBaseUnknown* value to a CORBAAny: corbaVal << pObject.
   */
  void operator <<(const CATBaseUnknown*);
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a short: corbaVal >> shortVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(short &) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to an unsigned short: corbaVal >> uShortVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(unsigned short &) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a CATLONG32: corbaVal >> longVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(CATLONG32 &) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to an CATULONG32 : corbaVal >> uLongVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(CATULONG32  &) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a double: corbaVal >> doubleVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(double &) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to another CORBAAny:
   * corbaVal1 >> corbaVal2.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(CORBAAny&) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a char*: corbaVal >> charVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */ 
  CATBoolean operator >>(char *&) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a CATUnicodeString: corbaVal >> catUniCodeVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>(CATUnicodeString&) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a _SEQUENCE_CORBAAny: corbaVal >> seqCorbaVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>( _SEQUENCE_CORBAAny& ) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a _SEQUENCE_octet: corbaVal >> seqOctetVal.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>( _SEQUENCE_octet& ) const;
  /**
   * Bitwise right shift operator.
   * <br><b> Role: </b> Assigns a CORBAAny value to a CATBaseUnknown*: corbaVal >> pObject.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator >>( CATBaseUnknown*& ) const;

  /**
   * Equality operator.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator == (const CORBAAny&) const;
  /**
   * Inequality operator.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator != (const CORBAAny&) const;

  /**
   * Not operator.
   * @return
   *   <code>TRUE</code> if everything ran ok, otherwise FALSE.
   */
  CATBoolean operator ! () const;
  
  /**
   * CATBaseUnknown operator.
   * <br><b> Role: </b> Allows the assignment and retrieval of a CATBaseUnknown* in a
	 * CORBAAny*: pCATBaseUnknown = pCORBAAny to save a CORBAAny to a CATBaseUnknown or
	 * pCORBAAny = pCATBaseUnknown to save a CATBaseUnknown to a CORBAAny.
   */
  operator const CATBaseUnknown* () const;
  
  /** @nodoc*/
  struct from_boolean 
    {from_boolean(boolean b): val(b) {}
     boolean val;};
  /** @nodoc*/
  struct from_octet
    {from_octet(octet b): val(b) {}
     octet val;};
  /** @nodoc*/
  struct from_char 
    {from_char(char b): val(b) {}
     char val;};
  /** @nodoc*/
  void operator <<(from_boolean);
  /** @nodoc*/
  void operator <<(from_octet);
  /** @nodoc*/
  void operator <<(from_char);

  /** @nodoc*/
  struct to_boolean 
    {to_boolean(boolean& b): ref(b) {}
     boolean& ref;};
  /** @nodoc*/
  struct to_octet
    {to_octet(octet& b): ref(b) {}
     octet& ref;};
  /** @nodoc*/
  struct to_char 
    {to_char(char& b): ref(b) {}
     char& ref;};
  /** @nodoc*/
  boolean operator >>(to_boolean&) const;
  /** @nodoc*/
  boolean operator >>(to_octet&) const;
  /** @nodoc*/
  boolean operator >>(to_char&) const;


  /** @nodoc*/
  void         replace (TCKind tc, void* value, boolean release = FALSE);
  /** @nodoc*/
  TCKind       type    ()  const;
  /** @nodoc*/
  const void * value   ()  const;

  //private:
private : 
  // to avoid mismatch use of char
  // instead of one of boolean, octet and char
  //------------------------------------------
  /** Assigns an unsigned char to a CORBAAny: corbaVal << uCharVal.  */
  void operator <<(unsigned char) {}
  /** Assigns a CORBAAny value to an unsigned char: corbaVal >> uCharVal.  */
  void operator >>(unsigned char&) const{}

  union
    {
      short _tk_short;
      CATLONG32  _tk_long;
      unsigned short _tk_ushort;
      CATULONG32  _tk_ulong;
      char _tk_char;
      void *         _val;
#if defined(PLATEFORME_DS64)
      double _tk_double; 
      char _tk_data[8];  
#else      
      char _tk_data[4]; 
#endif      
     };

  unsigned char  _release_mod;
  unsigned char  _valued;
  unsigned char  _size; 
  TCKind         _typ:8; 
  
  void ReleaseData();
  void* CopyInterface(void*);
};


/** @nodoc*/
ExportedByCATOmxKernel 
void operator << (CATListValCATBaseUnknown_var&, const _SEQUENCE_CORBAAny&);
/** @nodoc*/
ExportedByCATOmxKernel 
void operator << (CATListValCATBaseUnknown_var&, const CORBAAny&);
/** @nodoc*/
ExportedByCATOmxKernel 
void operator << (CORBAAny&, const CATListValCATBaseUnknown_var&);


#endif


