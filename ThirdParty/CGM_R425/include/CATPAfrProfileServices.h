#ifndef CATPAfrProfileServices_h
#define CATPAfrProfileServices_h
#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATCollec.h"
#include "CATListOfCATUnicodeString.h"


class CATPAfrMasterProfile;
class CATPAfrProfile;
class CATPAfrVariable;
class CATPAfrItem;
class CATSYPStyleProcessor;

// COPYRIGHT DASSAULT SYSTEMES 2012

//------------------------------------------------------------------------------
// This class exposes services for profiles management.
//------------------------------------------------------------------------------


class ExportedByCATAfrFoundation CATPAfrProfileServices
{
  
public:

  CATPAfrProfileServices();

  ~CATPAfrProfileServices();

  HRESULT ApplyProfile ( CATPAfrMasterProfile * iMP, CATPAfrProfile * iP, int start = 0 );

  HRESULT ApplyProfile ( CATUnicodeString iProfileName, int start = 0 , int deprof = 0 );
  
  CATUnicodeString GetOs();

  HRESULT ApplySetting ( CATBaseUnknown * ipVBU, CATPAfrVariable * ipVT );

  HRESULT ApplyPreference ( CATBaseUnknown * ipVBU, CATPAfrVariable * ipVT );

  HRESULT ApplyIProfile ( CATBaseUnknown * ipVBU, CATPAfrVariable * ipVT );

  CATUnicodeString GetValue( CATPAfrItem * iItem, CATPAfrVariable * ipVT);

  CATBaseUnknown_var  CreateSYPView( CATBaseUnknown* ipObject, const CATUnicodeString& iXmlFile, const CATUnicodeString& iTemplateName);

  CATString PAfrProfileFolder( );

  HRESULT GetProfileList (CATListOfCATUnicodeString &ilist );

private:

  CATListOfCATUnicodeString _listeErreurs;

  CATPAfrProfileServices (const CATPAfrProfileServices &);
  CATPAfrProfileServices & operator= (const CATPAfrProfileServices &);

  HRESULT WriteError ( CATUnicodeString iProfileName, int iStart );
  HRESULT ReadAndApplyErrors(CATUnicodeString iProfileName);

  static CATSYPStyleProcessor & GetPAfrStyleProcessor();

  void split(CATUnicodeString& iSrc, CATUnicodeString& iSplit, CATListOfCATUnicodeString& oLst);
  
  // for debug purpose, it allows to reload the P-Afr Style Processor from a debug panel.
  friend class CIDDebugReloadResourcesWidget;
  
};

#endif

















