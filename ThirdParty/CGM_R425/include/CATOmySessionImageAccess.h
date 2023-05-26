#ifndef CATOmySessionImageAccess_H
#define CATOmySessionImageAccess_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Private
 * @usage U3
 */
#include "CATOMYBaseSession.h"
#include "CATBaseUnknown_var.h"

class OmySessionImageAdapter;
class CATOmySessionImageDescriptor;

/* classe d'accesseurs pour l'image */
class ExportedByCATOMYBaseSession CATOmySessionImageAccess
{
  friend class CATAdpChangeLogSetter;
  friend class CATAdpChangeLogGetter;
  friend class CATOmyServicesForPXn;
  friend class CATOmyServicesForSIM;
  friend class CATOmyServicesForSession;
  friend class CATPLMSessionImageManager;
  friend class CATPLMFaradayConnection;
  friend class TestFaradayLocalSaveServicesConnectionMngr;
private:
    /**
   * Get the current image from session, from BSC
   * @return
   *  The image in a CATBaseUnknown_var
   * <dl>
   *  <dt>CATBaseUnknown_var</dt><dd>Image (could be NULL)</dd>
   * </dl>  
   */
  static CATOmySessionImageDescriptor* GetCurrentImage();
  static OmySessionImageAdapter* GetCurrentImageAdapter();
};

#endif
