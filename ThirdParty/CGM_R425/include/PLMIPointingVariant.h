// COPYRIGHT Dassault Systemes 2009
//===================================================================
//  Jun 2009  Creation: Code generated by the LRG wizard
//===================================================================
#ifndef PLMIPointingVariant_H
#define PLMIPointingVariant_H

/**
* @level Protected
* @usage U3
*/

#include "PLMPointingCmpVarsMgmt.h"

#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
class CATString;
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMPointingCmpVarsMgmt IID IID_PLMIPointingVariant;
#else
extern "C" const IID IID_PLMIPointingVariant ;
#endif

/**
* Interface allowing to declare properties on a pointing plm component (connection, port, ...) to determine 
*  - its behavior with regards to a configured operation on instances it points.
*  - its validity rules in terms of effectivities of its pointed pathes.
* A plm component must adhere to and implement this interface in order to be analyzed and treated by a 
* @href PLMIPointingVariantsManager
* @see PLMIPointingVariantsMngrFactory, PLMIPointingVariantsManager
* _NOTE THAT AS OF TODAY, EVEN IF ANY TYPE OF PLM COMPONENT CAN ADHERE TO THIS INTERFACE, ONLY CONNECTIONS
* WILL BE TREATEN AT RUNTIME !_
*/
class ExportedByPLMPointingCmpVarsMgmt PLMIPointingVariant: public CATBaseUnknown
{
  CATDeclareInterface;

  friend class ImpactOnLogicalPointingComp;
protected:

  /**
  * This method must be implemented to return the key of the modeler of <tt>this</tt> pointing plm component.
  */
  virtual CATUnicodeString GetModelerKey() = 0;

public:

  /**
  * Returns the policy/behavior of <tt>this</tt> pointing plm component with regards to a configured operation on instances
  * it points.
  *   @return
  *     <ul>
  *       <li> FALSE if <tt>this</tt> pointing plm component is not impacted at all by configuration. It will consequently not be treaten by the @href PLMIPointingVariantsManager.</li>
  *       <li> TRUE if <tt>this</tt> pointing plm component is impacted by configured operation on instances it points. It will consequently be treaten by the @href PLMIPointingVariantsManager.</li>
  */ 
  virtual CATBoolean HasAManagedVariability()=0;

  /**
  * Returns TRUE if <tt>this</tt> plm pointing component is impacted by a configured operation on the object pointed
  * by the relation <tt>iRelationName</tt> is ruled or FALSE if it is not impacted.
  *
  *  @param iRelationName
  *      The name of the relation.<br>
  *      Input parameter. <br>
  *   @return
  *     <ul>
  *       <li> if <tt>this</tt> plm pointing component is impacted by a configured operation on the object pointed by the relation <tt>iRelationName</tt></li>
  *       <li> FALSE otherwise.<br></li>
  *     </ul>
  */
  virtual CATBoolean ImpactedByConfiguredOpOnPointedByRelation(const CATString& iRelationName)=0;

  /**
  * Returns the list of the roles of the relations that are impacted by a configured operation on the object pointed.
  *
  *  @param oRolesOfRuledRelations
  *      The list of the roles of the relations that are impacted by a configured operation on the object pointed.<br>
  *      Output parameter. <br>
  *   @return
  *     <ul>
  *       <li> S_OK if succeeded.</li>
  *       <li> E_FAIL otherwise.</li>
  *     </ul>
  */
  virtual HRESULT GetRolesOfRelsImpactedByAConfiguredOp(CATListOfCATUnicodeString& oRolesOfRuledRelations)=0;

};

CATDeclareHandler(PLMIPointingVariant, CATBaseUnknown);

#endif
