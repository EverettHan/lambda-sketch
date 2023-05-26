#ifndef CATKWEErrorSeverity_h
#define CATKWEErrorSeverity_h

// COPYRIGHT DASSAULT SYSTEMES 2002
/** 
* @CAA2Level L1
* @CAA2Usage U1
*/


/*  CAA2Reviewed by FRH */


#include "CATLifSpecs.h"

/**   
 * Description of the severity of an error that may be raised in a user function.
 * @see CATCkeEvalContext
 */
class ExportedByCATLifSpecs CATKWEErrorSeverity 
{
	public:
		/** Severity of errors that may be raised in a user function.
		 * @param Information
	 	 * This raises an information only to be sent to the end user. It is not an error.
		 * @param Warning
	 	 * This raises an error that is not critical
		 * @param Error
		 * This raises an error that corresponds to a problem.
		 */
		enum Severity { Information, Warning, Error };

	private:
		CATKWEErrorSeverity();

};
#endif
