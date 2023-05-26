/* -*-c++-*- */
#ifndef LIFE_CYCLE_OBJECT_H
#define LIFE_CYCLE_OBJECT_H

// COPYRIGHT DASSAULT SYSTEMES 1999 

/**
* @CAA2Required
*              
*/

#include "CATBaseUnknown.h"


#include "CATOMY.h"
extern ExportedByCATOMY IID IID_LifeCycleObject ;

/**
* Interface to manage remove of an object.
*/
class ExportedByCATOMY LifeCycleObject : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
	/**
    * Removes the object.
	 * @param iForCloseContext
    *      This argument must be always 0. Only internal DS code can use the value 1. If you do not
    *      use 0, you can have DOC_4 errors in the CATDUA application (Cleaner).  
	 */
	  virtual void           remove( int iForCloseContext=0 ) = 0 ;
} ; 

CATDeclareHandler( LifeCycleObject, CATBaseUnknown ) ;


#endif


