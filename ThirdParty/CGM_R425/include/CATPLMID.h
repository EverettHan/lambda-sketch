#ifndef CATPLMID_H
#define CATPLMID_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Private
 * @usage U1
 */


#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATPLMTypeId.h"
#include "CATPLMIdentificationAccessMacros.h"
#include "CATIAV5Level.h"
#include "CATOmxArray.h"
#include "CATOmxVector.h"
#include "CATOmxDeprecated.h"
#include "CATIAV5Level.h"
#include "CATOmxSupport.h" //DS_CXX11_SUPPORT_MOVE_SEMANTIC
#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
#include <utility>
#endif

class CATPLMID_Simple;
class CATPLMID;
class CATPLMID_Any;
class CATPLMRepositoryName;
class CATPLMID_RepositoryLocation;
class CATIAdpPLMIdentificator;
class CATPLMIdentifier;
class CATTrace;
class CATComponentId;
class CATPLMID_Iterator;
class CATPLMIDSimpleVisitor;
class CATPLMID_Simple;
class PlmIDSimple;
template <> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager<CATPLMID_Simple>::manager();
class CATListValCATPLMID;
class CATPLMIDRangeForAdapter;

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi tcx 2005-08-02.20:09:19 [Replace forward declaration of standard streams with osfwd.h] **/
#include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS


/** prefer using default constructor */
extern const ExportedByCATPLMIdentificationAccess CATPLMID CATPLMID_Null;

/**
 * This class is a list of CATPLMID_Simple and allows to "identify" a component or a path of components
 */
class ExportedByCATPLMIdentificationAccess CATPLMID
{
public:

  /**
  * standard contructors etc ...*/
  inline CATPLMID() = default;
  inline CATPLMID(const CATPLMID& iReference) = default;
  inline CATPLMID& operator=(const CATPLMID& iOther) = default;
  inline ~CATPLMID() = default;

  /**
  * IsValidForRemoteUsage
  *
  * @param oValidForRemoteUsage
  *
  *      TRUE  if Value of identification is valid in repository, meaning :
  *                1) it has been given from Query/Expand/Open
  *                2) it has been saved, comitted in repository and validated back in client side
  *      FALSE if it correspond to a dummy identification
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT IsValidForRemoteUsage(CATBoolean & oValidForRemoteUsage) const;

  /**
   * IsEqual
   *
   *  Comparison on value of physical identifier
   *      (excluding all other attributes of PLMID)
   *
   * @param iSecondIdentifier
   *   Second identifier to compare with
   *
   * @param iPhysical
   *   Kind of comparison which is performed
   *     TRUE  : Only on physical Identifier Value
   *     FALSE : Only on logical  Identifier Value
   *
   * @param oIsEqual
   *    Result of the comparison :
   *       TRUE  = the two PLMID shared same value of identifier
   *       FALSE = the two PLMID have distinct values of identifier
   *
   * @return
   *      S_OK if request succeeded <br>
   *      E_FAIL if request failed <br>
  */
  HRESULT IsEqual(const CATPLMID& iSecondIdentifier, const CATBoolean iPhysical, CATBoolean& oIsEqual) const;

  /**
   * Compare
   *
   *  Comparison on value of physical identifier
   *      (excluding all other attributes of PLMID)
   *  Order is a total order.
   *
   * @param iOtherIdentifier
   *   Second identifier to compare with
   *
   *
   * @return
   *      -1 if inferior to iOtherIdendifier<br>
   *       1 if superior to iOtherIdendifier<br>
   *       0 if equal to iOtherIdendifier<br>
   *       2 if there was an error<br>
   */
  int Compare(const CATPLMID &iOtherIdentifier) const;

  /**
   * Compare by major id.
   *
   *  Comparison on value of major family identifier
   *      (excluding all other attributes of PLMID)
   *  Order is a total order.
   *
   * @param iOtherIdentifier
   *   Second identifier to compare with
   *
   *
   * @return
   *      -1 if inferior to iOtherIdendifier<br>
   *       1 if superior to iOtherIdendifier<br>
   *       0 if equal to iOtherIdendifier<br>
   *       2 if there was an error<br>
   */
  int CompareByMajorId(const CATPLMID &iOtherIdentifier) const;

