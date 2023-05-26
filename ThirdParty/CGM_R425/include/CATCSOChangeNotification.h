#ifndef CATCSOChangeNotification_H_
#define CATCSOChangeNotification_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"
#include "CATNotification.h"
#include "CATLISTP_CATBaseUnknown.h"

/**
 * Class representing a notification whose instance is sent when
 * the selection is changed.
 * <b>Role</b>: An instance of this class is sent by the @href CATCSO
 * class after the selection is changed. It contains two lists : a 
 * list of elements that were removed from the selection and a list
 * of elements that were added to the selection.
 */
class ExportedByCATAfrFoundation CATCSOChangeNotification : public CATNotification
{
  CATDeclareClass;

  public:

  /** @nodoc */
  CATCSOChangeNotification ();
  virtual ~CATCSOChangeNotification();

  /**
   * List of elements added to the selection.
   * <br><b>Legal values</b>: Each element of the list is a @href CATPathElement instance.
   */
   CATLISTP(CATBaseUnknown) Add;

  /**
   * List of elements removed from the selection.
   * <br><b>Legal values</b>: Each element of the list is a @href CATPathElement instance.
   */
   CATLISTP(CATBaseUnknown) Remove;
};

#endif
