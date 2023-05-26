// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMBodyTessellateCache.h
//
//===================================================================
//
// Feb 2016  Creation: TPG
//===================================================================

#ifndef CATCGMBodyTessellateCache_H
#define CATCGMBodyTessellateCache_H

#include "ExportedByTessellateCommon.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATTessSettings;

class ExportedByTessellateCommon CATCGMBodyTessellateCache : public CATBaseUnknown
{
CATDeclareClass;

public :
  CATCGMBodyTessellateCache ();

public:
  //Update tess cache
	HRESULT Update(CATTessSettings * iTessSettings);

  //Flag tess cache as persistent
  //To be done during an execute before save process
  HRESULT SetPersistent(CATTessSettings * iTessSettings);

public:  
  //Check
  //return 1 if a cache is available for the body
  //return 0 if no cache is available for the body
  HRESULT Check(CATTessSettings * iTessSettings);

private:
  enum Command_T
  {
    UpdateCache=0,
    SetCachePersistent,
    CheckCache
  };

  HRESULT RunCommand(Command_T iCommand, CATTessSettings * iTessSettings);

protected:
  virtual ~CATCGMBodyTessellateCache ();
};

#endif
