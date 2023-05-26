/* -*-c++-*- */
#ifndef _PLMPosAny_h
#define _PLMPosAny_h

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Protected
 * @usage U1
 */

//#define POS_ANY_SEQUENCE
//#define POS_ANY_OCTET
#define POS_ANY_LISTANY


#include "IUnknown.h"
#include "CATDataType.h"
//#include "booleanDef.h"
#include "CATCORBABoolean.h"
#ifdef POS_ANY_OCTET
#error POS_ANY_OCTET est ACTIF !
//#include "octetDef.h"
#endif
#include "ExportedByGUIDPLMPosBaseInterfaces.h"


class CATBaseUnknown;
class CATUnicodeString;

#ifdef POS_ANY_LISTANY
class PLMPosAny;
#include "CATListOfPLMPosAny.h"
#endif


#ifdef POS_ANY_SEQUENCE
#error POS_ANY_SEQUENCE est ACTIF !
//class _SEQUENCE_PLMPosAny; // = SEQUENCE(PLMPosAny)
# ifdef POS_ANY_OCTET
//class _SEQUENCE_octet;     // = SEQUENCE(octet)
# endif
#endif

/**
* Class to define generic types of objects.
*/
class ExportedByGUIDPLMPosBaseInterfaces PLMPosAny
{
public:
  /** @nodoc*/
  enum TCKind {tk_null,
           //tk_void,
           tk_short,tk_long,
           tk_ushort,tk_ulong,
           tk_double,
           tk_boolean,tk_char,
#ifdef POS_ANY_OCTET
           //tk_octet,
#endif
           tk_objref,
           tk_string,
#ifdef POS_ANY_LISTANY
           tk_list,
#endif
#ifdef POS_ANY_SEQUENCE
           //tk_sequence,
#ifdef POS_ANY_OCTET
           //tk_binary,
#endif
#endif
           tk_unicode};

public:
  /**
   * Constructs an empty any.
   */
  PLMPosAny();
 
  /**
   * @nodoc
   * Note: if value is not null and it is a tk_objref, a AddRef() is performed.
   */
  //PLMPosAny(TCKind tc, void* value, boolean release = FALSE);
  
  /** @nodoc */
  ~PLMPosAny();
  /**
   * Copy constructor.
   * @param iAny
   *   The any to copy
   */
  PLMPosAny(const PLMPosAny& iAny);
  /**
   * Assignment operator.
   * @param iAny
   *   The any to assign to the current one
   * @return 
   *   The any resulting from the assignment
   */
  PLMPosAny& operator = (const PLMPosAny& iAny);

  /**
   * Constructs a PLMPosAny from a short.
   */
  PLMPosAny(short);
  /**
   * Constructs a PLMPosAny from a unsigned short.
   */
  PLMPosAny(unsigned short);
  /**
    * Constructs a PLMPosAny from a CATLONG32.
    */
  PLMPosAny(CATLONG32);
  /**
    * Constructs a PLMPosAny from a CATULONG32 .
    */
  PLMPosAny(CATULONG32 );
  /**
    * Constructs a PLMPosAny from a double.
    */
  PLMPosAny(double);
  /**
    * Constructs a PLMPosAny from a const char*.
    */
  PLMPosAny(const char*);
  /**
    * Constructs a PLMPosAny from a CATUnicodeString.
    */
  PLMPosAny(const CATUnicodeString&);
  /**
    * Constructs a PLMPosAny from a CATBaseUnknown.
    * Note: if iObj is not null, a AddRef() is performed.
    */
  PLMPosAny(CATBaseUnknown* iObj);
#ifdef POS_ANY_LISTANY
  /**
    * Constructs a PLMPosAny from a CATListOfPLMPosAny.
    */
  PLMPosAny(const CATListOfPLMPosAny&);
#endif

