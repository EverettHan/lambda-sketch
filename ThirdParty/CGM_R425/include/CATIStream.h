/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIStream_h
#define CATIStream_h

//====================================================================================
//
// Interface CATIStream :
//     
//       Interface for stream and unstream processes
//
//====================================================================================
// Usage Notes:
//
//  Methods
//      - Stream ..... Convert Data to binary format
//      - Unstream ... Do the opposite
//
//====================================================================================

/**
 * @level Private 
 * @usage U3
 */

#include "CATBaseUnknown.h"

class CATStreamArea;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIStream ;


class ExportedByAD0XXBAS CATIStream : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

	/*
     * Used to stream containers.
	 * @param oStreamArea
     * Pointer to a CATStreamArea created during save operations and used to stream on disk.
	 * @return 
     *   <code>S_OK</code> Streaming operation successfull. oStreamArea is pointing a valid CATStreamArea. 
  *   <code>S_FALSE</code> Nothing to be streamed. oStreamArea must be null
     *   <code>E_FAIL</code> Streaming operation failed. oStreamArea is null. 
	 */
    virtual HRESULT Stream (CATStreamArea*& oStreamArea) = 0;

	/*
     * Used to unstream  containers.
	 * @param iWhere
     * Pointer to a valid CATStreamArea where data will be unstreamed.
	 * @return 
     *   <code>S_OK</code> Unstreaming sucessfull. 
     *   <code>E_FAIL</code> Unstreaming failed (data inconsistency or system error). 
	 */

	virtual HRESULT UnStream (CATStreamArea* iWhere) = 0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIStream , CATBaseUnknown ) ;


#endif
