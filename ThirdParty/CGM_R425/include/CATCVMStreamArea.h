#ifndef CATCVMStreamArea_H
#define CATCVMStreamArea_H

// COPYRIGHT DASSAULT SYSTEMES 2001

//=========================================================================================
// Nov  06                                     JMA
//=========================================================================================

#include "CATCVMGeoObjects.h"
#include "CATDataType.h"
#include "CATMultipleStreamArea.h"
#include "CATCGMNewArray.h"
/**
* Class to define an area.
*/

class CATCGMStream;

class ExportedByCATCVMGeoObjects CATCVMStreamArea : public CATMultipleStreamArea
{
  public :

  CATCVMStreamArea(void*             iBuffer,
                   CATULONG32        iSizeBuffer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  CATCVMStreamArea(CATCGMStream *iStream);
  virtual ~CATCVMStreamArea();

  /* On ne peut pas encore passer sur des size_t tant que CATMultipleStreamArea n'est pas migre...

  virtual HRESULT GetArea(size_t           &oGlobalLengthInBytes,
                          CATULONG32     &oNumberOfArea,
                          size_t         * &oAreaLengthInBytes,
                          void         * * &oAreaAddress);
  */

  virtual HRESULT GetArea(CATULONG32     &oGlobalLengthInBytes,
                          CATULONG32     &oNumberOfArea,
                          CATULONG32     * &oAreaLengthInBytes,
                          void         * * &oAreaAddress);

  virtual HRESULT FreeArea();

  private :
CATCGMStream *_stream;
};

#endif
