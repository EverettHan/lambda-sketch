#ifndef VisDisplayInfo_H
#define VisDisplayInfo_H

// COPYRIGHT DASSAULT SYSTEMES 2013

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
class CATUnicodeString;
class VisGPUAndDriverUtility;

class ExportedByCATVisFoundation VisDisplayInfo : public CATBaseUnknown
{
  CATDeclareClass;

public:

  enum  VisDisplayInfoRetCode {E_FAILED =0 , S_Supported_OS=1 ,S_LowOS_Ver=2};

  VisDisplayInfo();
  VisDisplayInfo(CATBoolean iUseVendorDisplayInfo);
  virtual ~VisDisplayInfo();
  
  int GetDisplayCount(int& oDisplayCount);
  int GetDisplayId(int iDisplayIndex, int& oDisplayId);
  int GetDisplayName(int iDisplayIndex, CATUnicodeString& oDisplayName);
  int GetGPUName(int iDisplayIndex, CATUnicodeString& oGPUName);
  int GetAdapterName(int iDisplayIndex, CATUnicodeString& oAdapterName);
  int GetBusNum(int iDisplayIndex, int& oBusNum);
  int GetDriverPath(int iDisplayIndex, CATUnicodeString& oDriverPath);
  int GetDisplayPositionAndResolution(int iDisplayIndex, int& oXDisplayOrigine, int& oYDisplayOrigine, int& oHorResolution, int& oVertResolution);
  VisDisplayInfoRetCode  CheckTouchDeviceAvailable(int & oTouchDeviceAvailable);

private:
  int Init();

  int SetupGDI();
  int SetupADL();
  int SetupNV();

private:
  VisGPUAndDriverUtility* _pGPUAndDriverUtility;
  int _setup;
  CATBoolean _useVendorDisplayInfo;
};

#endif
   
