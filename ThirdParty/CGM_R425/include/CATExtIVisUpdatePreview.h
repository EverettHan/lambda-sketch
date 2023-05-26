//===================================================================
// COPYRIGHT Dassault Systems 2015/04/24
//===================================================================
// CATExtIVisUpdatePreview.h
// Header definition of class CATExtIVisUpdatePreview
//===================================================================


#ifndef CATExtIVisUpdatePreview_H
#define CATExtIVisUpdatePreview_H

#include "CATIVisUpdatePreview.h"
#include "CATVisItf.h"


class CSIIViewModelContributor3D;

/*Adapter class of <tt>CATIVisUpdatePreview</tt>*/

class ExportedByCATVisItf CATExtIVisUpdatePreview : public CATIVisUpdatePreview
{
public :
	CATExtIVisUpdatePreview();
  virtual ~CATExtIVisUpdatePreview();

  // Methods that can be overloaded
  virtual HRESULT BuildPreviewData();
  virtual HRESULT GetPreviewData(CSIIViewModelContributor3D*& oData);
  virtual HRESULT FlushPreviewData();
};
#endif

