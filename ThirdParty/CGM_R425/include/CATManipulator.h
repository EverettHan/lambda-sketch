#ifndef CATManipulator_H
#define CATManipulator_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   basic class for defining interactive behavior on object
// ----------   such object are created and plugged on representation
//
//
//              the behavior can be specified on representation at different
//              interactive time
//
//	 CATPreactivate -> mouse enters on the representation
//	 CATMove -> mouse move over the representation
//	 CATEndPreactivate -> mouse leaves the representation
//	 CATActivate -> representation is selected
//	 CATBeginManipulate -> representation is taken for manipulation
//		               ( with mouse or spaceball or key after
//                                       a first drag with mouse )
//	 CATManipulate -> during manipulation
//	 CATEndManipulate -> when object is released
//	 CATEndActivate -> told to old when new manipulated object 
//                                is selected
//	 CATContext -> contextual action is asked (mouse 3 down)
//	 CATEndContext -> contextual action is choosen
//	 CATEdit -> edit action is asked (mouse dble click)
//             
//------------------------------------------------------------------------------
// Usage :       is used by application which wants to put interactive behavior
// -------       on its applicative objects in a graphical view
//
//------------------------------------------------------------------------------
// Main methods :
// --------------
//			/Preactivate/Move/Activate/Context/Edit
//			/BeginManipulate/Manipulate/EndManipulate
//                       
//			
//------------------------------------------------------------------------------
// Class :      CATManipulator
// -------         CATCommand
//
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATCommand.h"
#include "CAT2DIndication.h"
#include "list.h"
#include "CATVizCursor.h"
#include "CATMutex.h"

#include "CATPreactivate.h"
#include "CATEndPreactivate.h"
#include "CATMove.h"
#include "CATActivate.h"
#include "CATEndActivate.h"
#include "CATBeginManipulate.h"
#include "CATManipulate.h"
#include "CATEndManipulate.h"
#include "CATEdit.h"
#include "CATEndEdit.h"
#include "CATContext.h"
#include "CATEndContext.h"
class l_CATManipulator;
class CATManipulatorTouchBehavior;
class CATManipulatorMouseBehavior;

// JOV pour enlever des erreurs chez les clients, du a l'elimination de la variable  connectedViewer_.
#define CATVIEWPOINTEDITOR_NODIALOG


/** @nodoc */
enum MInfo { MActionNotDone, MActionDone};

//  global state of the manipulator is defined by 3 composite state
//  ---------------------------------------------------------------
//
//  - MState defines the current action executed on the manipulator at t time
//  - MDeviceState is valuated for the last mouse manipulated object.
//    if space ball or key are pressed, the plugged manipulator is called
//  - MEditState is valuated if an instance of CATPopup has been associated
//    to the manipulator at edit time.

/** @nodoc */
enum MState { MInNormal, MInPreactivate, MInActivate, MInManipulate, MInContext };
/** @nodoc */
enum MDeviceState { DEVICE_UNPLUGGED, DEVICE_PLUGGED };
/** @nodoc */
enum MDragAndDropState { NothingOver, DraggedOver };
/** @nodoc */
enum MEditState { NOT_RUNNING, RUNNING  };

class CATRep;
class CATNotification;
class CATVizViewer;
class CATNotification;
class CATTrace;
class CATVizBaseManipulatorMediator;

/**
*
* Class to manipulate representations.
* <b>Role</b>:
* This object fines the basic mechanisms used to provide direct manipulation
* of the visualized objects.
* This object should not be instanciated; event thought it is not an abstract object
* it should be considered as one.
*
**/
class ExportedByCATVisFoundation CATManipulator : public CATCommand
{
	friend class CATVizViewer;
	friend class CATRep;
  friend class SGInfraToVisuFConnectToolImpl;

	//----------------------------------------------------------------------------
public:
	/** @nodoc */
	CATDeclareClass;

	/**
	*
	* Constructs the Class.
	* @param iFather
	*   a pointer to the father command of the manipulator
	* @param iName
	*   a name for the manipulator
	* @param irepresentation
	*   a pointer to the manipulated representation 
	**/
	CATManipulator( CATCommand *iFather, const CATString &iName, CATRep *irepresentation=NULL, CATVizBaseManipulatorMediator *i_pManipulatorMediator = NULL);

