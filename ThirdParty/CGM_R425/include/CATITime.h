/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Private
  * @usage U5
  */

#ifndef CATITime_H
#define CATITime_H

#include "AD0XXBAS.h"
#include "CATTime.h"
#include "CATBaseUnknown.h"

extern ExportedByAD0XXBAS IID IID_CATITime ;

/**
* Interface to manage the time stamp of an object.
* <br> Do  not use this Interface
* @see CATTime
*/
class ExportedByAD0XXBAS CATITime : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

	/**
	* Returns the time stamp of an object.
    */
   virtual CATTime GetTimeStamp () = 0 ;
    
    /**
     * Sets a time stamp to an object.
	 * @param iNewTime
	 *       time stamp to set to the object.
     */
   virtual void SetTimeStamp (CATTime iNewTime) = 0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler (CATITime ,CATBaseUnknown) ;


#endif
