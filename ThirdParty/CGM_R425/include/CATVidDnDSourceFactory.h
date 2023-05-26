#ifndef CATVidDnDSourceFactory_H
#define CATVidDnDSourceFactory_H

#include "VisuDialog.h"
#include "CATVidDnDBaseFactory.h"
#include "CATMathPoint2Df.h"
#include "CATEventSubscriber.h"
#include "CATBaseUnknown_WR.h"
#include "CATVidDnDTarget.h"
class CATVidCtl;
class CATVidDnDEventArgs;
class CATVidMouseEventArgs;
class CATVidDnDData;
class CATVidDnDSource;
class CATNotification;
class CATVidGP;

/** @ingroup groupVidDnD
 *
 * This factory is created for each control to which an active drag mode is 
 * given (@ref CATVidCtl#SetDragMode).
 *
 * It listens to @c CATVidGP#Press() and @c CATVidGP#Drag() events on the drag 
 * source and creates a @c CATVidDnDSource to initiate drag-and-drop when a 
 * drag go past the @c DragThreshold.
 *
 * @see CATVidCtl
 * @see CATVidDnDSource
 */
class ExportedByVisuDialog CATVidDnDSourceFactory: public CATVidDnDBaseFactory
{
  CATDeclareClass;

public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the drag source that this factory is associated to.
   *
   * @see CATVidCtl#SetDragMode
   */
  CATVidDnDSourceFactory(CATVidCtl * i_pOwner);
  /**
   * @return the Manhattan distance over which the user needs to drag before
   * Drag&Drop is initiated. Default value is <tt>10</tt>.
   */
  float GetDragThreshold() const;
  /**
   * @param i_dragThreshold threshold before initializing Drag&Drop, in 
   * Manhattan distance.
   *
   * @see #GetDragThreshold
   */
  void SetDragThreshold(float i_dragThreshold);

  /**
   * @return the position of the last press in the viewer.
   */
  const CATMathPoint2Df& GetPressPos() const;

protected:
  /** Destructor. */
  virtual ~CATVidDnDSourceFactory();
  /**
   * Creates a new drag source.
   *
   * @param i_pSourceData helper class associated to the source. Cannot be
   * @c NULL.
   */
  virtual CATVidDnDSource * CreateSource(CATVidDnDData * i_pSourceData);
  /**
   * @return the helper created for the drag source (owner control) during 
   * drag-and-drop, @c NULL else.
   */
  CATVidDnDSource * GetSource() const;
  /**
   * Calls @ref #EndDnD(TRUE).
   *
   * @see #EndDnD
   */
  void OnEndDrop();
  /**
   * Calls @ref #EndDnD(FALSE).
   *
   * @see #EndDnD
   */
  void OnCancelDrag();
  /**
   * Called each time a GP of the owner drag source is pressed. Saves the mouse
   * position and the new "last GP pressed".
   *  
   * @param i_pSender the GP pressed.
   * @param i_pArgs event arguments.
   */
  virtual void OnPress(CATBaseUnknown * i_pSender, CATVidMouseEventArgs * i_pArgs);
  /**
   * Called each time a GP of the owner drag source is dragged. Launches
   * drag-and-drop in case the position of the last press is distant enough
   * from the current position of the mouse pointer.
   *  
   * @param i_pSender the GP pressed.
   * @param i_pArgs event arguments.
   */
  virtual void OnDrag(CATBaseUnknown * i_pSender, CATVidMouseEventArgs * i_pArgs);
   /**
   * Called each time a GP of the owner drag source is in long hold. Saves the mouse
   * position and the new "last GP pressed". In touch, only launch the drag and drop after a long hold
   *  
   * @param i_pSender the GP pressed.
   * @param i_pArgs event arguments.
   */
  virtual void OnLongHold(CATBaseUnknown * i_pSender, CATVidMouseEventArgs * i_pArgs);

  /**
  * @return the last GP pressed inside the drag source.
  */
  CATVidGP * GetPressGP() const;

  /**
  * @Set the press GP.
  */
	void SetPressOrDragGP(CATBaseUnknown * i_PressOrDragGPBU);

  /**
  * @Set the press GP.
  */
	void SetPressOrDragGPPosition(CATMathPoint2Df i_position);

  /**
  * @Set the drag source.
  */
	void SetDragSource(CATVidDnDSource * i_pSource);

private:
  /**
   * To be called once after the application leaves the drag-and-drop loop.
   * Dispatches the @ref CATVidCtl#Dropped event on the source control. 
   * Releases the current @ref CATVidDnDSource.
   *
   * @param i_success the success of the drop: @c TRUE if the drop succeeeded,
   * @c FALSE if the drag has been canceled.
   */
  void EndDnD(const CATBoolean & i_success);

private:
  void BeginDnDTransaction();
  void StopDnDTransaction();
private:
  /** @see #GetDragThreshold */
  float _dragThreshold;
  /** @see #GetSource */
  CATVidDnDSource * _pSource;
	  /** @see #GetPressPos */
  CATMathPoint2Df _pressPos;
  /** @see #GetPressGP */
  CATBaseUnknown_WR _wrPressGP;
  
  int _listeningFlag;

friend class CATVidDnDTarget;
friend class CATVidDnD;
friend class CATVidDnDTstSourceVidTstDnDSourceFactory;


};

//-----------------------------------------------------------------------------

#endif