	/** @nodoc */
	virtual ~CATManipulator();

	//  defines what kind of information can be decoded
	//  -----------------------------------------------
	/**
	* Get a desired object provided a notification.
	*
	* @param iUuid
	*  The desired object, given by the ClassName method.
	*  the CATManipulator can return :
	*    CATViewer                     The viewer from wich the manipulation event originates
	*    CATVisibleElement             The CATVisibleElement containing the CATPathElement of all visible elements  
	*    CATInsideVisibleElement       The CATVisibleElement containing the CATPathElement of all  elements entirely visible
	*    CATMouseEvent                 The CATMouseEvent that spawned the manipulation event
	*    CATIndicationSegment          The pincking segment 
	*    CATGraphicElementIntersection The point at which the picking segment intersects the manipulated representation
	*    CATGraphicElementNormal       The tangent to the manipulated representation if it is a lineic representation, the normal to this representation otherwise
	*    CATSO                         The CATSO containing all CATPathElements of repesentations under the mouse. Use CATManipulator::PickAllUnder as the iUuid to retrieve it
	*
	* @param iGraphicNotification
	*  The notification which caused the need for that object
	*  Usually, you ask a command for more information when that
	*  command calls you back. Use pass the notification you receive
	*  in your callback.
	*/
	virtual void * SendCommandSpecificObject(const char *iUuid, 
		CATNotification *iGraphicNotification);

