#ifndef CATAfrCustomSelectionFilterHeader_H
#define CATAfrCustomSelectionFilterHeader_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "CATDialogEngine.h"

#include "CATCheckHeader.h"
#include "CATString.h"

class CATIDegUserFilter;
class CATCustomFilterEngine;

class ExportedByCATDialogEngine CATAfrCustomSelectionFilterHeader : public CATCheckHeader
{
  CATDeclareClass;
  CATDeclareHeaderSpecialResources;

public:

  CATAfrCustomSelectionFilterHeader(const CATString& iHeaderId, 
    CATString iResourcesFileNamePrefix="CATAfr");
  CATAfrCustomSelectionFilterHeader( CATAfrCustomSelectionFilterHeader * iHeader);
  virtual ~CATAfrCustomSelectionFilterHeader();

  virtual CATCommandHeader * Clone();
  virtual void SetChecked();
  virtual void SetUnChecked();

  // iLateType must implement CATIDegUserFilter interface
  void SetCustomFilter(const CATString & iLateType);

private:

  void InitCustomFilter();

  CATIDegUserFilter   * _customFilter;
  CATCustomFilterEngine * _customFilterEngine;
  CATString _customFilterType;
};
#endif
