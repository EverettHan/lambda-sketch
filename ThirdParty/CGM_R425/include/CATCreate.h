#ifndef CATCreate_h
#define CATCreate_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATModelEntityNotification.h"

class CATBaseUnknown;

/**
 * Class representing a visualization event requesting the visualization of one object which is not visualized yet within 
 * existing trees of graphical representations. 
 * <b>Role</b>: providing a visualization event which holds all the information required to visualize a new object
 * as child of another object within any opened documents where it is not already visualized.
 * <p>
 * The idea is that one is working with one or several documents 
 * having their own visualization, and one wants to add a new object as child of another object, which is already
 * visualized in one or several documents. To achieve this goal, one has only to send a @href CATCreate event
 * enclosing the new object one wants to visualize along with the object's parent. Refer to the @href CATIModelEvents
 * interface to have details about the management of the visualization events and their mechanism.
 * 
 *
 * @see CATModelEntityNotification
 */
class ExportedByCATVisItf CATCreate : public CATModelEntityNotification
{
  CATDeclareClass;

   /** @nodoc */
  enum  CATVisCreationMode  {CATVisDefaultMode, CATVisBackgroundMode};

  public:
   /** 
     * Constructs the Class.
     * @param iObject
     *    a pointer to the object one wants to visualize.
     * @param iParent
     *    a pointer to the object's parent.
     */
    CATCreate(CATBaseUnknown *iObject, CATBaseUnknown *iParent, CATVisCreationMode iCreationMode = CATVisDefaultMode);

    /** @nodoc */
    CATCreate(void *iModelId, void *iParentModelId,  CATVisCreationMode iCreationMode = CATVisDefaultMode);

    virtual ~CATCreate();
    
    /**
      * Returns a pointer to the parent.
      */
    CATBaseUnknown * GetFather() const;

    /** @nodoc */
    void * GetFatherModelId() const;

    /** 
      * Returns a pointer to a new CATCreate event which is the clone of the current one.
      */
    virtual CATModelNotification* Clone ();

    /**
     * The creation mode of the current notif.
     */
     CATVisCreationMode _CreationMode;

  protected:
    /**
      * Pointer to the object's parent.
      */
    CATBaseUnknown *_father;
};

#endif
