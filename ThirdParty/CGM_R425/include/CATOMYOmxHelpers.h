// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// CATOMYOmxHelpers.h
// Header definition of CATOMYOmxHelpers
//
//===================================================================
// 
// BE CAREFULL, WITH THIS BIG SH...T OF CATOmxAny, YOU ARE NOT ABLE TO MAKE THE DIFFERENCE BETWEEN
// AN ANY CONTAINING ONE ELEMENT 
// AND
// AN ANY CONTAINING A LIST OF ONE ELEMENT...
//
//===================================================================
//
// Usage notes:
//  --------------------------------------------
// |  Here is the way to FILL a CATOmxAny with: |
//  --------------------------------------------

// 1- a CATBoolean:
//    CATOmxAny any;
//    any.SetBoolean(TRUE);
//    type of any generated omx_boolean

// 2- a list of OmxAny :
//      CATOmxAny val1;  // Generated with previous
//      CATOmxAny val2;
//      CATOmxAny any;
//      any.Append(val1);
//      any.Append(val2);
//      type of any generated : same as val1 if all elements are identical
//      Warning : we do not support list of heterogenous elements

// 3- a double:
//      CATOmxAny any;
//      any.SetDouble(888);
//      type of any generated omx_double

// 4- a list of double:
//      CATOmxAny val1; // Generated with previous
//      CATOmxAny val2;
//      CATOmxAny any;
//      any.Append(val1);
//      any.Append(val2);
//      type of any generated : same as val1 if all elements are identical
//      Warning : we do not support list of heterogenous elements

// 5- an integer:
//      CATOmxAny any;
//      any.SetInteger(888);
//      type of any generated omx_int

// 6- a list of integer:
//      CATOmxAny val1; // Generated with previous
//      CATOmxAny val2;
//      CATOmxAny any;
//      any.Append(val1);
//      any.Append(val2);
//      type of any generated : same as val1 if all elements are identical
//      Warning : we do not support list of heterogenous elements

// 7- a CATUnicodeString
//      CATOmxAny any;
//      any.SetString(888);
//      type of any generated omx_string

// 8- a list of CATUnicodeString
//      CATOmxAny val1;  // Generated with previous
//      CATOmxAny val2;
//      CATOmxAny any;
//      any.Append(val1);
//      any.Append(val2);
//      type of any generated : same as val1 if all elements are identical
//      Warning : we do not support list of heterogenous elements

// 9- a date
//      CATOmxAny any;
//      any.SetTime(888);
//      type of any generated omx_int64, extended_kind==omx_time

// 10- a list of date
//      CATOmxAny val1;  // Generated with previous
//      CATOmxAny val2;
//      CATOmxAny any;
//      any.Append(any1);
//      any.Append(any2);
//      type of any generated : same as val1 if all elements are identical
//      Warning : we do not support list of heterogenous elements

// 11- an enum
//      CATOmxAny any;
//      CATString Key("toto");
//      CATOmxKeyString enumKey(Key.CastToCharPtr());
//      any.SetEnum(enumKey,3);
//      type==omx_IUnknown , extended_kind==omx_enum

// 12- a list of enum
//      CATOmxAny val1;  // Generated with previous
//      CATOmxAny val2;
//      CATOmxAny any;
//      any.Append(any1);
//      any.Append(any2);
//      type of any generated : same as val1 if all elements are identical
//      Warning : we do not support list of heterogenous elements

// 13- for binary and list of binary, you can use CATPLMOmxHelpers::SetBinary

// 14- for PLMID and list of PLMID, you can use CATPLMOmxHelpers::SetPLMID

// 15- for CATPLMTypeId and list of CATPLMTypeId, you can use CATPLMOmxHelpers::SetPLMTypeId

//  --------------------------------------
// | Here is the way to READ a CATOmxAny: |
//  --------------------------------------

// 1-For all types except binary,PLMID,CATPLMTypeId, here is what you have to do:
// Suppose you want to retrieve a list of type XXX:
//      XXX id;
//      CATOmxKind tm_kind;
//      CATOmxKind kind=iAny.Kind();
//      if(kind!=omx_XXX)return E_FAIL;
//      int size=iAny.Size();
//      for(int i=1;i<=size;i++){
//        const CATOmxAny& tmp_any=iAny[i];
//        tm_kind=tmp_any.Kind();
//        if(tm_kind!=omx_XXX){return E_FAIL;break;}
//        id=tm_kind.GetXXX();
//        oListId.Append(id);
//      }

