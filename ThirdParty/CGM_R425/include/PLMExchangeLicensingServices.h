//=======================================================================================
//** WARNING: YWE 19:02:25 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
#ifndef PLMExchangeLicensingServices_H
#define PLMExchangeLicensingServices_H
// *****************************************************************
// COPYRIGHT DASSAULT SYSTEMES 2013 - 2014
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class enabling to provide services to test option or product
//     authorization based on V6 licensing.
//    Class providing a service to detect SolidWorks context
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//    Enable to test Packaging & licensing easily.
//
//    Since V6R2014x, there is only one common exe for all applications:
//     3DEXPERIENCE.exe.
//     Therefore, every specific behavior requested by an application must
//     be hardcoded through packaging test.
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  May      2013  (JLM) Initial Revision for V6R2014
//   Revision 2.0  October  2013  (SGA) Add tests on Products for V6R2014x
//   Revision 2.1  November 2013  (SGA) Add a service to test the SolidWorks context
//   Revision 2.2  November 2013  (SGA) Change of packaging for XPDM commands in V6R2014x
//   Revision 2.3  September2014  (SGA) Add packaging option for SolidWorks
//
// ****************************************************************

/**  
  *  @level  Protected    
  *  @usage  U1    
  */

// -- PLMExchangeServices
#include "PLMExchangeGlobalServices.h"    //PLMExchangeGlobalServices.m

// -- System & SpecialAPI
#include "CATSysErrorDef.h"
#include "CATString.h"                    //JS0STR.m
#include "CATUnicodeString.h"             //NS0S3STR.m
#include "CATSysBoolean.h"

/**
  * Class enabling to provide services to test product & option authorization based on V6 licensing.
  *
  * <b>Role</b>:
  *  This class provides a unique service to check if a product or an option is authorized or not.
  * <sl>
  * <li>This class also implements a mechanism that enables to test inactivation of a product or an option through a RT variable.<li>
  * <li>To force inactivation of a product or an option, you have only to use a RT variable having the same name as the product or the option and 
  * with a value set to "Inhibit".</li>
  * <li></li>
  * <li>This class also proposes a set of strings representing the product names and options currently used in Exchange operations.</li>
  * <li></li>
  * <li>This class also provides a service to detect if the application is launched in the context of SolidWorks.</li>
  * </sl>
  */
//-----------------------------------------------------------------------
class ExportedByPLMExchangeGlobalServices PLMExchangeLicensingServices
{
public:

   /** 
     * Check if an option is authorized or not.
     *
     * <br><b>Role</b>: Check if an option is authorized or not.
     *   One option could regroup authorization for several commands.
     *
     * @param isOptionId
     *    The identifier of the licensing option.
     *
     * @param opusMessage
     *    Enables to retrieve the default message in case the option is not authorized.
     *
     * @return
     *    Returns error code.
     * <br><b>Legal values</b>:
     *  <dl>
     *     <dt>S_OK</dt>    <dd>the option is authorized.</dd>
     *     <dt>S_FALSE</dt> <dd>the option is not authorized.</dd>
     *     <dt>E_FAIL</dt>  <dd>Error during licensing test, thus option must be considered as not authorized.</dd>
     *  </dl>
     */
   static HRESULT CheckIfOptionAuthorized(const char* isOptionId, CATUnicodeString* opusMessage=NULL);

   /** 
     * Check if a Product is authorized or not.
     *
     * <br><b>Role</b>: Check if a Product is authorized or not.
     *
     * @param isProductId
     *    The identifier of the licensing Product.
     *
     * @param opusMessage
     *    Enables to retrieve the default message in case the Product is not authorized.
     *
     * @return
     *    Returns error code.
     * <br><b>Legal values</b>:
     *  <dl>
     *     <dt>S_OK</dt>    <dd>the Product is authorized.</dd>
     *     <dt>S_FALSE</dt> <dd>the Product is not authorized.</dd>
     *     <dt>E_FAIL</dt>  <dd>Error during licensing test, thus Product must be considered as not authorized.</dd>
     *  </dl>
     */
   static HRESULT CheckIfProductAuthorized(const char* isProductId, CATUnicodeString* opusMessage=NULL);

   /** 
     * Check if a Product is authorized or not on server (MCS).
     *
     * <br><b>Role</b>: Check if a Product is authorized or not.
     *
     * @param isProductId
     *    The identifier of the licensing Product.
     *
     * @param opusMessage
     *    Enables to retrieve the default message in case the Product is not authorized.
     *
     * @return
     *    Returns error code.
     * <br><b>Legal values</b>:
     *  <dl>
     *     <dt>S_OK</dt>    <dd>the Product is authorized.</dd>
     *     <dt>S_FALSE</dt> <dd>the Product is not authorized.</dd>
     *     <dt>E_FAIL</dt>  <dd>Error during licensing test, thus Product must be considered as not authorized.</dd>
     *  </dl>
     */
   static HRESULT CheckIfMCSProductAuthorized(const char* isProductId, CATUnicodeString* opusMessage=NULL);

   /** 
     * Check if the application is launched in the context of SolidWorks.
     *
     * <br><b>Role</b>: In SolidWorks context, there are some specific behaviors:
     *   For Export and Import menus, there is a specific Export/Import SolidWorks V1 menu.
     *
     * @return
     *    Returns error code.
     * <br><b>Legal values</b>:
     *  <dl>
     *     <dt>TRUE</dt>    <dd>the SolidWorks context is activated.</dd>
     *     <dt>FALSE</dt>   <dd>the SolidWorks context is not activated.</dd>
     *  </dl>
     */
   static CATBoolean IsSolidWorksContext();

   /** List of Licencing options currently used privileges for exchanges. */
   static const char * option_3DLive_Authoring                 ;
   static const char * option_AO_Education                     ;
   static const char * option_AO_ExportForMnt                  ;
   static const char * option_AO_ExportAsNewDesign             ;
   static const char * option_AO_ImportAsNewDesign             ;
   static const char * option_AO_MergerForMnt                  ;
   static const char * option_AO_Migrate_3DXML_2009_2009x      ;
   static const char * option_AO_SRMV6_AdvancedExchange        ;
   static const char * option_AO_SRMV6_BasicExchange           ;
   static const char * option_AO_SRMV6_ControlledExchange      ;
   static const char * option_AO_SRMV6_ReplicationExchange     ;
   static const char * option_AO_SRMV6_StandardExchange        ;
   static const char * option_PLMManageImport                  ;
   static const char * option_XAO_MergerForMnt                 ;
   static const char * option_AO_XPDM_Enterprise               ;
   static const char * option_SWX_AO_SOLIDWORKS_V1_File_Import ;

   /** List of Products currently used privileges for exchanges. */
   static const char * product_WMC                             ;
   static const char * product_InternalDS                      ;

   /** Define Security & Licensing error catalog and main error messages. */
   static const CATString sSecurityAccessCatalog               ;
   static const CATString sSecurityNotAllowed                  ;
   static const CATString sDelegationSecurityNotAllowed        ;//IR-649794
} ;
//-----------------------------------------------------------------------
#endif
