#ifndef CATVidInteractionRecPtHinter_H
#define CATVidInteractionRecPtHinter_H

#include <VisuDialog.h>
#include <CATMathPoint2Df.h>
#include <CATSYPProperties.h>
#include <CAT4x4Matrix.h>
#include <CATUnicodeString.h>

class CATVidInteractionRecorderData;
class CATVidWidget;

/** @ingroup groupVidRecord
 * Utility class to use to hint pointer position when implementing
 * interaction recording.
 *
 * Pointer can be the mouse for example, but also any other pointing
 * device.
 *
 * The advantage of using this class instead of manually implementing
 * the record is that it may adapt automatically to new pointing
 * devices and their events. Moreover it will use the last version of
 * event data for each kind of interactions it supports.
 *
 * This class is meant to be instantiated on stack.
 *
 * There are two constructors to this class:
 *  - #CATVidInteractionRecPtHinter(const CATUnicodeString &,CATVidInteractionRecorderData &) 
 *    is meant to be called in @ref CATVidWidget#PreInteractionRecord
 *  - #CATVidInteractionRecPtHinter(const CATUnicodeString &, CATVidInteractionRecorderData &, const CATSYPProperties &)
 *    is meant to be called in @ref CATVidWidget#PostInteractionRecord
 * 
 * @par Usage
 * In the @ref CATVidWidget#PreInteractionRecord override of your
 * widget instantiate on stack a @ref CATVidInteractionRecPtHinter in
 * all cases. If @ref #IsHintableInteraction returns @c !=0 then the
 * interaction is hintable. 
 *
 * @par
 * In that case use @ref #GetPointerPosition to obtain the pointer
 * position to hint and then build the record data that will be stored
 * by modifying the return value of @ref #GetHintableData.<br/>
 * It is mandatory to use @ref #GetHintableData as base for storing
 * record data since it contains specials properties that will be used
 * by @ref CATVidInteractionHintedPtReplayer at replay to identify
 * hinted interactions.
 *
 * @par
 * Finally call @ref CATVidInteractionRecorderData#RecordInteraction
 * with the patched data.
 *
 * @par
 * If you need to delay the recording then call @ref
 * CATVidInteractionRecorderData#DelayRecordInteraction with @ref
 * #GetHintableData (or your own partially patch derivation of
 * it). Then in the override of @ref
 * CATVidWidget#PostInteractionRecord of your widget instantiate a
 * @ref CATVidInteractionRecPtHinter using its second
 * constructor. This will ensure that @ref #IsHintableInteraction only
 * returns @c !=0 in @c PostInteractionRecord when @c
 * DelayRecordInteraction was called with @ref #GetHintableData.
 *
 * @par Sample
 * Sample implementation for @c MyWidget widget of hinting:
 * @code
 * void MyWidget::PreInteractionRecord(CATVidInteractionRecorderData &i_recorder)
 * {
 *   CATVidInteractionRecPtHinter hinter("MyWidget", i_recorder);
 *   if (hinter.IsHintableInteraction()) {
 *     CATVidWidget * const pLeaf = i_recorder.GetInteractionLeaf();
 *     CHECK_POINTER_RET(pLeaf);
 * 
 *     // handle the mouse on the background GP.
 *     if (pLeaf == __MustRetrieveSypNamedObject(this, "Background")) {
 *       // retrieve the event coordinates
 *       const CATMathPoint2Df pt = hinter.GetPointerPosition(this);
 * 
 *       // compute mouse offset relative to logical position
 *       const int offsetAlongDir = ...;
 *       const int offsetNormalDir = ...;
 * 
 *       // create the MyWidget namespace
 *       CATSYPProperties recordingData = hinter.GetHintableData();
 *       recordingData.SetProperty("MyWidget:version", CATBoxingOfint::Box(1));
 * 
 *       // store the mouse offsets
 *       recordingData.SetProperty("MyWidget:offsetAlongDir",
 *                                 CATBoxingOfint::Box(offsetAlongDir));
 *       recordingData.SetProperty("MyWidget:offsetNormalDir",
 *                                 CATBoxingOfint::Box(offsetNormalDir));
 * 
 *       i_recorder.RecordInteraction(recordingData);
 * 
 *       return;
 *     }
 *   }
 * 
 *   // by default, since no one called return, the recording has not
 *   // been handled. We call the parent class implementation to ensure
 *   // that its own recording may be used
 *   CATVidCtl::PreInteractionRecord(i_recorder);
 * }
 * @endcode
 *
 * @par
 * In this example we stores two hints, @c "MyWidget:offsetAlongDir"
 * and @c "MyWidget:offsetNormalDir", in the recording data.
 *
 * @see CATVidInteractionHintedPtReplayer
 */