// Suppose you want to retrieve a type XXX:
//      XXX id;
//      CATOmxKind kind=iAny.Kind();
//      if(kind!=omx_XXX)return E_FAIL;
//      id=iAny.GetXXX();

// 2-For  binary,PLMID,CATPLMTypeId, we provide services:
// CATPLMOmxHelpers::GetPLMID, CATPLMOmxHelpers::GetBinary, CATPLMOmxHelpers::GetPLMTypeId

// ODT: TSTCATPLMServicesOmx
//
//===================================================================
// June 2020  Creation: EPB
//===================================================================

#ifndef CATOMYOmxHelpers_H
#define CATOMYOmxHelpers_H

#include "ObjectModelerSystem.h"

// ObjectModelerSystem
#include "CATA5CsvRow.h"

// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxArray.h"
#include "CATOmxOMap.h"

// SpecialAPI
#include "CATSysErrorDef.h"

 // System
#include "CATBinary.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"

class CATOmxKeyString;
class CATUnicodeString;
#include "CATCollec.h"
class CATLISTV(CATUnicodeString);
class CATLISTV(CATTime);
class CATLISTV(CATBoolean);
class CATLISTV(CATBinary);
class CATString;

class ExportedByObjectModelerSystem CATOMYOmxHelpers
{
public:

  /**
   * Store CATBinary on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATBinary on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATBinary.
   * @param iId [in]
   *   CATBinary stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT SetBinary(CATOmxAny& ioAny, const CATBinary& iBinary);

  /**
   * Store CATListOfCATBinary on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATListOfCATBinary on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATListOfCATBinary.
   * @param iId [in]
   *   CATListOfCATBinary stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT SetBinary(CATOmxAny& ioAny, const CATLISTV(CATBinary)& iListBinary);

  /**
   * Store CATListOfCATBinary on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATBinary on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATListOfCATBinary.
   * @param iBinary [in]
   *   CATBinary stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT AppendBinary(CATOmxAny& ioAny, const CATBinary& iBinary);

  /**
  * <br><b>Role</b>:
  * @param iVal
  *
  * @param iIndex
  *
  * @param oAnyVal
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  static HRESULT SetEnum(const CATOmxKeyString& iVal, int iIndex, CATOmxAny& oAny);

  static HRESULT AppendEnum(const CATOmxKeyString& iVal, int iIndex, CATOmxAny& ioAny);

  static HRESULT SetEnum(const CATOmxOMap<int, CATOmxKeyString>& iMapIndexToKey, CATOmxAny& oAny);

  static HRESULT SetEnum(const CATOmxOMap<CATOmxKeyString, int>& iMapKeyToIndex, CATOmxAny& oAny);

  /**
   * Store CATListOfDouble on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATListOfDouble on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATBinary.
   * @param iListInt [in]
   *   CATListOfDouble stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   *
   */
  static HRESULT SetDouble(CATOmxAny& ioAny, const CATListOfDouble& iListDouble);

  static HRESULT SetDouble(CATOmxAny& ioAny, const CATOmxArray<double>& iListDouble);

  static HRESULT SetDouble(CATOmxAny& ioAny, double iDouble);

  /**
   * Store double on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store double on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the double.
   * @param iDouble [in]
   *   double stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT AppendDouble(CATOmxAny& ioAny, double iDouble);

  static HRESULT SetInteger(CATOmxAny& ioAny, int i);

  /**
   * Store CATListOfInt on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATListOfInt on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATBinary.
   * @param iListInt [in]
   *   CATListOfInt stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT SetInteger(CATOmxAny& ioAny, const CATListOfInt& iListInt);

  static HRESULT SetInteger(CATOmxAny& ioAny, const CATOmxArray<int>& iListInt);

  /**
   * Store int on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store int on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the int.
   * @param i [in]
   *   int stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT AppendInteger(CATOmxAny& ioAny, int i);

  /**
   * Store CATLISTV(CATUnicodeString) on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATLISTV(CATUnicodeString) on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATBinary.
   * @param iListTime [in]
   *   CATLISTV(CATUnicodeString) stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT SetString(CATOmxAny& ioAny, const CATLISTV(CATUnicodeString)& iListString);
  static HRESULT SetString(CATOmxAny& ioAny, const CATOmxArray<CATUnicodeString>& iListString);
  static HRESULT SetString(CATOmxAny& ioAny, const CATOmxOrderedOSet<CATUnicodeString>& iStringSet);
  static HRESULT SetString(CATOmxAny& ioAny, const CATUnicodeString& iString);

  /**
   * Store CATUnicodeString on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATUnicodeString on CATOmxAny.
   *
   * @param ioAny [inout]
   *   CATOmxAny that stores the CATUnicodeString.
   * @param iString [in]
   *   CATUnicodeString stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT AppendString(CATOmxAny& ioAny, const CATUnicodeString& iString);

  /**
   * Store CATTime on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATTime on CATOmxAny.
   *
   * @param ioAny [out]
   *   CATOmxAny that stores the CATBinary.
   * @param iListTime [in]
   *   CATTime stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   *
   */
  static HRESULT SetTime(CATOmxAny& ioAny, const CATTime& iTime);

