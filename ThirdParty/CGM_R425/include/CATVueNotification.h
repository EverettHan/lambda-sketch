#ifndef _CATVueNotification
#define _CATVueNotification

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"
#include "CATNotification.h"
#include <string.h>

class CATPickPath;

/**
  *  Class to notify an event from the user interface.
  * <b>Role</b>: This notification is the base class for all notification
  * send by CATManipulator and its derived classes. They notify of the
  * different interactions from the user.
  */

class ExportedByCATVisFoundation CATVueNotification : public CATNotification
{
	CATDeclareClass;

  enum VueState { VueRefuse, VueAccept };

  public:
  /** 
    * Constructs a CATVueNotification notification.
    * @param iNotification 
    *   The device event notification.
    *   This notification contains the manipulation device 
    *   parameters like mouse position and move vector.
    */
    CATVueNotification(CATNotification *iNotification = NULL);

    virtual ~CATVueNotification();

    /** @nodoc */
    CATNotification *GetDataNotification() const;

    /** @nodoc */
    void SetDataNotification(CATNotification *);

    /**
      * Sets the CATPickPath returned by GetPickPath
      * to the CATPickPath corresponding to the first
      * element under thge mouse.
      */
    void InitElementList();

    /** 
     * Sets the CATPickPath returned by GetPickPath
     * to the  CATPickPath corresponding an
     * element deeper under the mouse.
     *
     * @return
     * Returns 1 when such a PickPath exists.
     * Returns 0 if tehere is no element deeper under the mouse.
     */
    int MoveToNextElement();

    /**
      * Retrieves the PickPath associated to the VueNotification.
      *
      * @return
      * The CATPickPath constructed during the user interaction
      */
    CATPickPath *GetPickPath();

    /** @nodoc */
    void Accept();

    /** @nodoc */
    void Refuse();

    /** @nodoc */
    CATVueNotification::VueState GetState() const;
    

 protected:
	/** @nodoc */
    CATNotification *_notification;
    /** @nodoc */
    CATVueNotification::VueState _vueState;

};

#endif
