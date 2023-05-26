/**
*  @quickReview SOU 17:08:14 Migration from CATIPolyMesh to CATPolyBody
*/

#include "CATIACGMLevel.h"
#ifdef CATIAR420

#ifndef CAT_ADMFG_VOL_SUPPORT_DOMAIN_H
#define CAT_ADMFG_VOL_SUPPORT_DOMAIN_H

#include "AdvTopoOpeItf.h"
#include "CATIPolyMesh.h"
#include "CATPolyBody.h"

/**
 * Class that represents output of <tt>CATAdMfgVolSupportGenerator</tt>. 
*/
class ExportedByAdvTopoOpeItf CATAdMfgVolSupportDomain
{
public:
	/**
	* Destructor.
	*/
	virtual ~CATAdMfgVolSupportDomain();

	/**
	* Returns upper face of support structure as a CATPolyBody.
	* To be released by the user.
	*/
	virtual CATPolyBody * GetUpperSupportPolyBody() = 0;
	
	/**
	* Returns bottom face of support structure as a CATPolyBody.
	* To be released by the user.
	*/
	virtual CATPolyBody * GetBottomSupportPolyBody() = 0;
	
	/**
	* Returns volume of support structure as a CATPolyBody.
	* To be released by the user.
	*/
	virtual CATPolyBody * GetVolumicSupportPolyBody() = 0;
	
	/**
	* -DoNotUse-
	* It is recommended to use <tt>GetUpperSupportPolyBody<tt>.
	* To be released by the user.
	*/
	virtual CATIPolyMesh * GetUpperSupportMesh() = 0;
	
	/**
	* -DoNotUse-
	* It is recommended to use <tt>GetBottomSupportPolyBody<tt>.
	* To be released by the user.
	*/
	virtual CATIPolyMesh * GetBottomSupportMesh() = 0;
	
	/**
	* -DoNotUse-
	* It is recommended to use <tt>GetVolumicSupportPolyBody<tt>.
	* To be released by the user.
	*/
	virtual CATIPolyMesh * GetVolumicSupportMesh() = 0;
};

ExportedByAdvTopoOpeItf CATAdMfgVolSupportDomain * CATCreateSupportDomain(CATPolyBody * iVolumicBody);
ExportedByAdvTopoOpeItf CATAdMfgVolSupportDomain * CATCreateSupportDomain(CATPolyBody * iUpperBody, CATPolyBody * iBottomBody, CATPolyBody * iVolumicBody);

#endif

#endif
