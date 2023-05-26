#ifndef CATIPerformance_h
#define CATIPerformance_h

#include "CATBaseUnknown.h"
#include "JS0ERROR.h"
enum CATMonitoredObjectType {BasicType, CommandType} ;

//
// COPYRIGHT DASSAULT SYSTEMES  2000
//=============================================================================
// Jan. 2000   Creation
//=============================================================================
//
/**
 * This private interface must be implemented by performance tool adapter
 * This is the  way to introduce starting and stopping points in the code
 */


/* 3a4bb70c-ca94-11d3-b822-0008c74fe80d */
extern "C" const IID IID_CATIPerformance ;

class ExportedByJS0ERROR CATIPerformance : public CATBaseUnknown 
{
	CATDeclareInterface;

	public:
		/**
		 * Set a starting point .
		 */
		virtual HRESULT Start (void* Object, const char* ObjectName, CATMonitoredObjectType CurrentType ) = 0;

		/**
		 * Set a stopping point.
		 */
		virtual HRESULT Stop (void* Object, const char* ObjectName, CATMonitoredObjectType CurrentType ) = 0;

};

CATDeclareHandler(CATIPerformance,CATBaseUnknown);

#endif
