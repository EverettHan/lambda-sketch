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
#ifndef CATKWEEvent_h
#define CATKWEEvent_h


#include "CATLifDictionary.h" // Just for WinNT dllexport !!

#include "CATNotification.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"



/** The CATKWEEvent class from the module KnowledgeCommunication.<br>
* This class is the base class for several events used in knowledgeware<br>
* An event is defined by two characteristics:<br>
* <ol>
* 1. Event source (Any object deriving from CATBaseUnknown.<p>
* 2. Event classname.<p>
* </ol>
*/
class ExportedByCATLifDictionary CATKWEEvent : public CATNotification
{
	
	CATDeclareClass;
	
public:
		
	/** 
	* Constructor with and without parameter.
	* @param iSource the object that generated the error.<br>
	*/	
	CATKWEEvent( const CATBaseUnknown_var&		iSource		= NULL_var );


	/** 
	* Affectation.
	*/	
	virtual const CATKWEEvent& operator=( const CATKWEEvent& h);
	
	/** 
	* Destructor.
	*/	
	virtual ~CATKWEEvent();
	
	/**
	* Get the object at the origin of the event.
	* @return the object source of the event. 
	* This object is given in argument at the event construction.
	*/
	virtual const CATBaseUnknown_var GetSource() const;
		
	/**
	* Compares the event sources and classnames.
	*/
	virtual const int IsEqual(const CATKWEEvent& h) const;

	/** 
	* Equality test. Two errors are the same if their message are the same.<br>
	*/	
	virtual int operator==(const CATKWEEvent& h) const;		

	/**
	* Sends this event using the CATEventBus as source.
	*/
	virtual int SendEvent();

protected:
		
	/** 
	* Copy constructor.<br>
	* Protected Method.
	*/	
	CATKWEEvent(const CATKWEEvent& h);
	

	
	CATBaseUnknown_var	_source;
};

#endif



