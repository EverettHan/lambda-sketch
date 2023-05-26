#ifndef SWXUtAssert_H
#define SWXUtAssert_H

#include "SWXUtDebugging.h"
#include "assert.h"
#include "CATUnicodeString.h"

int ExportedBySWXUtDebugging SWXDevelopmentStage();
int ExportedBySWXUtDebugging SWXGetCATDevelopmentStage();

enum SWXPerformanceLogTag_e
{
	SWXPerformanceLogTag_LogStarted = 0,
	SWXPerformanceLogTag_LogEnded = 1,
	SWXPerformanceLogTag_SWXAssert = 2,
	SWXPerformanceLogTag_ProcessTerminated = 3,
	SWXPerformanceLogTag_CommandStarted = 4,
	SWXPerformanceLogTag_CommandEnded = 5,
	//Add before this line and increase the count
	SWXPerformanceLogTag_Count = 6
};

void ExportedBySWXUtDebugging SWXDumpToLogFile(SWXPerformanceLogTag_e iFlag, const CATUnicodeString& iMessage);

void ExportedBySWXUtDebugging SWXUtAssertFailure(
	bool iCondition,
	const CATUnicodeString &iConditionString,
	const CATUnicodeString &iMessage,
	const char *iFile,
	int iLine);

// Some Linux compiler warnings will soon become errors.  The _LINUX_SOURCE clause below removes the following warning:
//		left operand of comma operator has no effect [-Wunused-value]
// caused by calling the comma operator in (message, condition) and then throwing away the left operand "message".  The Windows
// version in the else clause works as before, in which ultimately a Stringified version of (message, condition) is passed to 
// _wassert in Microsoft's assert.h, which allows both the message and condition to appear in the error dialog.  If the Windows 
// version of these warnings become errors at some point in the future, we will need to address this else clause [bo8, 10/7/2019]
#ifdef _LINUX_SOURCE
#define SWXASSERT(condition, message) \
{ if(!(condition)) { SWXUtAssertFailure((condition) ? true : false, (#condition), (message), __FILE__, __LINE__); if ( SWXGetCATDevelopmentStage() ) assert((message, condition)); }}
#else
#define SWXASSERT(condition, message) \
{ if(!(condition)) { SWXUtAssertFailure((condition) ? true : false, (#condition), (message), __FILE__, __LINE__); if ( SWXGetCATDevelopmentStage() ) assert((message, condition)); }}
#endif

#define SWX_VERIFY_RETURN(condition, message, ret)	\
{													\
	if ( !(condition) )								\
	{												\
		SWXASSERT(FALSE, message);					\
		return (ret);								\
	}												\
}

#define SWX_VERIFY_EXIT(condition, message)	\
{											\
	if ( !(condition) )						\
	{										\
		SWXASSERT(FALSE, message);			\
		return;								\
	}										\
}

#define SWX_VERIFY_CONTINUE(condition, message)	\
{												\
	if ( !(condition) )							\
	{											\
		SWXASSERT(FALSE, message);				\
		continue;								\
	}											\
}

#define SWX_VERIFY_BREAK(condition, message)\
{											\
	if ( !(condition) )						\
	{										\
		SWXASSERT(FALSE, message);			\
		break;								\
	}										\
}

#define SWX_RETURN_FALSE(condition, message)		\
{													\
	SWX_VERIFY_RETURN(condition, message, FALSE);	\
}

#define SWX_RETURN_NULL(condition, message)		\
{												\
	SWX_VERIFY_RETURN(condition, message, NULL);\
}

// Some Linux compiler warnings will soon become errors.  The _LINUX_SOURCE clause below removes the following error:
//		error: format not a string literal and no format arguments [-Werror=format-security]
// caused by calling printf without a string literal format specifier.  If the Windows version of these warnings become
// errors at some point in the future, we will need to address this else clause [bo8, 10/7/2019]
#ifdef _LINUX_SOURCE
#define SWXPRINTF(fmt, ...) { if ( SWXGetCATDevelopmentStage() ) printf(fmt, ##__VA_ARGS__) ;}
#else
#define SWXPRINTF(...) { if ( SWXGetCATDevelopmentStage() ) printf(__VA_ARGS__) ;}
#endif
#define SWXYZ(o)  o.GetX(),o.GetY(),o.GetZ()

#endif
