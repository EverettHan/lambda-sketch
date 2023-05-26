//===================================================================
// COPYRIGHT Microsoft 2011/03/18
//===================================================================
// CATVidDnDManager.cpp
// Header definition of class CATVidDnDManager
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/03/18 Creation: QJP
//===================================================================

#ifndef CATVidDnDManager_H
#define CATVidDnDManager_H

#include <VisuDialog.h>
#include <CATEventSubscriber.h>
#include <CATUnicodeString.h>
#include <CATVidDnDDataSupport.h>

class CATVidDnDTransferHandler;
class CATPixelImage;
class CATNotification;
class CATVidCtl;
class CATVidGP;
class CATVidDnDModel;
//-----------------------------------------------------------------------

/**
 * @deprecated Use @ref CATVidCtl drag-and-drop instead.
 *
 * This class manages drag and drop operation.and acts as a bridge between
 * drop source and drop target. This is a singleton.
 * This class listens to drag/drop related notifications and callbacks 
 * from l_CATInteractiveApplication and routes them to the drag source or
 * drop target appropriately.
 */
class ExportedByVisuDialog CATVidDnDManager : public CATEventSubscriber
{
public:
  /** @return the singleton drag and drop manager. */
  static CATVidDnDManager * GetInstance();

public:
  /**
   *  Sets the Transfer handler of the source,
   *  Should be called by drop source when drag is started
   *  @param i_pHandlerIn the source handler
   */
  void SetSrcTransferHandler(CATVidDnDTransferHandler* i_pHandlerIn);
  /**
   *  Called by drop target after Drop is done for cleanup etc. on drop source side.
   */
  void DropDone(CATBoolean i_bDropDone);
  /**
   * routes thsi call to drag source  transfer handler during drag operation 
   * to check if drag data exists.
   * @param i_dataType enum of data type requested 
   * ( for eg. e_Text, e_CATPixelImage etc. )
   */
  CATBoolean IsDataPresent(CATVidDnDDataSupport::DataType_e dataType)const;
  /**
  * routes this call to drag source transfer handler.
  * Returns helper object of type CATVidDnDDataSupport that manages drag data.
  */
  CATVidDnDDataSupport* GetSourceDataSupport();
  /**
   * Returns if drag is curently in progress
   */
  CATBoolean IsDragging() const;

  /**
   * Callback function that listens to CATDlgDragFeedbackNotification 
   * sent by l_CATInteractiveApplication::DragFeedback()
   */
  void OnDragFeedbackCB(CATCallbackEvent iEvent,void* iPublisher, CATNotification* iNotification, CATSubscriberData  iUsefulData, CATCallback iCallBackId);
  /**
   * Callback function that listens to CATDlgQueryContinueDragNotification 
   * sent by l_CATInteractiveApplication::QueryContinueDrag()
   */
  void OnQueryContinueDragCB(CATCallbackEvent iEvent,void* iPublisher, CATNotification* iNotification, CATSubscriberData  iUsefulData, CATCallback iCallBackId);
  /**
   * Callback function that listens to DRAGEND  event. 
   * sent by l_CATInteractiveApplication when drag is cancelled.
   */
  void OnDragEndCB(CATCallbackEvent iEvent,void* iPublisher, CATNotification* iNotification, CATSubscriberData  iUsefulData, CATCallback iCallBackId);

private:
  /** Constructor. */
  CATVidDnDManager ();
  /** Destructor. */
  virtual ~CATVidDnDManager ();

private:
  /** Copy constructor. */
  CATVidDnDManager (CATVidDnDManager &);
  /** Assignment operator. */
  CATVidDnDManager& operator=(CATVidDnDManager&);

private:
  /** Singleton instance. */
  static CATVidDnDManager*  the_instance;

  /** @see #SetSrcTransferHandler */
  CATVidDnDTransferHandler* _pSrcHandler;
  /** @c TRUE during drag, @ FALSE else. */
  CATBoolean                _isDragging;
  CATCallback               _dragFeedBackCB;
  CATVidDnDDataSupport*     _pDataSupportForExternalObj;
};

//-----------------------------------------------------------------------

#endif
