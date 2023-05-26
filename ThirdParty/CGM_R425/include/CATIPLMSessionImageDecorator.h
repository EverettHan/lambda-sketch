#ifndef CATIPLMSessionImageDecorator_h
#define CATIPLMSessionImageDecorator_h



// this pseudo-interface is used to communicate between the SIM and the UI componants


/**
 * @level Private
 * @usage U2
 */




#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionImageDecorator;
#else
extern "C" const IID IID_CATIPLMSessionImageDecorator ;
#endif




class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionImageDecorator : public CATBaseUnknown
{
    CATDeclareInterface;
 public :

  /**
   * Writes an preview (image) of the session. The image should be in JPEG format and should be small (~130px width)
   * @param iImagePath [in] the file path where to write the image
   * @return S_OK if the image was correctly written
   *         E_FAIL if a problem occured
   */
  virtual HRESULT SnapshotSession(const CATUnicodeString & iImagePath) = 0;

};


#endif