class ExportedByVisuDialog CATVidInteractionRecPtHinter
{
public:
  /**
   * Initialize this object with recording data.
   *
   * This constructor is meant to be used in the implementation of
   * @ref CATVidWidget#PreInteractionRecord.
   *
   * Use @ref #IsHintableInteraction to know if the interaction can be
   * hinted.
   *
   * @param i_hinterClass the name of the class that is using
   * hinting. This name will be stored in the data returned by @ref
   * #GetHintableData and as a consequence in the record capture
   * file. It will be used during replay to identify the hinting
   * class, enabling a parent class and a child class to both use
   * hinting.
   *
   * @param i_recorder the recording data. Note that a reference to
   * this data is kept by this class. As a consequence this object
   * must be destroyed before exiting from the scope of @ref
   * CATVidWidget#PreInteractionRecord.
   */
  CATVidInteractionRecPtHinter(const CATUnicodeString &i_hinterClass, 
                               CATVidInteractionRecorderData &i_recorder);

  /**
   * Initialize this object with recording data and delayed data.
   *
   * This constructor is meant to be used in the implementation of
   * @ref CATVidWidget#PostInteractionRecord. It will reuse special
   * data set by @ref #GetHintableData. This special data are used to
   * know that the delayed recording has been delayed by this
   * class. Use @ref #IsHintableInteraction to check that it is the
   * case before calling any other method.
   *
   * @param i_hinterClass the name of the class that is using
   * hinting. It must match the name given in @c PreInteractionRecord.
   *
   * @param i_recorder the recording data. Note that a reference to
   * this data is kept by this class. As a consequence this object
   * must be destroyed before exiting from the scope of @ref
   * CATVidWidget#PostInteractionRecord.
   *
   * @param i_delayedRecordingData the delayed data.
   */
  CATVidInteractionRecPtHinter(const CATUnicodeString &i_hinterClass, 
                               CATVidInteractionRecorderData &i_recorder, 
                               const CATSYPProperties &i_delayedRecordingData);

  /** Destroy this class */
  virtual ~CATVidInteractionRecPtHinter();

  /**
   * Check if the interaction to record can be hinted by this object.
   *
   * When used in @ref CATVidWidget#PostInteractionRecord this
   * indicates that the delayed data has been produced by this class.
   *
   * It will check that the @c hinterClass is the expected one when
   * used in @c PostInteractionRecord.
   *
   * @return @c !=0 if the interaction can be hinted; else @c 0.
   */
  int IsHintableInteraction();

  /**
   * Get the pointer position to hint.
   *
   * This function can only be called if @ref IsHintableInteraction
   * returned @c !=0.
   *
   * The returned position is relative to @a i_pWidget. If not @c
   * NULL, @a i_pWidget must be in the same viewer as the one in which
   * the event occured. If it is not the case a @ref FAILURE will
   * occur and this function will return <code>0.f,0.f</code> as coordinates.
   *
   * @param i_pWidget the widget. @c NULL if the caller wants to
   * obtain the mouse position in the viewer.
   *
   * @return the mouse position relative to @a i_pWidget or relative
   * to the viewer if @a i_pWidget is @c NULL. It will return
   * <code>0.f,0.f</code> if i_pWidget is not in the correct viewer
   * (in this case a @ref FAILURE) will also be triggered.
   */
  CATMathPoint2Df GetPointerPosition(CATVidWidget *i_pWidget);
  
  /**
   * Get the interaction data where hints should be stored.
   *
   * It will also add the @c "CATVidInteractionRecPtHinter" namespace
   * that can be used to identified hinted data during replay.
   *
   * In this namespace, under the key @c
   * "CATVidInteractionRecPtHinter:hinterClass", the @c i_hinterClass
   * parameter given in the constructor will be stored to be reused by
   * @ref CATVidInteractionHintedPtReplayer during replay.
   *
   * @return the data.
   */
  CATSYPProperties GetHintableData();

public:
  /**
   * Compute the cumulated matrix that converts coordinates from @a
   * i_pFromWidget coordinates space to @a i_pToWidget coordinates
   * space.
   *
   * @param i_pFromWidget the source coordinates space. Can't be @c
   * NULL.
   *
   * @param i_pToWidget the target coordinates space. Can be @c NULL,
   * in the target coordinates space is the viewer.
   */
  static CAT4x4Matrix ComputeCumulatedMatrix(CATVidWidget *i_pFromWidget, CATVidWidget *i_pToWidget);
private:
  CATVidInteractionRecPtHinter(const CATVidInteractionRecPtHinter &);
  CATVidInteractionRecPtHinter &operator=(const CATVidInteractionRecPtHinter &);
private:
  /**
   * Setup the @c "CATVidInteractionRecPtHinter" namespace in @a io_data.
   *
   * This will set the "CATVidInteractionRecPtHinter:hinterClass"
   * property using @ref #_hinterClass value.
   */
  void SetNamespace(CATSYPProperties &io_data);
private:
  /** the recorder */
  CATVidInteractionRecorderData &_recorder;

  /** the hinter class */
  const CATUnicodeString _hinterClass;

  /** @c !=0 if interaction can be hinted; it is set to @c 0 in @c
      PostInteractionRecord constructor if the delayed data have not
      been produced by @ref #GetHintableData function */
  int _hintable;
};

#endif // CATVidInteractionRecPtHinter_H
