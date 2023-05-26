//-----------------------------------------------------------------------------
// CATSupportAlgoFactory.h
// Usage : 
//-----------------------------------------------------------------------------
// Inheritance : 
//   CATSupportAlgoFactory
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2003
//-----------------------------------------------------------------------------
#ifndef CATSupportAlgoFactory_H
#define CATSupportAlgoFactory_H

#include "CATVisFoundation.h"
#include "CATVizBaseIUnknown.h"
#include "list.h"

class CATViewpoint;
class CATSupport;
class CATFrameData;
class CATPassContainerGeneral;
class CATVizBasePathElementRep;

class ExportedByCATVisFoundation CATSupportAlgoFactory : public CATVizBaseIUnknown
{
		friend class l_CATVisManager;
    friend class SGInfraToVisuFConnectToolImpl;
public:
  // 'or
  CATSupportAlgoFactory();
  virtual ~CATSupportAlgoFactory();
    
private:
  CATSupportAlgoFactory(const CATSupportAlgoFactory &);         // no copy constructor
  CATSupportAlgoFactory& operator = (const CATSupportAlgoFactory&);   // no egal operator

  static HRESULT UpdateBoundingElementOfPathElementRep(CATVizBasePathElementRep * iRep);

  // ORE: Deprecated
public:
  virtual void CreateSupportAlgo(CATSupport* i_prSupport);
};

#endif //CATSupportAlgoFactory_H