  /**
    * Assigns a short value to a PLMPosAny.
    */
  void operator <<(short);
  /**
    * Assigns an unsigned short value to a PLMPosAny.
    */
  void operator <<(unsigned short);
  /**
    * Assigns a CATLONG32 value to a PLMPosAny.
    */
  void operator <<(CATLONG32);
  /**
    * Assigns an CATULONG32  value to a PLMPosAny.
    */
  void operator <<(CATULONG32 );
  /**
    * Assigns a double value to a PLMPosAny.
    */
  void operator <<(double);
  /**
    * Assigns a PLMPosAny value to another PLMPosAny.
    */
  void operator <<(const PLMPosAny&);
  /**
    * Assigns a char* value to a PLMPosAny.
    */
  void operator <<(const char *);
  /**
    * Assigns a CATUnicodeString value to a PLMPosAny.
    */
  void operator <<(const CATUnicodeString&);
#ifdef POS_ANY_LISTANY
  /**
    * Assigns a CATListOfPLMPosAny value to a PLMPosAny (copy elements).
    */
  void operator <<(const CATListOfPLMPosAny&);
  /**
    * Assigns a CATListOfPLMPosAny (pointeur) to a PLMPosAny.
    */
  void operator <<(CATListOfPLMPosAny * &);
#endif
#ifdef POS_ANY_SEQUENCE
  /**
    * Assigns a _SEQUENCE_PLMPosAny value to a PLMPosAny.
    */
  //void operator <<(const _SEQUENCE_PLMPosAny&);
  /**
    * Assigns a _SEQUENCE_octet value to a PLMPosAny.
    */
  //void operator <<(const _SEQUENCE_octet&);
#endif
  /**
    * Assigns a CATBaseUnknown* value to a PLMPosAny.
    * Note: if iObj is not null, a AddRef() is performed.
    */
  void operator <<(const CATBaseUnknown* iObj);
  /**
    * Assigns a PLMPosAny value to a short.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(short &) const;
  /**
    * Assigns a PLMPosAny value to an unsigned short.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(unsigned short &) const;
  /**
    * Assigns a PLMPosAny value to a CATLONG32.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(CATLONG32 &) const;
  /**
    * Assigns a PLMPosAny value to an CATULONG32.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(CATULONG32  &) const;
  /**
    * Assigns a PLMPosAny value to a double.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(double &) const;
  /**
    * Assigns a PLMPosAny value to another PLMPosAny.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(PLMPosAny&) const;
  /**
    * Assigns a PLMPosAny value to a char*.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */ 
  CATBoolean operator >>(char *&) const;
  /**
    * Assigns a PLMPosAny value to a CATUnicodeString.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(CATUnicodeString&) const;
#ifdef POS_ANY_LISTANY
  /**
    * Assigns a PLMPosAny value to a CATListOfPLMPosAny.
    * The list elements are copied to the CATListOfPLMPosAny.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(CATListOfPLMPosAny&) const;
  /**
    * Assigns a PLMPosAny value to a CATListOfPLMPosAny.
    * The internal list is assigned to the CATListOfPLMPosAny* ; there is no copy.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>(const CATListOfPLMPosAny *&) const;
#endif
#ifdef POS_ANY_SEQUENCE
  /**
    * Assigns a PLMPosAny value to a _SEQUENCE_PLMPosAny.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  //CATBoolean operator >>( _SEQUENCE_PLMPosAny& ) const;
  /**
    * Assigns a PLMPosAny value to a _SEQUENCE_octet.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  //CATBoolean operator >>( _SEQUENCE_octet& ) const;
#endif
  /**
    * Assigns a PLMPosAny value to a CATBaseUnknown*.
    * Note: if value is not null, a AddRef() is performed.
    * @return
    *   <code>TRUE</code> if assignment was ok, otherwise FALSE.
    */
  CATBoolean operator >>( CATBaseUnknown*& rpObj) const;

  /**
    * Equality operator.
    * @return
    *   <code>TRUE</code> if both PLMPosAny are equal, FALSE otherwise.
    */
  CATBoolean operator == (const PLMPosAny&) const;
  /**
    * Inequality operator.
    * @return
    *   <code>TRUE</code> if both PLMPosAny are different, FALSE otherwise.
    */
  CATBoolean operator != (const PLMPosAny&) const;

  /**
    * Not operator.
    * @return
    *   <code>TRUE</code> if the PLMPosAny is valued, FALSE otherwise.
    */
  CATBoolean operator ! () const;
  
