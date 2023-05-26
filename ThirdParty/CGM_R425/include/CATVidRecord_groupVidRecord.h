/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group that aggregates functions used by the VID
 * record.
 */

#error this file must never be included; doxygen file only.


/**
 * @defgroup groupVidRecord VID Record
 *
 * The <b>VID Record</b> modules groups the classes used in the
 * implementation of the recording for interactive tests of VID.
 *
 * This documentation explains how all the involved classes works
 * together.<br/>
 * There are also sub-groups that group and document specific topics:
 *  - @ref groupVidRecordPath "Paths" for the paths used in record.
 *  - @ref groupVidRecordRecorder "Record Recorder" for the internal 
 *    classes of the @ref CATVidRecorder.
 *
 * A more user-oriented documentation is available on the 
 * <a href="http://codewiki/codewiki/index.php/VID_:_Interaction_Recording">VID : Interaction Recording</a>
 * and 
 * <a href="http://codewiki/codewiki/index.php/VID_:_Implementing_Interaction_Recording">VID : Implementing Interaction Recording</a>
 * wiki pages.
 *
 * @section groupVidRecord_secOverview Overview
 * VID objects, as implied by their name (the I stands for Immersive),
 * are displayed in a CATViewer. As a consequence, they benefit from
 * the implementation of the recording of mouse events by the
 * CATViewer. The problem is that this recording does not take into
 * accout widgets positions; it records mouse events with coordinates
 * that are relative to the top left hand corner of the window. That
 * means that any change in the layout of VID widgets may break the
 * test.
 *
 * To overcome this issue an implementation of recording has been made
 * in VID. It has been called "interaction recording".
 *
 * An other tentative implementation has been made in the past. It has
 * been canceled but the code is still there. In this document we will
 * refer to it as the "ctl recording" (you can go to @ref
 * groupVidRecord_secCtlRec to have details about the deprecated
 * functions used for this recording).
 *
 * @section groupVidRecord_secChoice Recording Implementation Choice
 * The choice of the recording implementation is depends for a widget
 * from the returned value of in @ref CATVidWidget#GetVidRecordLevel.
 *
 * This function can return one of the following values defined in
 * @ref CATVidEnum.h:
 *  - @ref VID_RECORD_LEVEL_MANIP : an implementation that never existed
 *  - @ref VID_RECORD_LEVEL_VISU : the recording of the CATViewer
 *  - @ref VID_RECORD_LEVEL_INTERACTION : the "interaction recording"
 *
 * By default the function returns, during capture, @ref
 * VID_RECORD_LEVEL_VISU. This can be changed by setting the
 * environment variable @c "VID_RECORD_MODE" with one of the following
 * value:
 *  - @c "interaction" : set the @ref VID_RECORD_LEVEL_INTERACTION mode
 *  - @c "visu" : set the @ref VID_RECORD_LEVEL_VISU mode
 *
 * Note that even though the @c "VID_RECORD_MODE" is only needed
 * during the capture it may still be a good idea to set it in the
 * shell of the ODT. This way it won't be forgotten if someone records
 * the test again later.
 *
 * The value returned during the replay by @ref
 * CATVidWidget#GetVidRecordLevel is the same as the one that has been
 * returned during the capture. We don't take into account any
 * variable but only the content of <tt>capture.ver</tt> file.
 *
 * @section groupVidRecord_secInteraction Interaction Recording
 * @subsection groupVidRecord_secInteractionOverview Overview
 * The protocol of the "interaction recording" is describied in the
 * documentation of the class @ref CATVidInteractionRecorderData.
 *
 * The implementation of this protocol is based on the abstract class
 * @ref CATVidInteractionRecorder. Each time an interaction occurs an
 * instance of a specialization of this class is created and called to
 * run the protocol. For example with mouse events a @ref
 * CATVidManipulatorInteractionRecorder is built.
 *
 * The @ref CATVidInteractionRecorder will run the record protocol and
 * then:
 *  - generate the path of the responsible widget using a 
 *    @ref CATVidLockablePathGenerator
 *  - store the interaction data and path in a @ref CATVidRecordingTarget
 *
 * @subsection groupVidRecord_secInteractionPath Responsible Widget Path
 * To identify the responsible widget during the replay we use a
 * string that contains the path of the widget in the widget tree.
 *
 * The record is based on the @ref CATVidLockablePathGenerator that
 * embeds a @ref CATVidPathGenerator. Please consult the documentation
 * of these classes for details.
 *
 * The default generator to use in widget is returned by @ref
 * CATVidLockablePathGenerator#GetDefaultGenerator.
 *
 * The current generator is @ref CATVidPathGeneratorV2.
 *
 * @subsection groupVidRecord_secInteractionTarget Interaction Storage
 * The @ref CATVidInteractionRecorder stores the interactions
 * (i.e. the path of the widget, the type of interaction and the
 * interaction data) in a @ref CATVidRecordingTarget.
 *
 * There is a default target that stores informations in the
 * capture.rec file. An overriding target can be provided to support
 * batch testing of record.
 *
 * The default target is a @ref CATVidRecorderRecordingTarget. This
 * target stores the interactions in the capture.rec file. It stores
 * them using @ref CATRecord#SaveState as notifications on the @ref
 * CATVidRecorder object.
 *
 * The default target is obtained with @ref
 * CATVidRecordingTarget#GetRecordingTarget that returns @c !=NULL
 * only when either the target has been overridden (by a test) or
 * when:
 *  - @ref CATVidWidget#GetVidRecordLevel returns @ref VID_RECORD_LEVEL_INTERACTION
 *  - and we are in a capture of an interactive test
 * As a consequence there is no need for widget code to test anything
 * else than the fact that the target is not @c NULL to know if
 * "interaction recording" should be used.
 *
 * @subsection groupVidRecord_secInteractionReplay Interaction Replay
 * The replay protocol of "interaction recording" is describied in the
 * documentation of class @ref CATVidInteractionReplayerData.
 *
 * The implementation of this protocol is made by @ref
 * CATVidInteractionReplayer class. For each interaction stored
 * during the capture an instance of @ref CATVidInteractionReplayer
 * class is created. It is used to replay the interaction. It will:
 *   - decode the path of the responsible widget using a 
 *     @ref CATVidLockablePathInterpreter
 *   - run the replay protocol on the responsible widget
 *
 * The @ref CATVidRecorder object is called by recording
 * infrastructure to replay the stored notifications. It is this
 * component that instantiate the @ref CATVidInteractionReplayer class
 * for each interaction in a replay (a unit test that test
 * record/replay may instantiate @ref CATVidInteractionReplayer
 * itself).
 *
 * @subsection groupVidRecord_secInteractionPathInt Responsible Widget Path Interpretation
 * The path of the responsible widget is interpreted using a @ref
 * CATVidLockablePathInterpreter. It should embed a @ref
 * CATVidPathInterpreterVAll so that it can interpret any version of
 * paths (for older records).
 *
 * @subsection groupVidRecord_secInteractionMouse Mouse Interaction Recorder
 * The recorder used for mouse interactions is @ref
 * CATVidManipulatorInteractionRecorder. Please read its documentation
 * for details about provided data.
 *
 * By default, if no parent component implements recording, then the
 * @ref CATVidGP#PreInteractionRecord function of the GP that is the
 * leaf of the interaction will simply add the @c "CATVidGP:version"=1
 * to the data of the recorder and store that. As a consequence,
 * without any specific code, the relative mouse position is stored
 * for each mouse interaction. The responsible widget being the GP
 * itself (that must have a valid path). For example the @ref
 * CATVidCtlButton have absolutely no recording code since this
 * default behavior is good enough.
 *
 * The problem is when the relative position is not enough to have a
 * "stable" replay. For exemple for a @ref CATVidCtlAbstractSlider the
 * click in the background of the slider is interpreted by comparing
 * the mouse position to the position of the sliding button. Without
 * any specific code that would means that a resize of the slider may
 * change the behavior of the slider at replay. To solve this issue
 * and keeping this simple a hinting of the mouse position has been
 * introduced for this component.
 *
 * A hinting means that a parent component of the leaf GP becomes the
 * responsible widget and stores informations (hints) that it can use
 * at replay to recreate a mouse position that will ensures that the
 * same thing happen during the replay even if the size of the
 * component (or any other property) has changed. After having
 * computed the new mouse position using its hints it can simply
 * delegate the replay of the event to the @ref CATVidGP using @ref
 * CATVidInteractionReplayerData#DelegateReplayInteraction.
 *
 * To ease the implementation of hinting the class @ref
 * CATVidInteractionRecPtHinter should be used during capture. Please
 * read class documentation for details. During the replay the class
 * @ref CATVidInteractionHintedPtReplayer should be used.
 *
 * @subsection groupVidRecord_secInteractionNTM Notifier Transaction Mode
 * The @ref CATVidNotifierTransactionModeRecorder widget is used with
 * mouse event to ensure @ref CATNotifierTransactionMode is correctly
 * restored at replay.
 *
 * @subsection groupVidRecord_secInteractionEvts Interaction Events
 * Some events are dispatched during replay of interactions:
 *  - @ref CATVidPathV1Events#ElementNotFound : it can be used to 
 *    recreate widgets that existed at capture but not during the
 *    replay.
 *  - @ref CATVidGP#VisibilityAtReplay : dispatched when a GP
 *    visibility during the replay does not match the visiblity
 *    during the capture. It can be used to force the visiblity of
 *    a widget during the replay (for example the optional scrollbars
 *    of a scrollable).
 */

