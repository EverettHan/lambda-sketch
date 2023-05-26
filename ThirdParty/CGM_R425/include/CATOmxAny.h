/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmxAny_h__
#define __CATOmxAny_h__

 // System
#include "CATUnicodeString.h"
// SystemTS
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxCxxPortability.h"
#include "CATOmxIter.h"
#include "CATOmxKernel.h"
#include "CATOmxKeyString.h"
#include "CATOmxKind.h"
#include "CATOmxPair.h"
#include "CATOmxPortability.h"

#if OMX_CXX11 == 1
// OS
#include <type_traits>
#endif

class CATOmxBaseTuple;
class CATInterUnicodeString;
class CATOsmValue;
class CATUuid;
class CATOmxBaseArray;
class CATOmxUTF8String;

/** restricted for internal usage */
struct CATOmxAnyMembers
{
  friend class CATOmxAny;
  friend class CATOsmValue;
private:
  union U
  {
    octet o;
    int i;
    double d;
    CATLONG64 i64;
    CATInterUnicodeString* s;
    char* id;
    IUnknown* iu;
    CATOmxBaseTuple* t;
    void* v;

#if OMX_CXX11 == 1
    CATUnicodeString cus;
    CATOmxKeyString ks;

    U() {}
    U(const U& u) { OMX_STATIC_ASSERT(sizeof(U) == sizeof(U::i64), ""); i64 = u.i64; }
    U& operator=(const U& u) { OMX_STATIC_ASSERT(sizeof(U) == sizeof(U::i64), ""); i64 = u.i64; return *this; }
    ~U() {}
#endif
  } m;
#ifdef _WINDOWS_SOURCE
#pragma pack(push,1) 
#endif
  CATOmxKind m_kind : 15;
  unsigned int m_isList : 1;
  CATOmxKind m_extendedKind : 15;
  unsigned int m_sharedValue : 1;

#ifdef _WINDOWS_SOURCE
#pragma pack(pop) 
#endif
  unsigned int m_padding;
};

#ifdef _WINDOWS_SOURCE
#pragma warning( push )
//non dll-interface struct 'CATOmxAnyMembers' used as base for dll-interface class 'CATOmxAny'
#pragma warning( disable : 4275 )
#endif

/**
  * A mutable variant class able to hold the following raw data types:
  * <pre>
  *    omx_void        => an unset value
  *    omx_boolean     => a boolean value (see @href CATBoolean)
  *    omx_octet       => an unsigned char value (see @href octet)
  *    omx_int         => a signed 32 bits integer value
  *    omx_int64       => a signed 64 bits integer value (see @href CATLONG64)
  *    omx_double      => a double value
  *    omx_string      => an unicode string value (see @href CATUnicodeString)
  *    omx_identifier  => a shared ascii string value (see @href CATOmxKeyString)
  *    omx_uuid        => an uuid value (see @href CATUuid)
  *    omx_IUnknown    => a IUnknown pointer value (see @href IUnknown), AddRef/Release is performed
  *    omx_pointer     => a void pointer value
  * </pre>
  *
  * it supports also (eventually heterogeneous) copy-on-write lists of these types
  * which allow shallow copies
  */
class ExportedByCATOmxKernel CATOmxAny : private CATOmxAnyMembers
{
  friend class CATOsmValue;
public:
  /**
   * Build a variant with size 0 and Kind omx_void.
   */
  CATOmxAny();

  /**
   * Copy contructor.
   */
  CATOmxAny(const CATOmxAny&);

  /**
   * Copy operator.
   */
  CATOmxAny& operator=(const CATOmxAny&);

#if OMX_CXX11 == 1 
  CATOmxAny(CATOmxAny && iAny);
  CATOmxAny &operator =(CATOmxAny && iAny);
#endif

  /**
   * Efficiently swaps content of two variants.
   */
  static void Swap(CATOmxAny&, CATOmxAny&);

  /**
   * Returns the CATOmxKind of the variant.
   */
  inline CATOmxKind Kind() const { return m_kind; }

