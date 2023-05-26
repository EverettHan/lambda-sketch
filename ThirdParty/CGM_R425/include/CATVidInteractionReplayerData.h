#ifndef CATVidInteractionReplayerData_H
#define CATVidInteractionReplayerData_H

#include <VisuDialog.h>
#include <CATSYPProperties.h>
#include <CATUnicodeString.h>

// friendship protection
#undef CATVidInteractionReplayer
#undef private

class CATVidInteractionReplayer;
class CATVidWidget;

/** @ingroup groupVidRecord
 * Interface of the protocol of interactions replaying for VID widgets.
 *
 * @par Replay protocol
 * The path of the interpreted widget stored in the record file
 * is interpreted to identify the widget in the session.<br/>
 * If this interpretation fails, the replay fails immediately.
 *
 * @par
 * The responsible widget is then called on @ref CATVidWidget#InteractionReplay
 * to replay the interaction it has taken the responsibility to record.
 * 
 * @par Replay delegation
 * During the record, a parent widget may have taken the responsibility
 * to record an interaction for one of its child. It may decide, during
 * the replay to delegate the replay of this interaction to its child.
 *
 * @par
 * To delegate the replay, the method @ref #DelegateReplayInteraction
 * after having built a new data object that can be understood by
 * the target object.
 *
 * @par
 * Note that to be target object should document the replay data it is
 * expecting to receive so that other object can delagate the replay.
 *
 * @par Replay errors handling
 * If an error is detected in the replay, the @ref CATVidWidget#InteractionReplay
 * function should call @ref #FatalReplayFailure method.
 *
 * @par Replay success
 * To signal the success of the replay of the interaction, the @ref
 * CATVidWidget#InteractionReplay should call @ref #ReplaySuccess
 * method.
 *
 * @par
 * If the function is not called then the a fatal replay failure will
 * occur.
 *
 * @par SendNotification
 * The replay of an interaction may trigger some @c
 * CATCommand::SendNotification.
 *
 * @par
 * Note that the first call to SendNotification in a callstack is
 * synchronous but all other subsequent enclosed calls are
 * asynchronous (delayed until all the commands have received the
 * previous SendNotification).
 *
 * @par
 * So the replay code for an interaction should ensure that if the
 * original (i.e. recorded) interaction was originally dispatched
 * using a @c SendNotification, it should also use a @c
 * SendNotification to simulated the replayed interaction. Note that
 * as of today, all mouse interactions are called in a @c
 * SendNotification by the @c CATManipulator; as a consequence the
 * replay of a mouse interaction must be done with a @c
 * SendNotification to ensure that other @c SendNotification that may
 * occur in the handlers of VID mouse events are asynchronous.
 *
 * @par
 * The @ref CATVidInteractionReplayer will ensure that the replay is
 * called ouside any @c SendNotification.
 */
class ExportedByVisuDialog CATVidInteractionReplayerData
{
  friend class CATVidInteractionReplayer;
private:
  /**
   * Create a new data.
   *
   * @note
   * This constructor is private since it is only meant
   * to be used by @ref CATVidInteractionReplayer.
   *
   * @param i_pNotification the notification instance owning this class.
   */
  CATVidInteractionReplayerData(CATVidInteractionReplayer *i_pReplayer);
  /**
   * <b>Non virtual</b> destructor.
   *
   * @note
   * The destructor is not virtual since this class should
   * not be specialized.
   *
   * @note
   * This constructor is private since it is only meant
   * to be used by @ref CATVidInteractionReplayer.
   */
  ~CATVidInteractionReplayerData();
public:
  /**
   * Get the type of the interaction that has been
   * recorded.
   *
   * @return the type of interaction.
   *
   * @see CATVidInteractionRecorderData#GetInteractionType
   */
  CATUnicodeString GetInteractionType();

  /**
   * Get the data that was stored by the responsible widget
   * during the record.
   *
   * @return the data.
   *
   * @see CATVidInteractionRecorderData#RecordInteraction
   */
  CATSYPProperties GetInteractionData();

  /**
   * Signals an error during the replay.
   *
   * @note
   * It may lead to an early exit of the process, but it is not
   * mandatory. For example when unit testing a component, this
   * function will not exit the test.
   *
   * @param i_error the error message.
   */
  void FatalReplayFailure(const CATUnicodeString &i_error);

  /**
   * Signals the success of the replay of the interaction.
   */
  void ReplaySuccess();

  /**
   * Delegate the replay to the @a i_pDelegatedWidget widget.
   * See class documentation for details about delegation.
   *
   * @param i_pDelegatedWidget the widget that receive the delegation.
   * Can't be @c NULL.
   *
   * @param i_delegatedWidgetData the interactions data that 
   * will be given to the @a i_pDelegatedWidget widget.
   */
  void DelegateReplayInteraction(CATVidWidget *i_pDelegatedWidget, 
                                 const CATSYPProperties &i_delegatedWidgetData);
private:
  /** Private copy constructor: this class is a reference-like class */
  CATVidInteractionReplayerData(const CATVidInteractionReplayerData&);
  /** Private assignement operator: this class is a reference-like class */
  CATVidInteractionReplayerData &operator=(const CATVidInteractionReplayerData&);
private:
  /** the replayer */
  CATVidInteractionReplayer *_pReplayer;
};

#endif // CATVidInteractionReplayerData_H
