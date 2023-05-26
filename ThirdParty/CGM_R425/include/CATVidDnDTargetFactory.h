#ifndef CATVidDnDTargetFactory_H
#define CATVidDnDTargetFactory_H

#include "VisuDialog.h"
#include "CATVidDnDBaseFactory.h"
class CATVidDnDTarget;
class CATVidDnDEventArgs;
class CATVidMouseEventArgs;

/** @ingroup groupVidDnD
 * This factory is created for each control to which an active drop mode is 
 * given (@ref CATVidCtl#SetDropMode). Said control becomes a drop target and
 * owns the factory.
 *
 * Factory associated to a drop target. Builds a @ref CATVidDnDTarget when
 * the mouse pointer enters the drop target and releases it when the mouse
 * pointer leaves the control or on release.
 *
 * @see CATVidCtl#SetDnDMode
 * @see CATVidDnDTarget
 */
class ExportedByVisuDialog CATVidDnDTargetFactory: public CATVidDnDBaseFactory
{
  CATDeclareClass;

public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the drop target that this factory is associated to. A weak 
   * reference is kept on the input pointer.
   *
   * @see CATVidCtl#SetDropMode
   */
  CATVidDnDTargetFactory(CATVidCtl * i_pOwner);

protected:
  /** Destructor. */
  virtual ~CATVidDnDTargetFactory();
  /** @return a new source data. */
  virtual CATVidDnDTarget * CreateTarget();
  /**
   * @return the helper created for the drop target (owner control) during 
   * drag-and-drop, @c NULL else.
   */
  CATVidDnDTarget * GetTarget() const;

private:
  CATBoolean IsTargetLocked() const;
  /**
   * Called during drag-and-drop when the mouse pointer enters a GP in the 
   * owner drop target (@ref #GetOwner). Builds a @ref CATVidDnDTarget.
   * 
   * @param i_pSender the GP entered
   * @param i_pArgs arguments of the event
   *
   * @see CATVidGP#BeginPreDrop
   */
  void OnBeginPreDrop(CATBaseUnknown * i_pSender, CATVidDnDEventArgs * i_pArgs);
  /**
   * Called during drag-and-drop when the mouse pointer leaves a GP in the 
   * owner drop target (@ref #GetOwner). Releases the @ref CATVidDnDTarget.
   * 
   * @param i_pSender the GP left by the mouse
   * @param i_pArgs arguments of the event
   *
   * @see CATVidGP#EndPreDrop
   */
  void OnEndPreDrop(CATBaseUnknown * i_pSender, CATVidDnDEventArgs * i_pArgs);
  /**
   * Called during drag-and-drop when the mouse pointer moves over a GP in the 
   * owner drop target (@ref #GetOwner). 
   * 
   * @param i_pSender the GP on which the drop happened
   * @param i_pArgs arguments of the event
   *
   * @see CATVidGP#Drop
   */
  void OnDrop(CATBaseUnknown * i_pSender, CATVidDnDEventArgs * i_pArgs);
  /**
   * Called when the mouse pointer is released over a GP of the owner drop 
   * target (@ref #GetOwner). If the drag-and-drop was launched, it is called
   * juste after @ref CATVidGP#Drop.
   * 
   * @param i_pSender said GP
   * @param i_pArgs arguments of the event
   *
   * @see CATVidGP#Release
   */
  void OnRelease(CATBaseUnknown * i_pSender, CATVidMouseEventArgs * i_pArgs);

private:
  /** @see #GetTarget */
  CATVidDnDTarget * _pTarget;
};

//-----------------------------------------------------------------------------

#endif
