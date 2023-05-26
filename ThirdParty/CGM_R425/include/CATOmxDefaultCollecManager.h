/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxDefaultCollecManager_H
#define __CATOmxDefaultCollecManager_H

#include "CATOmxKernel.h"

#ifndef Exporting
#define Exporting DSYExport
#include "DSYExport.h"
#endif

class CATOmxCollecManager;


/** 
 * This is used to implement the default Collection manager bind to a collection.
 */
template<class Object> 
class Exporting CATOmxDefaultCollecManager 
{
public:
  static CATOmxCollecManager& manager(); 
private:
  CATOmxDefaultCollecManager();
  CATOmxDefaultCollecManager(const CATOmxDefaultCollecManager<Object>&);
  CATOmxDefaultCollecManager<Object>& operator=(const CATOmxDefaultCollecManager<Object>& );
};
/* define forward of default collect manager. */
#define OMX_FWD_DEFAULT_MANAGER(type) \
template<> Exporting CATOmxCollecManager& CATOmxDefaultCollecManager<type>::manager()

#include "CATOmxKernel_mgr.h"
#include "CATOmxSystem_mgr.h"

#endif
