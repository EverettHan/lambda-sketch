#ifndef CATVidDnD_H
#define CATVidDnD_H

#include "VisuDialog.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_WR.h"
#include "CATVidMouseEventArgs.h"
#include "CATSYPEnumBitField.h"
#include "CATSYPDeclareEnumFactory.h"
#include "CATDlgUtility.h"
#include "CATVidData.h"
#include "CATEventSubscriber.h"

class CATVidDnDData;
class CATVidDnDSourceFactory;
class CATVidCtl;
class CATVidGP;


/**
 * @defgroup groupVidDnD VID drag-and-drop infrastructure
 */

/**
 * @ingroup groupVidDnD
 *
 * Class for all drag & drop services. 
 */
class ExportedByVisuDialog CATVidDnD : public CATBaseUnknown
{

//---------------------------------------------------------------------------//
//                             Class properties
//---------------------------------------------------------------------------//

public:
  /** 
   * A bitfield representing the drag-and-drop effects.
   *
   * @par
   * Its value must be an or-combination of masks @ref #Copy,
   * @ref #Move and @ref #Link.
   *
   * @par
   * When a drag-and-drop is performed from a drag source, several effects can
   * happen on drop: 
   * @li @c Move (shift key pressed): the source data is moved at the drop 
   * position (the object from which the data has been exported is destroyed).
   * @li @c Copy (control key pressed): the source data is duplicated at the 
   * drop position.  
   * @li @c Link (control+shift keys pressed): the source data is refered to
   * at the drop position.
   * @li @c Default (no key pressed): a defaut effect is chosen among those
   * available on source (see @ref #ComputeAppliedEffect for internal
   * drags).
   *
   * @par
   * If the requested effect on release of the mouse is not compatible with
   * available effects of the drag source, the drop is not successful.
   * 
   * @par 
   * Else, the precise effect that a successful drop will have on the drag 
   * source (resp. on the drop target) is defined by handling 
   * @ref CATVidCtl#Dropped (resp. @ref CATVidCtl#ImportData) differently 
   * depending on the requested effect on drop.
   */
  enum Effect
  { 
    /**
     * Choose a drop effect among available effects on the source of the drag,
     * with the following priority order: @c Move, @c Copy or @c Link.
     */
    DnDNone = 0,
    /** 
     * Copy the drag source data holder into drop target. 
     */
    DnDCopy = 1<<0,
    /** 
     * Copy the drag source data to drop target and delete original drag 
     * source data holder. 
     */
    DnDMove = 1<<1, 
    /** 
     * Create a link between the drag source data holder and the drop target.
     * The nature of the link is user-defined.
     */
    DnDLink = 1<<2
  };
  CATSYP_DECLARE_ENUM_BIT_FIELD(Effects, Effect);

  /**
   * Drag mode or drop mode.
   */
  enum Mode {
    /**
     * @li Drag: no drag allowed.
     * @li Drop: no drop received.
     */
    Inactive=0,
    /** 
     * NOT ACTIVE. FOR FUTURE DEVELOPMENTS.
     *
     * @li Drag: Do not launch OS DnD. Data is stored in @ref CATVidDnD.
     * @li Drop: Receive drops of data stored in @ref CATVidDnD if the
     * OS DnD has not been launched (for example, CID @ref Clipboard drags).
     */
    Clipboard,
    /**
     * @li Drag: Launches OS DnD. Data is stored in @ref CATVidDnD.
     * @li Drop: Control only accept drops from itself. Use for controls
     * composed of smaller components, for example model/view controls.
     */
    Itself,
    /** 
     * @li Drag: Launches OS DnD. Data is stored in @ref CATVidDnD.
     * @li Drop: Receive drops of data stored in @ref CATVidDnD if the
     * OS DnD has been launched (for example, CID @ref Internal drags).
     */
    Internal,
    /** 
     * @li Drag: Launches OS DnD and allow OS data export. 
     * @li Drop: Receive all drops, provided that the OS DnD has been launched.
     */
    External };