  /**
   * Returns the extended kind of the variant, by default returns kind
   */
  inline CATOmxKind ExtendedKind() const { return m_extendedKind == omx_void ? m_kind : m_extendedKind; }

  /**
   * Using this method allows you to specialize the extended kind of your variant
   * For example: if you want to hold a CATILinkableObject in a variant
   * you may assign it, creating a omx_IUnknown variant and then set the extended kind
   * to omx_linkable in order to keep this type.
   * This operation will not change other behaviours of the variant.
   * This specialization should pass through the boundaries of a modeler
   * because a same extended kind could have different meaning in two differents modelers.
   */
  inline void SetExtendedKind(CATOmxKind iKind) { m_extendedKind = iKind; }

  /**
   * returns size of the variant, an unset variant has size 0.
   * Beware that if the underlying object is map, you should use MapSize() instead.
   */
  int Size() const;

  /**
   * Unset the variant, kind becomes omx_void and size 0.
   */
  void Unset();

  /**
   * Build a variant from an octet value.
   */
  CATOmxAny(octet o);

  /**
   * Build a variant from an octet value.
   */
  CATOmxAny& operator=(octet o);

  /**
   * Cast variant to an octet value
   * Variant's kind must be omx_octet and size 1,
   * else 0 will be returned.
   */
  operator octet() const;


  /**
   * Build a variant from an integer value.
   */
  CATOmxAny(int i);

  /**
   * Build a variant from an integer value.
   */
  CATOmxAny& operator=(int i);

  /**
   * Cast variant to an integer value
   * Variant's kind must be omx_int and size 1,
   * else 0 will be returned.
   */
  operator int() const;


  /**
   * Build a variant from a 64 bits integer value.
   */
  CATOmxAny(CATLONG64 i);

  /**
   * Build a variant from a 64 bits integer value.
   */
  CATOmxAny& operator=(CATLONG64 i);

  /**
   * Cast variant to a 64 bits integer value
   * Variant's kind must be omx_int64 and size 1,
   * else 0 will be returned.
   */
  operator CATLONG64() const;

  /**
   * Build a variant from a double value.
   */
  CATOmxAny(double d);

  /**
   * Build a variant from a double value.
   */
  CATOmxAny& operator=(double d);

  /**
   * Cast variant to a double value
   * variant's type must be omx_double and size 1
   * else 0 will be returned.
   */
  operator double() const;


  /**
   * Build a variant from an unicode string value.
   */
  CATOmxAny(const CATUnicodeString& s);
  /**
   * Build a variant from an unicode string value.
   */
  OMX_EXPLICIT CATOmxAny(const CATOmxUTF8String& s);


  /**
   * Build a variant from an unicode string value.
   */
  CATOmxAny& operator=(const CATUnicodeString& s);

  /**
   * Cast variant to an unicode string value
   * variant's type must be omx_string (or omx_identifier) and size 1
   * else empty string "" will be returned.
   */
  operator CATUnicodeString() const;

  /**
   * Build a variant from a C string.
   */
  CATOmxAny(const char* s);

  /**
   * Build a variant from an unicode string value.
   */
  CATOmxAny& operator=(const char* s);


  /**
   * Build a variant from an IUnknown pointer.
   * AddRef/Release will be managed.
   */
  CATOmxAny(const IUnknown* iu);

  /**
   * Build a variant from an IUnknown pointer and an extended kind.
   * AddRef/Release will be managed.
   */
  CATOmxAny(const IUnknown* iu, CATOmxKind extendedKind);

  /**
   * Build a variant from an IUnknown pointer.
   * AddRef/Release will be managed.
   */
  CATOmxAny& operator=(const IUnknown* iu);

  /**
   * Cast variant to an IUnknown pointer value
   * variant's type must be omx_IUnknown and size 1
   * else empty NULL pointer will be returned.
   */
  operator IUnknown*() const;

  /**
   * Assign a boolean value to the variant.
   */
  void SetBoolean(CATBoolean b);

