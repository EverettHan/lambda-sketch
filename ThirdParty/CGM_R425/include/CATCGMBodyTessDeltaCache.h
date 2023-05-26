// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMBodyTessDeltaCache.h
//
//===================================================================
//
// Feb 2016  Creation: TPG
//===================================================================

#ifndef CATCGMBodyTessDeltaCache_H
#define CATCGMBodyTessDeltaCache_H

#include "ExportedByTessellateCommon.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATTessSettings;
class CATListPtrCATCell;

class ExportedByTessellateCommon CATCGMBodyTessDeltaCache : public CATBaseUnknown
{
CATDeclareClass;

public :
  CATCGMBodyTessDeltaCache ();

public:
  //Update tess cache
  //return S_OK if all cells have cache
  //return S_FALSE if some cells don't have cache
	//oListPtrCATCell : list of CATCell actually having cache
	HRESULT Update(CATTessSettings * iTessSettings, CATListPtrCATCell * oListPtrCATCell=0);

  //Flag tess cache as persistent
  //To be done during an execute before save process
  //return S_OK if all cells have cache
  //return S_FALSE if some cells don't have cache
	//oListPtrCATCell : list of CATCell actually having cache
  HRESULT SetPersistent(CATTessSettings * iTessSettings, CATListPtrCATCell * oListPtrCATCell=0);

public:  
  //Check
  //return S_OK if all cells have cache
  //return S_FALSE if some cells don't have cache
	//oListPtrCATCell : list of CATCell actually having cache
  HRESULT Check(CATTessSettings * iTessSettings, CATListPtrCATCell * oListPtrCATCell=0);

private:
  enum Command_T
  {
    UpdateCache=0,
    SetCachePersistent,
    CheckCache
  };

  HRESULT RunCommand(Command_T iCommand, CATTessSettings * iTessSettings, CATListPtrCATCell * oListPtrCATCell);

protected:
  virtual ~CATCGMBodyTessDeltaCache ();
};

#endif
