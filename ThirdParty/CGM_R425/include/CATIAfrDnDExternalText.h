// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATIAfrDnDExternalText.h
// Define the CATIAfrDnDExternalText interface
//
//===================================================================
//
// Usage notes:
//   Interface to enable Drag&Drop from outside of V5 to V5, for example from a web browser.
//   The dragged content is a text containing a string like this: "serviceId":"XXX"
//   XXX will be taken a the base for a late type name: XXX_AfrDnDExternalText
//   
//   Your implementation will be taken into account only if deriving from adapter CATEAfrDnDExternalText.
//
//===================================================================
#ifndef CATIAfrDnDExternalText_H
#define CATIAfrDnDExternalText_H

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIAfrDnDExternalText;
#else
extern "C" const IID IID_CATIAfrDnDExternalText ;
#endif

class CATUnicodeString;
class CATPathElement;
//------------------------------------------------------------------

class ExportedByCATAfrFoundation CATIAfrDnDExternalText: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * A text is being dragged over the application.
    * Please return S_OK to accept the drag or anything else to refuse the drag; the cursor will change depending on this.
    */
    virtual HRESULT  ExternalTextDraggedOver(const CATUnicodeString & iDraggedText) = 0;

    /**
    * A text was dropped.
    * The return code will be ignored in this version.
    */
    virtual HRESULT  ExternalTextDropped(const CATUnicodeString & iDroppedText) = 0;

    /**
    * Set key modifiers position.
    * Inform the interface implementer of the state of SHIFT, CTRL and ALT keys before calling ExternalTextDraggedOver or ExternalTextDropped.
    * Works only on Windows OS.
    */
    virtual HRESULT  SetModifiers(const CATBoolean & iShift, const CATBoolean & iCtrl, const CATBoolean & iAlt) = 0;

    /**
    * Set hover element.
    * Inform the interface implementer of the selectable element currently preselected before calling ExternalTextDraggedOver or ExternalTextDropped.
    * The hovered object has to be "selectable", i.e. the current command is waiting for a selection of this type of object.
    */
    virtual HRESULT  SetPathElement(const CATPathElement & iPathElt) = 0;


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
