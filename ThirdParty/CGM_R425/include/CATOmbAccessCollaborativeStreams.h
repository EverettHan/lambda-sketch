#ifndef CATOmbAccessCollaborativeStreams_H
#define CATOmbAccessCollaborativeStreams_H

#include "IUnknown.h"
#include "CATOmbSelectiveLoading.h"

class CATBaseUnknown;
class CATDocument;

class ExportedByCATOmbSelectiveLoading CATOmbAccessCollaborativeStreams
{
public:
  /* Method to override
  *  it will be called after during Start method. This one will load necessary data and unload them once visiting is finished
  *  @param iRepRef
  *     the repRef given to Start method
  *  @param iDoc
  *     the CATDocument loaded that has to be visited
  *  @return
  *     S_OK if all went well, else E_FAIL
  */
  virtual HRESULT VisitCollaborativeAuthoring(CATBaseUnknown& iRepRef, CATDocument& iDoc) = 0;

  /* This is the method to call to start visiting collaborative streams
  *  @param
  *     iRepRef : the repRef to visit
  *  @return
        S_OK : all is ok
        E_FAIL : error during load of document or during visit
  */
  HRESULT Execute(CATBaseUnknown& iRepRef);
};


#endif // CATOmbAccessCollaborativeStreams_H