  /**
   * Specifies where a drop can happen in a components.
   */
  enum DropLocation
  {
    /**
     * Drop is not possible anywhere.
     */
    NoDropLocation = 0,
    /**
     * Dragged item can be dropped on other items.
     */
    DropOn = 1<<0,
    /**
     * Dragged item can be dropped before other items. 
     */
    DropBefore = 1<<1,
    /**
     * Dragged item can be dropped after other items. 
     */
    DropAfter = 1<<2,
    /**
     * Dragged items can be dropped on the viewport. On that case, their drop
     * position is determined by the default drop position of the model.
     */
    DropViewport = 1<<3
  };
  CATSYP_DECLARE_ENUM_BIT_FIELD(DropLocations, DropLocation);

public:
  /** @return the singleton CID DnD instance. */
  static CATVidDnD * GetInstance();
  /** 
   * @param i_dropEffect a DROPEFFECTs bit field 
   *
   * @return the equivalent CID drag-and-drop effects bit field
   *
   * @see CATDlgUtility
   */
  static Effects DropEffectsToDnDEffects(unsigned int i_dropEffect);
  /** 
   * @param i_dropEffect a DROPEFFECT 
   *
   * @return the equivalent CID drag-and-drop effect enum
   *
   * @see CATDlgUtility
   */
  static Effect DropEffectToDnDEffect(DROPEFFECT i_dropEffect);
  /**
   * @param i_effect a CID drag-and-drop effects bit field
   *
   * @return the equivalent DROPEFFECTs bit field 
   *
   * @see CATDlgUtility
   */
  static unsigned int DnDEffectsToDropEffects(Effects i_effect);
  /**
   * @param i_effect a drag-and-drop effect
   *
   * @return the corresponding DROPEFFECT: @c DROPEFFECT_NONE, 
   * @c DROPEFFECT_COPY, @c DROPEFFECT_MOVE or @c DROPEFFECT_LINK
   *
   * @see CATDlgUtility
   */
  static DROPEFFECT DnDEffectToDropEffect(CATVidDnD::Effect i_effect);
  /**
   * @param i_keyModif a dialog keyboard modifier: 
   * <tt>0, MK_CTRL, MK_SHIFT|MK_CTRL</tt>
   *
   * @return the corresponding drag-and-drop effect (resp. move, copy, link)
   *
   * @see CATVidDnD#Effect
   */
  static Effect KeyboardModifiersToDnDEffect(unsigned int i_keyModif);
  /**
   * @param i_keyModif a CID keyboard modifier: 
   * <tt>0, CTRL_MASK, SHIFT_MASK|CTRL_MASK</tt>
   *
   * @return the corresponding drag-and-drop effect (resp. move, copy, link)
   *
   * @see CATVidDnD#Effect
   */
  static Effect ModifiersToDnDEffect(CATVidMouseEventArgs::Modifiers i_keyModif);
  /**
   * @param i_effect a drag-and-drop effect.
   *
   * @return a string representation of the drag-and-drop effect.
   */
  static CATUnicodeString DnDEffectToString(CATVidDnD::Effect i_effect);
  /**
   * @param i_effects a drag-and-drop effects bitfield.
   *
   * @return a string representation of the bitfield.
   */
  static CATUnicodeString DnDEffectsToString(CATVidDnD::Effects i_effects);
  /**
   * @param i_effect a drag-and-drop effect.
   *
   * @return a string representation of the drag-and-drop effect.
   */
  static CATUnicodeString DropEffectToString(DROPEFFECT i_effect);
  /**
   * @param i_effects a drag-and-drop effects bitfield.
   *
   * @return a string representation of the bitfield.
   */
  static CATUnicodeString DropEffectsToString(unsigned int i_effects);
  /**
   * @param i_location a drop location.
   *
   * @return a string representation of the drop location.
   */
  static CATUnicodeString DropLocationToString(CATVidDnD::DropLocation i_location);
  /**
   * @param i_locations a drag-and-drop locations bitfield.
   *
   * @return a string representation of the bitfield.
   */
  static CATUnicodeString DropLocationsToString(CATVidDnD::DropLocations i_locations);
  /**
   * The effect applied on drop depends on which effects are allowed by the 
   * drag source (@ref CATVidCtl#GetPossibleDnDEffects) and which effect is 
   * requested by the current key modifiers state 
   * (@ref CATVidMouseEventArgs#GetModifiers). If no modifiers are active, 
   * one effect is chosen among all available effects of the drag source, with
   * the following priority order: @c Move, @c Copy or @c Link.
   *
   * @param i_sourceEffects available effects on the source of drag-and-drop.
   * @param i_requestedEffect effect corresponding to current key modifiers.
   */
  static Effect ComputeAppliedEffect(CATVidDnD::Effects i_sourceEffects, CATVidDnD::Effect i_requestedEffect);

private:
  /** 
   * The singleton CID DnD clipboard instance. When the drag comes from a CID
   * control, the exported data will be accessible from the clipboard until
   * @ref CATVidCtl#Dropped is emitted by said control. 
   */
  static CATVidDnD * _pInstance;

//---------------------------------------------------------------------------//
//                          Instance properties 
//---------------------------------------------------------------------------//

public:
  /**
   * @return after drag from anywhere and until drop is done : the source data 
   * exported for drag-and-drop (internal drag only). Pointer is @c AddRefed:
   * it must be @c Released.
   */
  static CATVidData * RetrieveSourceData();
  /**
   * @return after drag from anywhere and until drop is done : the source data 
   * exported for drag-and-drop (internal drag only). Pointer is @c AddRefed:
   * it must be @c Released.
   */
  static CATVidDnDData * RetrieveInternalSourceData();
  /** 
   * @return @c TRUE if the data currently being dragged has been exported
   * from a CID control, @c FALSE else.
   */
  static CATBoolean IsDragInternal();

protected:
  /** Destructor. */
  virtual ~CATVidDnD();
  /**
   * @param i_pData the data currenlty being dragged
   *
   * @see #GetSourceData
   */
  void SetSourceData(CATVidDnDData * i_pData);
  /**
   * @return the drag-and-drop effect applied at the time of the drop.
   */
  Effect GetEffectOnDrop() const;
  /**
   * @param i_effect the drag-and-drop effect applied at the time of the drop.
   */
  void SetEffectOnDrop(Effect i_effect);

private:
  /** Constructor. */
  CATVidDnD();
  /** Copy constructor. */
  CATVidDnD(const CATVidDnD &i_original);
  /** Equal operator. */
  CATVidDnD& operator=(const CATVidDnD& i_original);
  /**
   * @return after a drag from CID and until drop is done : the source data 
   * exported for drag-and-drop. @c NULL else. Pointer has not been 
   * @c AddRefed.
   */
  CATVidDnDData * GetSourceData() const;
  /**
   * Sets the current DnD source.
   */
  void SetCurrentDnDSource(CATVidDnDSourceFactory* i_pDnDFactory);
  /**
   * @return the current DnD source.
   */
  CATVidDnDSourceFactory* GetCurrentDnDSource()const;
  /**
  * Called when the  @c l_CATInteractiveApplication emits a
  * @c CATDlgEndDropNotification. Redirects to @ref CATVidDnDSourceFactory#OnEndDrop.
  */
  void OnEndDropCB(CATCallbackEvent i_evt, void * i_pSender, CATNotification * i_pNotif, CATSubscriberData i_data, CATCallback i_cb);
  /**
  * Called when the  @c l_CATInteractiveApplication emits a
  * @c CATDlgCancelDragNotification. Redirects to @ref CATVidDnDSourceFactory#OnCancelDrag.
  */
  void OnCancelDragCB(CATCallbackEvent i_evt, void * i_pSender, CATNotification * i_pNotif, CATSubscriberData i_data, CATCallback i_cb);

private:
  /* @see #GetDnDSource */
  CATBaseUnknown_WR _wrDnDSource;
  /* @see #GetSourceData */
  CATBaseUnknown_WR _wrSourceData;
  /** @see #GetEffectOnDrop */
  Effect _effectOnDrop;
  CATCallback    _cancelDragCB;
  CATCallback    _endDropCB;

friend class CATVidDnDTargetFactory;
friend class CATVidDnDSourceFactory;
friend class CATVidMdlDnDSourceFactory;
friend class CATVidTstDnDBasicListPossibleDropEffects;
friend class CATVidDnDTarget;
friend class CATVidTstDnDSourcePossibleDropEffects;
friend class CATVidTstDnDTargetDrop;
friend class CATVidTstDnDTargetNoDrop;
friend class CATVidTstDnDTargetEndPreDrop;
friend class CATVidSessionCleaner;

};
//-----------------------------------------------------------------------------

CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidDnD__Mode);

//-----------------------------------------------------------------------------
#endif
