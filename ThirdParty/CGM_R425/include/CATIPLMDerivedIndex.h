#ifndef CATIPLMDerivedIndex_h_
#define CATIPLMDerivedIndex_h_

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATTime.h"
#include "CATListOfCATTime.h" // ObjectModelerSystem/ProtectedInterfaces/CATListOfCATTime.h

class CATPLMID;
class CATListValCATPLMID;
class CATILockBytes2;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMDerivedIndex;
#else
extern "C" const IID IID_CATIPLMDerivedIndex;
#endif



/**
 * This class supplies methods to manage derived objects.
 * <b>role</b>: This class enables to create and read derived objects
 */

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMDerivedIndex : public CATBaseUnknown
{
    CATDeclareInterface;

	public:
	
	/** Begins indexation 
    *  Returns S_OK if beginning of indexation was successfull
    *  Returns E_FAIL if indexation is not initialized properly or if an unexpected error occured.
    */
    virtual HRESULT BeginIndexation() = 0;

    /** Ends indexation (processes attributes indexation)
     *  Returns S_OK if end of indexation went on successfully.
     *  Returns E_FAIL if end of indexation failed or if an unexpected error occured.
     */
    virtual HRESULT EndIndexation() = 0;


    /** Indexes Derived object for object iID, with tag iTag and url iUrl.
     *  iID is a CATPLMID
     *  iTag is a CATUnicodeString representing Tag for derived object
     *  iStream is the derived stream
     *  Returns S_OK if adding the object went on successfully.
     *  Returns E_FAIL if adding the object failed or if an unexpected error occured.
     */
    virtual HRESULT AddDerivedObject(const CATPLMID	&iID, 
					const CATUnicodeString			&iTag, 
					const CATTime					&iTime, 
					const CATILockBytes2			*iStream) = 0;

	/**
	* Get a list of derived objects for a Tag.
	*/
	virtual HRESULT GetDerivedObjects(const CATListValCATPLMID &iListOfIDs,
					const CATUnicodeString iTag,
					CATListOfCATUnicodeString &oListOfURLs,
					CATListOfCATTime & oListOfCATTime) = 0;

};

CATDeclareHandler(CATIPLMDerivedIndex,CATBaseUnknown);

/**
*  Create a CATIPLMDerivedIndex object. If called several times, this method returns the same object.
*/
extern HRESULT ExportedByGUIDCATPLMIndexInterfaces GetPLMDerivedIndexFactory(CATIPLMDerivedIndex_var &oIndex);

#endif // CATIPLMDerivedIndex_h_
