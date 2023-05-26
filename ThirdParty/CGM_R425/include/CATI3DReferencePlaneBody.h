#ifndef CATI3DReferencePlaneBody_H
#define CATI3DReferencePlaneBody_H

#include "CATBaseUnknown.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"
#include "CATVisItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCATVisItf IID IID_CATI3DReferencePlaneBody;
#else
	extern "C" const IID IID_CATI3DReferencePlaneBody;
#endif

/** INTERNAL USE : this interface should not be implemented outside GeometryVisualizationBase framework
 * Interface to activate the creation of a new kind of SceneGraph node through CATI3DGeoVisu interface.
 * Elligible Feature : body infinite face
 * Old representation : CAT3DAxisSytemRep
 * New representation : CAT3DReferencePlaneRep
 */
class ExportedByCATVisItf CATI3DReferencePlaneBody : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Activate new SceneGraph representation
	* @param iActivate
	* Activation boolean
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>Successfull.
	*   <dt><tt>E_FAIL</tt>        <dd>An error occured.
	*   </dl>
	*/
	virtual HRESULT ActivateNewSGRepresentation(CATBoolean iActivate) = 0;

	/**
	* Is the new SceneGraph representation activated ?
	* @param ioActivated
	* Activation boolean
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>Successfull.
	*   <dt><tt>E_FAIL</tt>        <dd>An error occured.
	*   </dl>
	*/
	virtual HRESULT IsNewSGRepresentationActivated(CATBoolean& ioActivated) const = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATI3DReferencePlaneBody, CATBaseUnknown);

#endif // CATI3DReferencePlaneBody_H
