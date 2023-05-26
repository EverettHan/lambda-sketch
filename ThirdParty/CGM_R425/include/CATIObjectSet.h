#ifndef CATIObjectSet_h
#define CATIObjectSet_h
/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include <IUnknown.h>

class CATIObjectPathList;

/**
 */
class CATIObjectSet : public IUnknown
{
public:
  
  /**
   */
  virtual HRESULT GetObjects(CATIObjectPathList ** oPaths) const = 0;
  
  /**
   */
  virtual HRESULT Add(const CATIObjectPathList * iPaths) = 0;
  
  /**
   */
  virtual HRESULT Remove(const CATIObjectPathList * iPaths) = 0;
  
  /**
   */
  virtual HRESULT Clear() = 0;
};

/* 8D29ADC9-28CB-0000-0280-020F32000000 */
extern "C" const IID IID_CATIObjectSet;

#endif
