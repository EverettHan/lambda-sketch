// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATVidCtl3DScreen.h
// Header definition of CATVidCtl3DScreen
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2007  Creation: jov
//===================================================================
#ifndef CATVidCtl3DScreen_H
#define CATVidCtl3DScreen_H

#include "VisuDialog.h"
#include "CATVidCtlScreen.h"
#include <CAT3DViewpoint.h>
#include <CATMathPlane.h>
#include <CATMathPoint2Df.h>

class CAT3DViewpoint;
class CAT3DRep;
class CATVid3DViewpointEditor;

#define CTL3DSCREEN_ROTATE    (1 << 1)
#define CTL3DSCREEN_TRANSLATE (1 << 2)
#define CTL3DSCREEN_ZOOM      (1 << 3)

//-----------------------------------------------------------------------
/**
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtl3DScreen: public CATVidCtlScreen
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidCtl3DScreen ();
  CATVidCtl3DScreen (CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetRep(CAT3DRep* i_pRep);
  CAT3DRep*GetRep() const;

  void SetCamera(const CAT3DViewpoint& i_viewpoint);
  const CAT3DViewpoint& GetCamera() const;

  void SetAvailableLocalTransformation(unsigned int i_availableLocalTransformation);

protected:
  virtual ~CATVidCtl3DScreen ();
  virtual void ManipulateViewpoint(const CATUnicodeString& i_eventName);

private:
  CATRepWeakRef* _pRepWR;
  CATVid3DViewpointEditor* _pCameraEditor;
  unsigned int _availableLocalTransformation;
};


//-----------------------------------------------------------------------

#endif
