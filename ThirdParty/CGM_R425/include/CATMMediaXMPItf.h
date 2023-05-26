#ifndef CATMMEDIAXMPITF_H
#define CATMMEDIAXMPITF_H

#include "CATUnicodeString.h"

class CATMMediaXMPItf
{
public:
  enum fileMode      { fm_closed, fm_read, fm_write };
  enum fileAttribute { fa_no, fa_exist, fa_readable, fa_writable };

  virtual ~CATMMediaXMPItf() {};
                                                                                                   
  virtual bool              OpenFile(const CATUnicodeString iFilePathName, fileAttribute iMode)    = 0;
  virtual bool              CloseFile()                                                            = 0;
  virtual CATUnicodeString  GetFilePathName()                                                      = 0;
  virtual fileMode          GetFileStatus()                                                        = 0;
  virtual CATUnicodeString& GetErrors()                                                            = 0;

  virtual bool ReadMeta()                                                                          = 0;
  virtual CATUnicodeString DumpMeta()                                                              = 0;
  virtual bool HasNamespace(const char* iNS)                                                       = 0;
  virtual bool AddNamespace(const char* iNS, const char* iPrefix)                                  = 0;
  virtual bool WriteMeta()                                                                         = 0;

  virtual bool GetProperty      (const char* ipNS, const char* ipPropName, CATUnicodeString &oVal) = 0;
  virtual bool GetProperty_Bool (const char* ipNS, const char* ipPropName, bool             &oVal) = 0;
  virtual bool GetProperty_Int  (const char* ipNS, const char* ipPropName, CATINT32         &oVal) = 0;
  virtual bool GetProperty_Float(const char* ipNS, const char* ipPropName, double           &oVal) = 0;
  virtual bool SetProperty      (const char* ipNS, const char* ipPropName, CATUnicodeString  iVal) = 0;
  virtual bool SetProperty_Bool (const char* ipNS, const char* ipPropName, bool              iVal) = 0;
  virtual bool SetProperty_Int  (const char* ipNS, const char* ipPropName, CATINT32          iVal) = 0;
  virtual bool SetProperty_Float(const char* ipNS, const char* ipPropName, double            iVal) = 0;

protected:
  CATMMediaXMPItf() {};
};

#endif
