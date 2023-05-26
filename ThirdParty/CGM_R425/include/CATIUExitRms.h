/* COPYRIGHT DASSAULT SYSTEMES 2008 */

#ifndef CATIUExitRms_H 
#define CATIUExitRms_H
#include "IUnknown.h"


#if defined(__JS0DRMDOC)
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"

 
extern "C" const IID IID_CATIUExitRms;

     
  /**
   * @nodoc
   **/


class ExportedByJS0DRMDOC CATIUExitRms : public IUnknown
{
public:

  /**
   *  @nodoc
   * Get a Consolidated Status for the DRM
   * @param oOut
   *  Not Used 
   * @return
   *  S_OK   if the consolidated DRM status is OK
   *  E_FAIL if the consolidated DRM status is not OK
     */

  virtual HRESULT CheckPrereques ( int oOut )=0;
  /**
   * @nodoc
   */
};

#endif
