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
//    Cette interface (qui �tend le comportement du CATFrmEditor) sert
//    � r�cup�rer un pointeur sur diff�rentes interfaces.
//    Lors de l'appel aux diff�rentes m�thodes GetXXXPanel, la fen�tre
//    de la commande XXX est instanci�e, et la m�thode appelante 
//    r�cup�re un pointeur sur l'interface CATIXXXPanel. 
//    Par le biais de cette derni�re, l'appelant peut s'abonner � divers
//    �v�nements et obtenir les informations de OK, CANCEL et autres.
//
//===================================================================
//
// Module
#include "UIModelInterfaces.h"

// H�ritage
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
