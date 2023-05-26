// Copyright Dassault Systemes 2000
#ifndef CATCkeExprComponent_h
#define CATCkeExprComponent_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Engineering Equations
// 	Named components
//
//////////////////////////////////////////////////////////////////////////

// module
#include "CATLifExpressions.h"

#include "CATCkeObject.h"

class ExportedByCATLifExpressions CATCkeExprComponent: public CATCkeObject
{
	CATDeclareClass	;

public :
	
	CATCkeExprComponent (const CATICkeType_var&, const CATUnicodeString  = "");
	virtual ~CATCkeExprComponent() ;
	
	virtual CATUnicodeString   Name    () const ;
	
	// Object inherited services
	virtual CATUnicodeString   Identify() const; 
	
	virtual CATICkeType_var Type    () const ;
	virtual void     Rename  (CATUnicodeString s) ;
	
	// uses - not exported
	CATUnicodeString  IdtType() const;
	
	// use with ultra care
	void SetType (const CATICkeType_var &type);
	
protected:
	
	CATUnicodeString   _name;
	CATICkeType_var _type;

private:
	CATCkeExprComponent (const CATCkeExprComponent&);
	void operator=(const CATCkeExprComponent&);
}; 

#endif



