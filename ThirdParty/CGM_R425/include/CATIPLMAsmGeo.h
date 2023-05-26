#ifndef _CATIPLMAsmGeo_h_
#define _CATIPLMAsmGeo_h_

// Includes
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMAsmGeo;
#else
extern "C" const IID IID_CATIPLMAsmGeo;
#endif

/**
 * @level Private
 * @usage U3
 */

/**
 * This class supplies CATIAsmGeoObject.
 * <b>role</b>: CATIAsmGeoObject defines the Root, Config and other query parameters
 */

// Forward references
class CATPLMID;
class CATMathTransformation;
class CATIPLMFilterConfig;
class CATListPtrCATIPLMFilterConfig;

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMAsmGeo : public CATBaseUnknown
{
    CATDeclareInterface;

  public:

	enum PositionFlag {NoOverload = 0, Absolute = 1, Relative = 2};	

	/*
	* Returns the max number of contexts allowed in one CATIPLMAsmGeo object.
	*/
	enum AsmGeoLimits {MAX_CONTEXTS_ALLOWED = 25000};

	/**
	 * Converts the asmgeo to string in json format. Meant as a helper for calling cvservlet.
	 *
	 */

	virtual CATListOfCATUnicodeString ToJsonString() = 0;

   	/**
	 * Add a context (Path) to the ASMGEO.
	 *
	 * @param iPath
	 *     path with form [ Ref-Inst-Inst-...-Inst ] (can be only a Ref).
	 *     Remark: the Root Ref must be the same for all contexts added to the AsmGeo.
	 *             Except for MultiWrapMultiRoot
	 */
	virtual HRESULT AddContext(const CATPLMID &iPath) = 0;

    /**
	 * Add a context (Path + Position) to the ASMGEO.
	 *
	 * @param ipPath
	 *   path with form [ Ref-Inst-Inst-...-Inst ] (can be a Ref only ).
	 *     Remark: the Root Ref must be the same for all contexts added to the AsmGeo.
	 *             Except for MultiWrapMultiRoot
	 * @param iMatrixPosition
	 *   the new position for the context
	 * @param iFlagPosition
	 *   defining the new position for the context 
	 * @return 
	 * <ul>
	 *   <li>S_OK if the add operation succeeded</li>
	 *   <li>E_FAIL if an error occured during process </li>
	 * </ul>
	 */
	virtual HRESULT AddContext(const CATPLMID &iPath, const CATMathTransformation& iNewPosMatrix, const PositionFlag& iNewPosFlag) = 0;

	/** Empty the list of contexts. */
	virtual HRESULT ResetContextList() = 0;

	/**
	 * Add a path to exclude from query set.
	 *
	 * @param iExcluded
	 *     path with form [ Ref-Inst-Inst-...-Inst ]. */
	virtual HRESULT AddExcluded(const CATPLMID &iExcluded) = 0;

	/**
	 * Add a path to exclude _Majors_ from query set.
	 *
	 * @param iExcluded
	 *     path with form [ Ref-Inst-Inst-...-Inst ]. */
	virtual HRESULT AddExcludedMajor(const CATPLMID &iExcluded) = 0;

	/** Empty the list of excluded paths. */
	virtual HRESULT ResetExcludedList() = 0;

	/** Deprecated
	 *  @nodoc */
	virtual HRESULT SetExcluded(const CATPLMID &iExcluded) = 0;

	/** Set config handler that is to be used at root level. */
	virtual HRESULT SetConfigFilter(CATIPLMFilterConfig &iConfig) = 0;

    /** Set config handler that is to be used at root level. Multiple filters */
    virtual HRESULT SetConfigFilter(CATListPtrCATIPLMFilterConfig &iListConfig) = 0;

	virtual HRESULT SetExplicitMinorList(const CATLISTV(CATPLMID) &iExplicitList) = 0;

	/** 
	 * Include non 3D reps in query results
	 * Remark: Not all the index queries are complient with the mode "Non-3D Reps"
	 */
	virtual HRESULT SetWithNon3DReps() = 0;
	
	/**
	* Include bbox in query results
	* Not all the index queries are complient with the mode "bbox". Also this will do nothing if you have the legacy 3DIndex as backend.
	*/
	virtual HRESULT SetReturnBBoxes() = 0;

	/** 
	 * Prefers the Navrep of type UV when available
	 */
	virtual HRESULT SetPreferedUV() = 0;
	
};

CATDeclareHandler(CATIPLMAsmGeo, CATBaseUnknown);


#endif // CATIPLMAsmGeo_h_
