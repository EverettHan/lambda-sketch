#ifndef CATVidInteractionHintedPtReplayer_H
#define CATVidInteractionHintedPtReplayer_H

#include <VisuDialog.h>

class CATVidInteractionReplayerData;
class CATVidWidget;
class CATMathPoint2Df;
class CATUnicodeString;

/** @ingroup groupVidRecord
 * Replayer of interactions hinted using @ref CATVidInteractionRecPtHinter.
 *
 * This class is meant to be instantiated on stack.
 *
 * @par Usage
 * Instantiate this class on stack in your override of @ref
 * CATVidWidget#InteractionReplay in all cases. Then use @ref
 * #IsHintedInteraction to test if interaction data comes from a @ref
 * CATVidInteractionRecPtHinter.
 *
 * @par
 * If this is the case, look for your own hinting data to compute a
 * mouse position and finally call @ref #ReplayInteraction to complete
 * the replay.
 *
 * @par Sample
 * We continue the sample found in the @ref
 * CATVidInteractionRecPtHinter documentation:
 * @code
 * void MyWidget::InteractionReplay(CATVidInteractionReplayerData &i_replayer)
 * {
 *   CATVidInteractionHintedPtReplayer hintReplayer("MyWidget", i_replayer);
 * 
 *   if (hintReplayer.IsHintedInteraction()) {
 *     CATSYPProperties interactionData = i_replayer.GetInteractionData();
 *     // get the version number
 *     int version = -1;
 *     CHECK_TRUE_RET(SUCCEEDED(CATBoxingOfint::Unbox(interactionData.GetProperty("MyWidget:version"), 
 *                                                    version)));
 * 
 *     CHECK_TRUE_RET(version == 1);
 * 
 *     // unstream the offsets
 *     int offsetAlongDir = 0;
 *     int offsetNormalDir = 0;
 *     CHECK_TRUE_RET(SUCCEEDED(CATBoxingOfint::Unbox(interactionData.GetProperty("MyWidget:offsetAlongDir"),
 *                                                    offsetAlongDir)));
 *     CHECK_TRUE_RET(SUCCEEDED(CATBoxingOfint::Unbox(interactionData.GetProperty("MyWidget:offsetNormalDir"),
 *                                                    offsetNormalDir)));
 * 
 *     // find the target GP named "Background" under this widget
 *     CATVidWidget *pTargetWidget = CAT_DYNAMIC_CAST(CATVidWidget, __MustRetrieveSypNamedObject(this, "Background"));
 *
 *     // compute the new point 
 *     const CATMathPoint2Df pt = ...;
 * 
 *     // replay the hinted event
 *     hintReplayer.ReplayInteraction(pTargetWidget, this, pt);
 *
 *     return;
 *   }
 * 
 *   // by default, since no one called return, the replay has not
 *   // been handled. We call the parent class implementation to ensure
 *   // that its own replaying may be used
 *   return CATVidWidget::InteractionReplay(i_replayer);
 * }
 * @endcode
 *
 * @see CATVidInteractionRecPtHinter
 */
class ExportedByVisuDialog CATVidInteractionHintedPtReplayer
{
public:
  /**
   * Initialize this object with replaying data.
   *
   * This constructor is meant to be used in the implementation of
   * @ref CATVidWidget#InteractionReplay.
   *
   * Use @ref #IsHintedInteraction to know if the interaction has been
   * hinted for @a i_hinterClass.
   *
   * @param i_hinterClass the name of the class that is using hinting.
   *
   * @param i_replayer the replaying data. Note that a reference to
   * this data is kept by this class. As a consequence this object
   * must be destroyed before exiting from the scope of @ref
   * CATVidWidget#InteractionReplay.
   */
  CATVidInteractionHintedPtReplayer(const CATUnicodeString &i_hinterClass, 
                                    CATVidInteractionReplayerData &i_replayer);

  /** Destroy this class */
  virtual ~CATVidInteractionHintedPtReplayer();

  /**
   * Check if the interaction data corresponds to an hinted
   * interaction.
   *
   * The check is made by reading the version of the @c
   * "CATVidInteractionRecPtHinter" namespace and that the @c
   * "CATVidInteractionRecPtHinter:hinterClass" property value is the
   * @c i_hinterClass of this replayer.
   *
   * @return @c !=0 if the interaction has been hinted using @ref
   * CATVidInteractionRecPtHinter.
   */
  int IsHintedInteraction();

  /**
   * Replay the interaction.
   *
   * This function will:
   *   - setup the position expected by the leaf for the replay using
   *     @a i_pointerPosition value
   *   - delegate the replay to the leaf
   *
   * This function must only be used if @ref IsHintedInteraction
   * returns @c !=0.
   *
   * @param i_pLeafWidget the leaf widget to use for the replay. It
   * should be the same widget (semantically) than the one that was
   * the leaf during the record for which the recording has been
   * hinted.
   *
   * @param i_pPosWidget the widget used for coordinates bases of @a
   * i_pointerPosition. Can be @c NULL if @a i_pointerPosition is
   * relative to the viewer of @a i_pLeafWidget.
   *
   * @param i_pointerPosition the restored pointer position, relative
   * to @a i_pPosWidget.
   */
  void ReplayInteraction(CATVidWidget *i_pLeafWidget, 
                         CATVidWidget *i_pPosWidget, const CATMathPoint2Df &i_pointerPosition);
private:
  CATVidInteractionHintedPtReplayer(const CATVidInteractionHintedPtReplayer &);
  CATVidInteractionHintedPtReplayer &operator=(const CATVidInteractionHintedPtReplayer &);

private:
  /** the replayer */
  CATVidInteractionReplayerData &_replayer;

  /** @c !=0 if the namespace @c "CATVidInteractionRecPtHinter" has
   *  been found int the replaying data */
  int _hinted;
};

#endif // CATVidInteractionHintedPtReplayer_H