	//  behavior of the manipulator
	//  ---------------------------
	/** @nodoc */
	virtual MInfo Preactivate         (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo MouseWheel          (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo MoveOver            (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo Move                (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo EndPreactivate      (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo Activate            (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo EndActivate         (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo BeginManipulate     (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo Manipulate          (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo EndManipulate       (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo Edit                (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo EndEdit             (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo Context             (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo EndContext          (CATNotification *, CATManipulator *);
	/** @nodoc */
	virtual MInfo BeginPreDrop        (CATNotification *, CATNotification *,
		CATManipulator *);
	/** @nodoc */
	virtual MInfo PreDrop             (CATNotification *, CATNotification *,
		CATManipulator *);
	/** @nodoc */
	virtual MInfo EndPreDrop          (CATNotification *, CATNotification *,
		CATManipulator *);
	/** @nodoc */
	virtual MInfo Drop                (CATNotification *, CATNotification *,
		CATManipulator *);

	//  notification type exported by the manipulator
	//  ---------------------------------------------

	/** Get the CATPreactivate notification's name. */
	static  const char* GetCATPreactivate();
	/** Get the CATMoveOver notification's name. */
	static  const char* GetCATMoveOver();
	/** Get the CATMove notification's name. */
	static  const char* GetCATMove();
	/** Get the CATEndPreactivate notification's name. */
	static  const char* GetCATEndPreactivate();
	/** Get the CATActivate notification's name. */
	static  const char* GetCATActivate();
	/** Get the CATEndActivate notification's name. */
	static  const char* GetCATEndActivate();
	/** Get the CATBeginManipulate notification's name. */
	static  const char* GetCATBeginManipulate();
	/** Get the CATManipulate notification's name. */
	static  const char* GetCATManipulate();
	/** Get the CATEndManipulate notification's name. */
	static  const char* GetCATEndManipulate();
	/** Get the CATEdit notification's name. */
	static  const char* GetCATEdit();
	/** Get the CATEndEdit notification's name .*/
	static  const char* GetCATEndEdit();
	/** Get the CATContext notification's name .*/
	static  const char* GetCATContext();
	/** Get the CATEndContex notification's name. */
	static  const char* GetCATEndContext();
	/** Get the CATBeginPreDrop notification's name. */
	static  const char* GetCATBeginPreDrop();
	/** Get the CATPreDrop notification's name. */
	static  const char* GetCATPreDrop();
	/** Get the CATEndPreDrop notification's name. */
	static  const char* GetCATEndPreDrop();
	/** Get the CATDrop notification's name. */
	static  const char* GetCATDrop();


	//  representation plug management
	//  ------------------------------

	/** 
	* Remove all manipulated representions from the lis of manipulated representations
	* and add a new one instead.
	*/
	void AssociateToRep(CATRep *);
	/** Add a representation to the list of manipulated representations. */
	void AddRepToManipulate(CATRep *);
	/** Remove a representation to the list of manipulated representations. */
	void RemoveRepToManipulate(CATRep *);

	//  destruction and state management
	//  --------------------------------

	/** @nodoc */
	void ResetState(CATNotification* iNotif=NULL);
	/** @nodoc */
	void InhibAutomaticActivation();
	/**
	* Destroy the manipulator, additionnal cleaning is provided
	* manipulators should always be destroyed this way. 
	*/
	void Destroy();
	/** @nodoc */
	MState GetInteractiveState() const;
	/** @nodoc*/
	MDeviceState GetDeviceState() const;
	/** @nodoc */
	MEditState GetEditState() const;
  /** @nodoc */
	MDragAndDropState GetDnDState() const;
  /** @nodoc */
  void SetDnDState (MDragAndDropState iState);
 

	/** @nodoc */
	int IsRecursiveContextualMenu() const;
	/** @nodoc */
	void SetRecursiveContextualMenu(int value = 1);
	/** 
	* Set the feedbacks on. 
	* The feedback is displayed when the user moves the mouse over the representation.
	* The feedkach is displayed on the intersection point between the mouse and the object.
	* @param OnOff Mode On=1 Off=0
	*/
	void SetFeedbackMode ( const int iOnOff = 1); 

	/** @nodoc */
	void SetIndication2D(CAT2DIndication i_indication);

	/** @nodoc */
	CAT2DIndication* GetIndication2DPtr();

	/** @nodoc */
	CATVizBaseManipulatorMediator *GetMediator();


	//++ CATManipulator lifecycle managment

	// This event is only fired in the following case :
	// If an object calls a method on the CATManipulator that sends an event (such as Activate,
	//  Preactivate, BeginManipulate, ...) and that this event is received by another object that
	//  calls the Destroy method on the same CATManipulator then, when coming back to the method
	//  that executed the send call, the CATManipulator object is dead.
	// Thanks to the Lock/Unlock methods, the calls to the Destroy method of a CATManipulator will
	//  record the CATManipulator to destroy if we're in a context of sending an event and therefore
	//  preventing its destruction.
	//  At the end of the send method, the lock is removed and all the CATManipulator marked to destroy
	//  will be destroyed. If the CATManipulator that executed the send call is in the list of objects
	//  to destroy, then the event is fired.
	/** @nodoc */
	CATDeclareCBEvent (MANIPULATOR_DESTROYED);
	/** @nodoc */
	static void Lock(void);
	/** @nodoc */
	static void Unlock(CATManipulator* iManipulator=NULL);

	//-- CATManipulator lifecycle managment

	//  manipulator behaviors
	//  --------------------------------

	/** @nodoc */
	CATManipulatorTouchBehavior* GetManipulatorTouchBehavior();

	/** @nodoc */
	void SetManipulatorTouchBehavior(CATManipulatorTouchBehavior* ipManipulatorTouchBehavior);

	/** @nodoc */
	// in case you  need Mouse wheel manupulations, you can still have some beaviours
	// CATManipulatorMouseBehavior is the class to set
	// 
	CATManipulatorMouseBehavior* GetManipulatorMouseBehavior();

	/** @nodoc */
	void SetManipulatorMouseBehavior(CATManipulatorMouseBehavior* ipManipulatorBehavior);

	/** @nodoc */
	// this query is connected to Set/Get ManipulatorMouseBehavior : it reads the parameter set
	// for the Lost Capture of the window behaviour.
	CATBoolean IsAllowedToResetOnLostCapture();

	/** @nodoc */
	// this query is connected to Set/Get ManipulatorMouseBehavior : it reads the parameter set
	// for the Mouse Wheel manipulator behaviour.
	CATBoolean IsAllowedToManipulateMouseWheel ();
  
	/** @nodoc */
	// this query is connected to Set/Get ManipulatorMouseBehavior : it reads the parameter set
	// for the Mouse manipulator behaviour.
	CATBoolean IsAllowedToActivateOnMiddleClickMode();

  /** @nodoc */
	// this query is connected to Set/Get ManipulatorMouseBehavior : it reads the parameter set
	// for the Mouse manipulator behaviour.
  CATBoolean IsAllowedToEndPreactivateOnLeave();

  /** @nodoc */
	// this query is connected to Set/Get ManipulatorTouchBehavior : it reads the parameter set
	// for the Touch manipulator behaviour.
	CATBoolean IsTouchInactivated();


  /** @nodoc */
	// SetManipWithCursor inhibits or activates cursor managment in all CATManipulator methods (such as preactivate etc)
	void SetManipWithCursor(CATBoolean icursorShow);
  CATBoolean IsManipWithCursor ();

   /** @nodoc */
	// SetIsVidCtlViewer inhibits or activates some events on texture that controls a CATViewer
	void SetIsVidCtlViewer(CATBoolean iIsVidCtlViewer);
  CATBoolean IsVidCtlViewer ();

  /** @nodoc */
	//Some Vid manipulators should forard Drag and Drop events onto the hidden content (hidden viewer).
  CATBoolean IsForwardDnDOnContentAllowed();

	//-----------------------------------------------------------------------------
protected:
	//  message send and destruction request
	//  ------------------------------------
	/** @nodoc */
	virtual void Send( CATNotification * );

	/** @nodoc */
	friend class CATVizContextualMenuHandlerV5;

	//  internal dynamic bahavior 
	//  -------------------------
	/** @nodoc */
	virtual void DereferenceRep(CATRep *);
	/** @nodoc */
	virtual void DereferenceManipulator(CATManipulator *);
	/** @nodoc */
	virtual void DereferenceViewer(CATVizViewer *);

	CATVizBaseManipulatorMediator *CreateMediator(char* string);


	//  internal data
	//  -------------
	/** @nodoc */
	CATVizViewer	*_pVizViewer;
	/** Associated representation */
	CATRep	*representation_;
	/** List of manipulated representations */
	::list<CATRep>	*manipulatedRep_;
	/** @nodoc */
	MState	mState_;
	/** @nodoc */
	MDeviceState _mDeviceState;
	/** @nodoc */
	MEditState _mEditState;
	/** @nodoc */
	MDragAndDropState _mDropState;
	/** @nodoc */
	static float _UsualRotationStep; 

	//  CATGraphicElementIntersection _intersection;
	//  CATGraphicElementNormale _normal;
	//  CATIndicationSegment _indicationSegment;

	// obsolete : cette variable ne contient plus rien. Elle a ete deplace dans CATVizBaseManipulatorMediator 
	// et est accessible par les fonctions   
	// void CATVizBaseManipulatorMediator::SetIndication2D(CAT2DIndication i_indication) et CAT2DIndication *CATVizBaseManipulatorMediator::GetIndication2DPtr();
	CAT2DIndication _indication2d;

	/** @nodoc */
	int _FeedbackMode;
	/** @nodoc */
	CATVizCursor::CATVizStyle _PreactivateCursor;

	/** @nodoc */
	CATVizBaseManipulatorMediator *_pManipulatorMediator;

	//++ CATManipulator lifecycle managment

	/** @nodoc */
	static void DestroyLockedManipulator(CATManipulator* iManipulator=NULL);

	/** @nodoc */
	static int                  _nb_lock;
	/** @nodoc */
	static ::list<CATManipulator> _listOfCATManipulator;
	/** @nodoc */
	static CATMutex             _mutexCATManipulator;

	//-- CATManipulator lifecycle managment

	//-----------------------------------------------------------------------------
private:

	//  internal job for automatic activation
	//  -------------------------------------
	void CheckAutomaticImplementationOn(CATRep &rep);

	//  recursive contextual menu management
	//  ------------------------------------
	int _recursiveContextualMenu;

	// Trace management
	static CATTrace  *_TraceManipulator;
	static int _TraceManipulatorCounter;

public:
	/** A name used to retrieve all CATPathElements on the picking segment
	*   used combined with the SendCommandSpecificObject method.
	*/
	static const char* PickAllUnder;

private :
	/** @nodoc */
	MInfo DrillActivate (CATNotification *, CATManipulator *);

public:
	/** @nodoc */
	l_CATManipulator& GetLetter() const;

private:
	l_CATManipulator* _pLetter;

	CATManipulatorTouchBehavior* _pManipulatorTouchBehavior;
	CATManipulatorMouseBehavior* _pManipulatorBehavior;

  CATBoolean _manipWithCursor;
  CATBoolean _isVidCtlViewer;
};


#endif
