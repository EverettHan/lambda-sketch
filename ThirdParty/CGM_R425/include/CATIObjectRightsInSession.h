#ifndef CATIObjectRightsInSession_H
#define CATIObjectRightsInSession_H
// COPYRIGHT Dassault Systemes 2003

// module declaration
#include "KnowledgeItf.h"

// classes used  
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

// inherited from
#include "CATBaseUnknown.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATIObjectRightsInSession;
#else
extern "C" const IID IID_CATIObjectRightsInSession ;
#endif

typedef unsigned long CATKweRight;

//------------------------------------------------------------------

/**   
 * Interface dedicated to feature protection management.
 * <b>Role</b>: manages informations to protect in edition, browse or execution or deletion a feature.
 *              It has several types of protection :
 *                            Frozen (the protection could never be changed),
 *                            CAA (CAA applicative protection),
 *                            Setting (setting protection),
 *              The protection can also be protected by a key (like a password it needs to change the protection)
 *              The feature can be protected in exectution depending on a license.
 */

class ExportedByKnowledgeItf CATIObjectRightsInSession: public CATBaseUnknown
{
  CATDeclareInterface;

#define       CATRightTypeNoRight       (1 << 0)
#define  	  CATRightTypeEdit          (1 << 1)
#define  	  CATRightTypeBrowse        (1 << 2)
#define  	  CATRightTypeRun           (1 << 3)
#define  	  CATRightKweDelete         (1 << 4)

  public:

    /**
	* Tests if the object is editable.
	* @param oResult 
	* 0 if the object is not editable, 1 else
	* @param oExplain
	* If oExplain is not NULL when calling method, it contains the reason why the object is not editable.
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT IsEditable(int& oResult, CATUnicodeString *oExplain = NULL) const = 0;
	
	/**
	* Tests if the object is browsable.
	* @param oResult 
	* 0 if the object is not browsable, 1 else
	* @param oExplain
	* If oExplain is not NULL when calling method, it contains the reason why the object is not browsable.
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT IsBrowsable(int& oResult, CATUnicodeString *oExplain = NULL) const = 0;
	
	/**
	* Tests if the object is runnable.
	* @param oResult 
	* 0 if the object is not runnable, 1 else
	* @param oExplain
	* If oExplain is not NULL when calling method, it contains the reason why the object is not runnable.
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT IsRunnable(int& oResult, CATUnicodeString *oExplain = NULL) const = 0;


	/**
	* Set the protection level to the current object.
	* @param iRight 
	* the protection rights are either :
	                         CATRightTypeEdit, CATRightTypeBrowse, CATRightTypeRun or CATRightTypeNoRight 
	*                        or CATRightKweDelete.
	* example : CATRightTypeBrowse | CATRightKweDelete
	* @param iKey 
	*	a key to allow to change the right
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT SetRight(const CATKweRight &iRight, const CATUnicodeString &iKey = "") = 0;


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler(CATIObjectRightsInSession, CATBaseUnknown);

#endif
