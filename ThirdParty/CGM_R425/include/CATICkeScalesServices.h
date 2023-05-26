// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATICkeScalesServices.h
// Header definition of CATICkeScalesServices
//
//===================================================================

#ifndef CATICkeScalesServices_H
#define CATICkeScalesServices_H

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

// Module export
#include "CATLifSpecs.h"
#include "CATCkeScale.h"
#include "CATBaseUnknown.h"
#include "CATICkeUnit.h"
#include "CATUnicodeString.h"

class CATTolerance;
class CATICkeMagnitude_var;

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeScalesServices;
#else
extern "C" const IID IID_CATICkeScalesServices;
#endif

//-----------------------------------------------------------------------
/**
Interface providing a set of services about design ranges (model scales) management

* <br><b>Role</b>: This interface is mono implemented. It is obtained from CATCkeGlobalFunctions::GetScalesServices() method.
* <p>
* @href CATCkeGlobalFunctions
 */
class ExportedByCATLifSpecs CATICkeScalesServices : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/** 
	* Gets the list of scales that are currently used
	* @return
	* a list of integers : each integer is the result of the cast of a CATCkeScale enum value into integer
	*/
	virtual CATListOfInt GetActivatedScales() = 0;

	/**
	* This method allows retrieving the scale of the PLM Component containing the object passed in argument
	* @param iObject
	* can be any linkable object. The scale is retrieved from the PLM Component containing iObject
	* @param oScale
	* the scale found on PLM component. It is equal to CATNormalScale if the PLM Component does not support scales management
	* @return
	* S_OK if the method succeds, E_FAIL if passed object does not allow retrieving PLM component, E_POINTER if passed object is NULL_var
	*/
	virtual HRESULT GetScaleFromObject(const CATBaseUnknown_var &iObject,  CATCkeScale &oScale) = 0;

	/**
	* This method returns the current design range chosen in preferences
	* @return
	* the current scale
	*/
	virtual CATCkeScale GetCurrentScale() = 0;

	/**
	* This method sets the current design range in preferences. The setting mustn't be locked by an administrator
	* @param iScale
	* the scale factor to set as current one. This scale has to one of the activated scales (@see GetActivatedScales)
	* @return
	* S_OK if the method succeeds, E_FAIL otherwise
	*/
	virtual HRESULT SetCurrentScale(CATCkeScale iScale) = 0;

	/**
	* This method checks if the scale setting can be modified by the caller or not
	* @return
	* TRUE if the setting is locked, FALSE otherwise
	*/
	virtual CATBoolean IsScaleSettingLocked() = 0;

	/**
	* This method returns the NLS name of a given scale
	* @param iScale
	* the scale whose name is looked for
	* @return
	* the translated name of the passed scale
	*/
	virtual CATUnicodeString GetScaleName(CATCkeScale iScale) = 0;


	/**
	* This method returns the tolerance associated to the scale deduced from the object
	* @param iObject
	* can be any linkable object. The tolerance is deduced from the scale retrieved from the PLM Component containing iObject
	* @return
	* the tolerance associated to the scale deduced from object. It returns normal scale tolerance if the scale cannot be deduced from the passed object
	*/
	virtual const CATTolerance& GetCATToleranceFromObject(const CATBaseUnknown_var &iObject) = 0;
};

CATDeclareHandler(CATICkeScalesServices,CATBaseUnknown);
//-----------------------------------------------------------------------

#endif
