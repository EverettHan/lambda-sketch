// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATCkeInspectObject_h
#define CATCkeInspectObject_h

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

class CATIAlias_var;
class CATIParmPublisher_var;
class CATIAllowUserInfo_var;
class CATICkeObject_var;
class CATUnicodeString;



//-------------------------------------------------------------------
/**   
 * These services are used to dump informations on objects. 
 * It is used by the Business rules to produce traces when CKE_CUSTO_TRACES==2
 * It is used by debug command that browse an object
 */
//-----------------------------------------------------------------------
class  ExportedByCATLifSpecs CATCkeInspectObject
{

public :

	// In all following methods, entete is a string that is provided. It is inserted at each beginning of a new line. It can serve for indenting information
	// The result is added to oResult which can be non empty

	// Traces the Alias of an object (CATIAlias)like this
	// entete + "- Alias: " + iAlias->GetAlias()+ "\n"
	// Returns E_FAIL is iAlias==NULL_var
	static HRESULT InspectAlias     (const CATIAlias_var &iAlias,CATUnicodeString &oResult,const CATUnicodeString &entete);

	// Traces the User Info of an object (CATIAllowUserInfo_var)like this
	// entete + " - No comment \n" or entete + " - One comment: " + iMyUserInfo->GetComment()+"\n"
	// entete + "- No URLs\n" or entete + "- x URLs\n" + entete + "
	static HRESULT InspectUserInfo  (const CATIAllowUserInfo_var &iMyUserInfo,CATUnicodeString &oResult,const CATUnicodeString &entete);

	// Not implemented
	static HRESULT InspectPublisher (const CATIParmPublisher_var &iMyPublisher,CATUnicodeString &oResult,const CATUnicodeString &entete);

	// Traces first the name of the instance, its type and its 
	static HRESULT InspectObject (const CATICkeObject_var &iMyInstance,CATUnicodeString &oResult,const CATUnicodeString &entete);

private : 


};
   
#endif
