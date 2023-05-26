/**
 * @level Protected
 * @usage U1
 */

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===============================================================
//
// CATLifWrongFormat.h
//
//===============================================================
//
// Usage Notes:
//===============================================================
//
// version 0.1
// author FRH
// Date creation March. 1999
// 
//===============================================================
#ifndef CATKWELifWrongFormat_h
#define CATKWELifWrongFormat_h

#include "CATLifDictionary.h"

#include "CATUnicodeString.h"
#include "CATLifError.h"
#include "CATKWEError.h"

#include "CATLifErrorManager.h"

/** The CATKWELifWrongFormat class from the module CATLifToolKit.<br>
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
*/
class ExportedByCATLifDictionary CATKWELifWrongFormat : public CATLifError
{
	
	CATDeclareClass;
	
public:
	
	
	/** 
	* Copy Constructor.
	*/	
	CATKWELifWrongFormat(const CATKWELifWrongFormat& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	* @see KnowledgeCommunication.CATKWEError
	*/	
	CATKWELifWrongFormat(const CATBaseUnknown_var &iSource);


	/** 
	* Constructor with parameters and without parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	* @see KnowledgeCommunication.CATKWEError
	*/	
	CATKWELifWrongFormat(
		const CATUnicodeString&			iMessage	= " ", 
		const CATBaseUnknown_var&		iSource		= NULL_var);

	
	/** 
	* Destructor.
	*/	
	virtual ~CATKWELifWrongFormat();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	
	
};

#endif



