//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012/09/20
//===================================================================
// CATV3DGPEmbeddedVid.h
// Header definition of class CATV3DGPEmbeddedVid
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/09/20 Creation: Code generated by the 3DS wizard  jv8
//===================================================================

#ifndef CATV3DGPEmbeddedVid_H
#define CATV3DGPEmbeddedVid_H

#include <VisuImmersive3D.h>
#include <CATV3DGraphicPrimitive.h>
#include <CATVidWidget.h>

class CATISYPPresenter_var;

/**
 * This class defines a V3D graphic primitive that displays a VID widget in 3D.
 * 
 * @par Role
 * The representation of this GP is the representation of any VID widget put in 3D.
 * Note that only the look of the VID widget is consistant since some VID behaviour
 * may not work properly in 3D.
 * This class implements the interface CATISYPPresenter, which allow 
 * the embedded VID widget to be defined directly in XML style definition.
 *
 * @ingroup V3DGP
 */
class ExportedByVisuImmersive3D CATV3DGPEmbeddedVid: public CATV3DGraphicPrimitive
{
  CATDeclareClass;
public:
  /** Constructor */
  CATV3DGPEmbeddedVid ();
  /** Constructor */
  CATV3DGPEmbeddedVid (CATVidWidget * i_pWidget);
  /**
   * @name CATISYPPresenter implementation
   */
  /*@{*/ 
  /** @copydoc CATISYPPresenter#SetChild */
  void SetChild(CATBaseUnknown_var i_spChild);
  /** @copydoc CATISYPPresenter#GetChild */
  CATBaseUnknown_var GetChild();
  /*@}*/ 
  /**
   * @return a handler on CATISYPPresenter. Used by XML StyleProcessor.
   */
  virtual CATISYPPresenter_var GetItem();

protected:
  /** Destrcutor */
  virtual ~CATV3DGPEmbeddedVid ();

private:
  CATV3DGPEmbeddedVid (CATV3DGPEmbeddedVid &);
  CATV3DGPEmbeddedVid& operator=(CATV3DGPEmbeddedVid&);

};

#endif