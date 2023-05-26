#ifndef CATIObjectRightsManager_H
#define CATIObjectRightsManager_H
// COPYRIGHT Dassault Systemes 2003

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH  */

// module declaration
#include "KnowledgeItf.h"

// classes used  
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

// inherited from
#include "CATBaseUnknown.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATIObjectRightsManager;
#else
extern "C" const IID IID_CATIObjectRightsManager ;
#endif

/**
* Type defining the rights on a feature.
* @param CATRightTypeNoRight
*	There is no right on the feature
* @param CATRightTypeNoRight
*   The feature can't be edited
* @param CATRightTypeBrowse
*	The feature can't be browsed
* @param CATRightTypeRun
*	The feature can't be run
* @param CATRightKweDelete
*	The feature can't be deleted
*/
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

class ExportedByKnowledgeItf CATIObjectRightsManager: public CATBaseUnknown
{
  CATDeclareInterface;

#define       CATRightTypeNoRight       (1 << 0)
#define  	  CATRightTypeEdit          (1 << 1)
#define  	  CATRightTypeBrowse        (1 << 2)
#define  	  CATRightTypeRun           (1 << 3)
#define  	  CATRightKweDelete         (1 << 4)

  /**
  * Type defining the protection of the rights of a feature.
  * @param NoType
  *		There is no protection
  * @param Frozen
  *		The rights can't be changed
  * @param Setting
  *		The rights can be modified through settings
  * @param CAA
  *		The rights can be modified through CAA APIs
  */
  enum CATProtectionType{
	  NoType = 0,
	  Frozen=1,
	  Setting=2,
	  CAA=3
  };
  

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
	* @param iProtectionType 
	* the protection types are either :
	                        NoType, 
	                        Frozen means that the right will never be modified,
	*	                    Setting means that the right come from a setting,
	*						CAA means that the right is defined by a CAA Application.
	* @param iKey 
	*	a key to allow to change the right
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT SetRight(const CATKweRight &iRight, const CATProtectionType &iProtectionType = Frozen, const CATUnicodeString &iKey = "") = 0;

	/**
	* Get the protection rights of the current object.
	* @param oRight 
	* The protection rights are either: 
	             CATRightTypeNoRight (no right)
				 CATRightTypeEdit (the object is not editable)
				 CATRightTypeBrowse (the object is not browsable)
				 CATRightTypeRun (the object is not runnable)
				 CATRightKweDelete (the object is not deletable)
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT GetRight(CATKweRight &oRight) const = 0;

	/**
	* Get the protection type to the current object.
	* @param oProtectionType 
	* the protection type : NoType,Frozen,Setting or CAA
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT GetProtectionType(CATProtectionType& oProtectionType) const = 0;

	/**
	* Allow the object to be runnable only with the defined list of licenses.
	* @param iListLicense 
	* the list of necessary licenses
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT SetLicense(const CATListOfCATUnicodeString& iListLicense) = 0;

	/**
	* Test if the object is runnable depending on licenses.
	* @param oResult 
	* 0 if the object is not licensed, 1 else. 
	* @return
	* E_FAIL if the method fails, S_OK else
	*/
	virtual HRESULT IsLicensed(int & oResult) const = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler(CATIObjectRightsManager, CATBaseUnknown);

#endif
