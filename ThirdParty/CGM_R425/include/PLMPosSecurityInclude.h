#ifndef _PLMPosSecurityInclude_h_
#define _PLMPosSecurityInclude_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByGUIDPLMPosBaseInterfaces.h"
class CATUnicodeString;



#ifdef _WINDOWS_SOURCE
# if !defined(POS_IMPLEMENTS_SYMBOL) && defined(__GUIDPLMPosBaseInterfaces)
  // module GUIDPLMPosBaseInterfaces, source n'exportant pas les symboles
# define extern_ExportedByGUIDPLMPosBaseInterfaces 
# else
# define extern_ExportedByGUIDPLMPosBaseInterfaces ExportedByGUIDPLMPosBaseInterfaces
# endif
#else
# ifdef POS_IMPLEMENTS_SYMBOL
# define extern_ExportedByGUIDPLMPosBaseInterfaces
#endif
#endif

/** variable declaration macro */
#ifdef POS_IMPLEMENTS_SYMBOL
# define POS_DECLARE_VAR(vartype,varname) extern vartype ExportedByGUIDPLMPosBaseInterfaces varname(DEF_##varname)
#else
# define POS_DECLARE_VAR(vartype,varname) extern vartype ExportedByGUIDPLMPosBaseInterfaces varname
#endif
/** constant declaration macro */
#define POS_DECLARE_CONST(vartype,varname) POS_DECLARE_VAR(const vartype,varname)
/** string declaration macro */
#define POS_DECLARE_STRING(varname) POS_DECLARE_VAR(const CATUnicodeString,varname)

/** new line char */
POS_DECLARE_CONST(CATUnicodeChar,gsPOS_NL);
/** CR char */
POS_DECLARE_CONST(CATUnicodeChar,gsPOS_CR);
/** cache information separator */
POS_DECLARE_CONST(CATUnicodeChar,gsPOS_CACHE_SEP);
/** odt mode */
POS_DECLARE_VAR(int,gsPOS_ODT_MODE);

/** SecurityToken information separator */
POS_DECLARE_STRING(gsPOS_TOKEN_SEP);
/** SecurityToken additionnal parameter name/value separator */
POS_DECLARE_STRING(gsPOS_TOKEN_PARAM_SEP);
/** SecurityToken additionnal parameter name prefix */
POS_DECLARE_STRING(gsPOS_TOKEN_PARAM_PREFIX);
/**
 * SecurityToken user parameter name.
 * This parameter is typically used in the GetRolesForUser and SetUserRole commands.
 */
POS_DECLARE_STRING(gsPOS_TOKEN_PARAM_USER);
/**
 * SecurityToken context parameter name.
 * This parameter is typically used in the SetUserRole command.
 */
POS_DECLARE_STRING(gsPOS_TOKEN_PARAM_CONTEXT);
/**
 * SecurityToken user's context parameter name.
 * This parameter is typically used in the GetRolesForUser command.
 */
POS_DECLARE_STRING(gsPOS_TOKEN_PARAM_USER_CONTEXTS);
/**
 * Marshalled SecurityToken parameter name.
 * This parameter is typically used :
 * - as output of the SetUserAndRole command;
 * - as input of all commands executed after SetUserAndRole.
 */
POS_DECLARE_STRING(gsPOS_TOKEN_PARAM_SECURITY_TOKEN);
/**
  * Parameter used to identify a login with multi contexts
  */
POS_DECLARE_STRING(gsPOS_PARAM_MULTI_CONTEXTS);
//
// RDB definitions:   See DB provider for usage 
//
/**
  * Name of the PNO business domain used during the expand and query 
  */
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_ROOT);
/**
  * Name of the Security business domain used during the expand and query
  */
POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_ROOT);
/**
  * Name of the standard security attributes
  */
POS_DECLARE_STRING(gsV_user);
POS_DECLARE_STRING(gsV_creator);
POS_DECLARE_STRING(gsV_org);
POS_DECLARE_STRING(gsV_prj);
/**
  * Name of the PnO and Security business domains per entity
  */  
POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_GACI);  
POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_AUTH);  
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_BUD); 
POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_COND);  
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_CTX);
POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_FACI); 
POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_FACIG);  
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_ORG);      
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_PEO);   
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_PRJ);   
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_ROL);   
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_AGR);   
//POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_AACI);  
//POS_DECLARE_STRING(gsPOS_SEC_DOMAIN_AACIG); 
POS_DECLARE_STRING(gsPOS_PNO_DOMAIN_LVL);   
/**
  * Name of the PnO and Security entity reference
  */ 
POS_DECLARE_STRING(gsPOS_SEC_GACI_REF);  
POS_DECLARE_STRING(gsPOS_SEC_AUTH_REF);  
POS_DECLARE_STRING(gsPOS_PNO_BUD_REF); 
POS_DECLARE_STRING(gsPOS_SEC_COND_REF);  
POS_DECLARE_STRING(gsPOS_PNO_CTX_REF);
POS_DECLARE_STRING(gsPOS_SEC_FACI_REF); 
POS_DECLARE_STRING(gsPOS_SEC_FACIG_REF);  
POS_DECLARE_STRING(gsPOS_PNO_ORG_REF);      
POS_DECLARE_STRING(gsPOS_PNO_PEO_REF);   
POS_DECLARE_STRING(gsPOS_PNO_PRJ_REF);   
POS_DECLARE_STRING(gsPOS_PNO_ROL_REF);   
POS_DECLARE_STRING(gsPOS_PNO_AGR_REF);   
//POS_DECLARE_STRING(gsPOS_SEC_AACI_REF);  
//POS_DECLARE_STRING(gsPOS_SEC_AACIG_REF); 
POS_DECLARE_STRING(gsPOS_PNO_LVL_REF);   

/**
  * Name of the PnO and Security entity instance
  */  
POS_DECLARE_STRING(gsPOS_SEC_GACI_INST);  
POS_DECLARE_STRING(gsPOS_PNO_BUD_INST); 
POS_DECLARE_STRING(gsPOS_SEC_COND_INST);  
POS_DECLARE_STRING(gsPOS_PNO_CTX_INST);
POS_DECLARE_STRING(gsPOS_SEC_FACI_INST); 
POS_DECLARE_STRING(gsPOS_SEC_FACIG_INST);  
POS_DECLARE_STRING(gsPOS_PNO_ORG_INST);      
POS_DECLARE_STRING(gsPOS_PNO_PEO_INST);   
POS_DECLARE_STRING(gsPOS_PNO_PRJ_INST);   
POS_DECLARE_STRING(gsPOS_PNO_ROL_INST);   
//POS_DECLARE_STRING(gsPOS_SEC_AACI_INST);  
//POS_DECLARE_STRING(gsPOS_SEC_AACIG_INST); 
POS_DECLARE_STRING(gsPOS_PNO_LVL_INST);   

/**
  * Name of the PnO and Security entity connection
  */  
POS_DECLARE_STRING(gsPOS_PNO_BUD_CNX); 
POS_DECLARE_STRING(gsPOS_PNO_ORG_CNX);      
POS_DECLARE_STRING(gsPOS_PNO_PEO_CNX);   
POS_DECLARE_STRING(gsPOS_SEC_AUTH_CNX);  

#endif
