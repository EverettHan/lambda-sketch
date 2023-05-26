//===================================================================
// COPYRIGHT Dassault Systemes 2015-01-21
//===================================================================
// CATDE2BaseElement.cpp
// Header definition of class CATDE2BaseElement
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015-01-21 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATDE2BaseElement_H
#define CATDE2BaseElement_H

#include "CATDialogEngine.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------

class ExportedByCATDialogEngine CATDE2BaseElement: public CATBaseUnknown
{
  public:

    // Standard constructors and destructors
    // -------------------------------------
    /**
    *Base element for all DE� tag (CAN BE USED DIRECTLY IN A DE� FILE)
    */
    CATDE2BaseElement ();
    virtual ~CATDE2BaseElement ();

    // Introspection getters and setters
    // -------------------------------------
    /**Id of the DE� element.
    *iId the DE� element Id
    */
    virtual void              SetId(const CATUnicodeString iId);
    virtual CATUnicodeString  GetId()const;

    virtual CATUnicodeString ToString();
  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATDE2BaseElement (CATDE2BaseElement &);
    CATDE2BaseElement& operator=(CATDE2BaseElement&);
    
    CATUnicodeString _Id;
};

//-----------------------------------------------------------------------

#endif