  /**
   * Cast variant to a boolean value.
   * variant's type must be omx_boolean and size 1
   * else FALSE will be returned
   */
  CATBoolean GetBoolean() const;

  /**
   * Paraphrase of operator =.
   */
  inline void SetOctet(octet b) { this->operator=(b); }

  /**
   * Adaptative version return 1/0 on omx_boolean or a 0..255 byte value for omx_int .
   */
  octet GetOctet() const;

  /**
   * Paraphrase of operator =.
   */
  inline void SetInteger(int i) { this->operator=(i); }
  /**
   * Adaptative version return 1/0 on omx_boolean or a 0..255 byte value for omx_octet .
   */
  int GetInteger() const;
  /**
   * Paraphrase of operator =.
   */
  inline void SetDouble(double d) { this->operator=(d); }
  /**
   * Paraphrase of cast operator.
   */
  double GetDouble() const { return this->operator double(); }

  /**
   * Paraphrase of operator =.
   */
  inline void SetString(const CATUnicodeString& str) { this->operator=(str); }
  /**
   * Adaptative version that works also for omx_identifier .
   */
  inline CATUnicodeString GetString() const { return this->operator CATUnicodeString(); }

  /**
   * Assign a CATOmxKeyString (omx_identifier) object to the variant.
   */
  void SetIdentifier(const CATOmxKeyString&);
  /**
   * return stored CATOmxKeyString.
   * variant must be of size 1 and of kind omx_identifier.
   */
  CATOmxKeyString GetIdentifier() const;

  /**
   * Assign a void pointer to the variant.
   */
  void SetPointer(const void* p);

  /**
   * Cast variant to a void pointer value.
   * variant's type must be omx_pointer and size 1
   * else NULL pointer will be returned
   */
  void* GetPointer() const;


  /**
   * Assign a CATUuid to the variant.
   */
  void SetUuid(const CATUuid& iUuid);

  /**
   * Cast variant to an uuid value.
   * variant's type must be omx_uuid and size 1
   * else method will fail.
   */
  HRESULT GetUuid(CATUuid& oUuid) const;

  /**
   * Set as iValue LONG64 as omx_int64,omx_time
   */
  HRESULT SetTime(CATLONG64 iValue);
  /**
   * Get a Time value.
   * operator CATLONG64 will also work.
   * @return S_OK if value is size 1 and omx_time
   */
  HRESULT GetTime(CATLONG64 &oValue) const;

  /**
   * Set as iValue LONG64 as omx_IUnknown,omx_enum
   */
  HRESULT SetEnum(const CATOmxKeyString &iValue, int iValueInt);
  /**
   * Get an enum (a string and a rank)
   * @return S_OK if value is size 1 and omx_enum
   */
  HRESULT GetEnum(CATOmxKeyString &oValue, int &oValueInt) const;

  /** factories, build a CATOmxAny with explicit type */
  static inline CATOmxAny CreateVoid() { return CATOmxAny(); }
  static        CATOmxAny CreateBoolean(CATBoolean b);
  static inline CATOmxAny CreateBool(bool b) { return CreateBoolean(b); }
  static inline CATOmxAny CreateByte(unsigned char b) { return CATOmxAny(b); }
  static inline CATOmxAny CreateInt(int i) { return CATOmxAny(i); }
  static inline CATOmxAny CreateInt64(CATLONG64 i) { return CATOmxAny(i); }
  static inline CATOmxAny CreateDouble(double d) { return CATOmxAny(d); }
  static inline CATOmxAny CreateString(const CATUnicodeString& s) { return CATOmxAny(s); }
  static        CATOmxAny CreateUuid(const CATUuid& u);
  static inline CATOmxAny CreatePointer(const IUnknown* p, CATOmxKind ek = omx_void) { return CATOmxAny(p, ek); }
  static        CATOmxAny CreateTime(CATLONG64 t);
  static        CATOmxAny CreateTime(const CATTime& t);
  static        CATOmxAny CreateEnum(const CATOmxKeyString& name, int rank);
  static        CATOmxAny CreateList(CATOmxKind kind);
  static        CATOmxAny CreateMap();

