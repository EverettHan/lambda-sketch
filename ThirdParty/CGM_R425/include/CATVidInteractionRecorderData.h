#ifndef CATVidInteractionRecorderData_H
#define CATVidInteractionRecorderData_H

#include <VisuDialog.h>
#include <CATUnicodeString.h>
#include <CATSYPProperties.h>

// friendship protection
#undef CATVidInteractionRecorder
#undef private

class CATVidInteractionRecorder;
class CATVidWidget;

/** @ingroup groupVidRecord
 * Interface of the protocol of interactions recording for VID widgets.
 *
 * @par Interactions
 * As of today, interactions are mouse and keyboard inputs.
 *
 * @par Recording protocol
 * Before the the interaction is handled, the widget that
 * will be responsible of the recording is identified.<br/>
 * This widget can then decide to either:
 *   - record directly the interaction.
 *   - or delay the recording of the interaction and be called back after
 *     the interaction has been handled.
 * 
 * @par
 * After the interaction has been handled, the widget responsible of the
 * recording (identified in the previous step) is called if this widget 
 * has decided to delay the recording.<br/>
 * If this widget has already recorded the interaction (during first step)
 * then nothing will be done.
 *
 * @par Responsible widget identification
 * In VID, interaction notifications are always recieved by a @ref CATVidWidget.<br/>
 * The identification of the widget responsible of the recording is made by
 * iterating through the path of widget build using @ref CATVidWidget#GetRecordingFather.<br/>
 * The iteration starts from the root to the leaf (the leaf is the widget that
 * received the interaction notification). The widgets are successively called
 * in @ref CATVidWidget#PreInteractionRecord. The first one that calls either
 * @ref CATVidInteractionRecorderData#RecordInteraction or
 * @ref CATVidInteractionRecorderData#DelayRecordInteraction will be identified
 * as the component responsible of the recording of the interaction and the
 * iteration will end.
 * 
 * @see CATVidInteractionRecorder
 */
