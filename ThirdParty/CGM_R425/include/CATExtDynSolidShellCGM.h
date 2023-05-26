#ifndef CATExtDynSolidShellCGM_H_
#define CATExtDynSolidShellCGM_H_

#include "CATShellOperatorExt.h"
#include "ExportedByBONEWOPE.h"


class ExportedByBONEWOPE CATExtDynSolidShellCGM : public CATShellOperatorExt
{
public :
  CATExtDynSolidShellCGM();
  ~CATExtDynSolidShellCGM();

  CATCGMNewClassArrayDeclare; // Pool allocation

  virtual CATBoolean IsVoBSupported();
};

#endif

