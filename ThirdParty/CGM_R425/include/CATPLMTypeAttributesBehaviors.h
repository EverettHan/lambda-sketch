/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeAttributesBehaviors_H
#define CATPLMTypeAttributesBehaviors_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeDescriptor.h"
#include "CATCollec.h"
class CATLISTV(CATString);
class CATString;
class CATPLMTypeRelationIter;

/**
 * Class enabling to determine semantical description of a PLM type.
 *
 * <br><b>Role</b>: Given a PLM type, this class enables to determine the physical aspect of the PLM type.
 * <ul>
 * <li>Available entry points:</li>
 * <li>public:GetBasicNamingAttributeId</li>
 * <li>public:GetMinimalIdAttributes</li>
 * <code>
 * CATPLMTypeH TypeH(myComponent);
 * CATPLMTypeAttributesBehaviors Behavior(TypeH);
 * CATLISTV(CATString) Attributes;
 * HRESULT rc_attributes=Behavior.GetMinimalIdAttributes(Attributes);
 * if ( SUCCEEDED(rc_attributes) )
 * {
 *   if ( rc_attributes==S_OK )
 *     printf("My Component has a minimal attribute set");
 *   else
 *     printf("My Component does not implement this behavior");
 * }
 * </code>
 * </ul>
 */
class CATPLMTypeAttributesBehaviors : public CATPLMTypeDescriptor
{
public:
  /** all constructors are deprecated, use static methods of this class on CATPLMTypeH */
  inline CATPLMTypeAttributesBehaviors(const CATPLMTypeH & iPLMType) :CATPLMTypeDescriptor(iPLMType) {}
  inline CATPLMTypeAttributesBehaviors(const CATPLMTypeId & iPLMType, const CATPLMRepositoryName & iRepository = CATPLMRepositoryName_Null) : CATPLMTypeDescriptor(iPLMType, iRepository) {}
  inline CATPLMTypeAttributesBehaviors(CATPLMType * iPLMType) : CATPLMTypeDescriptor(iPLMType) {}
  inline CATPLMTypeAttributesBehaviors(CATIAdpType * iAdpType) : CATPLMTypeDescriptor(iAdpType) {}
  inline CATPLMTypeAttributesBehaviors(const CATComponentId & iComponent) : CATPLMTypeDescriptor(iComponent) {}
  inline CATPLMTypeAttributesBehaviors(CATIAdpPLMIdentificator * iComponent) : CATPLMTypeDescriptor(iComponent) {}
  inline CATPLMTypeAttributesBehaviors(const CATPLMID& iId) : CATPLMTypeDescriptor(iId) {}

/**
 * Returns the attribute being the basic naming in the metadata.
 * <br><b>Role:</b>This method enables, for a given PLM type, to retrieve in the metadata the attribute symbolizing the basic naming. Most of the time, it should be <code>PLM_ExternalID</code>, <code>V_name</code> or <code>name</code>.
 *
 * @param oKey [out]
 * The attribute found.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if an attribute was found for the given type.</li>
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  inline HRESULT GetBasicNamingAttributeId(CATString & oAttribute, CATBoolean iUseBLs = TRUE) const { return GetBasicNamingAttributeId(*this, oAttribute, iUseBLs); }
  ExportedByCATPLMIdentificationAccess static HRESULT GetBasicNamingAttributeId(const CATPLMTypeH & iTypeh, CATString & oAttribute, CATBoolean iUseBLs = TRUE);

/**
 * Returns a set of minimal attributes available for a component identification.
 * <br><b>Role:</b>This method enables to retrieve a minimal set of attributes for a given PLM type. These attributes do not guarantee the unicity of a Component and cannot be interpreted as a Unique Key.
 *
 * @param oAttributes [out]
 * The atributes being part of the minimal set.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if attributes are found for the given type.</li>
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  inline HRESULT GetMinimalIdAttributes(CATLISTV(CATString) & oAttributes) const { return GetMinimalIdAttributes(*this, oAttributes); }
  ExportedByCATPLMIdentificationAccess static HRESULT GetMinimalIdAttributes(const CATPLMTypeH & iTypeh, CATLISTV(CATString) & oAttributes);

/**
 * Basic lifecycle attributes aliases.
 * <br><b>Role:</b>This enumeration defines the basic attributes used for specific lifecycle behaviors.
 *
 */
  enum PLMTypeAttributeAlias { Owner = 0, Organization = 1, Project = 2, Maturity = 3, Revision = 4, Reserved = 5, ReservedBy = 6, CreationDate = 7, Modification = 8, VersionId = 9 };

/**
 * Returns the attribute identifier representing the given lifecycle behavior.
 * <br><b>Role:</b>This method enables to retrieve the PLM attribute which is defined as the PLM attribute modelizing the given lifecycle operation for the given PLM type.
 *
 * @param iAttributeAlias [in]
 * The alias of the wanted lifecycle attribute.
 * @param oAttributeId [out]
 * The attribute identifier as defined by the PLM model.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the attribute was found for the given type.</li>
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  inline HRESULT GetAttributeId(PLMTypeAttributeAlias iAttributeAlias, CATString & oAttributeId) { return GetAttributeId(*this, iAttributeAlias, oAttributeId); }
  ExportedByCATPLMIdentificationAccess static HRESULT GetAttributeId(const CATPLMTypeH & iTypeh, PLMTypeAttributeAlias iAttributeAlias, CATString & oAttributeId);

private:
  CATPLMTypeAttributesBehaviors(const CATPLMTypeAttributesBehaviors &);
  CATPLMTypeAttributesBehaviors & operator =(const CATPLMTypeAttributesBehaviors &);
};
#endif
