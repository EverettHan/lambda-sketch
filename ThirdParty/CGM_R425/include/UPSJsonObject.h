
#ifndef UPSJsonObject_H
#define UPSJsonObject_H

#include "ExportedByCoexUPSJsonMapping.h"
#include "CATStdIO.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxOHMap.h"
#include "CATBoolean.h"
#include "CATOmxJsonArray.h"
#include "UPSJsonMapping.h"
#include "CATPLMID_Simple.h"

//class UPSJsonInstance;
//class UPSJsonReference;

class ExportedByCoexUPSJsonMapping UPSJsonObject
{
private:

  UPSJsonObject& operator=(const UPSJsonObject&);
  UPSJsonObject(const UPSJsonObject&);

public:
  UPSJsonObject();
  ~UPSJsonObject();


  HRESULT Get3dExpCEStamp(CATUnicodeString& o3dExpCEStamp);
  HRESULT Set3dExpCEStamp(const CATUnicodeString& i3dExpCEStamp);

  HRESULT Get3dExpID(CATUnicodeString& o3dExpID);
  HRESULT Set3dExpID(const CATUnicodeString& i3dExpID);

  // For TE to set the 3DExPID for Ref
  HRESULT Set3dExpID(const CATPLMID_Simple& i3dExpPLMID);

  HRESULT IsObjectLocal(CATBoolean& oIsLocal);
  HRESULT SetLocal(const CATBoolean& iIsLocal);

  HRESULT GetxCADID(CATUnicodeString& oXCADID);
  HRESULT SetxCADID(const CATUnicodeString& iXCADID);

  HRESULT GetDocID(CATUnicodeString& oCustomData);
  HRESULT SetDocID(const CATUnicodeString& iCustomData);

  HRESULT GetSynchroStamp(CATUnicodeString& oSynchroStamp);
  HRESULT SetSynchroStamp(const CATUnicodeString& iSynchroStamp);

  HRESULT GetXSS(CATBoolean& oIsSetXSS);
  HRESULT SetXSS(const CATBoolean& iIsSetXSS);

private:


  CATUnicodeString _xCADID;
  CATUnicodeString _CEStamp;
  CATUnicodeString _CustomData;
  CATUnicodeString _CUS3DExpId;
  CATBoolean _bIsLocal;
  CATUnicodeString _SynchroStamp;
  CATBoolean _isSetXSS;

};



#endif

