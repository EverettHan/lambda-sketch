#ifndef CATKWEEvaluationErrors_h
#define CATKWEEvaluationErrors_h

// COPYRIGHT DASSAULT SYSTEMES 2009

/** 
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATLifSpecs.h"

/**   
 * Namespace for evaluation errors.
 */
class ExportedByCATLifSpecs CATKWEEvaluationErrors 
{
	public:
		/**
		 * Provides a code for an evaluation error (that is raised during expressions evaluation).
		 * This code can be used to recognize SOME of the evaluation errors. Some errors are not particularly identified. They are anonymous.
		 */
		enum Code { 
					Anonymous = 0,           // By default an error is not identified.
					TruncatedString = 1      // A string attribute has been valuated but the string has been truncated
				  };

	private:
		CATKWEEvaluationErrors();

};
#endif
