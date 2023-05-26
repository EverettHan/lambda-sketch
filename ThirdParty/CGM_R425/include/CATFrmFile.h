#ifndef CATFrmFile_h
#define CATFrmFile_h


// COPYRIGHT DASSAULT SYSTEMES 2000

// Obsolete, do not use.

#include <CATAfrFoundation.h>
#include <CATDlgFile.h>

class ExportedByCATAfrFoundation CATFrmFile : public CATDlgFile
{
  CATDeclareClass;
  
public:
  
  CATFrmFile(CATDialog * pParent,
	     const CATString & rObjectName,
	     CATDlgStyle nStyle = NULL);
  virtual ~CATFrmFile();
};

#endif
