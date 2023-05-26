#ifndef CATISelectMoveSelector_h
#define CATISelectMoveSelector_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

#include "CATCafCATISelectMoveSelectorIID.h"

class CATPathElement;

class ExportedByCATAfrSelection CATISelectMoveSelector : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * This interface is to be implemented by workbench UIActive object
   * or by a late type of the workshop.
   *
   * It is used to find which element should be manipulated depending
   * on the selected CATPathElement
   * 
   * <br><b>Lifecycle rules deviation</b>: No AddRef must be performed 
   * on the returned value. 
   */

  virtual HRESULT GetManipulatedElement(CATPathElement * iSelectedElement,
    CATBaseUnknown ** oManipulatedElement) = 0;
};

CATDeclareHandler(CATISelectMoveSelector, CATBaseUnknown);

#endif
