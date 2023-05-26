#ifndef SWXUtTraceTime_H
#define SWXUtTraceTime_H

#include "SWXUtDebugging.h"
#include "CATLib.h"

// #define USE_SWX_DEBUG_TRACE

class ExportedBySWXUtDebugging SWXUtTraceTime
{
	int mCurrentLevel;
	CATTimeValue mStart;
	void Output(const char* iMessage);
	bool mExcluded;

public:
	SWXUtTraceTime(const char* iName);
	SWXUtTraceTime();
	double Elapsed();
	~SWXUtTraceTime();
	static void SetState(bool iEnabled);
	static bool GetState();
	static bool ActivateFeatureSetPerformance();
	static void SetActivateFeatureSetPerformance(bool iState);
};

#ifdef USE_SWX_DEBUG_TRACE
#define SWX_DEBUG_TRACE(NAME) SWXUtTraceTime trace_time(NAME)
#else  // USE_SWX_DEBUG_TRACE
#define SWX_DEBUG_TRACE(NAME) 
#endif // USE_SWX_DEBUG_TRACE

#endif
