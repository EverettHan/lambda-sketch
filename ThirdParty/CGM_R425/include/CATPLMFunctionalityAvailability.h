/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMFunctionalityAvailability_H
#define CATPLMFunctionalityAvailability_H

#include "CATPLMIntegrationBase.h"
#include "CATPLMTypeH.h"
#include "CATBaseUnknown.h"

/**
 * Class enabling to determine if a functionality is available for a given PLMType. 
 * This is used to temporarily avoid the use of a functionality for Components from a given PLM type.
 *
 * <br><b>Role</b>: Given a PLM type, this class enables to determine the availability of a functionality. The class must be specialized to
 * to implement the @href AnalyzeType method.
 * <ul>
 * <code>
 * CATPLMMyFunctionalityAvailability Manager(myPLMType);
 * HRESULT rc_isavailable=Manager.IsFunctionalityAvailable();
 * if ( SUCCEEDED(rc_isavailable) )
 * {
 *   if ( rc_isavailable==S_OK )
 *     printf("My Component can be treated");
 *   else
 *     printf("My Component cannot be treated");
 * }
 * </code>
 * </ul>
 */
class ExportedByCATPLMIntegrationBase CATPLMFunctionalityAvailability
{
public:
  CATPLMFunctionalityAvailability( const CATPLMTypeH & iPLMType );
  virtual ~CATPLMFunctionalityAvailability();

/**
 * Checks if the functionality is available.
 * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type can be used in a specific functionality.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the Component support the Pattern.</li> 
 * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT IsFunctionalityAvailable();

/**
 * Analyze the PLM type to determine if it is usable for the functionality.
 * <br><b>Role:</b>This method enables to determine if a PLM Type is usable for the functionality.
 *
 * @param iModelization [in]
 * The modelization of the PLM type (IRPC modeler or "ER" string).
 *
 * @param iEntity [in]
 * The Entity (IRPC coretype or "Entity", "Relation" or "Extension" strings).
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the Component support the Pattern.</li> 
 * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * </ul>
 */
  virtual HRESULT AnalyzeType( const CATPLMTypeH & iType )=0;

private:
  CATPLMFunctionalityAvailability( const CATPLMFunctionalityAvailability & );
  CATPLMFunctionalityAvailability & operator =( const CATPLMFunctionalityAvailability & );

private:
  CATPLMTypeH _PLMType;
};
#endif
