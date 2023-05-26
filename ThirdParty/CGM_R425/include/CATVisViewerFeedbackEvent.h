#ifndef CATVisViewerFeedbackEvent_H
#define CATVisViewerFeedbackEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisController.h"
#include "CATTimeStampedEvent.h"

class CATViewer;
class CATManipulatorUpdate;
class CATGraphicElementIntersection;
class CATSO;

/**
 * Class notification for CATViewer interactions.
 * <b>Role</b>: A such notification is sent when an interaction occurs in a 
 * @href CATViewer which has the feedback mode active. The @href CATViewer#GetFeedbackMode method
 * enables you to set the feedback mode, and the 
 * @href CATViewer#SetFeedbackMode method enables you to unset it.
 * <br>This class notification offers methods to access information concerning the 
 * interaction, be it a mouse motion or a button action.
 * <br>To receive such notifications, you should set a callback on a
 * <tt>CATViewer::VIEWER_FEEDBACK_UPDATE</tt> class event. 
 * @see CATViewer
 */
class ExportedByCATVisController CATVisViewerFeedbackEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :
  
    /** 
     * Defines the notification creation context.
     * @param Preactivate
     *  There are two cases to consider:
     *   <ul>
     *    <li>The mouse pointer, coming from the background, enters on a graphic representation. 
     *        Two notifications with the following context are sent in this order:</li>
     *     <ol>
     *      <li>A <tt>EndPreactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is null </li>
     *      <li>A <tt>Preactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is not null </li>
     *     </ol>
     *    <li>The mouse pointer leaves a graphic representation to the background. 
     *    Two notifications with the following context are sent in this order:</li>
     *     <ol>
     *      <li>A <tt>EndPreactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is not null </li>
     *      <li>A <tt>Preactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is null </li>
     *     </ol>
     *   </ul>
     * @param MoveOver
     *  The mouse pointer leaves a graphic representation to enter on a new one.
     *  The pointer returned by @href #GetElementsUnder is not null.
     * @param Move
     *  The mouse pointer moves on a graphic representation or the background. In the first case,
     * the pointer returned by @href #GetElementsUnder is not null, otherwise the pointer is nul.
     * @param EndPreactivate
     *  There are two cases to consider:
     *   <ul>
     *    <li>The mouse pointer, coming from the background, enters on a graphic representation. 
     *        Two notifications with the following context are sent in this order:</li>
     *     <ol>
     *      <li>A <tt>EndPreactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is null </li>
     *      <li>A <tt>Preactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is not null </li>
     *     </ol>
     *    <li>The mouse pointer leaves a graphic representation to the background. 
     *    Two notifications with the following context are sent in this order:</li>
     *     <ol>
     *      <li>A <tt>EndPreactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is not null </li>
     *      <li>A <tt>Preactivate</tt> context: 
     *          The pointer returned by @href #GetElementsUnder is null </li>
     *     </ol>
     *   </ul>
     * @param BeginManipulate
     *   If a graphic representation is taken for manipulation, the pointer returned 
     *   by @href #GetElementsUnder is not null, otherwise if the background is taken 
     *   for manipulation, the pointer is null. 
     *
     * @param Activate
     *  If a graphic representation is selected, the pointer returned by 
     *  @href #GetElementsUnder is not null, otherwise if the background is selected, 
     *  the pointer is null.
     * @param Context
     *  Contextual action is asked. If a graphic representation is selected, the pointer returned by 
     *  @href #GetElementsUnder is not null, otherwise if the background is selected, 
     *  the pointer is null.
     *
     * @param EndManipulate
     *  When a manipulation is ended, the manipulated object is released, the pointer returned by 
     *  @href #GetElementsUnder is not null, otherwise if the background is selected, 
     *  the pointer is null.
     */
    enum EventContext
    {
      Preactivate,
      MoveOver,
      Move,
      EndPreactivate,
      BeginManipulate,
      Activate,
      Context,
     // Manipulate,
      EndManipulate
    };

    /** @nodoc */
    CATVisViewerFeedbackEvent(CATViewer* iViewer, 
                              CATManipulatorUpdate* iManipulatorUpdate, 
                              EventContext iContext);
    virtual ~CATVisViewerFeedbackEvent();

    /** 
     * Retrieves the context that gave birth to the event.
     * @return 
     *   The event context.
     */
    CATVisViewerFeedbackEvent::EventContext GetContext();

    /** 
     * Retrieves the viewer that triggered the event.
     * @return 
     *   The viewer.
     */
    CATViewer* GetViewer();   

    /** 
     * Retrieves the mouse pointer position in screen coordinates.
     * @param oXPixel
     *   The X position. The range of the value is between <tt>0</tt> and
     *  the width (-1) of the support (@href CATSupport#GetWidthAndHeight ). 
     *  <br><tt>oXPixel</tt> increases from left to right. 
     * @param oYPixel
     *   The Y position. The range of the value is between <tt>0</tt> and
     *  the height (-1) of the support (@href CATSupport#GetWidthAndHeight ). 
     *  <br> <tt>oYPixel</tt> increases from top to bottom. 
     */
    void GetMousePosition(int* oXPixel, int* oYPixel);

    /** 
     * Retrieves the intersection point between the mouse pointer and the underlying geometry.
     * @return 
     *  The intersection point.
     */
    CATGraphicElementIntersection* GetIntersection();

    /** 
     * Retrieves elements under the mouse.
     * <br><b>Role</b>This methods enables you to know all the elements 
     *  (until the geometry level) under the mouse. The elements in the @href CATSO
     * are sorted: the first (0 index) is the nearest, and the last (n-1 index) is
     * the further.
     * @return 
     *  The set of element under the mouse.
     */
    CATSO* GetElementsUnder();

  protected :

    CATNotification*  GetNotification();

    CATManipulatorUpdate* _ManipulatorUpdate;
    CATViewer*            _Viewer;

    EventContext _Context;

    int _IsAnIndicator;
};

#endif
