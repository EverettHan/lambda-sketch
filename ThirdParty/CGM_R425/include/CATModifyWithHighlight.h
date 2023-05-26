#ifndef CATModifyWithHighlight_h
#define CATModifyWithHighlight_h

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATModify.h"

 /**
  * Modification of an object with the possibility to check the highlight of the object.
  * 
  * <br><b>Do not use this class</b>
  * <br><br>
  * <b>Role</b>: 
  * 
  * <br>Refer to the @href CATIModelEvents interface to have details about the management 
  * of the visualization events and their mechanism.
  *
  * @see CATIVisu, CATExtIVisu
  */
class ExportedByCATVisItf CATModifyWithHighlight : public CATModify
{
  /** @nodoc */
  CATDeclareClass;

  public:

  /**
   * Constructs the class from a given set of graphical attributes to apply onto a given object and for a specific 
   * interface of graphical properties.
   *
   * @param iObject
   * the object you want to modify.
   *
   * @param iSearchInHighlight
   *  1 : if you want the highlight of your object to be checked during its modification
   *
   */
    CATModifyWithHighlight(CATBaseUnknown *iObject, 
                            int iSearchInHighlight =1 );
  
    virtual ~CATModifyWithHighlight();
    
  
  /**
   * Returns a pointer to a new  CATModifyWithHighlight event which is the clone of the current one.
   */
  virtual CATModelNotification* Clone ();

  int IsToBeSearchedInXSO () const;

  protected :

     int        _iSearchInHighlight;

 
};

#endif