  /**
  * Checks if PLMIDs belongs to the same major family.
  * Is working with simple and complex ids.
  *
  * @param iPLMID
  *        Id compare with
  *
  * @return
  * S_OK    : MajorIds are found and equal
  * S_FALSE : MajorIds are not found
  *           MajorIds are found and not equal
  *           Depth is different
  * E_FAIL  : Otherwise (empty handles, ...)
  */
  HRESULT HasSameMinorFamily(const CATPLMID & iToCompare) const;

  /**
  * Detection of Complex ID
  *
  * @param oComplex
  *    Complexity Status
  *      TRUE  if Component is Complex identified<br>
  *      FALSE if Component is simple identified<br>
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT IsComplex(CATBoolean& oComplex) const;

  /**
  * Get Elementary ID Path
  *
  * @param oNodes
  *    List of simple Cell
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetElementaryPath(CATListValCATPLMID & oNodes) const;
  HRESULT GetElementaryPath2(CATOmxArray<CATPLMID_Simple> &oNodes) const;
  CATOmxArray<CATPLMID_Simple> GetPath() const;

  /**
   * ComputeHashKey
   */
  unsigned int ComputeHashKey() const;
  unsigned int ComputeHashKeyByMajorId() const;

  /**
  * conversion CATPLMID <=> CATIAdpPLMIdentificator*
  * succeed if input is not null
  */
  static HRESULT GetPLMIDFromAdpIdentificator(CATIAdpPLMIdentificator* iAdpId, CATPLMID & oPLMID);
  static HRESULT GetAdpIdentificatorFromPLMID(const CATPLMID & iID, CATIAdpPLMIdentificator*& oPLMIdentificator);


#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
  inline CATPLMID(CATPLMID&& iOther) :m_simples(std::move(iOther.m_simples)) {}
  inline CATPLMID& operator=(CATPLMID&& iOther) { m_simples = std::move(iOther.m_simples); return *this; }
#endif

  /** test emptiness */
  inline explicit operator bool() const { return m_simples.Size() != 0; }
  inline int IsNull() const { return m_simples.Size() == 0; }


  /**
   * Debug only.
   * Displays the PLMID according to iFormat
   */
  CATUnicodeString ToString(unsigned int iFormat = 0) const;


  /**
  * Unitary construction (Append value of CATPLMID_Simple)
  *
  * @param oSimple
  *
  * @return
  *      S_OK   if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  inline HRESULT AppendFreeSimpleID(CATPLMID_Simple & iSimple) { return Append(iSimple); }
  HRESULT Append(const CATPLMID_Simple & iSimple);

  /**internal usage*/
  HRESULT AppendFreeSimpleID(const PlmIDSimple *iSimple);

  /**
  * DefineComplex
  *
  * @param iNodes
  *
  * @return
  *      S_OK   if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT DefineComplex(const CATListValCATPLMID & iNodes);


  /**
   * Full comparison of all elements
   */
  int operator==(const CATPLMID & iOtherPLMID) const;
  inline int operator!=(const CATPLMID & iOtherPLMID) const { return !this->operator==(iOtherPLMID); }


  /**
  * if empty returns E_FAIL
  * else return S_OK
  *   if size==1 oSimple is TRUE
  *   if size!=1 oSimple is FALSE and oFirst is the first element
  */
  HRESULT IsSimple(CATBoolean & oSimple, CATPLMID_Simple & oFirst) const;

  /** Constructor from a CATPLMID_Simple*/
  inline CATPLMID(const CATPLMID_Simple& iSimple) { Append(iSimple); }
  CATPLMID& operator=(const CATPLMID_Simple& iSimple);

  /**
   * Conversion to a CATPLMID_Single
   * if this contains a single CATPLMID_Single, returns it,
   * else returns a NULL CATPLMID_Simple
   */
  CATPLMID_Simple AsSimple() const;

