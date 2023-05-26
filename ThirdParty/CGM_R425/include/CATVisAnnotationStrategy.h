#ifndef CATVisAnnotationStrategy_H
#define CATVisAnnotationStrategy_H

//--- cat fw ---//
#include "SGInfra.h"
#include "CATErrorDef.h"
#include "CATSGSYPCheck.h"
#include "CATSYPCheck.h"

class CATPathElement;
class CATRepPath;

/**	
 *	This class is an abstract class which MUST BE overridden. It represents a link between applications and infrastructure. 
 *	It's used by CATVisAnnotation to generate a CATRepPath from a CATPathElement
 *	@note : Strategy Design Pattern is used.
 */	
class ExportedBySGInfra CATVisAnnotationStrategy
{
public:
	
	//+++ Life cycle management +++//
	
	/** @nodoc */
	inline void AddRef();	
	/** @nodoc */
	inline void Release();

	//--- Life cycle management ---//

	//+++ To override (MANDATORY) +++//
	
	/** Builds a repPath from the given CATPathElement. (REMEMEBER : The CAT3DFilterbagRep itself MUST NOT be in the generated rep path)
	 *	@returns S_OK or E_FAIL or ERROR_INVALID_PARAMETER	
	 */
	virtual HRESULT BuildRepPath(CATRepPath& oRepPath, CATPathElement* iPath) = 0;

	//--- To override (MANDATORY) ---//

protected:

	//--- CTR ---//	
	CATVisAnnotationStrategy();

	//--- DTR ---//
	virtual ~CATVisAnnotationStrategy();
	

private:
	//--- Not Implemented ---//
	CATVisAnnotationStrategy(const CATVisAnnotationStrategy&);
	CATVisAnnotationStrategy& operator = (const CATVisAnnotationStrategy&);
	
	unsigned int _nRef;

};

//////////////////////////////////////////////////////////////////////////
				//--- INLINE IMPLEMENTATIONS ---//
//////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------

inline
void CATVisAnnotationStrategy::AddRef()
{
	++_nRef;
}

//------------------------------------------------------------------------------

inline
void CATVisAnnotationStrategy::Release()
{
	//CHECK_TRUE_MSG(_nRef > 0, "Bad life cycle management");
	--_nRef;	
	if(0 == _nRef)
		delete this;

	

}

//------------------------------------------------------------------------------

#endif // end : CATVisAnnotationStrategy_H
