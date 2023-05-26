#ifndef CATOmbIDLinkCorrTable_H_
#define CATOmbIDLinkCorrTable_H_

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
class CATOmbIDLinkCorrTable
{
public:

  CATOmbIDLinkCorrTable () {}
  ~CATOmbIDLinkCorrTable () {}
 
  /**
  * Retrieves the Link
  *
  * @param iRefLinkID
  * @return
  *         ==0 : no corresponding link !!!
  *         !=0 : the injected link
  */	
  const CATOmbLink * GetCorrLink (CATULONG32 iRefLinkID) const
  {
    const CATOmbLink*const* pLink = _Table.Locate(iRefLinkID);
    return pLink ? *pLink : NULL;
  }

  /** 
  * Gives the object size. 
  * @return
  *	the current size
  */	
  int Size() const {return _Table.Size();};

private:

  /* forbidden operations */
  CATOmbIDLinkCorrTable (CATOmbIDLinkCorrTable &);
  CATOmbIDLinkCorrTable& operator=(CATOmbIDLinkCorrTable&);

  friend class CATOmbLinkFactory;

  void InsertEntry (CATULONG32 iRefLinkID, const CATOmbLink & iCorrLink)
  {
    CATBoolean rc = _Table.Insert(iRefLinkID,&const_cast<CATOmbLink&>(iCorrLink));
    CATAssert(rc);
  }

  /**
  * Refines expected size before internal data initialisation (Default is 11)
  */
  void RefineExpectedSize (unsigned int iExpectedSize)
  {
    //_Table.Reserve(iExpectedSize); Missing on CATOmxOHMap...
    if(_Table.IsEmpty())
      _Table = CATOmxOHMap<CATULONG32,CATOmbLink*,CATOmxDefaultCollecManager<CATULONG32>::manager,naive_manager>(iExpectedSize);
  }
 
  CATOmxOHMap<CATULONG32,CATOmbLink*,CATOmxDefaultCollecManager<CATULONG32>::manager,naive_manager> _Table;
};

#endif


