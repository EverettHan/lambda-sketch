#ifndef CATDelete_h
#define CATDelete_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATModelEntityNotification.h"


/**
 * Class representing a visualization event dedicated to delete any graphical representations of one object.
 * <b>Role</b>: providing a visualization event which holds all the information required to destroy all the graphical
 * representations of one object within any opened documents where it is visualized.
 * To achieve this goal, one has only to send a @href CATDelete event.
 * Refer to the @href CATIModelEvents
 * interface to have details about the visualization events management and their mechanism.
 * 
 *
 * @see CATModelEntityNotification
 */
class ExportedByCATVisItf CATDelete : public CATModelEntityNotification
{
  CATDeclareClass;

  public:

    /** @nodoc */
    CATDelete(void *iModelId);

   /** 
     * Constructs the Class.
     * @param iObject
     *    a pointer to the object one wants to delete its graphical representations.
     */
    CATDelete(CATBaseUnknown *iObject);

    virtual ~CATDelete();

  /** 
     * Returns a pointer to a new CATDelete event which is the clone of the current one.
     */
  virtual CATModelNotification* Clone ();

};

#endif
