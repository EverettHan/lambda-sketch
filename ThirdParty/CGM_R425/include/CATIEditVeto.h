#ifndef CATIEditVeto_h
#define CATIEditVeto_h

// COPYRIGHT DASSAULT SYSTEMES 2006

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>

class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIEditVeto;
#else
extern "C" const IID IID_CATIEditVeto;
#endif


/**
  * Interface implemented by CATIA objects to control their edition.
  * <b>Role:</b> The CanEdit method of this interface controls whether the edition
  * is allowed or not. See @href CATIEdit for a description of the edition mechanism.
  * <br>
  * <b>Important notice</b>: Using the @href CATExtIEditVeto as a base class
  * when implementing <tt>CATIEditVeto</tt> is mandatory. 
  * <p><b>BOA information</b>: this interface can be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the CAA Encyclopedia home page. 
  * Click Middleware at the bottom left, then click the Object Modeler tab page.
  * Several articles deal with the BOA.</p>
  */
class ExportedByCATAfrItf CATIEditVeto : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
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
  virtual CATBoolean CanEdit (CATPathElement * iPath) = 0;
};

#endif
