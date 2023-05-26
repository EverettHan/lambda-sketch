#ifndef CATVidFraPrePlaceChangedEventArgs_h
#define CATVidFraPrePlaceChangedEventArgs_h

// COPYRIGHT Dassault Systemes 2016

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>

// IntrospectionInfrastructure framework
#include <CATSYPEventArgs.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

// System framework
#include <CATBaseUnknown_WR.h>

class CATSYPEvent;
class CATVidFraWindowGroup;

/**
 * Arguments for the event dispatched just before the window place is changed, i.e just before the window
 * is docked, undocked, maximized, extracted or inserted in the viewer. 
 * @see CATVidFraWindow::PrePlaceChanged
 */
class ExportedByVisuDialog CATVidFraPrePlaceChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

  public:
  
  /**
  * Possible place changes for a window.
  */
  enum PlaceChangeType
  {
    /** The window is about to be maximized */
    MaximizeWindow,
    /** The window is about to be restored from a maximized state */
    RestoreWindow,
    /** The window is about to be extracted */
    ExtractWindow,
    /** The window is about to be inserted in the viewer */
    InsertWindow,
    /** The window is about to be docked */
    DockWindow,
    /** The window is about to be undocked */
    UndockWindow,
    /** The window is about to be attached to a window group */
    AttachWindow,
    /** The window is about to be detached from a window group */
    DetachWindow
  };
  
  /**
   * Constructor
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   */
  CATVidFraPrePlaceChangedEventArgs(
        CATSYPEvent * i_pEvent, 
        CATVidFraPrePlaceChangedEventArgs::PlaceChangeType i_placeChangeType,
        CATVidFraWindow::DockArea i_futureDockArea = CATVidFraWindow::NoneDockArea,
        CATVidFraWindowGroup * i_pWindowGroup = NULL);
    
  /**
   * Destructor
   */
  virtual ~CATVidFraPrePlaceChangedEventArgs();

  /**
   * Returns the type of place change corresponding to the CATVidFraWindow::PrePlaceChanged event.
   */
  INLINE CATVidFraPrePlaceChangedEventArgs::PlaceChangeType GetPlaceChangeType() const {return _placeChangeType;}

  /**
   * Returns the future docking area of the window  once its place will be changed.
   */
  INLINE CATVidFraWindow::DockArea GetFutureDockArea() const {return _futureDockArea;}

  /**
   * Returns the group to which the window will be attached or from which it will be detached.
   * Valid only for the AttachWindow and DetachWindow types.
   */
  CATVidFraWindowGroup * GetWindowGroup() const;

  private:
    
  CATVidFraPrePlaceChangedEventArgs(CATVidFraPrePlaceChangedEventArgs&);
  CATVidFraPrePlaceChangedEventArgs& operator=(CATVidFraPrePlaceChangedEventArgs&);

  CATVidFraPrePlaceChangedEventArgs::PlaceChangeType _placeChangeType;
  CATVidFraWindow::DockArea _futureDockArea;
  CATBaseUnknown_WR _windowGroupWR;
};

#endif // CATVidFraPrePlaceChangedEventArgs_h
