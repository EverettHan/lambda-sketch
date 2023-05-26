#ifndef CATVisFilterPickPath_H
#define CATVisFilterPickPath_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "SGInfra.h"
#include "CATPickPath.h"

class CATVisFilter;

class ExportedBySGInfra CATVisFilterPickPath : public CATPickPath
{
public :
  CATVisFilterPickPath();
  virtual ~CATVisFilterPickPath();

  CATVisFilterPickPath(const CATPickPath& iPickPath);

  CATVisFilterPickPath(const CATVisFilterPickPath&) = delete;
  const CATVisFilterPickPath& operator = (const CATVisFilterPickPath&) = delete;
 

  void SetFilter(CATVisFilter* iFilter);
  void GetFilter(CATVisFilter*& oFilter);

protected:
  CATVisFilter* m_pFilter = nullptr;
};

#endif
