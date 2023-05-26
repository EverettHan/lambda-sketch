#ifndef CATIVisUpdatePreview_h
#define CATIVisUpdatePreview_h

// COPYRIGHT DASSAULT SYSTEMES 2018

#include "CATVisItf.h"
#include "CATBaseUnknown.h"

class CSIIViewModelContributor3D;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIVisUpdatePreview;
#else
extern "C" const IID IID_CATIVisUpdatePreview;
#endif


/**
* Interface to manage preview
* <br><b>Role</b>: This Interface is used to provide a protocol for preview management of geometrical operation.
* If you want to implement this interface for your feature, your implementation has to derive @href CATExtIVisUpdatePreview
*
*/
class ExportedByCATVisItf CATIVisUpdatePreview : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Build the preview data
	*
	* <br><b>Role</b>: this call allows you to build the data you want to display as a preview of your feature
	*
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>BuildPreviewData succeeded
	*   <dt><tt>E_FAIL</tt>        <dd>BuildPreviewData failed
	*   </dl>
	*/
	virtual HRESULT BuildPreviewData() = 0;

	/**
	* retrieves the data you want to display as a preview of your feature
	*
	* <br><b>Role</b>: using this method, a caller that needs to draw your feature in the 3D will be able to know what to use as a preview
	* when a preview event is treated (@href CATVisUpdatePreviewNotif).
	*
	* @param oData [out, CATBaseUnknown#Release]
	*   The CSIIViewModelContributor3D you want to be visualized as a preview of your feature
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>GetPreviewData succeeded
	*   <dt><tt>E_FAIL</tt>        <dd>GetPreviewData failed
	*   </dl>
	*/
	virtual HRESULT GetPreviewData(CSIIViewModelContributor3D*& oData) = 0;

	/**
	* Flush the preview data
	*
	* <br><b>Role</b>: this call allows you to flush the data you want to display as a preview of your feature
	*
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>FlushPreviewData succeeded
	*   <dt><tt>E_FAIL</tt>        <dd>FlushPreviewData failed
	*   </dl>
	*/
	virtual HRESULT FlushPreviewData() = 0;

};

CATDeclareHandler(CATIVisUpdatePreview, CATBaseUnknown);

#endif
