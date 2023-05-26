/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeProtectedDescriptor_H
#define CATPLMTypeProtectedDescriptor_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeToolsDefinitions.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeDescriptor.h"
class CATUnicodeString;
class CATString;

/**
 * Class enabling to determine semantical description of a PLM type.
 * <br><b>Role</b>: Given a PLM type, this class enables to determine the physical aspect of the PLM type.
 * Those methods should be used only if nothing can be from any help in CATPLMTypeBehaviors and it was discussed with FSD/XJT/PBV/JBB.
 * <ul>
 * <li>Available entry points:</li>
 * <li>protected:GetPackageName</li>
 * <li>protected:IsIRPCType</li>
 * <li>protected:IsERType</li>
 * <code>
 * CATPLMID myComponent;
 * CATPLMTypeProtectedDescriptor Descriptor(myComponent); // Implicit build of CATPLMTypeH.
 * HRESULT rc_er=Descriptor.IsERType();
 * if ( SUCCEEDED(rc_er) )
 * {
 *   if ( rc_er==S_OK )
 *     printf("My Component is a from an ER type");
 *   else
 *     printf("My Component is not from an ER type");
 * }
 *
 * or
 *
 * CATPLMID myComponent;
 * CATPLMTypeH TypeH(myComponent);
 * CATPLMTypeProtectedDescriptor Descriptor(TypeH);
 * HRESULT rc_er=Descriptor.IsERType();
 * if ( SUCCEEDED(rc_er) )
 * {
 *   if ( rc_er==S_OK )
 *     printf("My Component is a from an ER type");
 *   else
 *     printf("My Component is not from an ER type");
 * }
 * </code>
 * </ul>
 *
 * NB: if you already have a CATPLMTypeH, using the static methods will always
 *     be faster than creating a CATPLMTypeDescriptor to call the same method.
 */
class CATPLMTypeProtectedDescriptor : public CATPLMTypeDescriptor
{
public:
  inline CATPLMTypeProtectedDescriptor(const CATPLMTypeH & iType) :CATPLMTypeDescriptor(iType) {}
  inline CATPLMTypeProtectedDescriptor(const CATPLMType* iType) : CATPLMTypeDescriptor(const_cast<CATPLMType*>(iType)) {}

  /**
   * Retrieve the name of the Package in which the PLM type is defined.
   * <br><b>Role:</b>This method enables to determine the name of the Package in which the PLM type is defined.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Package name was found.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  inline HRESULT GetPackageName(CATUnicodeString & oPackageName) const { return GetPackageName(*this, oPackageName); }
  ExportedByCATPLMIdentificationAccess static HRESULT GetPackageName(const CATPLMTypeH & iType, CATUnicodeString & oPackageName);

  /**
   * Determine if the given PLM type is an ER type.
   * <br><b>Role:</b>This method enables to determine if the PLM type is an ER type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the PLM type is defined in the ER PLM Model.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  inline HRESULT IsERType() const { return IsERType(*this); }
  ExportedByCATPLMIdentificationAccess static HRESULT IsERType(const CATPLMTypeH & iType);

  /**
   * Determine if the given PLM type can be used for Authoring in the Session.
   * <br><b>Role:</b>This method enables to determine if the PLM type is part of a Modeler packaged in the Runtime View.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the PLM type is part of a packaged Modeler.</li>
   * <li><tt>S_FALSE</tt> if the PLM type is part of a not packaged Modeler.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  inline HRESULT IsAvailableForAuthoringRuntime() const { return IsAvailableForAuthoringRuntime(*this); }
  ExportedByCATPLMIdentificationAccess static HRESULT IsAvailableForAuthoringRuntime(const CATPLMTypeH & iType);

  /**
   * Determine if the given PLM type matched a core behavior.
   * <br><b>Role:</b>This method enables to determine if the PLM type matched a core behavior.
   *
   * @param iCoreTypesDefinition [in]
   * A context for analysis: can be a combination of (TYPTRP_Reference, TYPTRP_RepReference, TYPTRP_Entity, TYPTRP_Relation, TYPTRP_Instance, TYPTRP_RepInstance, TYPTRP_Connection, TYPTRP_Port).
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the PLM type matched the given behavior.</li>
   * <li><tt>S_FALSE</tt> if the PLM type does not matched the given behavior.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  inline HRESULT IsMatchingCoreBehavior(int iCoreTypesDefinition) const { return IsMatchingCoreBehavior(*this, iCoreTypesDefinition); }
  ExportedByCATPLMIdentificationAccess static HRESULT IsMatchingCoreBehavior(const CATPLMTypeH & iType, int iCoreTypesDefinition);

  /**
   * Retrieves the whole "core behavior" in a raw:
   *   S_OK == CATPLMTypeProtectedDescriptor::IsMatchingCoreBehavior(type,TYPTRP_Instance|TYPTRP_RepInstance);
   * is equivalent to
   *  int coreBehaviorMask;
   *  SUCCEEDED(CATPLMTypeProtectedDescriptor::GetCoreBehaviorMask(type,coreBehaviorMask)) && (coreBehaviorMask & (TYPTRP_Instance|TYPTRP_RepInstance))
   * prefer IsMatchingCoreBehavior which is more elegant
   * It is forbidden to use strict equality on the returned mask:
   *  int coreBehaviorMask;
   *  CATPLMTypeProtectedDescriptor::GetCoreBehaviorMask(type,coreBehaviorMask);
   *  if(coreBehaviorMask == TYPTRP_Instance) {...} //FORBIDDEN
   * do instead
   *  if(coreBehaviorMask & TYPTRP_Instance) {...}  //OK
   */
  ExportedByCATPLMIdentificationAccess static HRESULT GetCoreBehavior(const CATPLMTypeH & iType, int& oCoreTypesDefinition);

  /**
   * return matching 'root'/'core'
   * for IRPC types it is the corresponding PLMCoreXXX type:
   *  PLMCoreReference
   *  PLMCoreRepReference
   *  PLMCoreInstance
   *  PLMCoreRepInstance
   *  PLMPort
   *  PLMConnection
   * for ER entities it is BusinessType
   * for ER relations it is RelationType
   */
  ExportedByCATPLMIdentificationAccess static CATPLMTypeH GetRootType(const CATPLMTypeH & iType);

  /**
   * @nodoc
   * Do not use
   */
  inline HRESULT IsV1CustoType() const { return IsV1CustoType(*this); }
  ExportedByCATPLMIdentificationAccess static HRESULT IsV1CustoType(const CATPLMTypeH & iType);

  /**
   * @nodoc
   * Do not use
   */
  inline HRESULT IsPureV2Type() const { return IsPureV2Type(*this); }
  ExportedByCATPLMIdentificationAccess static HRESULT IsPureV2Type(const CATPLMTypeH & iType);

  /**
   * @see CATPLMType::IsStructuredConnection
   */
  ExportedByCATPLMIdentificationAccess static HRESULT IsStructuredConnection(const CATPLMTypeH & iType);
};
#endif
