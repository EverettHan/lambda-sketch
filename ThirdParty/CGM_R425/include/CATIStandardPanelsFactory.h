/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef CATIStandardPanelsFactory_H
#define CATIStandardPanelsFactory_H
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2001
//===================================================================
//
// CATIStandardPanelsFactory
//
//===================================================================
//
// Utilisation :
//    Cette interface (qui étend le comportement du CATFrmEditor) sert
//    à récupérer un pointeur sur différentes interfaces.
//    Lors de l'appel aux différentes méthodes GetXXXPanel, la fenêtre
//    de la commande XXX est instanciée, et la méthode appelante 
//    récupère un pointeur sur l'interface CATIXXXPanel. 
//    Par le biais de cette dernière, l'appelant peut s'abonner à divers
//    événements et obtenir les informations de OK, CANCEL et autres.
//
//===================================================================
//
// Module
#include "UIModelInterfaces.h"

// Héritage
#include <CATBaseUnknown.h>

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardPanelsFactory;
#else
extern "C" const IID IID_CATIStandardPanelsFactory;
#endif

class CATISearchPanel;
class ExportedByUIModelInterfaces CATIStandardPanelsFactory : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT GetISearchPanel(CATISearchPanel*& oISearchPanel) = 0;
};

// --------------------------------------------------------------------------
//                             pointeur intelligent
// --------------------------------------------------------------------------
//CATDeclareHandler(CATIStandardPanelsFactory, CATBaseUnknown);

#endif