  /**
   * Store CATLISTV(CATTime) on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATLISTV(CATTime) on CATOmxAny.
   *
   * @param ioAny [out]
   *   CATOmxAny that stores the CATBinary.
   * @param iListTime [in]
   *   CATLISTV(CATTime) stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT SetTime(CATOmxAny& ioAny, const CATLISTV(CATTime)& iListTime);

  static HRESULT SetTime(CATOmxAny& ioAny, const CATOmxArray<CATTime>& iListTime);

  /**
   * Store CATTime on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Store CATTime on CATOmxAny.
   *
   * @param ioAny [out]
   *   CATOmxAny that stores the CATTime.
   * @param iTime [in]
   *   CATTime stored on CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if an error has occurred
   */
  static HRESULT AppendTime(CATOmxAny& ioAny, const CATTime& iTime);

  /**
  * Store CATLISTV(CATBoolean) on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Store CATLISTV(CATBoolean) on CATOmxAny.
  *
  * @param ioAny [out]
  *   CATOmxAny that stores the CATBinary.
  * @param iListTime [in]
  *   CATLISTV(CATBoolean) stored on CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> if an error has occurred
  *
  */
  static HRESULT SetBoolean(CATOmxAny& ioAny, const CATLISTV(CATBoolean)& iListBoolean);

  static HRESULT SetBoolean(CATOmxAny& ioAny, const CATOmxArray<CATBoolean>& iListBoolean);

  static HRESULT SetBoolean(CATOmxAny& ioAny, CATBoolean iBool);

  static HRESULT SetBoolean(CATOmxAny& ioAny, bool iBool);

  /**
  * Store CATBoolean on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Store CATBoolean on CATOmxAny.
  *
  * @param ioAny [inout]
  *   CATOmxAny that stores the CATBoolean.
  * @param iBoolean [in]
  *   CATBoolean stored on CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> if an error has occurred
  *
  */
  static HRESULT AppendBoolean(CATOmxAny& ioAny, CATBoolean iBoolean);

  /**
  * Store CATBoolean on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Store CATBoolean on CATOmxAny.
  *
  * @param ioAny [inout]
  *   CATOmxAny that stores the CATBoolean.
  * @param iBoolean [in]
  *   bool stored on CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> if an error has occurred
  *
  */
  static HRESULT AppendBoolean(CATOmxAny& ioAny, bool iBoolean);

