#ifndef CATOmbLinkIDCorrTable_H_
#define CATOmbLinkIDCorrTable_H_

#include "IUnknown.h"
#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATOmxOHMap.h"
#include "CATAssert.h"

class CATOmbLink;
class CATDocumentProperty;

/**
 * Class that is a correspondance table between links
 */
class CATOmbLinkIDCorrTable
{
public:

  CATOmbLinkIDCorrTable() {}

  ~CATOmbLinkIDCorrTable () {}

  /**
  * Retrieves the ID to stream.
  *
  * @param iRefLink
  * @return
  *        0 : if correspondance is not found.
  */	
  CATULONG32 GetCorrID (const CATOmbLink & iRefLink) const
  {
    const CATULONG32* pId = _Table.Locate(&const_cast<CATOmbLink&>(iRefLink));
    return pId ? *pId : 0;
  }

  /** 
  * Gives the object size. 
  * @return
  *	the current size
  */	
  int Size() const {return _Table.Size();}

private:

  /* forbidden operations */
  CATOmbLinkIDCorrTable (CATOmbLinkIDCorrTable &);
  CATOmbLinkIDCorrTable& operator=(CATOmbLinkIDCorrTable&);

  friend class CATOmbLinkFactory;

  void InsertEntry (const CATOmbLink & iRefLink, CATULONG32 iCorrID)
  {
    CATBoolean res = _Table.Insert(&const_cast<CATOmbLink&>(iRefLink),iCorrID);
    CATAssert(res);
  }

  /**
  * Refines expected size before internal data initialisation (Default is 11)
  */
  void RefineExpectedSize (unsigned int iExpectedSize) 
  {
    //_Table.Reserve(iExpectedSize); Missing on CATOmxOHMap...
    if(_Table.IsEmpty())
      _Table = CATOmxOHMap<CATOmbLink*,CATULONG32,naive_manager>(iExpectedSize);
  }

  CATOmxOHMap<CATOmbLink*,CATULONG32,naive_manager> _Table;
};

#endif


