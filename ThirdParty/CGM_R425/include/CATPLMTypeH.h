/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeH_H
#define CATPLMTypeH_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMRepositoryName.h"
#include "CATPLMTypeDefinitionStrings.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxSR.h"

class CATUnicodeString;
class CATIAdpType;
class CATIAdpExtType;
class CATPLMType;
class CATPLMTypeId;
class CATPLMID;
class CATComponentId;
class CATIAdpType;
class CATIAdpPLMIdentificator;
class CATIPLMComponent;
class CATIType;
class CATProxySpace;
class CATOmxKeyString;
class CATOmxCollecManager;
class CATPLMTypeIdInfo;

// JBB:20181004: for build compatibility.
#if defined(CAT3DXMLImportToolbox_H) || defined(CATPrdASMReference_H) || defined(CATDocDocLinksFinderImpl_H)
#include "CATOmxClassManager.h"
#endif

/**
 * Class enabling to define a universal format of a PLM type (as defined in the metadata files).
 * <br><b>Role</b>: Given the name of a type, or an already binded PLM Component, or a given PLM Type, this class enables to retrieve the @href CATPLMType from the PLM dictionary.
 * It can also be seen as a Universal vehicle of a PLM type.
 *
 * <ul>
 * Generic cache management is implemented for this tool. You must not declare a CATPLMTypeH as "static", it is not supported (and it is useless).
 * </ul>
 *
 *
 * <ul>Collections are defined for use of this CATPLMTypeH. Do not define CATLISTV or CATLISTV collections
 * <li>@href CATPLMTypeHArray, ordered array with no unicity guaranteed</li>
 * <li>@href CATPLMTypeHSet, not ordered a set with unicity guaranteed</li>
 * <li>@href CATPLMTypeHMap, not ordered map with unicity guaranteed.</li>
 * <li>@href CATPLMTypeHtoBaseUnknownMap, association table from a @href CATPLMTypeH to a @href CATBaseUnknown, not ordered, unicity guaranteed.</li>
 * </ul>
 *
 * <ul>Structural definition of the PLM type can be obtained thanks to @href CATPLMTypeDescriptor api which gives access to information such as:
 * <li>Type structural information - GetTypeName, GetModelerName</li>
 * <li>Type inheritance - IsDSType, GetDSType, IsKindOf</li>
 * <li>Type nature (extension, IRPC ...) - IsExtension, IsAbstract, IsIRPCType</li>
 * </ul>
 *
 * <ul>Attributes behaviors of the PLM type can be determined thanks to @href CATPLMTypeAttributesBehaviors api which gives access to information such as:
 * <li>Name of the PLM attribute representing the internal name - GetBasicNamingAttributeId</li>
 * <li>Name of the attributes being part of a minimal set of attributes for a PLM Component - GetMinimalIdAttributes</li>
 * <li>Name of the attributes used for lifecycle operations - GetAttributeId</li>
 * </ul>
 *
 * <ul>Modeler behaviors of the PLM type can be determined thanks to @href CATPLMTypeModelerBehaviors api which gives access to information such as:
 * <li>Prefered instanciation PLM type - GetPreferedInstanciationType</li>
 * </ul>
 *
 * @example
 * <pre>
 * // Sample for type building:
 * CATPLMTypeH TypeBuilder(<my_type_name>);
 * CATPLMType * pPLMType=0;
 * TypeBuilder.GetPLMType(pPLMType);
 * ... I do my job here
 * CATSysReleasePtr(pPLMType);
 * </pre>
 *
 * @example
 * <pre>
 * // Sample for type converting:
 * CATPLMTypeH TypeConverter(PLMType_ProductReference);
 * CATIAdpType * pAdpType=0;
 * TypeBuilder.AsIAdpType(pAdpType);
 * ... I do my job here
 * CATSysReleasePtr(pAdpType);
 * </pre>
 */
class ExportedByCATPLMIdentificationAccess CATPLMTypeH
{
public:
  inline CATPLMTypeH() :m_type(nullptr) {}

