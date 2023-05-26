#ifndef CATIProfile_h
#define CATIProfile_h

// COPYRIGHT DASSAULT SYSTEMES 2012

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>

class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIProfile;
#else
extern "C" const IID IID_CATIProfile;
#endif


/**
  * Interface implemented by a late type base on name retrieved 
  * by CATPAfrIProfile node in profile declarative file. Late type
  * is UP_Name where name is the attribut define in the declarative file.
  * <b>Role:</b> This interface allows to execute applicative code 
  * when a profile is applied to the session
  * <br>
  * <b>Important notice</b>: Using the @href CATExtIProfile as a base class
  * when implementing <tt>CATIProfile</tt> is mandatory. 
  * <p><b>BOA information</b>: this interface must be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the CAA Encyclopedia home page. 
  * Click Middleware at the bottom left, then click the Object Modeler tab page.
  * Several articles deal with the BOA.</p>
  */
class ExportedByCATAfrItf CATIProfile : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  /**
    */
  virtual HRESULT SetAtt () = 0;
};

#endif
