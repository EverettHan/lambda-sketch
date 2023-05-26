// COPYRIGHT Dassault Systemes 2022

//===================================================================
#ifndef CATEStream2_H
#define CATEStream2_H

/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATIStream2.h"

class CATIOmxBinaryStream;



/*#else
extern "C" const IID IID_CATINStream2 ;
#endif*

//------------------------------------------------------------------

/**
 * This interface should be used to stream and unstream containers using CATIOmxBinaryStream reference. This replaces CATIStream and CAtINewStream for applicative containers
 * All methods have to be implemented, if CATIOmbIncrementalStream is not implemented for applicative containers. 
 * This interface is used in first choice and will be mandatory for applicative containers from R425 GA
 */
class ExportedByAD0XXBAS CATEStream2 : public CATIStream2
{

public:
/**
 * Method used to stream containers.
 *  @ioStream pointer to a CATIOmxBinaryStream created during save operations
 * and used to stream the container persistence.
 *  @iSeekAllowed is TRUE if the CATStream support Seek method.
 *  @returnCode :  S_OK : everything ran well
 *    E_XXX : error happened, the document streaming will be interrupted and not saved. Error will be logged
 *
 *  /!\ Size of streams are limited to 2Gio and 4Gio in case of LargeFile document. See CATIStream2 PES for more details. In case of oversize, the save procedure of the document will be canceled.
 *
 * To log application specific errors or warning only (with S_OK rc) we recommend to use function such as CATOmxLogError see https://osmwebdsy/wiki/index.php/CATOmxLogError
*/
  HRESULT Stream(CATIOmxBinaryStream& ioStream, const CATBoolean iSeekAllowed) override { return E_NOTIMPL; }

/**
 * Method used to unstream containers.
 *  @ioStream pointer to a CATIOmxBinaryStream created during Load operations
 * and used to unstream the container persistence.
 *  @iDataLength : The size in bytes of the stream to read.
 *  @returnCode :  S_OK : everything ran well
 *    E_XXX : error happened, the document unstreaming will be interrupted and not be loaded. Error will be logged
 *
 * To log application specific errors or warning only (with S_OK rc) we recommend to use function such as CATOmxLogError see https://osmwebdsy/wiki/index.php/CATOmxLogError
*/
  HRESULT Unstream(CATIOmxBinaryStream& ioStream, CATLONG64 iDataLength) override { return E_NOTIMPL; }

  //CATDeclareAdapter(CATEStream2);
  void* CATEStream2AdapterProtection(CATOmbAdapterProtection* iArg);

protected:
  CATEStream2() {}
  virtual ~CATEStream2() {}
};


//------------------------------------------------------------------

#endif