  /**
   * Building constructors.
   * <br><b>Role</b>: given a partial information, this constructors finds in the metadata the PLM type corresponding to the given information.
   * If no PLM type matches the given information, the @href CATPLMTypeH will be set as Invalid.
   * Optional given repository information might be used to determine the metadata which will be used to build the PLMType. If none is given, persistency repository will be used.
   * This last point is mostly useful for Import/Export contexts.
   * If the same type name is used for different domains (BusinessType, RelationType, extension, etc…):
   * @use CATPLMFindTypeH::BuildFromName
   */
  CATPLMTypeH(const CATUnicodeString & iTypeName, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  CATPLMTypeH(const CATUnicodeString & iTypeName, const CATPLMID & iPLMIDForRepositoryContext);
  CATPLMTypeH(const CATUnicodeString & iTypeName, const CATProxySpace & iRepositoryContext);
  CATPLMTypeH(const CATOmxKeyString & iTypeName, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  CATPLMTypeH(const CATOmxKeyString & iTypeName, const CATPLMID & iRepositoryContext);
  CATPLMTypeH(const CATOmxKeyString & iTypeName, const CATProxySpace & iRepositoryContext);
  CATPLMTypeH(const char * iTypeName, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  CATPLMTypeH(const char * iTypeName, const CATPLMID & iRepositoryContext);
  CATPLMTypeH(const char * iTypeName, const CATProxySpace & iRepositoryContext);

  /**
   * Constructor
   */
  CATPLMTypeH(const CATPLMTypeId & iPLMType, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  CATPLMTypeH(const CATPLMTypeId & iPLMType, const CATPLMID & iPLMIDForRepositoryContext);
  CATPLMTypeH(const CATPLMTypeId & iPLMType, const CATProxySpace & iRepositoryContext);

  /**
   * Transformation constructors.
   * <br><b>Role</b>: given a PLM type, this constructors checks and wraps the given information to be able to vehicle it between various APIs.
   */
  CATPLMTypeH(CATPLMType * iPLMType);
  CATPLMTypeH(CATIAdpType * iAdpType);
  CATPLMTypeH(CATIAdpExtType * iAdpExtType);
  CATPLMTypeH(CATIType * iType);

  /**
   * Extraction constructors.
   * <br><b>Role</b>: given a Component, this constructors extracts its PLM type to be able to vehicle it between various APIs
   * For complex ids (occurences, paths...), the type of the last component is used
   */
  CATPLMTypeH(const CATPLMID & iComponent);
  CATPLMTypeH(const CATComponentId & iComponent);
  CATPLMTypeH(CATIAdpPLMIdentificator * iComponent);
  CATPLMTypeH(CATIPLMComponent * iComponent);

  /** copy constructor */
  inline CATPLMTypeH(const CATPLMTypeH& other) :m_type(other.m_type) {}
  /** copy operator */
  inline CATPLMTypeH& operator=(const CATPLMTypeH& other) { m_type = other.m_type; return *this; }

  /** (in)equality operators */
  int operator ==(const CATPLMTypeH & iOther) const;
  int operator !=(const CATPLMTypeH & iOther) const;

  inline ~CATPLMTypeH() {}

  /**
   * For delayed initialisation
   */
  HRESULT Init(const CATUnicodeString & iTypeName, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  HRESULT Init(const CATUnicodeString & iTypeName, const CATPLMID & iPLMIDForRepositoryContext);
  HRESULT Init(const CATUnicodeString & iTypeName, const CATProxySpace & iRepositoryContext);
  HRESULT Init(const CATOmxKeyString & iTypeName, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  HRESULT Init(const CATOmxKeyString & iTypeName, const CATPLMID & iPLMIDForRepositoryContext);
  HRESULT Init(const CATOmxKeyString & iTypeName, const CATProxySpace & iRepositoryContext);
  HRESULT Init(const char * iTypeName, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  HRESULT Init(const char * iTypeName, const CATPLMID & iRepositoryContext);
  HRESULT Init(const char * iTypeName, const CATProxySpace & iRepositoryContext);
  HRESULT Init(const CATPLMTypeId & iPLMType, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null);
  HRESULT Init(const CATPLMTypeId & iPLMType, const CATPLMID & iPLMIDForRepositoryContext);
  HRESULT Init(const CATPLMTypeId & iPLMType, const CATProxySpace & iRepositoryContext);
  HRESULT Init(CATPLMType * iPLMType);
  HRESULT Init(CATIAdpType * iAdpType);
  HRESULT Init(CATIAdpExtType * iAdpExtType);
  HRESULT Init(CATIType * iType);
  HRESULT Init(const CATPLMID & iComponent);
  HRESULT Init(const CATComponentId & iComponent);
  HRESULT Init(CATIAdpPLMIdentificator * iComponent);
  HRESULT Init(CATIPLMComponent * iComponent);

  /**
   * Checks the validity of the PLM type.
   * <br><b>Role:</b>This method enables to check if the handle points to a valid PLM type. It can be invalid if:
   * <ul>
   * <li>No PLM type definition matches with the given information in the metadata.</li>
   * <li>The given Component (@href CATPLMID, @href CATIPLMComponent, @href CATComponentId) is invalid.</li>
   * </ul>
   *
   * @return
   * <ul>
   * <li><tt>TRUE</tt> if the handle wraps a PLM type which is fully defined in the metadata.</li>
   * <li><tt>FALSE</tt> if no PLM type is wrapped by the handle. It cannot be used. All methods will lead to a E_INVALIDARG return.</li>
   * </ul>
   */
  inline CATBoolean IsValid() const { return m_type != nullptr; }

  /**
   * Extracts the @href CATPLMTypeId from a PLM Type.
   * <br><b>Role:</b>This method enables to extract the @href CATPLMTypeId from the PLM type retrieved from the entry given by the user.
   *
   * @param oPLMTypeId [out]
   * The extracted type identifier.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the @href CATPLMTypeId was succesfully extracted from the PLM type.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the @href CATPLMTypeH could not be built successfully from the data given by the user. It is Invalid.</li>
   * </ul>
   */
  HRESULT GetPLMTypeId(CATPLMTypeId & oPLMTypeId) const;
  CATPLMTypeId GetPLMTypeId() const;

  /**
   * Give a @href CATPLMType view of a PLM type.
   * <br><b>Role:</b>This method enables to get a pointer on a @href CATPLMType protocol for a PLM type.
   * @example
    * <pre>
  * CATOmxSR<CATPLMType> srMonCATPLMType;
   * MonCATPLMTypeH.GetIAdpType(srMonCATPLMType.AsPtrRef()); // Automatic release on returned CATPLMType when CATOmxSR allocated on the stack is destroyed.
   * {
   *   // ... no need to release the pointer
   * }
   * </pre>
   *
   * @param oPLMType [out, CATBaseUnknown#Release]
   * A pointer on the PLM type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the @href CATPLMType view was succesfully built from the PLM type.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the @href CATPLMTypeH could not be built successfully from the data given by the user. It is Invalid.</li>
   * </ul>
   */
  HRESULT GetPLMType(CATPLMType *& oPLMType) const;
  CATOmxSR<CATPLMType> GetPLMType() const;

  /**
   * Give a @href CATIAdpExtType view of a PLM type.
   * <br><b>Role:</b>This method enables to get a pointer on a @href CATIAdpExtType protocol for a PLM type.
   * @example
   * <pre>
   * CATOmxSR<CATIAdpExtType> srMonCATIAdpExtType;
   * MonCATPLMTypeH.GetIAdpType(srMonCATIAdpExtType.AsPtrRef()); // Automatic release on returned CATIAdpExtType when CATOmxSR allocated on the stack is destroyed.
   * {
   *   // ... no need to release the pointer
   * }
   * </ul>
   * </pre>
   *
   * @param oPLMType [out, CATBaseUnknown#Release]
   * A pointer on the PLM type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the @href CATIAdpExtType view was succesfully built from the PLM type.</li>
   * <li><tt>E_UNEXPECTED</tt> if the PLM type is not an Extension type.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the @href CATPLMTypeH could not be built successfully from the data given by the user. It is Invalid.</li>
   * </ul>
   */
  HRESULT GetIAdpExtType(CATIAdpExtType *& oPLMType) const;

  /**
   * Give a @href CATIAdpType view of a PLM type.
   * <br><b>Role:</b>This method enables to get a pointer on a @href CATIAdpType protocol for a PLM type.
   * @example
   * <pre>
   * CATOmxSR<CATIAdpType> srMonCATIAdpType;
   * MonCATPLMTypeH.GetIAdpType(srMonCATIAdpType.AsPtrRef()); // Automatic release on returned CATIAdpType when CATOmxSR allocated on the stack is destroyed.
   * {
   *   // ... no need to release the pointer
   * }
   * </pre>
   *
   * @param oPLMType [out, CATBaseUnknown#Release]
   * A pointer on the PLM type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the @href CATIAdpType view was succesfully built from the PLM type.</li>
   * <li><tt>E_UNEXPECTED</tt> if the PLM type is an Extension type.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the @href CATPLMTypeH could not be built successfully from the data given by the user. It is Invalid.</li>
   * </ul>
   */
  HRESULT GetIAdpType(CATIAdpType *& oPLMType) const;

  /**
   * Give a @href CATIType view of a PLM type.
   * <br><b>Role:</b>This method enables to get a pointer on a @href CATIType protocol for a PLM type.
   * @example
   * <pre>
   * CATOmxSR<CATIType> srMonCATIType;
   * MonCATPLMTypeH.GetIType(srMonCATIType.AsPtrRef()); // Automatic release on returned CATIType when CATOmxSR allocated on the stack is destroyed.
   * {
   *   // ... no need to release the pointer
   * }
   * </pre>
   *
   * @param oPLMType [out, CATBaseUnknown#Release]
   * A pointer on the PLM type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the @href CATIType view was succesfully built from the PLM type.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the @href CATPLMTypeH could not be built successfully from the data given by the user. It is Invalid.</li>
   * </ul>
   */
  HRESULT GetIType(CATIType *& oPLMType) const;

  /**
   * Computes a hash key for this PLM Type.
   * <br><b>Role:</b>This method enables to get a hask key from a PLM type.
   *
   * @param oKey [out]
   * The computed hash key. The unicity is not guaranteed (ie different PLM Types can have the same hash key).
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the hash key was succesfully computed from the PLM type.</li>
   * <li><tt>E_INVALIDARG</tt> if the @href CATPLMTypeH could not be built successfully from the data given by the user. It is Invalid.</li>
   * </ul>
   */
  unsigned int ComputeHashKey() const;
  HRESULT ComputeHashKey(unsigned int & oKey) const;

  /**
   * Compares this PLM Type to another one (allow sorting).
   * <br><b>Role:</b>This method enables to compare (equal, lesser or greater) this PLM Type to another one.
   *
   * @param iOther [in]
   * The PLM Type to compare.
   *
   * @return
   * <ul>
   * <li><tt>-1</tt> if this PLM Type is lesser than iOther
   * <li><tt>0</tt> if this PLM Type is equal to iOther
   * <li><tt>1</tt> if this PLM Type is greater than iOther
   *
   */
  int Compare(const CATPLMTypeH & iOther) const;

  /**
  * Returns FALSE if typeH is valuated
  */
  inline explicit operator bool() const { return m_type != nullptr; }

  /**
   * For Internal use only
   * Returns a released pointer.
   */
  CATPLMType* GivePLMType() const;

  /**
   * returns the type name (see CATPLMTypeDescriptor::GetTypeName) or empty in case of error
   */
  CATOmxKeyString GetName() const;

protected:
  typedef CATPLMTypeIdInfo* CATPLMTypeIdInfoPtr; //trick for mkcs
  CATPLMTypeIdInfoPtr m_type;
private:
  HRESULT InitAndRelease(CATPLMType* type);
};

extern const ExportedByCATPLMIdentificationAccess CATPLMTypeH CATPLMTypeH_Null;

template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager<CATPLMTypeH>::manager();

#endif
