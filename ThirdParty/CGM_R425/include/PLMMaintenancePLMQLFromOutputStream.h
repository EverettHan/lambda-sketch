// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// PLMMaintenancePLMQLFromOutputStream.h
// Accumule le plmql arrivant via l'interface CATIComSidlOutputStream
// pour permettre ensuite de comparer 2 stream de ce type
#ifndef PLMMaintenancePLMQLFromOutputStream_H
#define PLMMaintenancePLMQLFromOutputStream_H

#include "CATOMYCommunication.h"
#include "CATOmyOutputStreamVPLMSessionPLMQLDetector.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------
class ExportedByCATOMYCommunication PLMMaintenancePLMQLFromOutputStream: public CATOmyOutputStreamVPLMSessionPLMQLDetector

{
  CATDeclareClass;

public:
  PLMMaintenancePLMQLFromOutputStream ();
  virtual ~PLMMaintenancePLMQLFromOutputStream ();

  // Compare 2 PLMMaintenancePLMQLFromOutputStream.
  // Returns E_FAIL if the streams haven't been ended, S_OK if PLMQL is the same, S_FALSE if different
  HRESULT HasSamePLMQL(const PLMMaintenancePLMQLFromOutputStream * iRefPLMQL);
  void InitPLMQLAcquisition();
  CATUnicodeString ConvertToString(){return _PLMQL;}
protected:

  // CATOmyOutputStreamVPLMSessionPLMQLDetector methods
  HRESULT DoBeginStream ();
  HRESULT DoWriteDouble (double  iNum );
  HRESULT DoWriteInt (int  iNum );
  HRESULT DoWriteString (const CATUnicodeString &  iChar );
  HRESULT DoWriteBinary (const char *  iSrc   , int  iLen );
  HRESULT DoEndStream ();

private:
  PLMMaintenancePLMQLFromOutputStream (PLMMaintenancePLMQLFromOutputStream &);
  PLMMaintenancePLMQLFromOutputStream& operator=(PLMMaintenancePLMQLFromOutputStream&);

  enum status{notstarted,started,ended};
  status _status;
  CATUnicodeString _PLMQL;
};
//-----------------------------------------------------------------------
#endif
