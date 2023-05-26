#pragma once

#include "CATLib.h"
#include "CATTime.h"
#include "CATString.h"
#include "CATUnicodeString.h"

#include <chrono>
#include <iostream>
#include <mutex>

/*
 * Usage:
 *	- Print logs using the macros AC_LOG_ERROR|AC_LOG_WARN|AC_LOG_INFO|AC_LOG_DEBUG
 *		e.g. AC_LOG_WARN("This is a warning (ln", 5, ")");
 *		prints: '[2023-02-03 11:27:46.480307][AC][WARN ] This is a warning (ln 5)'
 *		
 *	- Set the env var AC_LOG_LEVEL to either ERROR|WARN|INFO|DEBUG
 *		or to NONE to disable them altogether, default is ERROR.
 *
 * Note(hhr2): This logger is heavily inspired by OutputTrace in RenderingMacros.h
 */
namespace CATRmaLog
{
	static std::mutex sLogMutex;

	enum Severity : unsigned char
	{
		eSeverityError = 1,
		eSeverityWarn,
		eSeverityInfo,
		eSeverityDebug
	};

	inline unsigned char ParseLogLevelFromString(const char* iLogLevel)
	{
		if (iLogLevel == nullptr || strcmp(iLogLevel, "ERROR") == 0)
		{
			return eSeverityError;
		}
		else if (strcmp(iLogLevel, "DEBUG") == 0)
		{
			return eSeverityDebug;
		}
		else if (strcmp(iLogLevel, "INFO") == 0)
		{
			return eSeverityInfo;
		}
		else if (strcmp(iLogLevel, "WARN") == 0)
		{
			return eSeverityWarn;
		}

		return 0;
	}

	// Used as passthrough for recursion
	inline void LogToStdOut() { }

	template<typename T, typename... Targs>
	void LogToStdOut(T iValue, Targs... iFargs)
	{
		{
			std::lock_guard<std::mutex> lock(sLogMutex);

			if constexpr (std::is_same<T, CATUnicodeString>() || std::is_same<T, CATString>())
			{
				std::cout << iValue.CastToCharPtr();
			}
			else
			{
				std::cout << iValue;
			}
		}
		LogToStdOut(iFargs...); // recursive call
	}

	template<typename T, typename... Targs>
	void LogToStdOut(Severity iSeverity, T iValue, Targs... iFargs) // recursive variadic function
	{
		static const unsigned char sLogSeverity = ParseLogLevelFromString(CATGetEnv("AC_LOG_LEVEL"));

		// check if logging is disabled
		if (sLogSeverity == 0)
		{
			return;
		}

		if (static_cast<unsigned char>(iSeverity) > sLogSeverity)
		{
			return;
		}

		{
			const std::lock_guard<std::mutex> lock(sLogMutex);

			const CATUnicodeString timestamp = CATTime().ConvertToString("%Y-%m-%d %H:%M:%S");
			std::cout << "[" << timestamp.CastToCharPtr() << "]";
			std::cout << "[AC]";

			switch (iSeverity)
			{
				case eSeverityError:
				{
					std::cout << "[ERROR ]";
				}
				break;
				case eSeverityWarn:
				{
					std::cout << "[WARN ]";
				}
				break;
				case eSeverityInfo:
				{
					std::cout << "[INFO ]";
				}
				break;
				case eSeverityDebug:
				{
					std::cout << "[DEBUG ]";
				}
				break;
			}
		}
		
		LogToStdOut(iValue, iFargs...);

		{
			const std::lock_guard<std::mutex> lock(sLogMutex);
			std::cout << std::endl;
		}
	}
}

#define AC_LOG(iLvl, iFirstArg, ...) CATRmaLog::LogToStdOut(iLvl, __FILE__, ":", __LINE__, " ", iFirstArg, ##__VA_ARGS__)
#define AC_LOG_ERROR(iFirstArg, ...) AC_LOG(CATRmaLog::eSeverityError, iFirstArg, ##__VA_ARGS__)
#define AC_LOG_WARN(iFirstArg, ...) AC_LOG(CATRmaLog::eSeverityWarn, iFirstArg, ##__VA_ARGS__)
#define AC_LOG_INFO(iFirstArg, ...) AC_LOG(CATRmaLog::eSeverityInfo, iFirstArg, ##__VA_ARGS__)
#define AC_LOG_DEBUG(iFirstArg, ...) AC_LOG(CATRmaLog::eSeverityDebug, iFirstArg, ##__VA_ARGS__)