  /**
  * Retrieve CATBinary on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve CATBinary on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the CATBinary.
  * @param oBinary [out]
  *   CATBinary stored on the CATOmxAny.
  * @param iIndex [in]
  *   iIndex must be in [1,ioAny.Size()].
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> If an error has occurred.
  *                       If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny) at the iIndex, we return E_FAIL.
  *   <code>E_INVALIDARG</code> iIndex<1
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetBinary(const CATOmxAny& iAny, CATBinary& oBinary, int iIndex = 1);

  /**
  * Retrieve CATUnicodeString on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve CATUnicodeString on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the CATBinary.
  * @param oString [out]
  *   CATBinary stored on the CATOmxAny.
  * @param iIndex [in]
  *   iIndex must be in [1,ioAny.Size()].
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> If an error has occurred.
  *                       If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny) at the iIndex, we return E_FAIL.
  *   <code>E_INVALIDARG</code> iIndex<1
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetString(const CATOmxAny& iAny, CATUnicodeString& oString, int iIndex = 1);

  /**
  * Retrieve double on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve double on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the double.
  * @param oString [out]
  *   double stored on the CATOmxAny.
  * @param iIndex [in]
  *   iIndex must be in [1,ioAny.Size()].
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> If an error has occurred.
  *                       If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny) at the iIndex, we return E_FAIL.
  *   <code>E_INVALIDARG</code> iIndex<1
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetDouble(const CATOmxAny& iAny, double& oDouble, int iIndex = 1);

  /**
  * Retrieve integer on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve int on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the int.
  * @param oInt [out]
  *   int stored on the CATOmxAny.
  * @param iIndex [in]
  *   iIndex must be in [1,ioAny.Size()].
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> If an error has occurred.
  *                       If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny) at the iIndex, we return E_FAIL.
  *   <code>E_INVALIDARG</code> iIndex<1
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetInteger(const CATOmxAny& iAny, int& oInt, int iIndex = 1);

  /**
  * Retrieve long on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve int on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the int.
  * @param oLong [out]
  *   long stored on the CATOmxAny.
  * @param iIndex [in]
  *   iIndex must be in [1,ioAny.Size()].
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> If an error has occurred.
  *                       If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny) at the iIndex, we return E_FAIL.
  *   <code>E_INVALIDARG</code> iIndex<1
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetLong(const CATOmxAny& iAny, CATLONG64& oLong, int iIndex = 1);

  /**
   * Retrieve double on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Retrieve int on CATOmxAny.
   *
   * @param iAny [in]
   *   CATOmxAny that will store the int.
   * @param oString [out]
   *   double stored on the CATOmxAny.
   * @param iIndex [in]
   *   iIndex must be in [1,ioAny.Size()].
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> If an error has occurred.
   *                       If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny) at the iIndex, we return E_FAIL.
   *   <code>E_INVALIDARG</code> iIndex<1
   *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
   *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
   */
  static HRESULT GetEnum(const CATOmxAny& iAny, int& oInt, int iIndex = 1);

  static HRESULT GetEnum(const CATOmxAny& iAny, CATOmxKeyString& oKey, int iIndex = 1);

  static HRESULT GetEnum(const CATOmxAny& iAny, int& oInt, CATOmxKeyString& oKey, int iIndex = 1);

  static HRESULT GetEnum(const CATOmxAny& iAny, CATOmxOMap<int, CATOmxKeyString>& oMapIntToKey);

  static HRESULT GetEnum(const CATOmxAny& iAny, CATOmxOMap<CATOmxKeyString, int>& oMapIntToKey);

  /**
  * Retrieve CATTime on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve CATTime on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the CATBinary.
  * @param oTime [out]
  *   CATTime stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid CATBinary
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetTime(const CATOmxAny& iAny, CATTime& oTime, int iIndex = 1);

  /**
  * Retrieve CATBoolean on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve CATBoolean on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the CATBoolean.
  * @param oTime [out]
  *   CATBoolean stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid CATBinary
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetBoolean(const CATOmxAny& iAny, CATBoolean& oBool, int iIndex = 1);

  static HRESULT GetBoolean(const CATOmxAny& iAny, bool& oBool, int iIndex = 1);

  /**
  * Retrieve list of CATBinary on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve list of CATBinary on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the CATBinary.
  * @param oListBinary [out]
  *   CATBinary stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid CATBinary
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetBinary(const CATOmxAny& iAny, CATLISTV(CATBinary)& oListBinary);

  static HRESULT GetBinary(const CATOmxAny& iAny, CATOmxArray<CATBinary>& oListBinary);

  /**
  * Retrieve list of CATUnicodeString on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve list of CATUnicodeString on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the CATUnicodeString.
  * @param oListOfString [out]
  *   CATBinary stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid CATUnicodeString
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetString(const CATOmxAny& iAny, CATLISTV(CATUnicodeString)& oListOfString);
  static HRESULT GetString(const CATOmxAny& iAny, CATOmxArray<CATUnicodeString>& oListOfString);
  static HRESULT GetString(const CATOmxAny& iAny, CATOmxOrderedOSet<CATUnicodeString>& oListOfString);

  /**
  * Retrieve list of double on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve list of double on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the double.
  * @param oListOfDouble [out]
  *   double stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid double
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetDouble(const CATOmxAny& iAny, CATListOfDouble& oListOfDouble);

  static HRESULT GetDouble(const CATOmxAny& iAny, CATOmxArray<double>& oListOfDouble);

  /**
  * Retrieve list of integer on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve list of integer on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the integer.
  * @param oListOfInt [out]
  *   list of integer stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid integer
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetInteger(const CATOmxAny& iAny, CATListOfInt& oListOfInt);

  static HRESULT GetInteger(const CATOmxAny& iAny, CATOmxArray<int>& oListOfInt);

  /**
  * <br><b>Role</b>:
  * @param iAny
  *
  * @param oListOfInt
  *
  * @return
  *   <code>S_OK</code>
  *   <code>E_FAIL</code>
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetEnum(const CATOmxAny& iAny, CATListOfInt& oListOfInt);

  static HRESULT GetEnum(const CATOmxAny& iAny, CATOmxArray<int>& oListOfInt);

  /**
  * <br><b>Role</b>:
  * @param iAny
  *
  * @param oListOfKey
  *
  * @return
  *   <code>S_OK</code>
  *   <code>E_FAIL</code>
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetEnum(const CATOmxAny& iAny, CATOmxArray<CATOmxKeyString>& oListOfKey);

  /**
  * Retrieve list of time on CATOmxAny.
  *
  * <br><b>Role</b>:
  * Retrieve list of time on CATOmxAny.
  *
  * @param iAny [in]
  *   CATOmxAny that will store the time.
  * @param oListOfInt [out]
  *   list of time stored on the CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> If everything ran ok.
  *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
  *   <code>E_FAIL</code> ioAny doesn't contain any valid integer
  *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
  *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
  */
  static HRESULT GetTime(const CATOmxAny& iAny, CATLISTV(CATTime)& oListOfTime);

