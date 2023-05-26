#ifndef CATVOSnapshotFactory_H
#define CATVOSnapshotFactory_H

// ObjectModelerBase
#include "CATIVOFactory.h"
#include "CATObjectModelerBase.h"

// Implementation class of CATIVOFactory for VOSnapshot.
class ExportedByCATObjectModelerBase CATVOSnapshotFactory : public CATIVOFactory
{
public:
  CATVOSnapshotFactory();
  virtual ~CATVOSnapshotFactory();

  virtual HRESULT GetVOForList(CATLISTP(CATBaseUnknown) const & iList, CATOmbVOUpdateFlavour const & iFlavour, CATBaseUnknown *& oVO) const;
  virtual HRESULT GetListForVO(CATBaseUnknown * iVO, CATLISTP(CATBaseUnknown) & oList, CATOmbVOUpdateFlavour & oFlavour) const;
  virtual HRESULT GetName(CATUnicodeString & oId) const;
  virtual HRESULT CreateVOForList(CATLISTP(CATBaseUnknown) const & iList, CATOmbVOUpdateFlavour const & iFlavour, CATBaseUnknown *& oVO);

private:
  CATVOSnapshotFactory(CATVOSnapshotFactory &); // Not implemented.
  CATVOSnapshotFactory& operator=(CATVOSnapshotFactory&); // Not implemented.
};

#endif
