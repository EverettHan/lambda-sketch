// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
// Apr 2007  CDS modifications added                           VTN
//=============================================================================
#ifndef CATICkeSetOfEquationsFactory_H
#define CATICkeSetOfEquationsFactory_H

/** 
* @CAA2Level L1
* @CAA2Usage U3
*/

/*  CAA2Reviewed by FRH */

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATIParmPublisher.h"
#include "CATCke.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATICkeSetOfEquationsFactory ;
#else
extern "C" const IID IID_CATICkeSetOfEquationsFactory ;
#endif

/**
 * Interface dedicated to the creation of Set of Equation features.<br>
 * This interface is multi implemented on feature container and volatile factory returned by @href CATCkeGlobalFunctions#GetVolatileFactory .<br>
 * This interface requires the Knowledge Advisor license (KWA).
 */
class ExportedByKnowledgeItf CATICkeSetOfEquationsFactory
: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

 /**
  * Creates a set of equations relation between parameters  (example : x+y=z and x*2=y).
  * 
  * If a syntax error occurs, NULL_var is returned and a 
  * CATCkeParseException exception is raised<br>
  * 
  * @param iSetOfEquationsName     = set of equations relation' name
  * @param iComment          = comment
  * @param iListOfParameters = (pointer on list of CATBaseUnknown_var) 
  *                            contains literal used in inputs or outputs 
  *                            (x, y and z in our example)  
  * @param iBody             = contains the string describing the set of 
  *                            equations ("x+y=z and x*2=y" in our example)
  * @param ispRoot             = (CATIParmPublisher) used to name parameters with 
  *                            RelativeName (root) method and so to be able to 
  *                            recognize parameters by their name
  *                            Not used in realnames = false mode
  * @param iRealnames  = 2 possibilities to name a parameter in the body. 
  * <tt>CATCke::True</tt>  names used are the one returned by RelativeName 
  *                        (root) and we try to recognize names used in the 
  *                        body with parameters of iListParameters..
  * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
  *                        a1 meaning the first parameter of iListParameters, 
  *                        a2, the second one, etc....<br>
  * We advise you strongly to use this second method in your application to 
  * avoid NLS problems .  
  * @param iImmediateSolving TRUE if we want to perform a solving immediately
  *  
  * @return = Set of equations created or NULL_var if syntax error.
  * When creating a set of equation relation feature, it is highly recommended to aggregate it to another one.
  * By default, the parameters that are passed as arguments MUST be in the same feature container. 
  * Other data models are not guarranted. We will enforce this behavior in future releases.
  */
  virtual CATICkeRelation_var CreateSetOfEquations(
    const CATUnicodeString      &iSetOfEquationsName,
    const CATUnicodeString      &iComment,
    const CATCkeListOfParm       iListOfParameters,
    const CATUnicodeString      &iBody,
    const CATIParmPublisher_var &ispRoot = NULL_var,
    const CATCke::Boolean       &iRealnames = 1,
	const CATCke::Boolean       &iImmediateSolving = 1  ) = 0;

};

//------------------------------------------------------------------

CATDeclareHandler( CATICkeSetOfEquationsFactory, CATBaseUnknown );

#endif
