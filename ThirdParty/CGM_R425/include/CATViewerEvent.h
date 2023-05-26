#ifndef CATVizViewerEvent_H
#define CATVizViewerEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"

class CATVizViewer;
class CATPickPath;
class CATDevice;
class CATDeviceEvent;
class CATViewer;
class VisTouchGesture;

/**
* Event notifying of something happening to the viewer.
*
* <b>Role</b>: Notify of anything happening to the viewer. it
* also contains additionnale information about what was
* under the mouse when it happened.
* These notifications are kept inside more precise events that are
* generated from them like manipulation notifications.
*/

class ExportedByCATVisFoundation CATViewerEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public:
    /** nodoc */
    CATViewerEvent(CATDeviceEvent *e = NULL, CATPickPath *p = NULL);
    virtual ~CATViewerEvent();
    /** @nodoc */
    CATViewerEvent & operator = (const CATViewerEvent &brother);

    /** Moves the referenced object to the first object under the mouse. */
    void InitPickPathList();
    /** Moves teh referenced object to the next object under the mouse. */
    int MoveToNextPickPath();

    /** @nodoc */
    void SetPickPath(CATPickPath *) ;
    /** @nodoc */
    void SetPickPathUnder(CATPickPath *) ;
    /** Retrieves the referenced object under the mouse.
    *   The object is given using a CATPickPath
    **/
    CATPickPath *GetPickPath() const;
    /** Retrieves the referenced object under the mouse.
    *   The object is given using a CATPickPath
    *   This method regenerates the referenced object to take
    *   into account any change in the model that may have occured
    *   from the time the event was sent.
    **/
    CATPickPath *GetPickPathUnder() const;
    /** @nodoc*/
    CATDeviceEvent *GetDeviceEvent() const;
    /** @nodoc */
    void SetDevice ( CATDevice *device );
    /** @nodoc */
    void SetDeviceEvent ( CATDeviceEvent *deviceEvent );

    /** @nodoc */
    void SetViewer ( CATViewer *iViewer );
    /** @nodoc */
    CATViewer *GetViewer (void);
    
    /** @nodoc */
    void SetVizViewer ( CATVizViewer *iViewer );
    /** @nodoc */
    CATVizViewer *GetVizViewer (void);

    /** Viewer in which the event occured. */ 
    CATViewer *Viewer;
    
    /** @nodoc */   
    CATVizViewer *VizViewer;
    
    /** @nodoc */
    int IsTouchViewerEvent();

    /** @nodoc */
    const VisTouchGesture* GetTouchGesture() const;


  protected :

    
    //  the pickpath associated to the last manipulator choosen
    //  -------------------------------------------------------

  /** @nodoc */
    CATPickPath *_pickPath;

    //  the pickpath associated to the current object detected
    //  ------------------------------------------------------

  /** @nodoc */
    CATPickPath *_pickPathUnder;
    
    //  device information
    //  ------------------

  /** @nodoc */
    CATDevice *_device;
  /** @nodoc */
    CATDeviceEvent *_deviceEvent;
  /** @nodoc */
  VisTouchGesture* _pTouchGesture;
};

#endif