  /**
   * CATBaseUnknown * operator.
   * <br><b> Role: </b> Allows the assignment and retrieval of a CATBaseUnknown* in a PLMPosAny:
   * pCATBaseUnknown = pPLMPosAny to save a PLMPosAny to a CATBaseUnknown,
   * pPLMPosAny = pCATBaseUnknown to save a CATBaseUnknown to a PLMPosAny.
   * Note: NO AddRef() is performed on the CATBaseUnknown (which is logic if we consider it returns a const).
   */
  operator const CATBaseUnknown* () const;
  
  /** @nodoc*/
  struct from_boolean 
    {from_boolean(boolean b): val(b) {}
     boolean val;};
#ifdef POS_ANY_OCTET
  /** @nodoc*/
  //struct from_octet
    //{from_octet(octet b): val(b) {}
     //octet val;};
#endif
  /** @nodoc*/
  struct from_char 
    {from_char(char b): val(b) {}
     char val;};
  /** @nodoc*/
  void operator <<(from_boolean);
#ifdef POS_ANY_OCTET
  /** @nodoc*/
  //void operator <<(from_octet);
#endif
  /** @nodoc*/
  void operator <<(from_char);

  /** @nodoc*/
  struct to_boolean 
    {to_boolean(boolean& b): ref(b) {}
     boolean& ref;};
#ifdef POS_ANY_OCTET
  /** @nodoc*/
  //struct to_octet
    //{to_octet(octet& b): ref(b) {}
     //octet& ref;};
#endif
  /** @nodoc*/
  struct to_char 
    {to_char(char& b): ref(b) {}
     char& ref;};
  /** @nodoc*/
  boolean operator >>(to_boolean&) const;
#ifdef POS_ANY_OCTET
  /** @nodoc*/
  //boolean operator >>(to_octet&) const;
#endif
  /** @nodoc*/
  boolean operator >>(to_char&) const;


  /**
   * @nodoc
   * Note: if value is not null and it is a tk_objref, a AddRef() is performed.
   */
  //void         replace (TCKind tc, void* value, boolean release = FALSE);
  /** @nodoc*/
  TCKind       type    ()  const;
  /** @nodoc*/
  const void * value   ()  const;

  //private:
private : 
  // to avoid mismatch use of char
  // instead of one of boolean, octet and char
  //------------------------------------------
  /**
    * Assigns an unsigned char to a PLMPosAny: corbaVal << uCharVal.
    */
  void operator <<(unsigned char) {}
  /**
    * Assigns a PLMPosAny value to an unsigned char: corbaVal >> uCharVal.
    */
  void operator >>(unsigned char&) const{}

  // attributes (TCKind should be TypeCode_ptr)
  //------------------------------------------
  union
    {
      short          _tk_short;
      CATLONG32      _tk_long;
      unsigned short _tk_ushort;
      CATULONG32     _tk_ulong;
      char           _tk_char;
      void *         _val;
#if defined(PLATEFORME_DS64)
      double         _tk_double;   //
      char           _tk_data[8];  // small data array for small byte_seq
#else      
      char           _tk_data[4];  // small data array for small byte_seq
#endif      
     };

  unsigned char      _release_mod; // if value has to be released
  unsigned char      _valued;
  unsigned char      _is_ref;      // if value (_val) is a reference
  TCKind             _typ:8;       // small type
  
  void   ReleaseData();
  void*  CopyInterface(void*);
};


//#include "CATLISTV_CATBaseUnknown.h"

#ifdef POS_ANY_SEQUENCE
/** @nodoc*/
//ExportedByGUIDPLMPosBaseInterfaces
//void operator << (CATLISTV(CATBaseUnknown_var)&, const _SEQUENCE_PLMPosAny&);

/** @nodoc*/
//ExportedByGUIDPLMPosBaseInterfaces 
//void operator << (CATLISTV(CATBaseUnknown_var)&, const PLMPosAny&);

/** @nodoc*/
//ExportedByGUIDPLMPosBaseInterfaces 
//void operator << (PLMPosAny&, const CATLISTV(CATBaseUnknown_var)&);
#endif


#endif