  /**
   * TryGetXXX family
   * retrieve a simple value with exact type
   */
  HRESULT TryGetBoolean(CATBoolean& oValue) const;
  HRESULT TryGetBool(bool& oValue) const;
  HRESULT TryGetByte(octet& oValue) const;
  HRESULT TryGetInt(int& oValue) const;
  HRESULT TryGetInt64(CATLONG64& oValue) const;
  HRESULT TryGetDouble(double& oValue) const;
  HRESULT TryGetString(CATUnicodeString& oValue) const;
  inline HRESULT TryGetTime(CATLONG64& oValue) const { return GetTime(oValue); }
  inline HRESULT TryGetUuid(CATUuid& oValue) const { return GetUuid(oValue); }
  inline HRESULT TryGetEnum(CATOmxKeyString& oValue1, int& oValue2) const { return GetEnum(oValue1, oValue2); }

  /**
   * Reset variant to default value of kind iKind.
   * Default value is 0 for numerical types, NULL for pointer types, empty string for string type.
   * If isList is TRUE, variant size will become 0 else it will become 1.
   */
  void BuildDefaultValue(CATOmxKind iKind, CATBoolean isList, CATOmxKind extendedKind = omx_void);

  /**
   * Build a variant of kind iKind and size iSize from a raw C Array.
   * iKind must be equal to array type, iArray must be non NULL.
   * it is a generic implementation method, you should
   * prefer strictly typed versions see @href CATOmxAnyBuildFromCArray.
   */
  HRESULT BuildFromCArray(CATOmxKind iKind, const void* iArray, int iSize);

  /**
   * Convert a variant of kind iKind to a raw C Array.
   * iKind must be equal to oArray type, oArray must be non NULL.
   * It is a generic implementation method, you should
   * prefer strictly typed versions see @href CATOmxAnyConvertToCArray
   */
  HRESULT CopyToCArray(CATOmxKind iKind, void* oArray) const;

  /**
   * Build a variant of kind iKind from a CATOmxBaseArray.
   * iKind must be equal to iArray type.
   * A shallow copy will be performed;
   * It is a generic implementation method, you should
   * prefer strictly typed versions, see stream operators (<<) in CATOmxAnyConvertToArray.h
   */
  HRESULT BuildFromArray(CATOmxKind iKind, const CATOmxBaseArray& iArray);

  /**
   * Convert a variant of kind iKind to a CATOmxBaseArray.
   * iKind must be equal to oArray type.
   * A shallow copy will be performed;
   * It is a generic implementation method, you should
   * prefer strictly typed versions, see stream operators (>>) in CATOmxAnyConvertToArray.h
   */
  HRESULT CopyToArray(CATOmxKind iKind, CATOmxBaseArray& OArray) const;

  /**
   * Returns i-th element of variant, i must be in [1,Size()].
   */
  const CATOmxAny operator[](int i) const;

  /**
   * Returns i-th element of variant, if i is out of [1,Size()] an unset variant will be returned.
   */
  inline const CATOmxAny Get(int i) const { return this->operator[](i); }

  /**
   * Assign the i-th element of variant to oValue, E_OUTOFBOUND will be returned on bound error.
   */
  HRESULT Get(int i, CATOmxAny& oValue) const;

  /**
   * Assign i-th element of variant, i must be in [1,Size()].
   */
  void Set(int i, const CATOmxAny& iVal);

  /**
   * Append an element to the variant.
   */
  void Append(const CATOmxAny& val);

  /**
   * Insert an element in the variant, i must be in [1,Size()+1].
   */
  inline void InsertAt(int i, const CATOmxAny& iVal) { InsertIndex(i, iVal); }
  void InsertIndex(int i, const CATOmxAny& iVal);

  /**
   * Remove i-th element of the variant, i must be in [1,Size()].
   */
  inline void RemoveAt(int i) { RemoveIndex(i); }
  void RemoveIndex(int i);

