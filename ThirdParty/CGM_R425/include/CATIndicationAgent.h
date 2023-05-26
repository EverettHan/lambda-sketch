#ifndef CATIndicationAgent_H_
#define CATIndicationAgent_H_
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAcquisitionAgent.h"

#include "CATCommand.h"
#include "CATMathPlane.h"
#include "CATMathPoint2D.h"
#include "DI0STATE.h"

class CATDialog;
class CATString;
class CATListPtrCATMathPoint2D;

/**
 * Class representing an agent dedicated to indication.
 * <b>Role</b>: An Indication agent is a specific acquisition agent which
 * retrieves a 2D point from a mouse left click.
 * @see CATMathPoint2D
 */

class ExportedByCATDialogEngine CATIndicationAgent : public CATAcquisitionAgent
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Constructs an indication agent.
  * @param iId
  *   The agent identifier. It is used to retrieve the undo/redo titles in 
  *   the command resource file.
  */
  CATIndicationAgent (const CATString & iId);
  
  virtual ~CATIndicationAgent ();
  
  
  /*---------------------------------*/
  //     PROJECTION PLANE 
  /*---------------------------------*/
  
 /**
  * Sets the plane on which to project a point selected in a 3D viewer.
  * <br><b>Role</b>: An indication agent directly retrieves 2D point
  * coordinates from a click in a 2D viewer. But, with a 3D viewer,
  * the click is undetermined.
  * To determine it, this method specifies a plane on which the point
  * clicked on the screen plane will be projected according to the
  * @href CATIndicationSegment direction. This direction corresponds
  * to the line going from the viewpoint eye to the mouse position on screen.
  * If no projection plane is defined, a plane perpendicular to the
  * @href CATIndicationSegment and containing the visualization origin point 
  * will be used for projection.
  * @param iPlane
  *   The plane.
  *   <br><b>Legal values</b>: it mustn't be perpendicular to the near
  *   or far planes, that is to the screen plane, in order to get a point.
  */
  void SetMathPlane (const CATMathPlane & iPlane);
  
  /**
  * Returns the plane on which a point selected in a 3D viewer is projected.
  * @return
  *   The plane.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATMathPlane & GetMathPlane ();
  
  /*---------------------------------*/
  //     VALUE 
  /*---------------------------------*/
  
  /**
  * Returns the agent value.
  * <br><b>Role</b>: The value is a 2D point.
  * The returned value depends on the @href CATAcquisitionAgent#ValuationState.
  * Indeed, if the agent valuation state is <tt>Valuated</tt>, the 
  * <tt>GetValue</tt> method returns the real value; but if the agent 
  * valuation state is <tt>PreValuated</tt>, the <tt>GetValue</tt> method 
  * returns the prevalue even if the agent has got a value. 
  * @return
  *   The value.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATMathPoint2D & GetValue ();
  
  /** @nodoc */
  virtual CATMathPoint2D * GetSpecifiedValue (CATAcquisitionAgent::ValuationState);
  
  /**
  * Sets the agent value.
  * <br><b>Role</b>: The value is a 2D point.
  * This method does not register an undo step.
  * <br><b>Postcondition</b>: Use the @href CATAcquisitionAgent#SetValuation
  * method to make the agent accept the value, otherwise this value is not
  * taken into account.
  * @param iValue
  *   The value.
  */
  virtual void SetValue (const CATMathPoint2D & iValue);
  
  /**
  * Returns whether the shift and control keys have been pushed during 
  * the indication.
  * @return
  *   The key use.
  *   <br><b>Legal values</b>: Use the defined values to decode the returned
  *   integer:
  *   <ul>
  *   <li><tt>ShiftModifierOn</tt></li>
  *   <li><tt>ControlModifierOn</tt></li>
  *   </ul>
  *   e.g: <code>if (Agent->GetModifier() & ControlModifierOn)</code>
  */
  virtual int GetModifier ();
  
  
  /*---------------------------------*/
  //     INTERNAL METHODS 
  /*---------------------------------*/
  
  /*---------------------------------*/
  /*    Dialog                       */
  /*---------------------------------*/
  /**
  * @nodoc
  * <br><b>Role</b>: Point coordinates will appear in a window
  * only if you use the method SetDialogObject
  * Using the method SetDialogObject means you must also use
  * UnsetDialogObject at the end for cleanup.
  * For proper screen positionning, this window must be placed
  * as a parallel dialog agent 
  * and displayed at the same time as the acquisition method;
  * Position validation through this window is not part of this mechanism
  * (in other words, you must take care of the OK pushbutton)
  * 
  * Example:
  *  FirstPoint = new CATIndicationAcquisitionAgent ("firstPoint");
  *  FirstPoint -> SetMathPlane (plane);
  *  FirstPoint -> SetBehavior (CATDlgEngWithPrevaluation);
  *
  *  CATApplicationFrame * AppFrame=CATApplicationFrame::GetApplicationFrame();
  *  dialog = new CATDlgDialog (AppFrame -> GetMainWindow(), "LineCoord");
  *  frame1 = new CATDlgFrame (dialog,"Name",CATDlgFraNoFrame|CATDlgFraNoTitle);
  *  dialog->Attach4Sides (frame1);
  *  FirstPoint -> SetDialogObject (frame1);
  *
  *  AddCB (dialog, dialog->GetDiaOKNotification(),
  *         (CATCommandMethod)&class::OKPoint, NULL);
  *
  *  FirstState -> AddDialogAgent (FirstPoint);
  *  FirstState -> AddDialogAgent (dialog);
  *
  * Somewhere later, you will need to do:
  *  FirstPoint -> UnsetDialogObject ();
  *  delete FirstPoint;
  *  delete dialog;
  */
  void SetDialogObject (CATDialog *);
  /** @nodoc */
  void UnsetDialogObject ();
  
  
  /*---------------------------------*/
  /*    Life cycle                   */
  /*---------------------------------*/
  
  /** @nodoc */
  virtual CATStatusChangeRC Activate (CATCommand * fromClient, CATNotification * );
  /** @nodoc */
  virtual CATStatusChangeRC Desactivate (CATCommand * fromClient, CATNotification *);
  /** @nodoc */
  virtual CATStatusChangeRC Cancel (CATCommand * fromClient, CATNotification *);
  
  
  /*---------------------------------*/
  /*    Decode management            */
  /*---------------------------------*/
  
  /** @nodoc */
  virtual void * DecodeNotification (CATCommand * from, CATNotification * notif); 
  
  
  /*---------------------------------*/
  /* Undo and Redo management        */
  /*---------------------------------*/
  
  /** @nodoc */
  virtual void * UndoValue ();
  /** @nodoc */
  virtual void * RedoValue ();
  /** @nodoc */
  virtual void StoreValue ();
  /** @nodoc */
  virtual void InitializeValue ();
  /** @nodoc */
  virtual void ResetValue ();
  
  
  /*---------------------------------*/
  /* forbidden constructor           */
  /*---------------------------------*/
  /** @nodoc */
  CATIndicationAgent ();
  
private:
    
  CATMathPlane   _mPlane; // The working plane
  int            _IsmPlaneSet;
  CATMathPoint2D _tempValue; 
  CATMathPoint2D _value;    
  
  CATDialog * _Panel;
  int _modifier;
  int _tempModifier;
  
  int _currentValueInd;
  CATListPtrCATMathPoint2D * _valueStack;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATIndicationAgent (const CATIndicationAgent &);
  CATIndicationAgent & operator= (const CATIndicationAgent &);
protected:
  
  /*----------------------------------------------------------*/
  /* Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);
};

#endif
