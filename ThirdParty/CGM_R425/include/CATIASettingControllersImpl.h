#ifndef CATIASETTINGCTRLSIMPL_H
#define CATIASETTINGCTRLSIMPL_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATIASettingControllers.h"
#include "CATBaseCollection.h"
// * qay 2008:07:17 InfInterfaces split #include "CD0AUTOSTART.h"
#include "InfOSIDLImpl.h"

class /* * qay 2008:07:17 InfInterfaces split ExportedByCD0AUTOSTART*/ ExportedByInfOSIDLImpl CATIASettingControllersImpl: public CATBaseCollection
{
  CATDeclareClass;
public:
  CATIASettingControllersImpl();
  
  virtual HRESULT Item(const CATBSTR &iIndex, CATIASettingController*& oCtrl);
  virtual HRESULT get_Name(CATBSTR & oNameBSTR);
  virtual HRESULT get_Count(CATLONG & oNbItems);
  virtual HRESULT get__NewEnum(IUnknown *& oenumCollect);
  

};

#endif
