// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef _CATDBSERVER_
#define _CATDBSERVER_

#if defined(__CATSysDbSettings)
#define ExportedByCATSysDbSettings DSYExport
#else
#define ExportedByCATSysDbSettings DSYImport
#endif
#include "DSYExport.h"

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATMarshallableDbServer;

class ExportedByCATSysDbSettings CATDbServer : public CATBaseUnknown
{
  friend class CATMarshallableDbServer;

  CATDeclareClass;

  public:

  enum CATDbDatabaseVendor
    {
      DB2=1,
      Oracle=2,
      SQLServer=3,
      ODBC=4,
      JDBC=5
    };
  enum Authent
    {
      Server=1,
      System=2
    };

  CATDbServer();
  CATDbServer(const CATUnicodeString &iServerName
              ,const CATUnicodeString &iConnectionString
              ,CATDbDatabaseVendor iDatabaseVendor
              ,Authent iAuthenticationType);

  CATDbServer(const CATDbServer & iServer );

  ~CATDbServer() ;

  CATDbServer & operator= (const CATDbServer & iSrvToAffect);

  int operator== (const CATDbServer & iServerToCompare) const;
  int operator!= (const CATDbServer & iServerToCompare) const;

  const CATUnicodeString & GetName () const ;
  const CATUnicodeString & GetConnectionString () const;
  CATDbServer::CATDbDatabaseVendor GetDatabaseVendor() const;
  CATDbServer::Authent GetAuthenticationType () const;
  const CATUnicodeString & GetSingleUser () const ;
  const CATUnicodeString & GetSinglePass () const;

  void SetName (const CATUnicodeString & iName) ;
  void SetConnectionString (const CATUnicodeString & iCS) ;
  void SetDatabaseVendor(const CATDbServer::CATDbDatabaseVendor iVendor) ;
  void SetAuthenticationType (const CATDbServer::Authent iAuth);
  void SetSingleUser (const CATUnicodeString & iUs);
  void SetSinglePass (const CATUnicodeString & iPas);

  protected:

  CATUnicodeString                 _ServerName;
  CATUnicodeString                 _ServerConnection ;
  CATDbServer::CATDbDatabaseVendor _ServerType;
  CATDbServer::Authent             _ServerAuthent;
  CATUnicodeString                 _SingleUser;
  CATUnicodeString                 _SinglePass;
};

#endif
