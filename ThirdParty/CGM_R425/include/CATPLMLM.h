#ifndef CATPLM_H
#define CATPLM_H
// COPYRIGHT Dassault Systemes 2010
//
//
//
/**
 * Service to manage Licencing based on PLM Dictionary Type  
 *
 *<p>
 * Principle is the following 
 *    There are behavior (operation on type) for which a licence needs to be provided
 *    Operation can be 
 *             Production (creation of a new instance of that type by a factory)
 *             others to be defined
 *
 *    There are type that may inherit of a supertype
 *             1) DSApplicativeType (DSSuperType)
 *             2) CustomApplicativeType (DSSuperType)
 *             3) PartnerApplicativeType (DSSuperType)
 *
 *    What differenciate a partner from customer is the fact an Addin Product provides the partner-id with specific enablement
 * 
 *    A type will be authorized for production (by RootFactory API, or PLMNew type) on the following conditions
 *             AOP_nametype is authorized   (case nb1):  where nametype is the DSApplicativeType)
 *             AOD_supertype is authorized (case nb2): a DS (extend) product enable customer to derive a type) 
 *             AOD_partnerid_supertype is authorized (case nb3): a DS Addin (extend) Product for a given partner, enable the partner to Derive the supertype)
 *<\p>
 *<br>
 * Notice Licencing options are truncated to 24 char, thus AOP_ or AOD_ remove 4 char, 
 * additionnally partner-id are used be be 8 char or less, 
 * Thus granularity of Type authorisation is on 16 char at most. 
 */

//
#include "PLMLIC.h"
//
class CATIType; 
#include "CATBaseUnknown.h"
#include "CATLM.h"

//
class ExportedByPLMLIC CATPLMLM
{
  public:

   /**
     * Check that a new Object can be created with this Type (customer/ds)
	 *   @param iCtype 
	 *       The name of the type (customer/ds) to control for licencing 
	 *       (must be a type that is either a DS type, or custom and directly derive from a DS type)
	 *   @param iCid 
	 *       The name of the type package owner (customer-id, partner-id, "") of the type 
	 *               (must be provided as a non null string for non DS type)
	 *   @param iDSSuperType: name of the type (ds only) from which the above c_type derive
     *
 	 *   @return CATLM::AuthorizationStatus
	 *     Authorized: New Object of this type can be created
	 *     NotAutorized: and other value: not autorized
	 *     Unknown: programming error (invocation with bad structure, in wrong time, ...) 
     */

    static CATLM::AuthorizationStatus IsTypeAuthorizedForObjectProduction(const char* iCtype, const char* iCid=NULL, const char* IDSSuperType=NULL); 

    /**
     * Check that a new Object can be created with this PLM Type (customer/ds)
	 *   @param iType 
	 *      The type to control for licencing 
	 *       (must be a type that is either a DS type, or custom and directly derive from a DS type)
	 *   @param iCid 
	 *      The name of the type package owner (customer-id, partner-id,"") of the type. 
	 *      (must be provided as a non null string for non DS type)
	 *
 	 *   @return CATLM::AuthorizationStatus
	 *     Authorized: New Object of this type can be created
	 *     NotAutorized: and other value: not autorized
	 *     Unknown: programming error (invocation with bad structure, in wrong time, ...) 
     */
    static CATLM::AuthorizationStatus IsTypeAuthorizedForObjectProduction(const CATIType* iType, const char* iCid=NULL); 
};
#endif
