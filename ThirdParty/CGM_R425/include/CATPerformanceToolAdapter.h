#ifndef	CATPerformanceToolAdapter_h
#define	CATPerformanceToolAdapter_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0ERROR.h"
#include "CATBaseUnknown.h"

#include "CATIPerformance.h"

/**
 * This class is the base class of all performance tool adapter.
 * <b>Role</b>: The purpose of this class is to collect the monitored object pointer
 * 
 */
class ExportedByJS0ERROR CATPerformanceToolAdapter : public CATBaseUnknown
{
  public :
	  CATPerformanceToolAdapter () {}
	  ~CATPerformanceToolAdapter () {}

	  void SetObject (void* Object) { _MyObject=Object; }
	  void* GetObject () { return _MyObject;}

  private :
	void* _MyObject ;

};

ExportedByJS0ERROR HRESULT CATMakeStartPoint (void* Object, const char* ObjectName, 
											  CATMonitoredObjectType CurrentType = BasicType ) ;
ExportedByJS0ERROR HRESULT CATMakeStopPoint (void* Object, const char* ObjectName, 
											  CATMonitoredObjectType CurrentType = BasicType ) ;


#endif
