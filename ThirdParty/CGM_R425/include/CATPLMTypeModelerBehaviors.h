/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeModelerBehaviors_H
#define CATPLMTypeModelerBehaviors_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeDescriptor.h"
#include "CATPLMTypeToolsDefinitions.h"
#include "CATPLMTypeProperty.h"

 /**
  * Class enabling to determine behavioral patterns of a PLM type.
  *
  * <br><b>Role</b>: Given a PLM type, this class enables to determine the physical aspect of the PLM type.
  * <ul>
  * <li>Available entry points:</li>
  * <li>public:GetPreferedInstanciationType</li>
  * <code>
  * CATPLMID myComponent;
  * CATPLMTypeModelerBehaviors Behavior(myComponent);
  * HRESULT rc_instanciation=Behavior.GetPreferedInstanciationType(xxx);
  * if ( SUCCEEDED(rc_instanciation) )
  * {
  *   if ( rc_instanciation==S_OK )
  *     printf("My Component can be instanciated through xxx");
  *   else
  *     printf("My Component is stand alone");
  * }
  *
  * or
  *
  * CATPLMID myComponent;
  * CATPLMTypeH TypeH(myComponent);
  * CATPLMTypeModelerBehaviors Behavior(TypeH);
  * HRESULT rc_instanciation=Behavior.GetPreferedInstanciationType(xxx);
  * if ( SUCCEEDED(rc_instanciation) )
  * {
  *   if ( rc_instanciation==S_OK )
  *     printf("My Component can be instanciated through xxx");
  *   else
  *     printf("My Component is stand alone");
  * }
  *
  * </code>
  * </ul>
  */
class CATPLMTypeModelerBehaviors : public CATPLMTypeDescriptor
{
public:
  ExportedByCATPLMIdentificationAccess CATPLMTypeModelerBehaviors(const CATPLMTypeH & iPLMType);
  inline CATPLMTypeModelerBehaviors(CATPLMType * iPLMType) : CATPLMTypeDescriptor(iPLMType) {}

  /**
   * Retrieve the default instanciation PLM type given an instanciable PLM type.
   * <br><b>Role:</b>This method enables to retrieve the prefered PLM type of Component enabling to instanciate a Component, as defined in the metadata files.
   *
   * @param oInstanciationType [out]
   * The PLM type of the possible prefered Instance of the given Component/PLM Type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the PLM Type can be instanciated and a prefered instanciation type is defined.</li>
   * <li><tt>S_FALSE</tt> if the PLM Type cannot be instanciated or no prefered instanciation type is defined.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess HRESULT GetPreferedInstanciationType(CATPLMTypeH & oInstanciationType) const;

  /**
    * Check the property for a PLM Type
    * <br><b>Role:</b>This method enables to check if a given property is defined on a PLM type in metadata.
    *
    * @return
    *   S_OK: the facet is set
    *   S_FALSE: the facet is not set
    *   E_*: error
    */
  static ExportedByCATPLMIdentificationAccess HRESULT TestProperty(const CATPLMTypeH& iType, CATPLMTypeProperty iProperty);

  /**
   * @return
   *   S_OK: the (BusinessType) PLM type has the property
   *           <Property Name="ObjectNature" Value="Aggregated"/>
   *         notice that's the case for PLMPort/PLMConnection
   *   S_FALSE: the PLM type does not have this property
   *   E_*: error
   */
  inline static HRESULT IsComposed(const CATPLMTypeH& iType) { return TestProperty(iType, CATPLMTypeProperty::Composed); }

  /**
  * @return
  *   S_OK: the (BusinessType) PLM type has the property
  *           <Property Name="ObjectNature" Value="MayBeAggregated"/>
  *   S_FALSE: the PLM type does not have this property
  *            notice that a type which is "composed" is NOT "maybecomposed"
  *   E_*: error
  */
  inline static HRESULT MayBeComposed(const CATPLMTypeH& iType) { return TestProperty(iType, CATPLMTypeProperty::MayBeComposed); }

  /**
  * @return
  *   S_OK: the (RelationType) PLM type has the property
  *           <Property Name="RelationNature" Value="Aggregation"/>
  *   S_FALSE: the PLM type does not have this property
  *   E_*: error
  */
  inline static HRESULT IsCompositional(const CATPLMTypeH& iType) { return TestProperty(iType, CATPLMTypeProperty::Compositional); }

  /**
   * @return S_OK if iRelType is compositional and iBOType is composed/maybecomposed
   */
  static ExportedByCATPLMIdentificationAccess HRESULT IsComposition(const CATPLMTypeH& iRelType, const CATPLMTypeH& iBOType);

private:
  CATPLMTypeModelerBehaviors(const CATPLMTypeModelerBehaviors &);
  CATPLMTypeModelerBehaviors & operator =(const CATPLMTypeModelerBehaviors &);
};
#endif
