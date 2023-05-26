#ifndef CATScriptError_h
#define CATScriptError_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "AutomationItf.h"

// System framework.
#include "CATInputError.h"
#include "CATUnicodeString.h"

/**
 * Error class used to describe scripting errors.
 */
class ExportedByCATAutoItf CATScriptError: public CATInputError {
	public:

		// Declare that the class CATScriptError is an error class which derives
		// from CATInputError.
		CATDeclareError(CATScriptError, CATInputError)
  
		/**
		 * Copy Constructor
		 */
		CATScriptError(const CATScriptError& iError);

		/**
		 * Destructor
		 */
	    virtual ~CATScriptError();

		/**
		 * Specifies the script line at which the error occurred.
		 */
		void SetErrorLine(int iLine);

		/**
		 * Returns the script line at which the error occurred.
		 */
		int GetErrorLine();

		/**
		 * Specifies the reference of the program in which the error occurred.
		 */
		void SetProgramReference(const CATUnicodeString& iEncodedRef);

		/**
		 * Returns the reference of the program in which the error occurred.
		 */
		void GetProgramReference(CATUnicodeString& oEncodedRef);


	protected:
		int _line;
		CATUnicodeString _programRef;
};

#endif // CATScriptError_h

