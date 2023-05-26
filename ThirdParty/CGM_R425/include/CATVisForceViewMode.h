#ifndef CATVisForceViewMode_H
#define CATVisForceViewMode_H

#include "CATVisController.h"
#include "CATErrorDef.h"

class CATViewer;
class CATPathElement;
class ExportedByCATVisController CATVisForceViewMode
{
public:
  static HRESULT AddPath    (CATViewer* iViewer,
                            CATPathElement* iPath,
                            unsigned int iForceAxis=1,
                            unsigned int iForceLines=1,
                            unsigned int iForcePoints=1);

  static HRESULT RemovePath (CATViewer* iViewer,
                            CATPathElement* iPath);

  static void Empty         (CATViewer* iViewer);

private:
  CATVisForceViewMode();
  ~CATVisForceViewMode();
};

#endif

