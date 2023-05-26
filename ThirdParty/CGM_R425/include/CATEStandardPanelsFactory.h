/* -*-c++-*- */
#ifndef CAT_E_STANDARD_PANELS_FACTORY_H
#define CAT_E_STANDARD_PANELS_FACTORY_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2001
//=============================================================================
//
// CATEStandardPanelsFactory (Adapter)
//    CATBaseUnknown
//
//=============================================================================
// Class from which must derive all the classes implementing the 
// CATIStandardPanelsFactory interface.
//=============================================================================
// Module
#include "UIModelInterfaces.h"

// Héritage
#include "CATBaseUnknown.h"

class CATISearchPanel;
class ExportedByUIModelInterfaces CATEStandardPanelsFactory : public CATBaseUnknown
{
  CATDeclareClass;

public:
  CATEStandardPanelsFactory();
  virtual ~CATEStandardPanelsFactory();

  //On reprend ici toutes les méthodes de CATIStandardPanelsFactory
  virtual HRESULT GetISearchPanel(CATISearchPanel*& oISearchPanel);
};
#endif
