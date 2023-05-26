// Copyright Dassault Systemes 2000
#ifndef CATICkeFeature_H
#define CATICkeFeature_H

/** 
* @CAA2Level L1
* @CAA2Usage U4 CATKweObjectAdapter
*/

/*  CAA2Reviewed by FRH */

// load module
#include "CATLifSpecs.h"

// inherits from
#include "CATBaseUnknown.h"

// forwards
#include "CATICkeForwards.h"
#include "CATIParmPublisher.h"


// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeFeature;
#else
extern "C" const IID IID_CATICkeFeature;
#endif

/**   
 * Interface dedicated to manipulating objects in Knowledgeware. 
 * This interface must be implemented by features that are supposed to be selected as an input in the Knowledge Advisor rules.
 * <br>
 * For example, a surface feature S implements CATICkeFeature to be able to write a formula like this <tt> " a = area (S) " </tt><br>
 *
 * <b>Role</b>: this interface allows one to make his objects usable
 * in KnowledgeWare rule, check and formula editors.<br>
 * <br>
 * Implementations of that interface should derive from CATKweObjectAdapter.
 *
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 *
 * This interface will be multi implemented by the different applicative features.
 * This interface is not aimed at another usage than the Knowledge Advisor one.
 *
 * @see CATICkeObject, CATIType
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeFeature : public CATBaseUnknown
{
  CATDeclareInterface;

public:

	/**
	 * Returns the Knowledge type of the object. This type is part of the Knowledge dictionary.
	 * This type is used to check that the formula (rule or check) syntax is correct. <br>
	 * If your object implements CATIInstance (for DS developer) or CATIExposeObject (for CAA developer), the classical implementation returns the CATIInstance::Type method (CATIExposeObject::Type).
	 * If not, usually the implementation consists in calling CATGlobalFunctions::GetTypeDictionary()->FindTypeSafe("TypeName","PackageName",oType)
	 *
	 * @return the main type of the object. It is also a CATIType.
	 */
	virtual CATICkeType_var GetType    () const =0;

};

// declaration of Handler
CATDeclareHandler(CATICkeFeature,CATBaseUnknown);


#endif


































































