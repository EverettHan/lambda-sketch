#ifndef IVisuProductLoaderCGRLDHStrategy_H
#define IVisuProductLoaderCGRLDHStrategy_H

#include "CATVisItf.h"

#include "IVisuProductLoaderCGRStrategy.h"

extern ExportedByCATVisItf IID IID_IVisuProductLoaderCGRLDHStrategy;

class CATViewer;
class CATGraphicWindow;
class CATSGOptionManager;
template<class T>
class CATCompositeTPtr;

/** /Class IVisuProductLoaderCGRLDHStrategy is an interface for the CATVisuProductLoaderCGRLDHStrategy outside the current framework
* this strategy is dedicated to VisuProductLoader
* It determines how CGR are loaded.
* The current class uses the VVS cache and can activate LDH.
**/
class ExportedByCATVisItf IVisuProductLoaderCGRLDHStrategy : public IVisuProductLoaderCGRStrategy
{

  CATDeclareInterface;

public:

  virtual bool IsLDH() const = 0;

  virtual void SetLDH(bool iLDH) = 0;

  virtual bool IsBadAuthentication() const = 0;

  virtual HRESULT SetViewer(CATViewer* iViewer) = 0;

  virtual HRESULT SetOptionManager(const CATCompositeTPtr<CATSGOptionManager>& iOptionManager) = 0;

  virtual CATGraphicWindow* GetGraphicWindow() const = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler(IVisuProductLoaderCGRLDHStrategy, IVisuProductLoaderCGRStrategy);

#endif
