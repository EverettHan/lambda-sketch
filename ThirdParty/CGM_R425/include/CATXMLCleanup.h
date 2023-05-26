// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATXMLCleanup_h
#define CATXMLCleanup_h

// XMLParser framework private headers
#include "CatXmlItfBase.h"

typedef int (*ExitFunction)(int);
class CATExitRequest {
	public:
		int operator!=(const CATExitRequest & iRef) const;
	public:
		unsigned int _priority;
		ExitFunction _function;
};

//////////////////////////////////////////////////////////////////////////////

#include  "CATLISTV_Clean.h" 

// Define the methods supported by the list of values
#define	CATLISTV_Append
#define CATLISTV_ArrayVals

// For the macro CATLISTV_DECLARE
#include  "CATLISTV_Declare.h" 

// Declare the type : list of values of class <CATExitRequest>
CATLISTV_DECLARE(CATExitRequest)
typedef CATLISTV(CATExitRequest) CATListOfCATExitRequest;

//////////////////////////////////////////////////////////////////////////////


/**
 * Class to coordinate the execution of multiple cleanup
 * functions executed at exit.
 * @author Jean-Francois DOUE (JDU)
 */
class ExportedByCatXmlItfBase CATXMLCleanup {
	public:
		static void AddExitRequest(
			ExitFunction iFunction, 
			unsigned int iPriority);

	private:
		CATXMLCleanup();
		/**
		 * Invoked by CATCallOnExit.
		 */
		static int _Cleanup (int iRc );

		/**
		 * To prioritize CATExitRequest.
		 */
		static int _Compare(const void* iArg1, const void* iArg2);

		static CATListOfCATExitRequest* _exitRequests;
};

#endif // CATXMLCleanup_h
