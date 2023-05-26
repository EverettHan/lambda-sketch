#ifndef CATModifyRemoveRep_h
#define CATModifyRemoveRep_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATModify.h"

/**
 * Event that removes a rep from a bag without destroying it.
 */


class ExportedByCATVisItf CATModifyRemoveRep : public CATModify
{
  /** @nodoc */
  CATDeclareClass;

  public:

  /**
   * Constructs the class from a given set of graphical attributes to apply onto a given object and for a specific 
   * interface of graphical properties.
   *
   * @param iObject
   * the object whose graphical representation should not hold in representation of @href iObjectToRemove.
   * @param iObjectToRemove
   * the object whose representation you want to remove from the bag of the iso
   * but without destroying it.
   *
   */
    CATModifyRemoveRep(CATBaseUnknown *iObject, CATBaseUnknown *iObjectToRemove);
  
    virtual ~CATModifyRemoveRep();


   /**
    * Returns a pointer to the object which graphical representation should be removed.
    */
	CATBaseUnknown * GetDataToRemove();

	/** 
     * Returns a pointer to a new CATModify event which is the clone of the current one.
     */
    virtual CATModelNotification* Clone ();


  private :
	  CATBaseUnknown * _pObjectToRemove;

 
};

#endif
