#ifndef CATRepShortHelp_H 
#define CATRepShortHelp_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// Abstract: 
//
//------------------------------------------------------------------------------
// Usage:    
//
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
// Main methods:    
//
//           Preactivate()
//           ShowShortHelp()
//           HideShortHelp()
//       
//------------------------------------------------------------------------------
// Events:    
//           SHORTHELP_PREACTIVATED
//------------------------------------------------------------------------------
//       
#include "CATVisController.h"
#include "CATCommand.h"
#include "CATUnicodeString.h"

class CATViewer;
class CATNotification;
class CATRepBalloon;

/**
 * Class to add a short message to the representation.
 * <b>Role</b>: This message is usually used to give a short help 
 * about the representation.
 * When a representation is preactivated (see also @href CATPreactivate )
 * CATRepShortHelp will send a SHORTHELP_PREACTIVATED event and 
 * the callback method will be activated.
 * In this callback method an application can display
 * a text within a balloon using @href #ShowShortHelp method.
 */

class ExportedByCATVisController CATRepShortHelp: public CATCommand
{
  CATDeclareClass;

  //-----------------------------------------------------------------------------
  public:

    // Event Define
    // ------------
    /** @nodoc */
    CATDeclareCBEvent (SHORTHELP_PREACTIVATED);

    // Constructor / Destructor
    // ------------------------
    /**
     * Constructs a CATRepShortHelp instance.
     * A default instance of the CATRepShortHelp can be obtained 
     * from CATViewer::SetShortHelpState method.
     */
    CATRepShortHelp();
    virtual ~CATRepShortHelp();

    /** @nodoc */
    void SetState(unsigned long state);

    /** @nodoc */
    void  Preactivate(CATViewer * viewer, CATNotification * notif);
  
    /**
     * Shows a short help text.
     * @param iText 
     *   The text to display in a balloon under the mouse cursor.
     */
    void  ShowShortHelp(CATUnicodeString iText);
  
    /**
     * Delete the short help text.
     */
    void  HideShortHelp();

  private:

    CATRepBalloon* _balloon;
    unsigned long _state;
}; 
#endif