  /**
   * on a valid "simple" PLMID (size==1), returns the physicalid field.
   * else return NULL
   */
  CATPLMID_Any GetPhysicalId() const;


  /**
  * Size
  */
  inline int Size() const { return m_simples.Size(); }


  /**
   * access i-th element where i is in [ 1, Size() ]
   */
  HRESULT GetElementAt(int i, CATPLMID_Simple& oSimple) const;
  CATPLMID_Simple operator[](int i) const;

  /**
  * GetRepositoryName
  *
  * @param oRepositoryName
  *    Repository Name
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetRepositoryName(CATPLMRepositoryName & oRepositoryName) const;

  CATPLMIDRangeForAdapter begin() const;
  CATPLMIDRangeForAdapter end() const;

  /** obsolete */
  HRESULT Dump(CATTrace &iTrace) const;
  HRESULT GetUnicodeDump(CATUnicodeString& Dump) const;
  HRESULT Dump(ostream &iout) const;
  HRESULT GetType(CATPLMTypeId & oTypeId) const;
  HRESULT IsStrictyEqualTo(const CATPLMID& iSecondIdentifier, CATBoolean& oIsEqual) const;
  HRESULT ComputeHashKey(unsigned int& oKey) const { oKey = ComputeHashKey(); return S_OK; }
  HRESULT ClearContents() { m_simples.RemoveAll(); return S_OK; }
  OMX_DEPRECATED("meaningless") HRESULT GetSiteOfProvider(CATPLMID_RepositoryLocation & oSiteOfRepository) const;
  HRESULT GetToPLMIdentifier(CATPLMIdentifier& oPLMIdentifier) const;
  HRESULT SetFromPLMIdentifier(const CATPLMIdentifier  & iPLMIdentifier);
  inline OMX_DEPRECATED("not implemented") HRESULT SetType(const CATPLMTypeId & iTypeReference) { return E_NOTIMPL; }
  OMX_DEPRECATED("meaningless") HRESULT GetReference(CATPLMID &oReference) const;
  inline HRESULT Access(const unsigned int iItemNumber, CATPLMID_Simple & oSimple) const { return GetElementAt(iItemNumber, oSimple); }
  inline HRESULT Size(unsigned int & oNumberOfItem) const { oNumberOfItem = Size(); return S_OK; }
  OMX_DEPRECATED("Use GetElementAt") HRESULT VisitPLMIDSimples(CATPLMIDSimpleVisitor & iVisitor);
  HRESULT GetTypeOfRepository(CATPLMRepositoryName & oRepositoryName) const { return GetRepositoryName(oRepositoryName); }
  HRESULT IsValidForSpaceRegistration(CATBoolean & oValidForSpaceRegistration) const;
private:
  friend class CATPLMIDInternals;
  const PlmIDSimple *GetFirstHandle() const;

  CATOmxVector<PlmIDSimple> m_simples;
};

/** range based for loop adapter for CATPLMID */
class CATPLMIDRangeForAdapter
{
  friend class CATPLMID;
  CATOmxVector<PlmIDSimple> m_simples;
  int m_cursor;
public:
  inline CATPLMIDRangeForAdapter& operator++() { ++m_cursor; return *this; }

  ExportedByCATPLMIdentificationAccess CATPLMID_Simple operator*() const;

  inline bool operator!=(const CATPLMIDRangeForAdapter& other) const { return m_cursor != other.m_cursor; }
};

/** obsolete */
class ExportedByCATPLMIdentificationAccess CATPLMID_Iterator : public CATPLMID
{
  int m_index;
public:
  /**
   * Constructor
   */
  CATPLMID_Iterator(const CATPLMID& iReference);
  /**
  * Next
  */
  HRESULT Next(CATPLMID_Simple & oSimple);
private:
  CATPLMID_Iterator();
  CATPLMID_Iterator(const CATPLMID_Iterator& iReference);
  CATPLMID_Iterator& operator=(const CATPLMID_Iterator& iCopy);
};


#include "CATLISTV_CATPLMID.h"

#endif
