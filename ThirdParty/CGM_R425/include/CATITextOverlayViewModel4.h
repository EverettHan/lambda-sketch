
#ifndef CATITextOverlayViewModel4_H
#define CATITextOverlayViewModel4_H

#include "CATAfrItf.h"
#include <CATITextOverlayViewModel.h>
#include <CATBaseUnknown.h>
#include <CATString.h>

// COPYRIGHT Dassault Systemes 2007

class CATPathElement;
class CATString;
// TPC Version class CATTextOverlayViewItem;

extern ExportedByCATAfrItf IID IID_CATITextOverlayViewModel4;
//------------------------------------------------------------------
// TPC Version class ExportedByCATAfrItf CATITextOverlayViewModel4: public CATBaseUnknown
class ExportedByCATAfrItf CATITextOverlayViewModel4: public CATITextOverlayViewModel
{
  CATDeclareInterface;

  public:

    /**
     * Gets command status.
     *   @param ispNode
     *     Object
     *   @param iPropertyID
     *     Attribute identficator
     *   @param iHyperLink
     *     Hyperlink text
     */
    virtual int GetCommand( CATBaseUnknown_var ispNode,
                            const CATString &iPropertyID,
                            CATUnicodeString &oHyperLink ) = 0;

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
     *   @param iHyperLink
     *     Hyperlink text
     */
    virtual HRESULT LaunchCommand( CATBaseUnknown_var ispItem,
                                   const CATString& iPropertyID,
                                   const CATPathElement& iPath, const float ilx, const float ily,
                                   const CATUnicodeString &iHyperLink ) = 0;
};
CATDeclareHandler( CATITextOverlayViewModel4, CATITextOverlayViewModel );

#endif
