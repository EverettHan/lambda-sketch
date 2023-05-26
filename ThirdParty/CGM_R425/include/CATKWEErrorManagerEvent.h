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
//===============================================================
#ifndef CATKWEErrorManagerEvent_h
#define CATKWEErrorManagerEvent_h



#include "CATLifDictionary.h" // Just for WinNT dllexport !!

#include "CATBaseUnknown.h"
#include "CATKWEEvent.h"
#include "CATKWEError.h"
#include "CATListPV.h"



/** The CATKWEErrorManagerEvent class from the module KnowledgeCommunication.<br>
* This class is the base class for several events used in knowledgeware<br>
* An event is defined by two characteristics:<br>
* <ol>
* 1. Event source (Any object deriving from CATBaseUnknown.<p>
* 2. Event classname.<p>
* </ol>
*/
class ExportedByCATLifDictionary CATKWEErrorManagerEvent : public CATKWEEvent
{
	
	CATDeclareClass;
	
public:
		
	/** 
	* Constructor with and without parameter.
	* @param iSource the object that generated the error.<br>
	*/	
	CATKWEErrorManagerEvent( const CATKWEError* iError, 
		const CATBaseUnknown_var& iSource = NULL_var );

	/** 
	* Constructor to use when more than one error must be output at the same time.
	* @param iErrorsList the list of errors that must be sent via this event.<br>
	* @param iSource the object that generated the error.<br>
	*/	
	CATKWEErrorManagerEvent( const CATListPV& iErrorsList, 
		const CATBaseUnknown_var& iSource = NULL_var );


	/** 
	* Destructor.
	*/	
	virtual ~CATKWEErrorManagerEvent();
	
	/** 
	* Get the error conveyed by this event.
	* @return pointer to the error.<br>
	*/	
	const CATKWEError* GetError() const;

	/** 
	* Get the errors list conveyed by this event.
	* @return pointer to the error list.<br>
	*/	
	void GetErrorsList(CATListPV& oErrorsList) const;


protected:
		
	/** 
	* Copy constructor.<br>
	* Protected Method.
	*/	
	CATKWEErrorManagerEvent(const CATKWEErrorManagerEvent& h);

private:

	const CATKWEError*	_errorToDealWith;
	CATListPV		_errorsList;

};

#endif