  static HRESULT GetTime(const CATOmxAny& iAny, CATOmxArray<CATTime>& oListOfTime);

  /**
   * Retrieve list of boolean on CATOmxAny.
   *
   * <br><b>Role</b>:
   * Retrieve list of boolean on CATOmxAny.
   *
   * @param iAny [in]
   *   CATOmxAny that will store the boolean.
   * @param oListOfInt [out]
   *   list of boolean stored on the CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> If everything ran ok.
   *                     If the CATOmxAny contains a CATOmxAny which type is omx_void and size==0 (unset CATOmxAny)<=>empty list, we return S_OK.
   *   <code>E_FAIL</code> ioAny doesn't contain any valid integer
   *   <code>S_ATTR_NOT_SET</code> Please #include "CATOmyErrorDef.h"
   *   <code>E_TYPEMISMATCH</code> Please #include "CATOmxHRESULT.h"
   */
  static HRESULT GetBoolean(const CATOmxAny& iAny, CATLISTV(CATBoolean)& oListOfBoolean);

  static HRESULT GetBoolean(const CATOmxAny& iAny, CATOmxArray<CATBoolean>& oListOfBoolean);

  /**
   * Retrieve Size of CATOmxAny
   * It only works if any contains following supported types:  string,double,int,enum,date multivaluated or not.
   *
   * <br><b>Role</b>:
   * Retrieve Size of CATOmxAny.
   *
   * @param ioAny [in]
   *   Type of CATOmxAny.
   * @param oSize [out]
   *   Number of objects stored on the CATOmxAny.
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *                       Type of iAny is omx_void and size==0,oType=PLMTYPE_OMX_UNSET.
   *   <code>E_FAIL</code>
   *                       Type of iAny is omx_void and size!=0,oType=PLMTYPE_OMX_ERROR.
   *                       iAny stores more than one type of object so the call GetType has no sense, oType=PLMTYPE_OMX_ERROR.
   *                       iAny stores a CATOmxAny which type is omx_void, oType=PLMTYPE_OMX_ERROR.
   *                       iAny stores a CATOmxAny which type is unknown. oType=PLMTYPE_OMX_ERROR.
   */
  static HRESULT GetSize(const CATOmxAny& iAny, int& oSize);

  /*
  *Three empty elements:
  * monovaluated attribute: BuildEmptyTarget with isMulti == false
  * multivaluated attribute: BuildEmptyTarget with isMulti == true
  * one element inside a multivaluated attribute: BuildEmptyTargetOfAList
  */
  /*attribute is multivaluated or not*/
  static void BuildEmptyTarget(const CATOmxKind iFieldDescription, bool isMulti, CATOmxAny& oTarget);

  /*Specific treatment made for an empty target found on a specific element of a list*/
  static void BuildEmptyTargetOfAList(const CATOmxKind iFieldDescription, CATOmxAny& oTarget);

private:
  static void _DetectEmptyOmxDate();

  static void _DetectEmptyOmxBinary();

  static void _DetectEmptyOmxEnum();

  static void _DetectEmptyOmxUuid();

  static void _DetectEmptyOmxBoolean();

  static void _DetectEmptyDefault();

};

#endif
