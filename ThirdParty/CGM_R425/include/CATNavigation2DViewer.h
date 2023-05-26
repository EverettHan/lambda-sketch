#ifndef CATNavigation2DViewer_H
#define CATNavigation2DViewer_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : Interactive window to composed by a viewpoint interactions
//	      tool bar and a 2D viewer's area.
//------------------------------------------------------------------------------
// Usage :    The toolbar is composed by :
//	       - Viewpoint basic commands frame :
//		    + Reframe 
//		    + Previous/Next viewpoint
//
//	      The CATViewerStyle argument give the style for :
//		    + CATViewerBasicIcons : toolbar's display
//		    + CATViewerScrollbars : scrollbars's display
//------------------------------------------------------------------------------
// Main methods :
//
//	Viewpoint 
//	  + SaveViewpoint : Save the current viewpoint (restorable with icons)
//
//------------------------------------------------------------------------------
// Inheritance : CATNavigation2DViewer
//		    CAT2DViewer
//		       CATViewer
//------------------------------------------------------------------------------
#include "CATVisController.h"

#include "CAT2DViewer.h"

class CAT2DViewpoint;

class CATDlgRadioButton;
class CATDlgPushButton;
class CATDlgCheckButton;
class CATDlgSplitter;
   
class CAT2DViewpointEditor;
class CAT2DCustomRep;
/**
* Class to display 2D Graphic Representations on the screen, adding
* the Local Transformations.
* When beeing instantiated, this class creates a Basic2DViewpointEditor and associate
* it to the Main2DViewpoint
*/

class ExportedByCATVisController CATNavigation2DViewer : public CAT2DViewer
{
//------------------------------------------------------------------------------
  public :

     CATDeclareClass;

   /**
   * Create a 2D Dialog frame.
   * @param iFather Dialog object the viewer will be inserted into.
   * @param iName Name of the viewer.
   * @param iStyle Frame style (See CATDlgFrame styles)
   * @param iWidth Width of the viewer's window (in pixel)
   * @param iHeight Height of the viewer's window
   * @param iViewerStyle Options of the viewer's behaviour
   */   
   CATNavigation2DViewer (CATDialog *iFather, const CATString&iName, CATDlgStyle iStyle=CATDlgFraNoTitle,
	  const int iWidth= 800, const int iHeight= 500, const CATViewerStyle iViewerStyle=NULL);
  /** @nodoc */
    virtual ~CATNavigation2DViewer();

  //  General Layout
  //  --------------
  /** @nodoc */
  void Create (CATCommand *, CATNotification *, CATCommandClientData); 
   
  //  Viewpoint save and restore managment
  //  ------------------------------------
  /** Store the Current MainViewpoint so that it cn be restored later. */
  virtual void SaveViewpoint();
  /** Restore the Viewpoint store before the current viepoint.*/
  virtual void DisplayPreviousViewpoint();
  /** Restore the Viewpoint store after the current viepoint.*/
  virtual void DisplayNextViewpoint();

  // Viewpoint actions
  //  ---------------
  /** @nodoc */
  enum ViewpointManipulationType { NoViewpointManipulation, Recenter, Translate, Zoom, ZoomArea};
  /** @nodoc */
  virtual void SetViewpointManipulation( const ViewpointManipulationType Type);

//------------------------------------------------------------------------------
  protected :

//  Reframe
  /** @nodoc */
    void ActivateReframe( CATCommand *, CATNotification *, CATCommandClientData);
  /** @nodoc */
    CATDlgPushButton  *_reframe;
    
//  Viewpoint restore mechanisms
  /** @nodoc */
    virtual void PreviousViewpoint( CATCommand *, CATNotification *, CATCommandClientData);
  /** @nodoc */
    virtual void NextViewpoint( CATCommand *, CATNotification *, CATCommandClientData);
    /** @nodoc */
    CATDlgPushButton  *_previous;
  /** @nodoc */
    CATDlgPushButton  *_next;
          
// Viewpoint interaction done by manipulator (Via button1)
  /** @nodoc */
    virtual void EndManipulate( CATCommand *Command, CATNotification *Notification, CATCommandClientData Data);
  /** @nodoc */
    CAT2DViewpointEditor *_ManipulatedViewpointEditor;
  /** @nodoc */
    CAT2DViewpointEditor *_default2DViewpointEditor;
    
  /** @nodoc */
    CATIndicator *_ViewpointIndicator;
  /** @nodoc */
    CATIndicator *_LastIndicator;
  
//------------------------------------------------------------------------------

 private :

  /** @nodoc */
 CAT2DCustomRep *_LogoCustom;  
  
//------------------------------------------------------------------------------

 public :

  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_VIEWPOINT_ACTION_ENDED);

};

#endif

