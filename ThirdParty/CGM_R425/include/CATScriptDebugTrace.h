#ifndef CATScriptDebugTrace_h
#define CATScriptDebugTrace_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14
#include "JS0LOGRP.h"

#define SCRIPT_TRACE_ERROR_LEVEL 150
#define SCRIPT_TRACE_LOW_LEVEL 200
#define SCRIPT_TRACE_MIDDLE_LEVEL 300
#define SCRIPT_TRACE_HIGH_LEVEL 400
#define SCRIPT_TRACE_VERY_HIGH_LEVEL 500

/**
 * This class is used for printing the debug trace relative to journalling.
 * @author David Morisot (DMO)
 */
class ExportedByJS0LOGRP CATScriptDebugTrace {

  public :

		/**
		 * Starts the debug.
		 * This method creates a new instance of CATTrace.
		 */
		static HRESULT StartDebugging();

		/**
		 * Stops the debug.
		 * This method deletes the current instance of CATTrace.
		 */
		static HRESULT StopDebugging();

		/**
		 * Trace for debugging
		 */
		static CATTrace * scriptTrace;

};


#endif



