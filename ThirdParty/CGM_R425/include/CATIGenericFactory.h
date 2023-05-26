/* -*-c++-*- */
#ifndef CATI_GENERIC_FACTORY_H
#define CATI_GENERIC_FACTORY_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U5
*/

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"


#include "CATOMY.h"
extern ExportedByCATOMY IID IID_CATIGenericFactory ;

/**
* Interface to generically define factories.
* <b> Role: </b> some commands like Edit/Properties or Tools/Options 
* need to instanciate components programmed by applications. These applications
* has to provide a factory to enable the instantiation of a component.
* Usually, an object factory creates one and only one object type.
* <br><b> Note: </b> There is no adapter to implement this interface, but some 
* commands provide macro to generate such factories. 
* <br><b> Usage: </b> In order to create a factory, an application defines a new 
* interface derived from CATIGenericFactory, implements  this interface as an extension 
* of a given component, and inserts apropriate declarations in .dic and .fact dictionnaries.
*/

class ExportedByCATOMY CATIGenericFactory : public CATBaseUnknown
{
  CATDeclareInterface;

 public:
	/**
	* Returns whether a given object type can be created using the factory.
	* @param iEditName
	*        name of object.
	* @return
	*        1 if the object type is supported.
    */
   virtual unsigned char       Support( const CATUnicodeString& iEditName ) const = 0 ;
   
    /**
	* Creates object and returns a pointer to a given interface.
	* <br><b> Note </b> that the given interface is supposed to be implemented by the
	* created object.
	* @param iIntfName
	*       interface to handle the created object.
	* @return
	*        pointer on the created object
    */
   virtual CATBaseUnknown*     Create ( const CATUnicodeString& iIntfName ) const = 0 ;
} ;
  

CATDeclareHandler( CATIGenericFactory, CATBaseUnknown ) ;


#endif

