/* -*-c++-*- */
#ifndef CATINavigContainer_h
#define CATINavigContainer_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATINavigElement.h"
#include "CATBaseUnknown.h"

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATINavigContainer;

class CATNavigController;
class CATListValCATBaseUnknown_var;

/**
* Interface to manage container's navigation.
*/

class ExportedByCATOmnMain CATINavigContainer: public CATINavigElement
{
	CATDeclareInterface;
public:

	/**
	* Defines a root element of the navigation tree.
	* @param iObj
	*		root object.
	*/
	virtual void AddRoot(const CATBaseUnknown_var& iObj)=0;

	/**
	* Removes root element of the navigation tree.
	* @param iObj
	*		root object.
	*/
	virtual void RemoveRoot(const CATBaseUnknown_var& iObj)=0;
	
	/**
	* Removes all root elements.
	*/
	virtual void RemoveAllRoots()=0;
	
	/**
	* @nodoc 
	*/
	virtual CATListValCATBaseUnknown_var* GetAllRoots()=0;

	/**
	* @nodoc 
	*/
	virtual void SetController(const CATNavigController* controller)=0;
	
	/**
	* @nodoc 
	*/
	virtual void UpdateAll()=0;	
};


CATDeclareHandler ( CATINavigContainer, CATINavigElement );


#endif

