#ifndef CATIndicator_h
#define CATIndicator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisFoundation.h"

#include "CATManipulator.h"
#include "CATIndicateEvent.h"
#include "CATMathPoint2Df.h"
#include "CATMouseEvent.h"

class CATViewpoint;
class CATMultiSelEvent;
class CAT2DRep;
class CATSO;
class CATVizSelectionTrapManager;

/**
*
* Class defines a behavior in the back of a viewer.
*
* This class is used by application to have informations when mouse is on
* <br>no manipulator controlled representation.
*
**/
class ExportedByCATVisFoundation CATIndicator : public CATManipulator
{
  /** @nodoc */
  CATDeclareClass;

public:

  /**
   *
   * Default constructor.
   * @param iFather
   *   a pointer to the father command of the manipulator
   * @param iName
   *   a name for the manipulator
   * @param iViewpoint
   *   The viewpoint on which the indicator must be put.
   */
  CATIndicator( CATCommand *Father, const CATString &iName, CATViewpoint *iViewpoint=NULL, CATVizBaseManipulatorMediator *i_pManipulatorMediator = NULL);

  /** @nodoc */
  virtual ~CATIndicator();

  /** @nodoc */
  void UpdateIndicateEvent ( const CATViewerEvent & );

  /** @nodoc */
  CATIndicateEvent * GetIndicateEvent ( const CATViewerEvent & );

  /** @nodoc */
  virtual MInfo Preactivate     (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo MoveOver        (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo Move            (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo EndPreactivate  (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo Activate        (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo EndActivate     (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo BeginManipulate (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo Manipulate      (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo EndManipulate   (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo Edit            (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo EndEdit         (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo Context         (CATNotification *, CATManipulator *);
  /** @nodoc */
  virtual MInfo EndContext      (CATNotification *, CATManipulator *);

  /**
   * Gets the associated viewpoint.
   *
   * @return
   *        The associated viewpoint.
   */
  CATViewpoint* GetViewpoint() const;
  /**
   * Sets the associated viewpoint. Will Addref it, and Release the current one if not NULL and different.
   **/
  void SetViewpoint(CATViewpoint* i_pViewpoint);
  
  /**
   * Activates or deactivates the multisel behaviour.
   * <br>When multisel behaviour is activated a trap of selection
   * is drawn when you click and drag from a no manipulator 
   * controlled representation.
   * <br>In this case, a call to @href CATManipulator#SendCommandSpecificObject with
   * a CATPathElement in parameter will return a list of 
   * @href CATPathElement.
   *
   * @param iActivate
   *        Indicates if the multisel behaviour must be acivate or deactivate.
   *        <br>0 value means a deactivation, a positive value activates it.
   */
  void SetMultiSelBehavior ( int iActivate =1 );

  /**
   * Gets the multisel behaviour of this indicator.
   *
   * @return
   *        0 if the multisel behaviour is deactivated.
   *        <br>A positive value means the multisel behaviour is activated.
   */
  int GetMultiSelBehavior() const;  

  /** @nodoc */
  void SetTrapStyle(unsigned int iStyle);
  /** @nodoc */
  unsigned int GetTrapStyle();

protected:

  void EndOfTrapDefinitionCB (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

  CATViewpoint	*_viewpoint;
  CATIndicateEvent	*_indicateEvent;
  int _multiSelBehavior;
  CATMultiSelEvent *_multiSelEvent;

  /** @nodoc */
  CATVizCursor::CATVizStyle _SavedCursor;

  CATCallback _TrapDefinitionCB;
  CATVizSelectionTrapManager* _pSelectionTrapManager;
};


#endif

