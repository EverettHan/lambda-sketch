// COPYRIGHT Dassault Systemes 2012

#ifndef CATAfrUtilities_H
#define CATAfrUtilities_H

#include "CATAfrItf.h"
//---------------------------------------------------------------------- System
#include "CATBoolean.h"
#include "CATSysDevLA.h" 
#include "CATString.h" 

#define CATAFR_3DEXP_USE_LA_VAR(var)  USE_LA_VAR(V6Signature,var);                                         \
static int CATAFR_3DEXP_ISACTIVE_##var ();                                                                 \
static int SignatureActive_##var = -1;                                                                     \
int CATAFR_3DEXP_ISACTIVE_##var ()                                                                         \
{                                                                                                          \
  int varValue = 0;                                                                                        \
  if (DEV_LA_ISACTIVE(V6Signature,var)) varValue = 1;                                                      \
  return CATAfr3DExp_IsActive(varValue,SignatureActive_##var) > 0 ? TRUE: FALSE;                           \
}                                                                                                          \
                                                                                                           \
static CATBoolean CATAFR_3DEXP_ISACTIVE_RECORD_MODE_##var ();                                              \
CATBoolean CATAFR_3DEXP_ISACTIVE_RECORD_MODE_##var ()                                                      \
{                                                                                                          \
  int varValue = 0;                                                                                        \
  if (DEV_LA_ISACTIVE(V6Signature,var)) varValue = 1;                                                      \
  return CATAfr3DExp_IsActive(varValue,SignatureActive_##var) == 2 ? TRUE: FALSE;                          \
}                                                                                                          \
static CATBoolean CATAFR_3DEXP_ISACTIVE_RECORD_MODE_BY_NAME##var (const CATString & iAuthorizedNlsFileName); \
CATBoolean CATAFR_3DEXP_ISACTIVE_RECORD_MODE_BY_NAME##var (const CATString & iAuthorizedNlsFileName)        \
{                                                                                                          \
  int varValue = 0;                                                                                        \
  if (DEV_LA_ISACTIVE(V6Signature,var)) varValue = 1;                                                      \
  return CATAfr3DExp_IsActive(varValue,SignatureActive_##var,iAuthorizedNlsFileName) == 2 ? TRUE: FALSE;   \
}																																																					 \
static CATBoolean CATAFR_3DEXP_ISACTIVE_RECORD_MODE_FOR_CTXBAR##var ();																		 \
CATBoolean CATAFR_3DEXP_ISACTIVE_RECORD_MODE_FOR_CTXBAR##var ()																				     \
{                                                                                                          \
  int varValue = 0;																																												 \
	CATString  iAuthorizedNlsFileName("CATAfr3DExperienceAuthorizedODTSForCtxBar");													 \
	if (DEV_LA_ISACTIVE(V6Signature,var)) varValue = 1;                                                      \
  return CATAfr3DExp_IsActive(varValue,SignatureActive_##var,iAuthorizedNlsFileName) != 1 ? TRUE: FALSE;   \
}
/**
*
* <br><b>Role</b>: Return TRUE if the V6Signature is active, FALSE otherwise
* If Capture mode, this macro will return TRUE.
* If replay mode, this macro will return FALSE, if it is an old ODT, TRUE otherwise (ODT captured with the signature)
* 
* DO NOT FORGET TO add in your file CATAFR_3DEXP_USE_LA_VAR(var);
*
* @param var: the environment variable related to the V6Signature project
* 
* @return
* 
*/
#define  CATAFR_3DEXP_ISACTIVE(var) CATAFR_3DEXP_ISACTIVE_##var ()              

/**
*
* <br><b>Role</b>: Return TRUE if the V6Signature is active in ODT Context
* If the ODT is authorized, it will return FALSE, TRUE otherwise

* DO NOT FORGET TO add in your file CATAFR_3DEXP_USE_LA_VAR(var);
*
* @param var: the environment variable related to the V6Signature project
* 
* @return
* 
*/
#define CATAFR_3DEXP_ISACTIVE_RECORD_MODE(var) CATAFR_3DEXP_ISACTIVE_RECORD_MODE_##var ()

/**
*
* <br><b>Role</b>: Return TRUE if the V6Signature is active in ODT Context
* If the ODT is authorized, it will return FALSE, TRUE otherwise

* DO NOT FORGET TO add in your file CATAFR_3DEXP_USE_LA_VAR(var);
*
* @param var: the environment variable related to the V6Signature project
* 
* @param AuthorizedNlsFileName: the name of the CATNls file that store a list of ODT name
*  authaurized to capture when signature is activated for this environment variable.<br/>
*   To allow an odt to capture, add a new line in your dedicated CATNls file like this
* <code>
*                   ODTREC_3DEXPVIP = "enable"; 
* </code>
* @return
* 
*/
#define CATAFR_3DEXP_ISACTIVE_RECORD_MODE_BY_NAME(var,AuthorizedNlsFileName) CATAFR_3DEXP_ISACTIVE_RECORD_MODE_BY_NAME##var (AuthorizedNlsFileName)

/**
*
* <br><b>Role</b>: Return TRUE if the V6Signature is active in ODT Context
* If the ODT is authorized, it will return FALSE, TRUE otherwise

* DO NOT FORGET TO add in your file CATAFR_3DEXP_USE_LA_VAR(var);
*
* @param var: the environment variable related to the V6Signature project
* 
* @param AuthorizedNlsFileName: the name of the CATNls file that store a list of ODT name
*  authaurized to capture when signature is activated for this environment variable.<br/>
*   To allow an odt to capture, add a new line in your dedicated CATNls file like this
* <code>
*                   ODTREC_3DEXPVIP = "enable"; 
* </code>
* @return
* 
*/
#define CATAFR_3DEXP_ISACTIVE_RECORD_MODE_FOR_CTXBAR(var) CATAFR_3DEXP_ISACTIVE_RECORD_MODE_FOR_CTXBAR##var ()

// Management of Record ODTs versioning.
// Inputs : Id for versioning and minimum version number to check.
// Returns True in replay mode if the Recorded version is >= iVersion; else returns False.
// In Record mode registers iVersion as the version of the ODT.
//
// You should execute your new code if this service returns True and execute your old code if it returns False.
//
// If you need information about record versioning you may have a look at http://codewiki/codewiki/index.php/Record_versioning
//
// Please keep in mind the old code version is obsolete. Try to put it in a test framework as often as you can.

ExportedByCATAfrItf CATBoolean  IsNewRecordVersion (char * iSoftwareId, int iVersion);



ExportedByCATAfrItf int CATAfr3DExp_IsActive(const int & varValue,  int & static_varValue, const CATString & iAuthorizedNlsFileName = "CATAfr3DExperienceAuthorizedODTS");

ExportedByCATAfrItf int CATAfrImmersiveFrame_IsActive();

ExportedByCATAfrItf int CATAfrUniversalSearch_IsActive();

#endif
