// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATEAfrDnDExternalText.h
// Adapter for CATIAfrDnDExternalText interface
//
//===================================================================
//
// Usage notes of interface:
//   Interface to enable Drag&Drop from outside of V5 to V5, for example from a web browser.
//   The dragged content is a text containing a string like this: "serviceId":"XXX"
//   XXX will be taken a the base for a late type name: XXX_AfrDnDExternalText
//   
// Usage notes of adapter:
//   Use CATImplementBOA to implement the interface
//   You may use a data extension to implement the interface if you want to store the dragged text.
// 
//===================================================================
#ifndef CATEAfrDnDExternalText_H
#define CATEAfrDnDExternalText_H

#include "CATAfrFoundation.h"
#include "CATIAfrDnDExternalText.h"
#include "CATBoolean.h"
#include "CATPathElement.h"

class CATUnicodeString;
//------------------------------------------------------------------

class ExportedByCATAfrFoundation CATEAfrDnDExternalText: public CATIAfrDnDExternalText
{
  public:

    CATEAfrDnDExternalText();
    virtual ~CATEAfrDnDExternalText();

    /**
    * A text is being dragged over the application.
    * Please return S_OK to accept the drag or anything else to refuse the drag; the cursor will change depending on this.
    * virtual and should be overloaded.
    */
    virtual HRESULT  ExternalTextDraggedOver(const CATUnicodeString & iDraggedText);

    /**
    * A text was dropped.
    * The return code will be ignored in this version.
    * virtual and should be overloaded.
   */
    virtual HRESULT  ExternalTextDropped(const CATUnicodeString & iDroppedText);

    /**
    * Set key modifiers position.
    * Inform the interface implementer of the state of SHIFT, CTRL and ALT keys before calling ExternalTextDraggedOver or ExternalTextDropped.
    * Works only on Windows OS.
    * Not virtual, this adapter is the right implementation :) The right information is always stored in _SHIFT, _CTRL and _ALT protected data members.
    */
    HRESULT  SetModifiers(const CATBoolean & iShift, const CATBoolean & iCtrl, const CATBoolean & iAlt);

    /**
    * Set hover element.
    * Inform the interface implementer of the selectable element currently preselected before calling ExternalTextDraggedOver or ExternalTextDropped.
    * The hovered object has to be "selectable", i.e. the current command is waiting for a selection of this type of object.
    * Not virtual, this adapter is the right implementation :) The right CATPathElement is always  _PathElt, if not empty.
   */
    HRESULT  SetPathElement(const CATPathElement & iPathElt);


  protected:

    CATBoolean _SHIFT, _CTRL, _ALT;
    CATPathElement _PathElt;
};

//------------------------------------------------------------------

#endif
