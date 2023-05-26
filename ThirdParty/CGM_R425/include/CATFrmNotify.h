#ifndef CATFrmNotify_h
#define CATFrmNotify_h

// COPYRIGHT DASSAULT SYSTEMES 2000

// Obsolete, do not use.

#include <CATAfrFoundation.h>
#include <CATDlgNotify.h>

class ExportedByCATAfrFoundation CATFrmNotify : public CATDlgNotify
{
  CATDeclareClass;
  
public:
  
  CATFrmNotify(CATDialog * pParent,
	       const CATString & rObjectName,
	       CATDlgStyle nStyle = NULL);
  virtual ~CATFrmNotify();
};

#endif
