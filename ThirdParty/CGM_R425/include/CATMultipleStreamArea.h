/**
 * @level Protected
 * @usage U1
 */
#ifndef CATMultipleStreamArea_H
#define CATMultipleStreamArea_H

// COPYRIGHT DASSAULT SYSTEMES 2001


#include "AC0XXLNK.h"
#include "CATStreamArea.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"

/**
* Class to define an area.
*/


class ExportedByAC0XXLNK CATMultipleStreamArea : public CATStreamArea
{
  public :

  CATMultipleStreamArea();
  virtual ~CATMultipleStreamArea();
  
  virtual HRESULT GetArea(CATULONG32     &oGlobalLengthInBytes,
                          CATULONG32     &oNumberOfArea,
                          CATULONG32   * &oAreaLengthInBytes,
                          void         * * &oAreaAddress);

  virtual HRESULT FreeArea();

  virtual void* Get();
};

#endif
