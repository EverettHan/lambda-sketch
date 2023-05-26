
#ifndef CATITextOverlayViewModel3_H
#define CATITextOverlayViewModel3_H

#include "CATAfrItf.h"
#include <CATITextOverlayViewModel.h>
#include <CATBaseUnknown.h>
#include <CATString.h>

// COPYRIGHT Dassault Systemes 2007

class CATString;
class CATPathElement;
// TPC Version class CATTextOverlayViewItem;

extern ExportedByCATAfrItf IID IID_CATITextOverlayViewModel3;
//------------------------------------------------------------------
// TPC Version class ExportedByCATAfrItf CATITextOverlayViewModel3: public CATBaseUnknown
class ExportedByCATAfrItf CATITextOverlayViewModel3: public CATITextOverlayViewModel
{
  CATDeclareInterface;

  public:

    /**
     * Gets command status.
     *   @param ispNode
     *     Object
     *   @param iPropertyID
     *     Attribute identficator
     */
    virtual int GetCommand( CATBaseUnknown_var ispNode,
                            const CATString &iPropertyID ) = 0;

    /**
     * Launch command.
     *   @param ispItem
     *     Object
     *   @param iPropertyID
     *     Attribute identificator
     *   @param iPath
     *     CATPathElement
     *   @param ilx
     *     position of the new text
     *   @param ily
     *     position of the new text
     */
    virtual HRESULT LaunchCommand( CATBaseUnknown_var ispItem,
                                   const CATString& iPropertyID,
                                   const CATPathElement& iPath, const float ilx, const float ily ) = 0;
};
CATDeclareHandler( CATITextOverlayViewModel3, CATITextOverlayViewModel );

#endif
