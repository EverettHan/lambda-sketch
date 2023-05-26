/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// Copyright Dassault Systemes 2000
#ifndef CATCkeObject_h
#define CATCkeObject_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Implementation Adapters
// 	declaration of Generic Object Implementation
//
//
//////////////////////////////////////////////////////////////////////////
//
// module
#include "CATLifExpressions.h"
#include "CATICkeTerm.h"

#include "CATEventSubscriber.h"
#include "CATCkeContext.h"
#include "CATICkeType.h"

class ExportedByCATLifExpressions CATCkeObject : public CATBaseUnknown
{
	CATDeclareClass;
public :
  
  virtual CATICkeType_var Type     () const =0;

  virtual CATCke::Boolean Isa       (const CATICkeType_var &t) const ;
  virtual CATCke::Boolean IsaKindOf (const CATICkeType_var &t) const ;

  // IsaXX
  virtual CATCke::Boolean IsaBoolean() const;
  virtual CATCke::Boolean IsaInteger() const;
  virtual CATCke::Boolean IsaString () const;

  virtual CATUnicodeString  Name     () const ;
  virtual CATCke::Boolean IsNamed  () const ;
  virtual CATUnicodeString  Show     () const ;

  virtual void    Rename   (CATUnicodeString) ;

protected:

  CATCkeObject ();
  CATCkeObject (const CATCkeObject&);
  virtual ~CATCkeObject();

}; 

#endif


