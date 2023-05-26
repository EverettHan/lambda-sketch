/**
 * @level Private
 * @usage U3
 */
/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIOmbRepRefUpdateStamp.h
// Define the CATIOmbRepRefUpdateStamp interface
//
//===================================================================
//
// Usage notes:
//   Interface to be used to control UpdateStamp data increment 
//   on Representation Reference component
//===================================================================
//
//
//===================================================================
//  June 2005  Creation                                           VCS
//===================================================================

#ifndef CATIOmbRepRefUpdateStamp_H
#define CATIOmbRepRefUpdateStamp_H

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAD0XXBAS IID IID_CATIOmbRepRefUpdateStamp;
#else
extern "C" const IID IID_CATIOmbRepRefUpdateStamp ;
#endif

//------------------------------------------------------------------

/**
* Interface dedicated to UpdateStamp information modification on CATRepresentationReference.
* <br><b>Role:</b> Updates and store on CATRepresentationReference a modification stamp 
* <br> about changes that happened on its significant data currently handled :
* <br> that is, its authoring CATDocument in V5R201 but may be also other data later.
*/

class ExportedByAD0XXBAS CATIOmbRepRefUpdateStamp: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
	* Triggers off UpdateStamp incrementation on current CATRepresentationReference.
	* <br><b>Role:</b> triggers off UpdateStamp update and storage on current
	*                  CATRepresentationReference component.
	* @param oUpdateStampModified 
	*     TRUE: indicates that UpdateStamp effectively updated and its new value stored.
	* @return
	*		 S_OK : successfully ended
	* <br> E_FAIL : a software error occured
	*/
	virtual HRESULT TouchUpdateStamp(CATBoolean & oUpdateStampModified)= 0;

};

//------------------------------------------------------------------

#endif
