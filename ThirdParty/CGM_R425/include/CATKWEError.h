/**
 * @level Protected
 * @usage U1
 */

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===============================================================
//
// CATSolveNotification.h
//
//
//
//===============================================================
//
// Usage Notes:
// Used in conjonction with the CATErrorManagerBase class.
// 
//===============================================================
//
// version 0.1
// author PPG
// Date creation March. 1999
// 
// Jan 02 Modif SOC : ajout d'une variable membre permettant
//					  de stocker un résumé de l'erreur,
//					  ajout des méthodes Set et GetSummary(), et
//					  mise à jour des constructeurs et de
//					  certaines méthodes.
//===============================================================
#ifndef CATKWEError_h
#define CATKWEError_h

#include "CATLifDictionary.h"
//#include "CATLifToolkit.h" // Just for WinNT dllexport !!

#include "CATNotification.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATKWEEvent.h"
#include "CATKWEErrorSeverity.h"
/** The CATKWEError class from the module KnowledgeCommunication.<br>
* This class is the base class for all the errors used in connection with<br>
* the CATKWEErrorManagerBase and all its derived classes.<br>
* An error is defined by four characteristics:<br>
* <ol>
* 1. Error type set by its classname. <p>
* 2. Error source (Any object deriving from CATBaseUnknown.<p>
* 3. Error message (A string ).<p>
* 4. Error severity (typdedef in this class. enum Severity { Message, Warning, Error } )<p>
* </ol>
*	@see CATKWEErrorManager
*   @see CATKWEErrorManagerBase
*/
class ExportedByCATLifDictionary CATKWEError : public CATKWEEvent
{
	
	CATDeclareClass;
	
public:
		
	/** 
	* Constructor with parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	*/	
	CATKWEError(
		const CATUnicodeString&			iMessage	= " ", 
		const CATBaseUnknown_var&		iSource		= NULL_var,
		const CATKWEErrorSeverity::Severity		iSeverity	= CATKWEErrorSeverity::Information,
		const char *					iErrorType	= " ",
		const CATUnicodeString&			iSummary	= " "	// SOC : add optionnal parameter
		);

	
	/** 
	* Constructor with parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	*/	
	CATKWEError(
		const CATBaseUnknown_var&		iSource,
		const CATUnicodeString&			iMessage	= " ", 
		const CATKWEErrorSeverity::Severity		iSeverity	= CATKWEErrorSeverity::Information,
		const char *					iErrorType	= " ",
		const CATUnicodeString&			iSummary	= " "	// SOC : add optionnal parameter
		);



	/** 
	* Affectation.
	*/	
	virtual const CATKWEError& operator=( const CATKWEError& h);
	
	
	/** 
	* Destructor.
	*/	
	virtual ~CATKWEError();
	
	/**
	* Returns the message linked to the error.
	*/
	virtual const CATUnicodeString& ToString() const;

	// SOC : add method
	/**
	* Returns the summary linked to the error.
	*/
	virtual const CATUnicodeString& GetSummary() const;

	// SOC : add method
	/**
	* Set the summary of the error (the one which is displayed in the error panel
	* fired by Knowledge).
	*/
	void SetSummary(const CATUnicodeString& iSummary);
	
	/**
	* For debugging purpose.
	*/
	const CATUnicodeString Dump() const;
	
	/**
	* Returns a copy of the current object. This is cradouille !!<br>
	* The owner of the returned pointer IS IN CHARGE OF DELETING THE OBJECT.
	*/
	virtual CATKWEError* Clone() const;
	
	/**
	* Get the error type. By default it returns Classname()
	*/
	virtual const char* GetErrorType() const;
	
	/**
	* Get the object at the origin of the error.
	* @return the object source of the error. 
	* This object is given in argument at the error construction.
	*/
	//virtual const CATBaseUnknown_var GetSource() const;
	
	/**
	* Get the severity of the error. Defined by an enum of this same class.
	* @return the severity.
	*/
	const CATKWEErrorSeverity::Severity GetSeverity() const;

	/**
	* Set the severity of the error. Defined by an enum of this same class.
	* @param iSeverity the severity.
	*/
	void SetSeverity(CATKWEErrorSeverity::Severity iSeverity);

	/**
	* Compares the error TYPES, SOURCE, MESSAGE and SEVERITY.
	*/
	virtual const int IsEqual(const CATKWEError& h) const;
	
	/**
	* Compares the Errors TYPES.
	* @param iName
	*   The class name from which the given object's class is supposed to derive.
	* @return 0 if the given object's class doesn't derive from <tt>iName</tt>
	* and a non null value otherwise.
	*/
	virtual int IsOfSameType(const char * iErrorType) const;
	
	/**
	* Compares the error TYPE and SOURCE.
	* @param h a reference to an CATKWEError.
	* @return 0 if the errors are not equivalent, 1 if they are.
	*/
	virtual const int IsEquivalent(const CATKWEError& h) const;		

	/** 
	* Equality test. Two errors are the same if their message are the same.<br>
	* Protected Method.
	*/	
	virtual int operator==(const CATKWEError& h) const;
		
protected:
		
	/** 
	* Copy constructor.<br>
	* Protected Method.
	*/	
	CATKWEError(const CATKWEError& h);
	

	CATUnicodeString				_message;
	CATBaseUnknown_var				_source;
	CATKWEErrorSeverity::Severity	_severity;
	char*							_type;
	CATUnicodeString				_summary;
	
private:
	void Init(
		const CATUnicodeString&		iMessage, 
		const CATBaseUnknown_var&	iSource,
		const CATKWEErrorSeverity::Severity	iSeverity,
		const char *				iErrorType,
		const CATUnicodeString&		iSummary);
};

#endif



