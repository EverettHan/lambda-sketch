/**
 * @level Protected
 * @usage U1
 */

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===============================================================
//
// CATLifValueError.h
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
#ifndef CATKWELifValueError_h
#define CATKWELifValueError_h

#include "CATLifDictionary.h"

#include "CATUnicodeString.h"
#include "CATLifError.h"
#include "CATICkeRelation.h"
#include "CATKWEError.h"
#include "CATLifErrorManager.h"

#include "CATIParmManipulator.h"

/** The CATKWELifValueError class from the module CATLifToolKit.<br>
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
class ExportedByCATLifDictionary CATKWELifValueError : public CATLifError
{
public:
	
	/** 
	* Copy Constructor.
	*/	
	CATKWELifValueError(const CATKWELifValueError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	* @see KnowledgeCommunication.CATKWEError
	*/	
	CATKWELifValueError(const CATUnicodeString&			iMessage	= " ", 
                        const CATICkeParm_var &iSource = NULL_var,
			            const CATIParmManipulator::TestRC trc = CATIParmManipulator::Ok);
	
	
	/** 
	* Destructor.
	*/	
	virtual ~CATKWELifValueError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	
	
  private :	
	CATDeclareClass;
        CATIParmManipulator::TestRC trc_;	
};

#endif



