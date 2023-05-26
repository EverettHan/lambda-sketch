#ifndef __CATOmxJson_h__
#define __CATOmxJson_h__

#include "CATOmxKernel.h"
#include "IUnknown.h"
#include "CATOmxAny.h"
#include "CATOmxDeprecated.h"
class CATOmxKeyString;
class CATOmxUTF8String;

/**
* tranforms JSON 'null' pointers into "(IUnknown*)NULL" instead of default "void"
*/
#define OMX_JSON_NULL_IS_NULL 0x1
/**
* Try to keep lists types if possible
* (by default lists are always stored with kind omx_any)
* notice that empty or heterogeneous lists will still have omx_any kind
*/
#define OMX_JSON_KEEP_LIST_TYPE 0x2
#define OMX_JSON_CONSISTENT_DOUBLE_UNSTREAM 0x4

/**
* JSON parser
*/
class ExportedByCATOmxKernel CATOmxJson
{
  CATOmxJson(CATOmxJson &);
  CATOmxJson & operator=(CATOmxJson &);
  unsigned int m_flags;
public:
  CATOmxJson();
  ~CATOmxJson();

  /**Use a combination of the OMX_JSON_XXX flags here above*/
  inline CATOmxJson & SetFlags(unsigned int iFlags) { m_flags = iFlags; return *this; }

  // Method to activate consistent string to double conversion (see CATOmxAtoF).
  void ActivateConsistentDoubleUnstream();

  /**
  * Parse iStr and build oAny item.
  * @param iJSONString the JSON string to parse
  * @param oValue: a CATOmxAny object containing parse result
  *
  * notice that root element can be an object (ex: {"a": 1} ) or a list (ex: [ 1 ] ), but cannot be an "atom"/"basic value" (ex: 1)
  * notice that for an object attributes must be quoted ({"a": 1}  is valid, {a: 1} is not)
  *
  * for example:
  *   parsing the JSON string {"a":1 , "b":"a string"}
  *   will produce a CATOmxAny that can be scanned the following way
  *   CATOmxAny obj;
  *   CATAssert(SUCCEEDED(CATOmxJon().ParseString("{\"a\": 1, \"b\": \"string\"}",obj)));
  *   CATAssert(obj.ExtendedKind() == omx_map);
  *   CATAssert(obj.Size() == 1); //contains one objects
  *   CATAssert(obj.MapSize() == 2); //that contains 2 attributes
  *   CATAssert(obj("a") == CATOmxAny(1) && obj("b") == CATOmxAny("a string")); //which values are...
  */
  HRESULT ParseString(const CATOmxUTF8String & iJSONString, CATOmxAny & oValue);
  HRESULT parse(const CATOmxUTF8String & iJSONString, CATOmxAny & oValue);

  /**
  * Parses a file containing JSON text
  */
  HRESULT ParseFile(const CATOmxUTF8String & iFileName, CATOmxAny & oAny);
  HRESULT parse_file(const CATOmxUTF8String & iFileName, CATOmxAny & oAny);

  /**
  * All the following methods are deprecated.
  * If you want to produce json text, use CATOmxJsonWriter.
  * If you want to create a CATOmxAny, use CATOmxAny API.
  */
#define OMX_JSON_DEPRECATED_USAGE OMX_DEPRECATED("misuse of CATOmxJson")
  OMX_JSON_DEPRECATED_USAGE virtual void open_map(CATOmxAny & ioMap);
  OMX_JSON_DEPRECATED_USAGE virtual void close_map(CATOmxAny & ioMap);
  OMX_JSON_DEPRECATED_USAGE virtual void add_item(CATOmxAny & ioMap, CATOmxKeyString & iKey, CATOmxAny & iValue);
  OMX_JSON_DEPRECATED_USAGE virtual void open_seq(CATOmxAny & ioSeq);
  OMX_JSON_DEPRECATED_USAGE virtual void close_seq(CATOmxAny & ioseq);
  OMX_JSON_DEPRECATED_USAGE virtual void add_item(CATOmxAny & ioSeq, CATOmxAny & iValue);
  OMX_JSON_DEPRECATED_USAGE virtual void make_null(CATOmxAny & ioValue);
};

#endif
