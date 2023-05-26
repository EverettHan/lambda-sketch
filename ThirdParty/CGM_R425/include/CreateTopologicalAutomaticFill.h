#ifndef CreateTopologicalAutomaticFill_H 
#define CreateTopologicalAutomaticFill_H 

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "AutoFill.h"
#include "CATSkillValue.h"

#include "ListPOfCATBody.h"
#include "CATTopologicalFill.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"


class CATGeoFactory;
class CATBody;
class CATTopologicalFill;
class CATCGMJournalList;
class CATTopData;

/**
 * @nodoc
 * Attention constructeurs obsoletes.
 * Utiliser les constructeurs de SurfacicTopoOperators/ProtectedInterfaces/CATopologicalAutomaticFill.h:
 * CATTopologicalAutomaticFill * CATCreateTopologicalAutomaticFill(....) 
 */

ExportedByAutoFill
CATTopologicalFill * CreateTopologicalAutomaticFill(CATGeoFactory        *iFactory,
						     ListPOfCATBody const &iListOfWires,
					         const CATTopologicalFill::CATFillType iFillType=CATTopologicalFill::analytic,
					         CATCGMJournalList    *iJournal=NULL);




ExportedByAutoFill
CATTopologicalFill * CATCreateAutomaticFill(CATGeoFactory					* iFactory,
																						CATTopData						* iData,						     
																						ListPOfCATBody const	& iListOfWires,					       
																						ListPOfCATBody const	& iListOfSupports,						   
																						const CATTopologicalFill::CATFillType iFillType =CATTopologicalFill::analytic);



#endif


