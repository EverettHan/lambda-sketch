/**
 * @fullreview ERS 06:11:20 Editability : nouveaux services
*/

#ifndef CATExtIEditVeto_h
#define CATExtIEditVeto_h

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATAfrFoundation.h"
#include "CATIEditVeto.h"

class CATPathElement;


/**
  * Adapter for the CATIEditVeto interface .
  * <br>
  * The CATExtIEditVeto class provides the @href #CanEdit method that
  * tells whether the edition of the given path is allowed.
  * <br>
  * Implementing CATIEditVeto just consists in subclassing the 
  * CATExtIEditVeto class and simply override the @href #CanEdit method. Do not forget to implement the CATIEditVeto interface
  * using : CATImplementBOA(CATIEditVeto, CATExtIEditVeto).
  */
class ExportedByCATAfrFoundation CATExtIEditVeto : public CATIEditVeto
{
  
 CATDeclareClass;

public:
 
  
  /**
  * Constructs the class.
  */
  CATExtIEditVeto();
  virtual ~CATExtIEditVeto ();
  
  /**
    * Returns the authorization status to edit the object.
    * <br><b>Role:</b>
    * Called by the ui-activation manager, see @href CATIUIActivate,
    * when the user double-clics on the feature, or selects the
    * "Definition .." sub-item in the feature's contextual menu.
    * @param iPath
    *   A <tt>CATPathElement</tt> to the current feature object
    * @return
    *   The authorization status
    * <ul>
    * <li>TRUE if the edition is authorized. This is the default option if this method is not overloaded.</li>
    * <li>FALSE if the edition is not authorized. In this case the edition will not be done.</li>
    * </ul>
    */
  virtual CATBoolean CanEdit (CATPathElement * iPath);
};

#endif
