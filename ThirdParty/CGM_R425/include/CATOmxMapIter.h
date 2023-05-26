/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxMapIter_h__
#define __CATOmxMapIter_h__

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"

struct CATOmxMapIterContext;

/**
 * this is base class for CATOmxMapIter that allows to avoid code generation
 * you must use specialized class CATOmxMapIter
 */
class ExportedByCATOmxKernel CATOmxBaseMapIter 
{
protected:  
  CATOmxMapIterContext *ctx;
  void* _Value() const;
  void* _Key() const;
  void AssignIterator(const CATOmxBaseMapIter &op);
public:
  /** reserved for collection implementators.*/
  CATOmxBaseMapIter(CATOmxMapIterContext *iCtx, CATBoolean iSteal);
  CATBoolean Next(); 

  const void* _NextKey(); 

  ~CATOmxBaseMapIter();
  inline CATOmxBaseMapIter() : ctx(NULL) {}
private:
  CATOmxBaseMapIter(const CATOmxBaseMapIter &iIter);
};
/**
 * iterator on a CATOmxOmap map.
 * usage: (with a map that associates a string to an object
 * CATOmxOMap<CATUnicodeString,IUnknown*> map;
 * CATOmxMapIter<CATUnicodeString,IUnknown*> iter(map.MapIterator());
 * while(iter.Next())
 * {
 *   CATUnicodeString key = iter.Key();
 *   IUnknown* value = iter.Value();
 *   //your code
 * }
 * restriction: you must not alterate the map while using an iterator on it
 */
template<class KeyT,class ValueT=KeyT>
class CATOmxMapIter : public CATOmxBaseMapIter 
{
public: 
  /** reserved for collection implementators.*/
  inline CATOmxMapIter(CATOmxMapIterContext *iCtx, CATBoolean iSteal):CATOmxBaseMapIter(iCtx,iSteal) {}
  inline CATOmxMapIter(const CATOmxMapIter<KeyT,ValueT>& iIter):CATOmxBaseMapIter(iIter.ctx,FALSE) {}
  inline CATOmxMapIter() {}
  inline CATOmxMapIter<KeyT,ValueT>& operator=(const CATOmxMapIter<KeyT,ValueT>&iIter) { AssignIterator(iIter); return *this; }
  inline       ValueT& Value() { return *(ValueT*)_Value();  }
  inline const KeyT&   Key()   { return *(KeyT*)_Key();  }

  inline const KeyT* NextKey() {return (const KeyT*)_NextKey();}
};

#endif
