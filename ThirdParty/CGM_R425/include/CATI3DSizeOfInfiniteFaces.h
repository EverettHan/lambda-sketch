#ifndef CATI3DSizeOfInfiniteFaces_H
#define CATI3DSizeOfInfiniteFaces_H

#include "CATBaseUnknown.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"
#include "CATVisItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCATVisItf IID IID_CATI3DSizeOfInfiniteFaces;
#else
	extern "C" const IID IID_CATI3DSizeOfInfiniteFaces;
#endif

/** INTERNAL USE : this interface should not be implemented outside GeometryVisualizationBase framework
 * Interface to customize size of infinite faces (CAT3DFixedPlanGP) inside a CATSurfacicRep
 * Elligible Feature : body containing infinite faces
 * Old behavior :
 *			- either the body contains only one infinte face and a CAT3DAxisSystemRep + #1 CAT3DFixedPlanGP are created. The size of the planGP is CATGetAxisSystemLenght (from CATSettings)
 *			- or the body contains several infinite faces and a CATSurfacicRep + #N CAT3DFixedPlanGP are created. The size of the planGP is 15 millimeters
 * New behavior :
 *			- either the interface has been called and a body containing one OR several infinite faces will produce a CATSurfacicRep + #N CAT3DFixedPlanGP. The size of the planGP is customized through the interface.
 *			- or the interface has not been called and old behavior is triggered
 * 
 * WARNING : this interface is implemented in TransientExtension for CATBody, thus caller needs to keep the interface pointer alive all along its scenario
 */
class ExportedByCATVisItf CATI3DSizeOfInfiniteFaces : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Set a custom size for infinite face representation
	* @param iSize
	* Custom size in millimeters
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>Successfull.
	*   <dt><tt>E_FAIL</tt>        <dd>An error occured : e.g. if a different size is set consecutively.
	*   </dl>
	*/
	virtual HRESULT SetSize(float iSize) = 0;

	/**
	* Get the custom size for infinite face representation
	* @param oSize
	* Custom size in millimeters
	* @return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>Successfull.
	*   <dt><tt>S_FALSE</tt>			 <dd>Size has not been customized : oSize = 15.f
	*   <dt><tt>E_FAIL</tt>        <dd>An error occured.
	*   </dl>
	*/
	virtual HRESULT GetSize(float& oSize) const = 0;

	/**
	* Know whether or not the size has been customized through this interface
	* @return
	*   <dl>
	*   <dt><tt>TRUE</tt>          <dd>Size has been customized : new behavior is triggered.
	*   <dt><tt>FALSE</tt>				 <dd>Size has not been customized : old behavior is triggered.
	*   </dl>
	*/
	virtual CATBoolean SizeHasBeenCustomized() const = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATI3DSizeOfInfiniteFaces, CATBaseUnknown);

#endif // CATI3DSizeOfInfiniteFaces_H
