/**
 * @level Private
 * @usage U1
 */

#ifndef __CATIOsmContainerGist_h__
#define __CATIOsmContainerGist_h__

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATOmxKernel.h"
class CATUuid;
class CATIOsmFeatureGist;
class CATUnicodeString;


extern ExportedByCATObjectModelerBase IID IID_CATIOsmContainerGist ;

/**
 * This interface allows to retrieve feature gist (see CATIOsmFeatureGist) without loading the container.
 */
class ExportedByCATObjectModelerBase CATIOsmContainerGist : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * Retrieve feature gist by instance number.
   * Does not load the container but work even if is loaded.
   */
  virtual HRESULT GetFeatureGistByInstanceNumber(int iInstanceNumber, CATOmxSR<CATIOsmFeatureGist>& oGist)= 0;

  /**
   * Retrieve feature gist by uuid.
   * Warning: some features may have the same uuid in some old corrupted containers.
   * Does not load the container but work even if is loaded.
   */
  virtual HRESULT GetFeatureGistByUuid(const CATUuid & iUuid, CATOmxIter<CATIOsmFeatureGist>& oGists)= 0;
};

CATDeclareHandler( CATIOsmContainerGist, CATBaseUnknown );

/**
 * Retrieve container gist.
 */
HRESULT Exported CATOsmGetContainerGist(const CATBaseUnknown * iContext, const CATUnicodeString & iContainerType, const CATUnicodeString & iContainerUserId,CATIOsmContainerGist_var& oContainerGist);


#endif // __CATIOsmContainerGist_h__

