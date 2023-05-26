#ifndef CATModelNotification_h
#define CATModelNotification_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisItf.h"
#include "CATNotification.h"

/**
 * Class representing basic visualization events.
 * 
 * <b>Role</b>: Providing a visualization event basic class aimed at defining model events. Whenever objects' change happens, 
 * objects send a specialized visualization event to warn the "<tt>Visualization world</tt>". 
 * That means the way provided in CATIAV5 to update the graphical representations of one object is to send
 * a visualization event, which is defined by this class.
 * <p>
 * That 's the reason why when one object's color is changed or when its shape is modified , it sends a visu event.
 *  Refer to the @href CATIModelEvents interface to have details about the management of the visualization events 
 * and their mechanism.
 * <p>
 * Examples of visualization  events are @href CATModelEntityNotification, @href CATCreate, @href CATModify.
 * 
 *
 * @see CATNotification
 */

class ExportedByCATVisItf CATModelNotification : public CATNotification
{
  /** @nodoc */
  CATDeclareClass;

  public:
  
    /**
       * Default Constructor.
       */
    CATModelNotification();

    virtual ~CATModelNotification();

   /** 
      * Returns a pointer to a new CATModelNotification event which is the clone of the current one.
      */
    virtual CATModelNotification* Clone ();
  
  /**
     * Returns its identifier.
     */
    int GetId() const;


  private:

    /**
       * Identifier .
       */
    int _id;

    /** @nodoc .
       * static value dedicated to generate unique notification's identifier when one creates a new notification.
       */
    static int _classId;
};

#endif
