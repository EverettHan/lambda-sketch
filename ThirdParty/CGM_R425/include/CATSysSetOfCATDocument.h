/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
#ifndef CATSysSetOfDocument_H
#define CATSysSetOfDocument_H

#include "AD0XXBAS.h"
#include "CATSysSimpleHashTable.h"
#include "CATListPV.h"
#include "CATDocument.h"


class ExportedByAD0XXBAS CATSysSetOfCATDocument
{
// CATSyset is a set of n poniters to CATDocument which can be a single pointer (n<2)
// a list (1<n<_Limit) or a hastable n=>_Limit
public :

	enum ObjectType { Single, List, HTable } ;				
	// CATSysSet value type
		
	CATSysSetOfCATDocument (  unsigned short LIMIT = 6,  unsigned short MANMEM = 1 );	
	// CATSysSet constructor. the set will be a list beetween 2 and LIMIT elements.
	// if MANMEM is true, CATSysSet will manage the CATDocument life cycle using
	// addref and release

	CATSysSetOfCATDocument ( const CATSysSetOfCATDocument& iSysSet );
	// copy constructor

	virtual ~CATSysSetOfCATDocument();

	int Locate ( CATDocument* ) ;
	// returns 1 if the pointer is in the set 0 otherwise

	int Insert ( CATDocument* );
	// insert an element in the list; returns 1 if the pointer is already
	// in the set, 0 if the insertion succeeded, -1 if the insertion failed
	
	int Remove ( CATDocument* );
	// remove an element; returns 1 if the element is in the set, o otherwise

	int Size ();
	// returns the number of elements of the set

	CATDocument* operator [] ( int pos );
	// returns a pointer to the elememt number pos. The first element ranks at 0....

private :

	void SwitchTo ( ObjectType );

	union  { 
		CATDocument*				_ObjectS; 
		CATLISTP(CATDocument)*	_ObjectL; 
		CATSysSimpleHashTable*		_ObjectH; 
	};
	
	unsigned short _Limit ;

	unsigned short _ManRef;

	ObjectType _Type :3;
	
};


#endif
