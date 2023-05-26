#ifndef CATIObjectSetEvent_h
#define CATIObjectSetEvent_h
/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include <IUnknown.h>

class CATIObjectPathList;
class CATIObjectSet;

/**
 */
class CATIObjectSetEvent : public IUnknown
{
public:
  
  /**
   */
  virtual HRESULT ObjectsAdded(CATIObjectSet * iSet,
			       CATIObjectPathList * iPaths) = 0;
  
  /**
   */
  virtual HRESULT ObjectsRemoved(CATIObjectSet * iSet,
				 CATIObjectPathList * iPaths) = 0;
};

/* 8D29AB1B-111F-0000-0280-020F32000000 */
extern "C" const IID IID_CATIObjectSetEvent;

#endif
