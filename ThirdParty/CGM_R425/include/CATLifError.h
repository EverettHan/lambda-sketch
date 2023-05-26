/**
 * @level Protected
 * @usage U1
 */

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===============================================================
//
// CATLifOutOfBoundErr.h
//
//===============================================================
//
// Usage Notes:
//===============================================================
//
// version 0.1
// author PPG
// Date creation March. 1999
// Jan 2002 modif SOC : to add the last otionnal parameter in the
//						constructor due to the modifcations done
//						in the CATKWEError 
//===============================================================
#ifndef CATLifError_h
#define CATLifError_h

#include "CATLifDictionary.h"

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATKWEError.h"
#include "CATKWEErrorSeverity.h"
/** The CATLifError class from the module CATLifToolKit.<br>
*
* An error is defined by four characteristics:<br>
* <br>
* <ol>
* 1. Error type set by its classname.<p>
* 2. Error source (Any object deriving from CATBaseUnknown.<p>
* 3. Error message (A string ).<p>
* 4. Error severity (typdedef in this class. enum Severity { Message, Warning, Error } ).<p>
* </ol>
*	@see CATLifErrorManager
*	@see KnowledgeCommunication.CATKWEError
* 
* <b>Usage:</b><br>
* It is recommended to derive from this class to create other error types.
* @see CATKWELifOutOfBoundErr
*/
class ExportedByCATLifDictionary CATLifError : public CATKWEError
{
	
	CATDeclareClass;
	
public:
	
	
	/** 
	* Copy Constructor.
	*/	
	CATLifError(const CATLifError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	* @see KnowledgeCommunication.CATKWEError
	*/	
	CATLifError(
		const CATUnicodeString&			iMessage	= " ", 
		const CATBaseUnknown_var&		iSource		= NULL_var,
		const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Information,
		const char *					iErrorType	= " ",
		const CATUnicodeString&			iSummary	= " "	// SOC : add optionnal parameter
		);
	/** 
	* Destructor.
	*/	
	virtual ~CATLifError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	
	
	/**
	* Retrieves the current Error manager and throws this error.
	* @return 0 if the error manager was not found 1 the throw was successful.
	*/
	virtual const int Throw() const;
};

#endif