  /**
   * Compares two variants.
   * Comparison is performed by type then by size, then by value
   * Return  1 if iVal1>iVal2,
   *         0 if iVal1==iVal2,
   *        -1 if iVal1<iVal2.
   */
  static int Compare(const CATOmxAny& iVal1, const CATOmxAny& iVal2);

#if (__cplusplus >= 202002L) // bool will be necessary only starting from C++20 (202002L).
  /**
   * Returns true if Compare(*this, iVal)== 0, false otherwise.
   */
  inline bool operator==(const CATOmxAny& iVal) const { return (Compare(*this, iVal) == 0); }
#else
  /**
   * Returns 1 if Compare(*this, iVal) == 0, 0 otherwise.
   */
  inline int operator==(const CATOmxAny& iVal) const { return (Compare(*this, iVal) == 0); }

  /**
   * Returns 1 if Compare(*this, iVal) !=0 , 0 otherwise.
   */
  inline int operator!=(const CATOmxAny& iVal) const { return (Compare(*this, iVal) != 0); }
#endif


#if (__cplusplus >= 201103L) // Will be necessary only starting from C++20 (202002L).
  template <typename _Ty> // Called for a source type _Ty only if _Ty is a CATUnicodeString.
  typename std::enable_if<std::is_same<_Ty, CATUnicodeString>::value, bool>::type operator==(const _Ty & iVal) const
  {
    return ((*this) == CATOmxAny { iVal });
  }
#endif


  /**
   * compute hash key
   */
  CATHashKey Hash() const;

#define OMX_COERCE_NO_ANY_UNWRAP 1

  /**
   * Try to coerce variant to input kind iKind
   * Legal coercition are bool <-> octet <-> int <-> int64 <-> double.
   * This method will fail if a conversion introduces a loss of information or
   * if kind is not supported.
   * For example integer value 35535 can be converted to an omx_double value but
   * will fail to be converted to an omx_octet value.
   */
  HRESULT Coerce(CATOmxKind iKind, unsigned int iFlags = 0);

  /**
   * Resize variant to a variant of size iSize and kind iKind.
   */
  void Resize(int iSize, CATOmxKind iKind = omx_void, CATOmxKind extendedKind = omx_void);

  /**
   * Returns IUnknown pointer at i-th index.
   * Will fail if variant not a list of IUnknown or if i is out of bounds [1,Size()].
   */
  HRESULT GetIUnknown(int i, IUnknown*& oPtr) const;

  /**
   * Destructor.
   */
  ~CATOmxAny();

  /**
   * Set an IUnknown value of extendedKind type.
   */
  void SetIUnknown(const void* root, CATOmxKind extendedKind);
  /**
   * Get an IUnknown value if extendedKind match.
   */
  IUnknown* GetIUnknown(CATOmxKind extendedKind) const;

  /**
   * Returns iKey element of variant, if iKey does not exists an unset variant will be returned.
   */
  const CATOmxAny MapGetValue(const CATOmxKeyString &iKey) const;

  /**
   * Returns iKey element of variant, if iKey does not exists E_FAIL will be returned.
   * @return E_FAIL if iKey does not exists
   * @return E_TYPEMISMATCH if not a map object
   */
  HRESULT MapGetValue(const CATOmxKeyString &iKey, CATOmxAny &oValue) const;

  /**
   * Set iKey to iValue.
   * @return E_TYPEMISMATCH if not a map object
   */
  HRESULT MapSetValue(const CATOmxKeyString &iKey, const CATOmxAny &iValue);


  /** Remove iKey value if it exists.
   * @return E_TYPEMISMATCH if not a map object
   */
  HRESULT MapRemoveValue(const CATOmxKeyString &iKey);
  /** Return Map Size. */
  int MapSize() const;
  typedef  CATOmxPair<CATOmxKeyString, CATOmxAny> MapPairType;
  typedef CATOmxIter<const MapPairType> MapIteratorType;
  /** Return an iterator for the if the underlying object is a Map. */
  MapIteratorType  MapItems() const;
  /**
   * Transform the variant in a Map of <CATOmxKeyString,CATOmxAny> pair.
   */
  void MakeEmptyMap();

