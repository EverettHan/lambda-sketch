// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATINewStream.h
// Define the CATINewStream interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Nov 2002  Creation: Code generated by the CAA wizard  dem
//===================================================================
#ifndef CATINewStream_H
#define CATINewStream_H

/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATStream ;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAD0XXBAS IID IID_CATINewStream;
#else
extern "C" const IID IID_CATINewStream ;
#endif

//------------------------------------------------------------------

/**
 * This interface should be used to stream and unstream containers directly to disk
 * using a CATstream pointer. This should avoid the memory trouble
 * due to memory allocation for CATStreamArea used in the CATIStream interface.
 * If one only want to use one single method of this interface, 
 * the implementation of the other one should return E_NOTIMPL. Any other rc
 * would result in a critical error.
 * NB: For applicative containers only.
 */
class ExportedByAD0XXBAS CATINewStream: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
     * Method used to stream containers.
     * @ioStream pointer to a CATStream created during save operations
	 * and used to stream on disk.
	 * @iSeekAllowed is TRUE if the CATStream support Seek method.
	 * In case of error @oWriteError should be true if the error is due to a writing problem
	 * (error generated by CATStream write problem).
     */
    virtual HRESULT Stream (CATStream& ioStream, CATBoolean& oWriteError, const CATBoolean iSeekAllowed = FALSE) =0 ;

	/**
     * Method used to unstream containers.
     * @ioStream pointer to a CATStream created during load operations
	 * and used to unstream. iDataLength is corresponding to the total length 
	 * of the data of the given container.
	 * In case of inconsistency of the data read, oModelError should be valuated  
	 * at true and return E_FAIL.
	 * In case of an system error (i.e read error ) HRESULT should return an "FAILED" rc. 
	 * Returns S_OK if everything is OK.
     */
	virtual HRESULT UnStream (CATStream& ioStream, CATLONG32 iDataLength, CATBoolean& oModelError) =0 ;

 
};

CATDeclareHandler( CATINewStream, CATBaseUnknown );
 
//------------------------------------------------------------------

#endif
