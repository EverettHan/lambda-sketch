#ifndef CATI3DCustomHandleManager_h
#define CATI3DCustomHandleManager_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATMathTransformation;

extern ExportedByCATAfrSelection IID IID_CATI3DCustomHandleManager;

class ExportedByCATAfrSelection CATI3DCustomHandleManager : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  // Interface mise en oeuvre par le CAT3DMoveAgent pour la gestion des événements

  // Enregistre le CustomHandleManager (classe implémentant CATI3DCustomHandle) 
  // dans la liste des CustomHandleManager gérée par le CAT3DMoveAgent
  virtual HRESULT RegisterCustomHandle(CATBaseUnknown * iHandleManager) = 0;
  
  // Effectue l'inverse
  virtual HRESULT UnregisterCustomHandle(CATBaseUnknown * iHandleManager) = 0;

  // Définit un CustomHandleManager comme étant celui actif, c'est à dire celui 
  // d'où provient les notifications de manipulation
  virtual HRESULT SetActiveCustomHandle(CATBaseUnknown * iActiveHandleManager) = 0;


  // Move other handles on dragged object
  virtual HRESULT BeginMoveInactiveHandle(CATMathTransformation * iTransformation) = 0;
  virtual HRESULT MoveInactiveHandle(CATMathTransformation * iTransformation) = 0;
  virtual HRESULT EndMoveInactiveHandle(CATMathTransformation * iTransformation) = 0;


  // Move other objects in multiselection list
  virtual HRESULT BeginMoveMultiSelection(CATMathTransformation * iTransformation) = 0;
  virtual HRESULT MoveMultiSelection(CATMathTransformation * iTransformation) = 0;
  virtual HRESULT EndMoveMultiSelection(CATMathTransformation * iTransformation) = 0;
};

CATDeclareHandler(CATI3DCustomHandleManager, CATBaseUnknown);

#endif
