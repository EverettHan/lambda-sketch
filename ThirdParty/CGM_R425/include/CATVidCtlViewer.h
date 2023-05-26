// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATVidCtlViewer.h
// Header definition of CATVidCtlViewer
//
//===================================================================
//
//  July 2010  Creation: jov
//===================================================================
#ifndef CATVidCtlViewer_H
#define CATVidCtlViewer_H

#include <CATVisImmersivePanel.h>
#include <CATVidCtlViewerBase.h>
#include <CATVidInformation.h>
#include <CATVisRepresentationRole.h>
#include <CATVisInvalidationToken.h>
#include <CATMotionEvent.h>

class CATViewer;
class CATVidCtlDlgContainer;
class CATVidGPSquare;
class CATIndicator;
class CATRep;
class CATViewpoint;

/**
 * This component is a CATVidCtlViewerBase that can switch between 2D or 3D view.
 */
class ExportedByCATVisImmersivePanel CATVidCtlViewer: public CATVidCtlViewerBase
{
  CATDeclareClass;
public:
  /**
   * Default constructor. 
   */
  CATVidCtlViewer();
  /**
   * Static method allowing to create a %CATVidCtlViewer.
   * @param i_pParent the CATCommand parent, used to send events.
   * @param i_pIdentifier the name of the widget.
   * @returns the created %CATVidCtlViewer
   */
  static CATVidCtlViewer* CreateCATVidCtlViewer(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Allow to choose to work with a 2D or a 3D viewer.
   * In case of changing the dimensions of the viewer, all the rep that have been
   * added to the viewer will be destroyed.<br>
   * Call this method just after the creation of the viewer. 
   * @param i_3DFlag boolean indicating if the viewer must be 3D or not. 
   * Default value is 1 (3D).
   */
  void Set3DFlag(CATBoolean i_3DFlag);
  /**
   * Sets a flag that allows to display some VID content through the hidden viewer.
   */
  void SetEmbedVIDFlag(CATBoolean i_embedVIDFlag);
  /** @return the flag that allows to display some VID content through the hidden viewer.*/
  CATBoolean GetEmbedVIDFlag() const;
protected:
  /**
  * Destructor
  */
  virtual ~CATVidCtlViewer ();
};
//-----------------------------------------------------------------------
#endif
