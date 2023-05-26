#ifndef PLMManageContext_H
#define PLMManageContext_H
// COPYRIGHT Dassault Systemes 2008
//
//
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
//
/**
 * Service to manage Authoring Context & Customization solution among a Provider.  
 *
 *<p>
 * Context are managed as follow: 
 *    if the provider is anythingelse but PLM1: context is "" 
 *    if the provider is PLM1 (Multi-discipline): 
 *                   context is the name of an Imposed environment (Single Env behavior) or else "" 
 *                   the only known imposed env is ENOVIA_PLM_Express on a SMB deployment
 *                         on an official SMB licenced installation, environment is mandatory and always ENOVIA_PLM_Express
 *                         on an internal (E4A) installation (out of licencing) environment is mandatory as soon as it is initialized to ENOVIA_PLM_Express
 *                               internal behavior may require to provide the correct setting upfront or else to leave and restart with correct setting in place upfront                                   
 *<\p>
 *<br>
 * This context concept is not a published information to customer, nor a CAA published information
 */

//
#include "PLMMD1.h"
//
class ExportedByPLMMD1 PLMManageContext
{
  public:

    /**
     * Retrieves if software needs to behave with Team capabilities
 	 *   @param HRESULT
	 *     S_OK: This is a Team restricted behavior
	 *     E_FAIL: not a Team restricted behavior
     */
    static HRESULT GetTeamBehavior();
 
    /**
     * Retrieves the project solution for which is customization has been defined
	 *    
     *   @param oSolution
	 *     Name of the Solution supported by the current connection
	 *   @param HRESULT
	 *     S_OK: Solution is defined (eventually undef "")  
	 *     E_FAIL: not a PLM Solution based
     */
    static HRESULT GetPLMSolution(CATUnicodeString& oSolution);

    /**
     * Retrieves an imposed Custo Solution if any for the current provider that replace normal Provider custo
	 *    
     *   @param oCustoContext
	 *     Name of the sub-directory of Provider custo (ie returned oPath=ENOVIA_PLM_Express => CustoPath is PLM1\ENOVIA_PLM_Express 
	 *   @param HRESULT
	 *     S_OK: there is an imposed Provider Custo Solution that superseed normal Provider custo (ie PLM1\ENOVIA_PLM_Express instead of PLM1) 
	 *     S_FALSE: the Provider Custo Solution combines with Common Provider Custo and should be concatenated with Provider directory (ie PLM1\ENOVIA_PLM_Express;PLM1)
	 *     E_FAIL: no sub-directory concept
     */
    static HRESULT GetCustomizedSolution(CATUnicodeString& oCustoContext);

    /**
     * Retrieves an imposed context if any for the current provider
     *   @param oContext
	 *     Name of the imposed context, mainly used as the primary authoring environment in the solution
	 *   @param HRESULT
	 *     S_OK: there is an imposed context, context is meant to be the only one used in Creation, and the prefered/default one in Query 
	 *     S_FALSE: there is no imposed context, preferabily the context is meant to be default env for Creation and Query 
     */
      static HRESULT GetImposedContext( CATUnicodeString& oContext);
};
#endif
