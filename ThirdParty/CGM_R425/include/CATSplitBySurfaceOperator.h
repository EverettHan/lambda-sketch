//=============================================================================
// Fev. 2009   Creation                                  LD2
//=============================================================================

/** 
 * Class representing the operator that splits a body by a surface. 
 * <br>To use the CATSplitBySurfaceOperator:
 * <ul><li>Create it the <tt>CATCreateSplitBySurfaceOperator</tt> global function. 
 * <li> <tt>Run</tt> the operator
 * <li>Retrieve the created body with the <tt>GetResult</tt> method. 
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.</ul>
 */


#ifndef CATSplitBySurfaceOperator_H 
#define CATSplitBySurfaceOperator_H 

#include "CATTopOperator.h"
#include "ExportedByPBELight.h"
#include "CATCGMVirtualMacros.h"
#include "CATSurface.h"
//#include "CATSplitBySurfaceOperatorCXR19.h"

class CATSplitBySurfaceOperatorCXR19;

class ExportedByPBELight CATSplitBySurfaceOperator: public CATTopOperator
{
		CATCGMVirtualDeclareClass(CATSplitBySurfaceOperator);

	protected:

		CATSplitBySurfaceOperator(CATGeoFactory * iFactory, CATTopData * iTopData, CATSplitBySurfaceOperatorCXR19 * iExtensible);

	public:

		virtual ~CATSplitBySurfaceOperator();

    virtual CATBody * GetResult(CATCGMJournalList * ioJournal) = 0;

};

/**
 * Creates an operator to split a body by a surface.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside the
 * configuration is <tt>NULL</tt>, it is not filled. 
 * @param iSurface
 * The pointer to the surface used to split the body.
 * @param iBodySupport
 * The body to be split.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByPBELight CATSplitBySurfaceOperator * CATCreateSplitBySurfaceOperator(CATGeoFactory * iFactory, CATTopData * iTopData,
															CATSurface * iSurface, CATBody * iBodySupport);


#endif