  /**
   * Returns iKey element of variant, if iKey does not exists or the type is incorrect an unset variant will be returned.
   * Short syntax.
   */
  inline const CATOmxAny operator () (const CATOmxKeyString &iKey) const { return MapGetValue(iKey); }
  /**
   * Returns i-th item of variant, if index is out of bound or the type is incorrect an unset variant will be returned.
   * Short syntax.
   */
  inline const CATOmxAny operator () (const int i) const { return this->operator[](i); }


private:
  void Init(CATOmxKind k);
  void Reset();
  void Transtype(CATOmxKind k);
  inline int CheckType(CATOmxKind k) const { return m_kind == k && !m_isList; }
  const CATUnicodeString& _String() const;
  CATUnicodeString& _String();
  const CATOmxKeyString& _KeyString() const;
  CATOmxKeyString& _KeyString();
  void BuildTuple(CATOmxKind kind, const void* array, int size);
  void ConvertToListAny(int size);
  void GetData(union CATOmxAnyBuffer& oBuf) const;
  CATOmxBaseTuple* GetTuple() const;
  HRESULT BuildFromSingle(CATOmxKind iKind, const void* iData);
  HRESULT BuildFromTuple(CATOmxKind iKind, const CATOmxBaseTuple& iTuple);
  friend class CATOmxStruct;
};

#ifdef _WINDOWS_SOURCE
#pragma warning( pop )
#endif

// Until C++20, (CATUnicodeString("") == CATOmxAny(42)) yields true which is highly dangerous.
// Warning: to solve problems and not create more, we must not provide the compiler with additional ways to perform comparisons by creating a temporary CATUnicodeString or a temporary CATOmxAny (or both), 
// but either stop it or make the comparison work once the compiler has decided on its own that it is expected to compare a CATUnicodeString and a CATOmxAny (or a derived type if the right hand side argument 
// is a class inheriting from CATOmxAny). Hence the is_same on CATUnicodeString (inherited types not handled, as done by System where applicable) and is_base_of on CATOmxAny.
#if OMX_CODE_PHASE == 1
// However, on AIX, even C++11 is NOT available, so the best option available is to prevent that use case... on Windows.
#if (__cplusplus >= 201103L) // Implies Windows in V5.
template <typename _Ty, typename _Tz>
typename std::enable_if<std::is_same<_Ty, CATUnicodeString>::value && std::is_base_of<CATOmxAny, _Tz>::value, bool>::type operator==(const _Ty &, const _Tz &) = delete;
template <typename _Ty, typename _Tz>
typename std::enable_if<std::is_same<_Ty, CATUnicodeString>::value && std::is_base_of<CATOmxAny, _Tz>::value, bool>::type operator!=(const _Ty &, const _Tz &) = delete;
#endif
#else
// C++20 provides a "reversed" comparison that takes precedence over comparisons with implicit casts, which is ok since the user-defined (CATOmxAny <=> CATUnicodeString) comparison operator will be used.
// Hence providing a hand-made "reversed" comparison operator in the meantime. In V6 only because there is no such thing as AIX in V6 anymore.
#if (__cplusplus < 202002L) && !defined (CATRFLPLMBaseViewServices_H) // Temporary workaround for GCC and "CATBaseUnknown_var() == FALSE" in CATRFLPLMBaseViewServices.cpp :(
template <typename _Ty, typename _Tz>
typename std::enable_if<std::is_same<_Ty, CATUnicodeString>::value && std::is_base_of<CATOmxAny, _Tz>::value, int>::type operator==(const _Ty & o1, const _Tz & o2) { return (o2 == o1); }
template <typename _Ty, typename _Tz>
typename std::enable_if<std::is_same<_Ty, CATUnicodeString>::value && std::is_base_of<CATOmxAny, _Tz>::value, int>::type operator!=(const _Ty & o1, const _Tz & o2) { return (o2 != o1); }
#endif
#endif


#endif // __CATOmxAny_h__