class ExportedByVisuDialog CATVidInteractionRecorderData
{
  friend class CATVidInteractionRecorder;
private:
  /**
   * Create a new data.
   * @note
   * This constructor is private since it is only meant to be
   * used by @ref CATVidInteractionRecorder.
   * @param i_pRecorder the recorder instance owning this class.
   */
  CATVidInteractionRecorderData(const CATUnicodeString &i_interactionType, CATVidInteractionRecorder *i_pRecorder);
  /** 
   * <b>Non virtual</b> destructor.
   * @note
   * The destructor is not virtual since this class should
   * not be specialized.
   * @note
   * This destructor is private since it is only meant to be
   * used by @href CATVidInteractionRecorder.
   */
  ~CATVidInteractionRecorderData();
public:
  /**
   * Get the type of the interaction that must be
   * recorded.
   * @return the type of interaction.<br/>
   * As of today it can be @c "MouseInteraction" or @c "KeyboardInteraction".<br/>
   */
  CATUnicodeString GetInteractionType();
  /**
   * Get the data of the interaction.
   * @param i_version the version of the data that is supported by
   * the caller code. Note that this version depends of the type
   * of interaction returned by @ref #GetInteractionType.<br/>
   * If an invalid version number is given, @ref FAILURE will
   * be called and an empty dictionary will be returned.
   * @return the data corresponding to @a i_version; an empty
   * dictionary in case of invalid input.
   */
  CATSYPProperties GetInteractionData(int i_version);
  /**
   * Get the leaf widget.
   *
   * The leaf is the widget that received the notification
   * of the interaction.
   *
   * The leaf widget can be used for example to:
   *   - interpret the data returned by @ref GetInteractionData. For
   *     example, for a mouse event, the mouse coordinates are relative
   *     to the leaf widget.
   *   - identify which sub-widget of an aggregating widget is the
   *     source of the interaction notification.
   * 
   * @return a pointer of the leaf widget. Can't be @c NULL.<br/>
   * Note that @ref CATBaseUnknown#AddRef has not been called on
   * the returned pointer so the caller must not release it.
   */
  CATVidWidget *GetInteractionLeaf();
  /**
   * Record the interaction.
   *
   * @par Behavior in @c PreInteractionRecord
   * The widget that calls this function when called in 
   * @ref CATVidWidget#PreInteractionRecord will be identified as
   * the component reponsible of the recording of the interaction
   * and will immediately record the interaction (i.e. the function
   * @ref CATVidWidget#PostInteractionRecord will not be called).
   *
   * @par Behavior in @c PostInteractionRecord
   * The widget that called @ref #DelayRecordInteraction when called
   * in @ref CATVidWidget#PreInteractionRecord will have to call this 
   * function when called in @ref CATVidWidget#PostInteractionRecord
   * to record the interaction.<br/>
   * Note that in that case, calling this function is mandatory.
   * 
   * @par Data Values
   * The data given as argument @a i_data will be stored in the
   * record file and read at replay.<br/>
   * As a consequence the values of each property of must be a @ref
   * CATISYPValues that can be streamed (for example a @ref
   * CATSYPProperties can be boxed and its boxing does implement
   * CATISYPValues but this boxing can only be streamed if the
   * properties of the dico can also be streamed)
   *
   * @par
   * Note that, as of today, to ease the writting of tools not written
   * in C++ that can handle record files, a restriction has been added
   * on the @ref CATISYPValues that can be used. Only the boxing of the
   * following types can be used in the data:
   *   - @c int
   *   - @c CATLONG64
   *   - @c float
   *   - @c double
   *   - @ref CATUnicodeString
   *   - @ref CATString
   *   - @ref CATMathPointf
   *   - @ref CATMathPoint2Df
   *   - @ref CATMathVector2Df
   *   - @ref CAT4x4Matrix
   *   - @ref CATSYPProperties
   *
   * @par
   * Note also that containers types (such as @ref CATSYPProperties) 
   * can only contain some @ref CATISYPValues in the above list (the 
   * restriction is recursive).
   * 
   * @par Data Names
   * The names in the property dico @a i_data must respect the following
   * rules.
   * @verbatim
     propertyName: namespace ':' name;
     
     namespace: ID;

     name: ID;

     ID: ('A'..'Z' | 'a'..'z' | '_') ('A'..'Z' | 'a'..'z' | '_' | '0'..'9')*@endverbatim
   *
   * @par
   * Each property must be in a namespace.<br/>
   * The caller of @c RecordInteraction should use the name of its
   * class as the namespace for the values that it has added.
   *
   * @par
   * Each namespace must contain a property which name is 
   * @c "version".<br/>
   * The associated value must be a boxing of an @c int and must
   * represent a version of the recording code that has created
   * this namespace.<br/>
   * This ensures that the recording of any component can be versioned.
   * The record will fail if a namespace does not contain a version.
   *
   * @note
   * This function must only be called when a widget is called either
   * in @ref CATVidWidget#PreInteractionRecord or in 
   * @ref CATVidWidget#PostInteractionRecord.
   *
   * @param i_data the data that will be saved in the record. Note that
   * there should be at least one property (if only one property is
   * provided, it will be the "version" property).
   */
  int RecordInteraction(const CATSYPProperties &i_data);
  /**
   * Delay the recording of the interaction until interaction
   * has been handled.
   *
   * @par Behavior in @c PreInteractionRecord
   * The widget that calls this function when called in 
   * @ref CATVidWidget#PreInteractionRecord will be identified as
   * the component reponsible of the recording of the interaction
   * but the actual recording will be delayed until the interaction
   * has been handled. Then the function @ref CATVidWidget#PostInteractionRecord
   * will be called.
   *
   * @par Behavior in @c PostInteractionRecord
   * This function will fail (make the recording fail) and call 
   * @ref FAILURE if it is called from @ref CATVidWidget#PostInteractionRecord.<br/>
   * 
   * @param i_data the data that will be given back to the widget when
   * it is called in @ref CATVidWidget#PostInteractionRecord. It may be
   * used to pass informations that are only available before an 
   * interaction is handled to the code that actually record the
   * interaction after it has been handled.
   */
  void DelayRecordInteraction(const CATSYPProperties &i_data);
private:
  /** Private copy constructor: this class is a reference-like class */
  CATVidInteractionRecorderData(const CATVidInteractionRecorderData&);
  /** Private assignement operator: this class is a reference-like class */
  CATVidInteractionRecorderData &operator=(const CATVidInteractionRecorderData&);
private:
  /** The type of the interaction */
  const CATUnicodeString _interactionType;
  /** The recorder owning this class */
  CATVidInteractionRecorder *_pRecorder;
};

#endif // CATVidInteractionRecorderData_H
