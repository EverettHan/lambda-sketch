// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATIUIActiveControler.h
// Define the CATIUIActiveControler interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Mar 2002  Creation: Code generated by the CAA wizard  CLE
//===================================================================
#ifndef CATIUIActiveControler_H
#define CATIUIActiveControler_H

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrSelection IID IID_CATIUIActiveControler ;

//------------------------------------------------------------------
class ExportedByCATAfrSelection CATIUIActiveControler: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /** @nodoc */
    virtual CATBaseUnknown * Get3DControler() = 0;
    /** @nodoc */
    virtual CATBaseUnknown * Get2DControler() = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(CATIUIActiveControler, CATInterfaceObject);

//------------------------------------------------------------------

#endif